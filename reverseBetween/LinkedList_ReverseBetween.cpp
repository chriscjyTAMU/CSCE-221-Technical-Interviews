#include "LinkedList.h"

/* 

You should only implement reverseBetween(int m, int n) function in this file and submit it.

+======================================================+
|                 WRITE YOUR CODE HERE                 |
| Description:                                         |
| - Reverse nodes between positions m and n            |
| - Return type: void                                  |
|                                                      |
| Tips:                                                |
| - Create a dummy node and set its next to head       |
| - Use 'prev' pointer to go to m-th node              |
| - Use 'current' pointer for m+1 to n nodes           |
| - Loop to reverse m+1 to n nodes                     |
| - Update original list's head                        |
| - Free dummy node memory                             |
+======================================================+

Pseudo Code:

Define a function called reverseBetween with parameters m and n.
This function is a member of the LinkedList class.

Check if the linked list is empty (i.e., head is a nullptr). If it is, return.

Create a new Node pointer dummy with a value of 0, and set its next attribute
to be the head of the linked list.

Initialize a Node pointer prev to be dummy.

Move prev to the (m)-th node in the linked list by iterating from 0 to (m-1)
(not inclusive) and updating prev to be its next node.

Set a Node pointer current to be the next attribute of the prev node, i.e.,
the m-th node in the linked list.

Reverse the segment between positions m and n by iterating from 0 to (n-m)
(not inclusive) and performing the following steps:

Create a Node pointer temp and set it to be the next attribute of the current node.

Update the next attribute of current to be the next attribute of temp.

Update the next attribute of temp to be the next attribute of prev.

Update the next attribute of prev to be temp.

Finally, update the head of the linked list to be the next attribute of the dummy node.

Delete the dummy node to prevent memory leaks.
*/

// Function to reverse the nodes between the mth and nth nodes
void LinkedList::reverseBetween(int m, int n) {
    if (head == nullptr || m == n) {
        return;
    }

    // Create dummy node
    Node* dummy = new Node(0);
    dummy->next = head;

    // Move prev to the node before the sublist
    Node* prev = dummy;
    for (int i = 0; i < m; i++) {
        prev = prev->next;
    }

    // Reverse sublist from m to n
    Node* current = prev->next;
    for (int i = 0; i < n - m; i++) {
        Node* temp = current->next;
        current->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    // Update head if needed
    head = dummy->next;
    delete dummy;
};
