/*
  ==============================================================================

    BVLookAndFeel.cpp
    Created: 6 Mar 2025 12:24:26pm
    Author:  vqbao

  ==============================================================================
*/

#include "BVLookAndFeel.h"

BVLookAndFeel::BVLookAndFeel()
{
    setColour(juce::TextButton::buttonColourId, juce::Colour(0xff63462d));
    setColour(juce::TextButton::textColourOnId, juce::Colours::lightgreen);
    setColour(juce::TextButton::textColourOffId, juce::Colours::lightgreen);
}
