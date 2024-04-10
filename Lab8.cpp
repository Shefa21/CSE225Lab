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
#include <iostream>
#include "stacktype.cpp" // Include the implementation file to use the template class
using namespace std;

// Helper function to check if the stack is empty
void checkEmpty(bool b) {
    if (b)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

// Helper function to check if the list is full
void checkFull(bool b) {
    if (b)
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
}

// Helper function to print the list
void Print(StackType<int> st) {
    StackType<int> temp;

    // Push elements from stack 'st' to temporary stack 'temp'
    while (!st.IsEmpty()) {
        temp.Push(st.Top());
        st.Pop();
    }

    // Pop elements from 'temp' and print them while restoring 'st'
    while (!temp.IsEmpty()) {
        st.Push(temp.Top());
        cout << temp.Top() << " ";
        temp.Pop();
    }
    cout << endl;
}
//driver file
int main() {
    // First Task
    StackType<int> st; // Creating a stack of integers

    checkEmpty(st.IsEmpty()); // Check if the stack is empty

    // Push four items 5, 7, 4, 2
    st.Push(5);
    st.Push(7);
    st.Push(4);
    st.Push(2);

    checkEmpty(st.IsEmpty()); // Check if the stack is empty

    checkFull(st.IsFull()); // Check if the stack is full

    Print(st); // Print the values in the stack

    st.Push(3); // Push another item 3

    Print(st); // Print the values in the stack

    checkFull(st.IsFull()); // Check if the stack is full

    st.Pop(); // Pop two items
    st.Pop();

    cout << st.Top() << endl; // Print top item

    // Second Task
    StackType<char> parentheses; // Create a stack of characters to take input

    string str; // String to take input from the user
    cin >> str;

    // Loop until the end of string
    for (int i = 0; str[i] != '\0'; i++) {
        char array_item = str[i]; // Get current character from string

        if (array_item == '(') // Push '(' into stack
            parentheses.Push(array_item);

        try {
            if (array_item == ')') // Pop '(' if ')' is encountered
                parentheses.Pop();
        }
        catch (EmptyStack) { // If stack is empty and encounter ')', string is unbalanced
            cout << "Unbalanced" << endl;
            return 0;
        }
    }

    // If stack is empty after processing string, it's balanced
    if (parentheses.IsEmpty())
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
