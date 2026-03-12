#include "PluginProcessor.h"
#include "PluginEditor.h"

juce::AudioProcessorValueTreeState::ParameterLayout FaustSynthAudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("cutoff",  "Cutoff Hz",
        juce::NormalisableRange<float>(20.f, 20000.f, 1.f, 0.3f), 1000.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("q",       "Resonance",
        juce::NormalisableRange<float>(0.1f, 20.f, 0.01f), 1.f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("detune",  "Detune cents",
        juce::NormalisableRange<float>(-1200.f, 1200.f, 1.f), 0.f));
    return layout;
}

FaustSynthAudioProcessor::FaustSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ),
#else
    :
#endif
    apvts(*this, nullptr, "Parameters", createParameterLayout())
{
}

FaustSynthAudioProcessor::~FaustSynthAudioProcessor() {}

const juce::String FaustSynthAudioProcessor::getName() const { return JucePlugin_Name; }
bool FaustSynthAudioProcessor::acceptsMidi() const { return true; }
bool FaustSynthAudioProcessor::producesMidi() const { return false; }
bool FaustSynthAudioProcessor::isMidiEffect() const { return false; }
double FaustSynthAudioProcessor::getTailLengthSeconds() const { return 0.0; }
int FaustSynthAudioProcessor::getNumPrograms() { return 1; }
int FaustSynthAudioProcessor::getCurrentProgram() { return 0; }
void FaustSynthAudioProcessor::setCurrentProgram(int) {}
const juce::String FaustSynthAudioProcessor::getProgramName(int) { return {}; }
void FaustSynthAudioProcessor::changeProgramName(int, const juce::String&) {}

void FaustSynthAudioProcessor::prepareToPlay(double sampleRate, int)
{
    fDSP.init((int)sampleRate);
    fDSP.buildUserInterface(&fUI);
}

void FaustSynthAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FaustSynthAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    return true;
}
#endif

void FaustSynthAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                             juce::MidiBuffer& midiMessages)
{
    fUI.setParamValue("Cutoff Hz",     apvts.getRawParameterValue("cutoff")->load());
    fUI.setParamValue("Q / Resonance", apvts.getRawParameterValue("q")->load());
    fUI.setParamValue("Detune cents",  apvts.getRawParameterValue("detune")->load());

    for (const auto meta : midiMessages)
    {
        auto msg = meta.getMessage();
        if (msg.isNoteOn()) {
            fUI.setParamValue("gate", 1.0f);
            fUI.setParamValue("freq", (float)msg.getMidiNoteInHertz(msg.getNoteNumber()));
            fUI.setParamValue("gain", msg.getFloatVelocity());
        }
        else if (msg.isNoteOff()) {
            fUI.setParamValue("gate", 0.0f);
        }
    }

    float* outputs[2] = {
        buffer.getWritePointer(0),
        buffer.getWritePointer(1)
    };
    fDSP.compute(buffer.getNumSamples(), nullptr, outputs);
}

bool FaustSynthAudioProcessor::hasEditor() const { return true; }
juce::AudioProcessorEditor* FaustSynthAudioProcessor::createEditor()
{
    return new FaustSynthAudioProcessorEditor(*this);
}

void FaustSynthAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    auto state = apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void FaustSynthAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
    if (xml && xml->hasTagName(apvts.state.getType()))
        apvts.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FaustSynthAudioProcessor();
}
