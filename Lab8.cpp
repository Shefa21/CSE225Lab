//header file
//stacktype.h
#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int MAX_ITEMS = 5;

// Exception class thrown by Push when stack is full
class FullStack {};

// Exception class thrown by Pop and Top when stack is empty
class EmptyStack {};

// Template class for a stack
template <class ItemType>
class StackType {
public:
    // Constructor
    StackType();

    // Determines if the stack is full
    bool IsFull();

    // Determines if the stack is empty
    bool IsEmpty();

    // Empties the stack
    void MakeEmpty();

    // Pushes an item onto the stack
    void Push(ItemType);

    // Pops an item from the stack
    void Pop();

    // Returns the top item of the stack
    ItemType Top();

private:
    int top; // Index of the top item
    ItemType items[MAX_ITEMS]; // Array to store items
};

#endif // STACKTYPE_H_INCLUDED

//source file
//stacktype.cpp
#include "StackType.h"

// Constructor
template <class ItemType>
StackType<ItemType>::StackType() {
    top = -1; // Initialize top index to -1 indicating an empty stack
}

// Determines if the stack is empty
template <class ItemType>
bool StackType<ItemType>::IsEmpty() {
    return (top == -1); // Stack is empty if top index is -1
}

// Empties the stack
template <class ItemType>
void StackType<ItemType>::MakeEmpty() {
    top = -1; // Reset top index to -1 to empty the stack
}

// Determines if the stack is full
template <class ItemType>
bool StackType<ItemType>::IsFull() {
    return (top == MAX_ITEMS - 1); // Stack is full if top index equals maximum capacity - 1
}

// Pushes an item onto the stack
template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
    if (IsFull()) { // Check if the stack is already full
        throw FullStack(); // Throw FullStack exception if the stack is full
    }
    top++; // Increment top index
    items[top] = newItem; // Add newItem to the stack
}

// Pops an item from the stack
template <class ItemType>
void StackType<ItemType>::Pop() {
    if (IsEmpty()) { // Check if the stack is empty
        throw EmptyStack(); // Throw EmptyStack exception if the stack is empty
    }
    top--; // Decrement top index to remove the top item
}

// Returns the top item of the stack
template <class ItemType>
ItemType StackType<ItemType>::Top() {
    if (IsEmpty()) { // Check if the stack is empty
        throw EmptyStack(); // Throw EmptyStack exception if the stack is empty
    }
    return items[top]; // Return the top item of the stack
}

// Explicit instantiation of the template class for char type
template class StackType<char>;

//main file
#include "stacktype.h"
#include "stacktype.cpp"
#include<iostream>
#include<string>
using namespace std;

bool checkB(const string& p) {
    StackType<char> stack; // Initialize an empty stack to store opening parentheses
    for (int i = 0; i < p.length(); i++) { // Loop through each character in the string
        char ch = p[i];
        if (ch == '(') { // If the character is an opening parentheses
            stack.Push(ch); // Push it onto the stack
        } else if (ch == ')') { // If the character is a closing parentheses
            try {
                stack.Pop(); // Pop from the stack (matching opening parentheses)
            } catch (EmptyStack e) { // Catch EmptyStack exception if stack is empty
                return false; // More closing parentheses than opening ones
            }
        }
    }
    return stack.IsEmpty(); // Checking if the stack is empty after processing all characters
}

int main() {
    string p;

    // Prompt the user to input a set of parentheses
    cout << "input a set of parentheses: ";
    getline(cin, p);//Read the entire line of user input, including spaces and special characters

    // Check if the parentheses are balanced
    if (checkB(p)) {
        cout << "Balanced" << endl; // Output "Balanced" if parentheses are balanced
    } else {
        cout << "Not Balanced" << endl; // Output "Not Balanced" if parentheses are not balanced
    }

    return 0;
}

