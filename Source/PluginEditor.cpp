#include "PluginProcessor.h"
#include "PluginEditor.h"

FaustSynthAudioProcessorEditor::FaustSynthAudioProcessorEditor(FaustSynthAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setupKnob(cutoffKnob,  cutoffLabel,  "Cutoff");
    setupKnob(qKnob,       qLabel,       "Resonance");
    setupKnob(detuneKnob,  detuneLabel,  "Detune");

    cutoffAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "cutoff", cutoffKnob);
    qAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "q", qKnob);
    detuneAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.apvts, "detune", detuneKnob);

    setSize(400, 200);
}

FaustSynthAudioProcessorEditor::~FaustSynthAudioProcessorEditor() {}

void FaustSynthAudioProcessorEditor::setupKnob(juce::Slider& knob, juce::Label& label, const juce::String& labelText)
{
    knob.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    knob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(knob);

    label.setText(labelText, juce::dontSendNotification);
    label.setJustificationType(juce::Justification::centred);
    label.setFont(juce::Font(14.f, juce::Font::bold));
    addAndMakeVisible(label);
}

void FaustSynthAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(30, 30, 40));
    g.setColour(juce::Colours::white);
    g.setFont(juce::Font(18.f, juce::Font::bold));
    g.drawText("FaustSynth", getLocalBounds().removeFromTop(40), juce::Justification::centred);
}

void FaustSynthAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced(10);
    area.removeFromTop(40); // tytuł

    int knobW = area.getWidth() / 3;

    auto labelH = 20;
    auto knobArea = area.removeFromTop(area.getHeight() - labelH);
    auto labelArea = area;

    cutoffLabel.setBounds(labelArea.removeFromLeft(knobW));
    qLabel     .setBounds(labelArea.removeFromLeft(knobW));
    detuneLabel.setBounds(labelArea);

    cutoffKnob.setBounds(knobArea.removeFromLeft(knobW).reduced(10));
    qKnob     .setBounds(knobArea.removeFromLeft(knobW).reduced(10));
    detuneKnob.setBounds(knobArea.reduced(10));
}
