#include <iostream>
#include "CircularLinkedList.h"

// Constructor
CircularLinkedList::CircularLinkedList() : head(nullptr), size(0) {}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    if (isEmpty()) return;

    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
}

// Check if list is empty
bool CircularLinkedList::isEmpty() const {
    return head == nullptr;
}

// Get list size
int CircularLinkedList::getSize() const {
    return size;
}

// Insert at the end of the list
void CircularLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        // If list is empty, make the new node the head
        head = newNode;
        head->next = head;  // Point to itself
    } else {
        // Traverse to the last node
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        
        // Add new node and update links
        current->next = newNode;
        newNode->next = head;
    }
    size++;
}

// Insert at the beginning of the list
void CircularLinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        // If list is empty, make the new node the head
        head = newNode;
        head->next = head;  // Point to itself
    } else {
        // Find the last node
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        
        // Update links
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
    size++;
}

// Insert at a specific index
void CircularLinkedList::insertAtIndex(int index, int value) {
    // Handle index correction for circular list
    index = index % (size + 1);

    // If index is 0 or list is empty, insert at beginning
    if (index == 0 || isEmpty()) {
        insertAtBeginning(value);
        return;
    }

    // If index is size, insert at end
    if (index == size) {
        insertAtEnd(value);
        return;
    }

    // Create new node
    Node* newNode = new Node(value);

    // Traverse to the node before insertion point
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Update links
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

// Delete from the end
void CircularLinkedList::deleteFromEnd() {
    if (isEmpty()) {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    // If only one node
    if (head->next == head) {
        
        head = nullptr;
        delete head;
        size = 0;
        return;
    }

    // Find the second last node
    Node* current = head;
    while (current->next->next != head) {
        current = current->next;
    }

    // Delete last node and update links
    Node* temp = current->next;
    current->next = head;
    delete temp;
    size--;
}

// Delete from the beginning
void CircularLinkedList::deleteFromBeginning() {
    if (isEmpty()) {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    // If only one node
    if (head->next == head) {
        head = nullptr;
        delete head;
        
        size = 0;
        return;
    }

    // Find the last node
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    // Update links and delete first node
    Node* temp = head;
    current->next = head->next;
    head = head->next;
    delete temp;
    size--;
}

// Delete from a specific index
void CircularLinkedList::deleteFromIndex(int index) {
    // Handle index correction for circular list
    index = index % size;

    // If list is empty
    if (isEmpty()) {
        std::cout << "List is empty. Cannot delete." << std::endl;
        return;
    }

    // If deleting first node
    if (index == 0) {
        deleteFromBeginning();
        return;
    }

    // Find the node before the one to be deleted
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    // Update links and delete node
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}

// Traverse and print the list
void CircularLinkedList::traverse() {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

// Find the middle node
void CircularLinkedList::findTheMiddle() {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    // Handling the  odd and even node cases
    int midIndex = size / 2;
    Node* current = head;

    // Traverse to the middle node
    for (int i = 0; i < midIndex; i++) {
        current = current->next;
    }

    // If even number of nodes, print the second middle node
    std::cout << "Middle node is as follows: " << current->data << std::endl;
}

// Reverse the circular linked list
void CircularLinkedList::reverse() {
    if (isEmpty() || head->next == head) {
        return; // No need to reverse if empty or single node
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    do {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead
        prev = current;
        current = next;
    } while (current != head);

    // Update head to the last node
    head = prev;

    // Find the last node and point it back to head
    Node* lastNode = head;
    while (lastNode->next != current) {
        lastNode = lastNode->next;
    }
    lastNode->next = head;
}