#ifndef SLL_HPP
#define SLL_HPP

#include "SLLNode.hpp"

// SLL class represents a singly linked list that stores elements of any type (template-based).
template <class T>
class SLL {
private:
    SLLNode<T> *head; // Pointer to the first node in the list
    SLLNode<T> *tail; // Pointer to the last node in the list

public:
    // Constructor: Initializes an empty list
    SLL() : head(nullptr), tail(nullptr) {}

    // Returns the pointer to the head node
    SLLNode<T> *getHead() const { return head; }

    // Returns the pointer to the tail node
    SLLNode<T> *getTail() const { return tail; }

    // Checks if the list is empty
    // Returns 1 if empty, 0 otherwise
    int isEmpty() const { return head == nullptr; }

    // Adds a new node with the given value at the beginning of the list
    void addtoHead(T el) {
        SLLNode<T> *newNode = new SLLNode<T>(el, head); // Create a new node pointing to current head
        head = newNode; // Update head to the new node
        if (tail == nullptr) {
            tail = head; // If list was empty, set tail to the new head
        }
    }

    // Adds a new node with the given value at the end of the list
    void addtoTail(T el) {
        SLLNode<T> *newNode = new SLLNode<T>(el, nullptr); // Create a new node with no next node
        if (tail != nullptr) {
            tail->setNext(newNode); // Link current tail to new node
        } else {
            head = newNode; // If list was empty, set head to new node
        }
        tail = newNode; // Update tail to the new node
    }

    // Deletes the first occurrence of a node with the given value
    void deleteNode(T el) {
        SLLNode<T> *current = head;
        SLLNode<T> *previous = nullptr;

        // Traverse the list to find the node to delete
        while (current != nullptr && current->getData() != el) {
            previous = current;
            current = current->getNext();
        }

        // If node was found
        if (current != nullptr) {
            if (current == head) {
                head = head->getNext(); // Update head if deleting first node
                if (head == nullptr) {
                    tail = nullptr; // If list becomes empty, set tail to nullptr
                }
            } else {
                previous->setNext(current->getNext()); // Link previous node to next of current
                if (current == tail) {
                    tail = previous; // Update tail if deleting last node
                }
            }
            delete current; // Free memory of the deleted node
        }
    }

    // Inserts a node with the given value while keeping the list sorted
    void addNode(T el) {
        SLLNode<T> *newNode = new SLLNode<T>(el, nullptr);

        // If the list is empty or the new value is less than the head value
        if (isEmpty() || el < head->getData()) {
            addtoHead(el); // Use addtoHead to handle head update
            return;
        }

        SLLNode<T> *current = head;
        // Traverse to find the insertion point for the new node
        while (current->getNext() != nullptr && current->getNext()->getData() < el) {
            current = current->getNext();
        }

        // Insert newNode after current node
        newNode->setNext(current->getNext());
        current->setNext(newNode);

        // If new node is added at the end, update the tail
        if (newNode->getNext() == nullptr) {
            tail = newNode;
        }
    }
};

#endif