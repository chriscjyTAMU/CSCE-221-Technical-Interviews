#include "LinkedList.h"
#include <iostream>

// --- Implementations of PROVIDED LinkedList Methods ---

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    length = 1;
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

int LinkedList::getLength() {
    return length;
}

void LinkedList::makeEmpty() {
    Node* temp = head;
    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
    length = 0;
}      

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    length++;
}

void LinkedList::deleteFirst() {
    if (length == 0) return;
    Node* temp = head;
    if (length == 1) {
        head = nullptr;
    } else {
        head = head->next;
    }
    delete temp;
    length--;
}

/* NOTICE: 
   The reverseBetween(int m, int n) function is intentionally NOT implemented in this file.
   You should implement reverseBetween(int m, int n) function in LinkedList_ReverseBetween.cpp and
   submit just that file.
*/
