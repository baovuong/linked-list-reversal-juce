#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void reverseInput();

private:
    //==============================================================================
    // Your private member variables go here...
    juce::Label listInputLabel;
    juce::TextEditor listInput;
    juce::Label listOutputLabel;
    juce::TextEditor listOutput;

    juce::TextButton reverseButton;
    juce::TextButton sortButton;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
