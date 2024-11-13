#ifndef ORDEREDDOUBLYLINKEDLIST_H
#define ORDEREDDOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class OrderedDoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    OrderedDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertOrdered(int newData) {
        DoublyNode* newNode = new DoublyNode(newData);
        if (!head) {
            head = tail = newNode;
            return;
        }

        if (newData < head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        DoublyNode* current = head;
        while (current->next && current->next->data < newData) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) {
            newNode->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void printForward() {
        DoublyNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() {
        DoublyNode* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

#endif
