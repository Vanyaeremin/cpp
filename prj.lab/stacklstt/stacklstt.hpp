#pragma once
#ifndef STACKLSTT
#define STACKLSTT

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <cstdint>
#include <string>

template<class T>
class StackLstT final {
public: 
    StackLstT() = default;
    StackLstT(const StackLstT& rhs);
    StackLstT(StackLstT&& rhs) noexcept;
    ~StackLstT();
    StackLstT& operator=(const StackLstT& rhs);
    StackLstT& operator=(StackLstT&& rhs) noexcept;

    void Push(const T& val);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] T& Top() &;
    [[nodiscard]] const T& Top() const &;
    void Clear() noexcept;

private:
    struct Node {
        T v;
        Node* next = nullptr;
        Node(const T& val) : v(val) {}
        Node() = default;
        ~Node() = default;
    };
    Node* head_ = nullptr;
};

template<class T>
StackLstT<T>::StackLstT(const StackLstT<T>& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->v);
        head_ = newNode;
        Node* vs = rhs.head_->next;
        Node* pr = newNode;
        while (vs != nullptr) {
            Node* newNode = new Node(vs->v);
            pr->next = newNode;
            vs = vs->next;
            pr = newNode;
        }
    }
    else {
        head_ = nullptr;
    }
}

template<class T>
StackLstT<T>::StackLstT(StackLstT<T>&& rhs) noexcept {
    std::swap(head_, rhs.head_);
}

template<class T>
StackLstT<T>::~StackLstT() {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& rhs) {
    if (rhs.head_ == nullptr) {
        head_ = nullptr;
    }
    else {
        if (this != &rhs) {
            Node* rhs_cur = rhs.head_;
            Node* cur = head_;
            Node* tail = cur;
            if (cur == nullptr) {
                Node* newNode = new Node;
                cur = newNode;
                head_ = newNode;
                tail = cur;
            }
            while (rhs_cur != nullptr) {
                if (cur == nullptr) {
                    Node* newNode = new Node;
                    cur = newNode;
                    tail->next = newNode;
                    tail = newNode;
                }

                cur->v = rhs_cur->v;
                rhs_cur = rhs_cur->next;

                if (rhs_cur == nullptr) {
                    tail = cur;
                    tail->next = nullptr;
                }
                cur = cur->next;
            }
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }
    return *this;
}

template<class T>
void StackLstT<T>::Push(const T& c) {
    Node* newNode = new Node(c);
    newNode->next = head_;
    head_ = newNode;
    newNode = nullptr;
}

template<class T>
void StackLstT<T>::Pop() noexcept {
    if (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
}

template<class T>
bool StackLstT<T>::IsEmpty() const noexcept {
    return (head_ == nullptr) ? 1 : 0;
}

template<class T>
T& StackLstT<T>::Top() & {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

template<class T>
const T& StackLstT<T>::Top() const & {
    if (head_ == nullptr) {
        throw std::logic_error("Stack is empty!\n");
    }
    else {
        return head_->v;
    }
}

template<class T>
void StackLstT<T>::Clear() noexcept {
    while (head_ != nullptr) {
        Node* delete_future = head_;
        head_ = head_->next;
        delete delete_future;
        delete_future = nullptr;
    }
}

#endif