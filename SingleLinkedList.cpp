#include "SingleLinkedList.h"
#include <iostream>

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleLinkedList<T>::push_front(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::push_back(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

template <typename T>
void SingleLinkedList<T>::pop_front() {
    if (empty()) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (head == nullptr) tail = nullptr;
}

template <typename T>
void SingleLinkedList<T>::pop_back() {
    if (empty()) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    num_items--;
}

template <typename T>
T SingleLinkedList<T>::front() const {
    return head ? head->data : T();
}

template <typename T>
T SingleLinkedList<T>::back() const {
    return tail ? tail->data : T();
}

template <typename T>
bool SingleLinkedList<T>::empty() const {
    return num_items == 0;
}

template <typename T>
void SingleLinkedList<T>::insert(size_t index, const T& item) {
    if (index == 0) {
        push_front(item);
    }
    else if (index >= num_items) {
        push_back(item);
    }
    else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        Node* new_node = new Node(item);
        new_node->next = temp->next;
        temp->next = new_node;
        num_items++;
    }
}

template <typename T>
bool SingleLinkedList<T>::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }

    Node* temp = head;
    for (size_t i = 0; i < index - 1; ++i) {
        temp = temp->next;
    }

    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    if (to_delete == tail) tail = temp;
    delete to_delete;
    num_items--;
    return true;
}

template <typename T>
size_t SingleLinkedList<T>::find(const T& item) const {
    Node* temp = head;
    size_t index = 0;
    while (temp) {
        if (temp->data == item) return index;
        temp = temp->next;
        index++;
    }
    return num_items;
}

template <typename T>
void SingleLinkedList<T>::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr\n";
}

// Explicit template instantiation for int
template class SingleLinkedList<int>;