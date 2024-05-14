#include "List.h"

// Constructor
List::List() {
    head = NULL; // Initially, the list is empty
}

// Destructor
List::~List() {
    Node* currNode = head;
    Node* nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode; // Free the memory for the current node
        currNode = nextNode;
    }
}

// Check if the list is empty
bool List::IsEmpty() {
    return head == NULL;
}

// Insert a node at a specified index
Node* List::InsertNode(double x) {
    Node* newNode = new Node; // Create the new node
    newNode->data = x;

    if (head == NULL || head->data >= x) { // Insert at the beginning
        newNode->next = head;
        head = newNode;
    } else { // Find the correct position to maintain sorting
        Node* currNode = head;

        // Traverse until finding the right position
        while (currNode->next != NULL&& currNode->next->data < x) {
            currNode = currNode->next;
        }

        newNode->next = currNode->next;
        currNode->next = newNode;
    }

    return newNode;
}
// Find the position of a node with a specific value
int List::FindNode(double x) {
    Node* currNode = head;
    int currIndex = 1;

    while (currNode && currNode->data != x) {
        currNode = currNode-> next;
        currIndex++;
    }

    if (currNode) {
        return currIndex; // Node found
    }

    return 0; // Node not found
}

// Delete a node with a specific value
int List::DeleteNode(double x) {
    Node* prevNode = NULL;
    Node* currNode = head;
    int currIndex = 1;

    while (currNode && currNode->data != x) {
        prevNode = currNode;
        currNode = currNode-> next;
        currIndex++;
    }

    if (currNode) {
        if (prevNode) { // Node is not the first node
            prevNode-> next = currNode-> next;
        } else { // Node is the first node
            head = currNode->next;
        }
        delete currNode; // Release memory for the deleted node
        return currIndex; // Position of the deleted node
    }

    return 0; // Node not found
}

// Display all elements in the list
void List::DisplayList() {
    int count = 0;  // Variable to count the number of nodes in the list
    Node* currNode = head;  // Start traversing from the head of the list

    // Loop through the linked list until there are no more nodes
    while (currNode != NULL) {
        // Print the data stored in the current node
        std::cout << currNode->data << std::endl;

        // Move to the next node
        currNode = currNode->next;

        // Increment the node counter
        count++;
    }

    // After traversing the list, print the total count of nodes
    std::cout << "Number of nodes in the list: " << count << std::endl;
}

#include <iostream> // Include standard input/output library
using namespace std;

// Definition of the Node class for a binary tree
class Node {
public:
    int data; // Data value of the node
    Node *left; // Pointer to the left child
    Node *right; // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int a) {
        data = a;
        left = NULL; // Initially, no left child
        right = NULL; // Initially, no right child
    }
};

// Function to perform in-order traversal
void inorder(Node *root) {
    if (root == NULL) { // Base case: if the node is NULL, return
        return;
    }
    inorder(root->left); // Traverse left subtree
    cout << root->data << " "; // Print the current node's data
    inorder(root->right); // Traverse right subtree
}

// Function to perform pre-order traversal
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " "; // Print the current node's data
    preorder(root->left); // Traverse left subtree
    preorder(root->right); // Traverse right subtree
}

// Function to perform post-order traversal
void postorder(Node *root) {
    if (root == NULL) { // Base case: if the node is NULL, return
        return;
    }
    postorder(root->left); // Traverse left subtree
    postorder(root->right); // Traverse right subtree
    cout << root->data << " "; // Print the current node's data
}

int main() {
    // Create the binary tree with the specified structure
    Node *root = new Node(11); // Root node

    root->left = new Node(9); // Left child of the root
    root->right = new Node(4); // Right child of the root

    root->left->left = new Node(7); // Left child of 9
    root->left->right = new Node(8); // Right child of 9

    root->left->left->left = new Node(2); // Left child of 7
    root->left->left->right = new Node(5); // Right child of 7

    root->left->right->left = new Node(6); // Left child of 8

    root->right->left = new Node(3); // Left child of 4
    root->right->right = new Node(1); // Right child of 4

    // Perform in-order traversal
    cout << "In-order traversal: ";
    inorder(root); // Should print: 2 7 5 9 6 8 11 3 4 1
    cout << endl;

    // Perform pre-order traversal
    cout << "Pre-order traversal: ";
    preorder(root); // Should print: 11 9 7 2 5 8 6 4 3 1
    cout << endl;

    // Perform post-order traversal
    cout << "Post-order traversal: ";
    postorder(root); // Should print: 2 5 7 6 8 9 3 1 4 11
    cout << endl;

    return 0; // End of program
}
