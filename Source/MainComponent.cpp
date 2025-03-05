#include "MainComponent.h"
#include "LinkedList.h"

#define PADDING 5


void populateList(LinkedList& list, const juce::String &text);

//==============================================================================
MainComponent::MainComponent()
{
    // define gui components
    //listInput.setColour(juce::Label::backgroundColourId, juce::Colours::black);
    listInput.setJustification(juce::Justification::verticallyCentred);
    addAndMakeVisible(listInput);
    
    listInputLabel.setText("Input (numbers separated by commas):", juce::dontSendNotification);
    listInputLabel.attachToComponent(&listInput, true);
    listInputLabel.setJustificationType(juce::Justification::right);
    addAndMakeVisible(listInputLabel);

    listOutput.setJustification(juce::Justification::verticallyCentred);
    addAndMakeVisible(listOutput);

    listOutputLabel.setText("Output:", juce::dontSendNotification);
    listOutputLabel.attachToComponent(&listOutput, true);
    listOutputLabel.setJustificationType(juce::Justification::right);
    addAndMakeVisible(listOutputLabel);

    reverseButton.setButtonText("Reverse");
    reverseButton.onClick = [this] { reverseInput(); };
    addAndMakeVisible(reverseButton);

    sortButton.setButtonText("Sort");
    addAndMakeVisible(sortButton);
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{


    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::FontOptions (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World: " + juce::String(getLocalBounds().getWidth()) + ", " + juce::String(getLocalBounds().getHeight()), getLocalBounds(), juce::Justification::centred, true);


}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    auto area = getLocalBounds();
    auto listInputLabelWidth = 250;
    auto listInputLabelHeight = 40;
    auto listOutputLabelWidth = 50;
    listInput.setBounds(area.removeFromTop(listInputLabelHeight)
        .removeFromRight(area.getWidth()-listInputLabelWidth));

    listOutput.setBounds(area.removeFromBottom(listInputLabelHeight)
        .removeFromRight(area.getWidth() - listOutputLabelWidth));

    reverseButton.setBounds(area.removeFromLeft(area.getWidth() / 2).removeFromBottom(listInputLabelHeight));
    sortButton.setBounds(area.removeFromRight(area.getWidth() / 2).removeFromBottom(listInputLabelHeight));
}

void MainComponent::reverseInput()
{
    // convert to linked list
    LinkedList list;
    populateList(list, listInput.getText());

    // reverse the linked list
    list.reverse();

    // output it 
    listOutput.setText(list.toString());
}

void populateList(LinkedList& list, const juce::String &text)
{
    juce::StringArray tokens;
    tokens.addTokens(text, ",", "\"");
    for (int i = 0; i < tokens.size(); i++)
    {
        list.add(tokens.getReference(i).getIntValue());
    }
}