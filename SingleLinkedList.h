#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>

template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    T front() const;
    T back() const;
    bool empty() const;
    void insert(size_t index, const T& item);
    bool remove(size_t index);
    size_t find(const T& item) const;
    void display() const;  // Utility function for debugging
};

#endif