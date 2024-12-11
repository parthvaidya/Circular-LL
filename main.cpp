#include <iostream>
#include "CircularLinkedList.h"

int main() {
    CircularLinkedList cll;

    // Demonstrate insertion
    std::cout << "Inserting elements:" << std::endl;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.insertAtIndex(2, 15);

    std::cout << "List after insertions: ";
    cll.traverse();

    // Find middle
    std::cout << "\nFinding middle: ";
    cll.findTheMiddle();

    // Demonstrate deletion
    std::cout << "\nDeleting from end and beginning:" << std::endl;
    cll.deleteFromEnd();
    cll.deleteFromBeginning();

    std::cout << "List after deletions: ";
    cll.traverse();

    // Demonstrate index operations
    std::cout << "\nInserting at index 21 (which wraps around):" << std::endl;
    cll.insertAtIndex(21, 35);
    cll.traverse();

    // Demonstrate reverse
    std::cout << "\nReversing the list:" << std::endl;
    cll.reverse();
    cll.traverse();

    return 0;
}