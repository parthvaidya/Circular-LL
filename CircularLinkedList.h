#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

class CircularLinkedList {
private:
    // Node structure definition
    struct Node {
        int data;
        Node* next;
        
        // Constructor for Node
        Node(int val) : data(val), next(nullptr) {}
    };

    // Head node of the Circular Linked List
    Node* head;
    int size;

public:
    // Constructor
    CircularLinkedList();

    // Destructor to free memory
    ~CircularLinkedList();

    // Insertion operations
    void insertAtEnd(int value);
    void insertAtBeginning(int value);
    void insertAtIndex(int index, int value);

    // Deletion operations 
    void deleteFromEnd();
    void deleteFromBeginning();
    void deleteFromIndex(int index);

    // Utility operations
    void traverse();
    void findTheMiddle();
    void reverse();

    // Helper method to get list size
    int getSize() const;

    // Check if list is empty
    bool isEmpty() const;
};

#endif