/*
  ==============================================================================

    LinkedList.h
    Created: 4 Mar 2025 4:44:27pm
    Author:  vqbao

  ==============================================================================
*/
#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <JuceHeader.h>


struct LinkedListNode 
{
    LinkedListNode* next;
    int value;

    LinkedListNode();
    ~LinkedListNode();
};

class LinkedList 
{

private:
    LinkedListNode* first;

public:
    LinkedList();
    ~LinkedList();
    juce::String toString();
    bool contains(int value);
    bool isEmpty();
    void size();
    void add(int value);
    void reverse();
    void sort();

};

#endif