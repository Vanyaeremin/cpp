#pragma once
#pragma once
#ifndef QUEUELSTPRT
#define QUEUELSTPRT

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stdexcept>

template <class T>
class QueueLstPrT {
public:
    QueueLstPrT() = default;
    ~QueueLstPrT();
    QueueLstPrT(const QueueLstPrT& rhs);
    QueueLstPrT(QueueLstPrT&& rhs) noexcept;
    QueueLstPrT& operator=(const QueueLstPrT& rhs);
    QueueLstPrT& operator=(QueueLstPrT&& rhs) noexcept;

    void Push(const T& f);
    void Pop() noexcept;
    void Clear() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] T& Top()&;
    [[nodiscard]] const T& Top() const&;

private:
    struct Node {
        T f;
        Node* next = nullptr;
        Node(const float& item) : f(item) {}
        Node() = default;
        ~Node() = default;
    };
    Node* head_ = nullptr;
};

template <class T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T>& rhs) {
    if (rhs.head_ != nullptr) {
        if (this != &rhs) {
            Node* newNode = new Node(rhs.head_->f);
            Node* cur = newNode;
            head_ = newNode;
            Node* current = rhs.head_->next;
            while (current != nullptr) {
                Node* newNode = new Node(current->f);
                current = current->next;
                cur->next = newNode;
                cur = newNode;
            }
        }
    }
    else {
        head_ = nullptr;
    }
}

template <class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept {
    std::swap(head_, rhs.head_);
}

template <class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT<T>& rhs) {
    if (rhs.head_ == nullptr) {
        while (head_ != nullptr) {
            Pop();
        }
    }
    else {
        if (head_ == nullptr) {
            Node* new_node = new Node;
            head_ = new_node;
        }
        Node* cur = head_;
        Node* current = rhs.head_;
        Node* future_delete = nullptr;
        Node* future_delete_2 = nullptr;
        while (current != nullptr) {
            cur->f = current->f;
            if (cur->next == nullptr && current->next != nullptr) {
                Node* newNode = new Node;
                cur->next = newNode;
            }
            current = current->next;
            if (current == nullptr) {
                future_delete = cur->next;
                cur->next = nullptr;

            }
            cur = cur->next;
        }
        while (future_delete != nullptr) {
            future_delete_2 = future_delete;
            future_delete = future_delete->next;
            delete future_delete_2;
        }
    }
    return *this;
}

template <class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(QueueLstPrT<T>&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(head_, rhs.head_);
    }
    return *this;
}

template <class T>
void QueueLstPrT<T>::Push(const T& f) {
    Node* new_node = new Node(f);
    Node* cur = head_;
    Node* prev = nullptr;

    if (cur == nullptr) {
        head_ = new_node;
    }
    else {
        while (cur != nullptr) {
            if (f > cur->f) {
                prev = cur;
                if (cur->next == nullptr) {
                    cur->next = new_node;
                    break;
                }
                cur = cur->next;
            }
            else {
                if (cur == head_) {
                    head_ = new_node;
                }
                else {
                    prev->next = new_node;
                }
                new_node->next = cur;
                break;
            }
        }
    }
}

template <class T>
void QueueLstPrT<T>::Pop() noexcept {
    if (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = future_delete->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

template <class T>
QueueLstPrT<T>::~QueueLstPrT() {
    Node* future_delete = head_;
    while (future_delete != nullptr) {
        future_delete = head_->next;
        delete head_;
        head_ = future_delete;
    }
}

template <class T>
void QueueLstPrT<T>::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

template <class T>
bool QueueLstPrT<T>::IsEmpty() const noexcept {
    return head_ == nullptr;
}

template <class T>
T& QueueLstPrT<T>::Top()& {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}

template <class T>
const T& QueueLstPrT<T>::Top() const& {
    if (head_ == nullptr) {
        throw std::logic_error("QueueLstPr is empty!\n");
    }
    else {
        return head_->f;
    }
}

#endif