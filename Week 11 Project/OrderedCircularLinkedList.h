#ifndef ORDEREDCIRCULARLINKEDLIST_H
#define ORDEREDCIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class OrderedCircularLinkedList {
private:
    Node* head;

public:
    OrderedCircularLinkedList() : head(nullptr) {}

    void insertOrdered(int newData) {
        Node* newNode = new Node(newData);
        if (!head) {
            head = newNode;
            head->next = head; // circular link
            return;
        }
        
        if (newData < head->data) {
            Node* last = head;
            while (last->next != head)
                last = last->next;
            newNode->next = head;
            head = newNode;
            last->next = head;
            return;
        }

        Node* current = head;
        while (current->next != head && current->next->data < newData) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void printList() {
        if (!head) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

#endif
