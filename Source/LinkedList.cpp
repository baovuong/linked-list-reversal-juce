/*
  ==============================================================================

    LinkedList.cpp
    Created: 4 Mar 2025 4:44:27pm
    Author:  vqbao

  ==============================================================================
*/

#include "LinkedList.h"

#include <iostream>


using namespace std;


LinkedListNode::LinkedListNode()
{
    value = 0;
    next = nullptr;
}

LinkedListNode::~LinkedListNode()
{
}

LinkedList::LinkedList()
{
    first = nullptr;
}

LinkedList::~LinkedList()
{
    // deallocate every node
    LinkedListNode* current = first;
    LinkedListNode* prev;

    while (current->next != nullptr)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
}

juce::String LinkedList::toString()
{
    juce::String output;
    LinkedListNode* current = first;
    while (current != nullptr)
    {
        output += juce::String(current->value);
        current = current->next;
        if (current != nullptr) output += ", ";
    }
    return output;
}

bool LinkedList::contains(int value)
{
    // O(n) traversal 
    return false;
}

bool LinkedList::isEmpty()
{
    return first == nullptr;
}

void LinkedList::size()
{
}

void LinkedList::add(int value)
{
    if (first == nullptr)
    {
        first = new LinkedListNode();
        first->value = value;
        first->next = nullptr;
        return;
    }

    LinkedListNode* current = first;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new LinkedListNode();
    current->next->value = value;
}


