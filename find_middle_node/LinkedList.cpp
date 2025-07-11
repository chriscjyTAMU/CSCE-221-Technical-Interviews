#include "../include/LinkedList.h"
#include <iostream>

// --- Implementations of PROVIDED LinkedList Methods ---

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
}


LinkedList::~LinkedList() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList() {
    Node* temp = head;
    if (temp == nullptr) {
        std::cout << "empty";
    } else {
        while (temp != nullptr) {
            std::cout << temp->value;
            temp = temp->next;
            if (temp != nullptr) {
                std::cout << " -> ";
            }
        }
    }
    std::cout << std::endl;
} 

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail; 
}


void LinkedList::makeEmpty() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = nullptr;
}      

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

/* NOTICE: 
   The findMiddleNode() function is intentionally NOT implemented in this file.
   You should implement findMiddleNode() function in LinkedList_MiddleNode.cpp and
   submit just that file.
*/