#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Definition for a singly-linked list node.
class Node {
public:
    int value;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

// Declaration of the LinkedList class
class LinkedList {
private:
    Node* head;
    int length;

public:
    // Constructor: Creates a list with a single node
    LinkedList(int value);

    // Destructor: Frees all memory used by the list
    ~LinkedList();

    // Prints the values of all nodes in the list to the console
    void printList();

    // Returns a pointer to the head node of the list
    Node* getHead();

    // Returns the length of the list
    int getLength();

    // Removes all nodes from the list, freeing their memory
    void makeEmpty();

    // Appends a new node with the given value to the end of the list
    void append(int value);

    // Deletes the first node of the list
    void deleteFirst();
 
    // This is the function the student must implement.
    void reverseBetween(int m, int n);
};

#endif // LINKEDLIST_H