#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class FaustSynthAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    FaustSynthAudioProcessorEditor(FaustSynthAudioProcessor&);
    ~FaustSynthAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    FaustSynthAudioProcessor& audioProcessor;

    // Knobs
    juce::Slider cutoffKnob, qKnob, detuneKnob;
    juce::Label  cutoffLabel, qLabel, detuneLabel;

    // Attachments APVTS
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> qAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> detuneAttach;

    void setupKnob(juce::Slider& knob, juce::Label& label, const juce::String& labelText);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FaustSynthAudioProcessorEditor)
};
