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
        Node(const T& item) : f(item) {}
        ~Node() = default;
    };
    Node* head_ = nullptr;
};

template <class T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T>& rhs) {
    if (rhs.head_ != nullptr) {
        Node* newNode = new Node(rhs.head_->f);
        head_ = newNode;
        Node* next = rhs.head_->next;
        Node* cur = newNode;
        while (next != nullptr) {
            Node* newNode = new Node(next->f);
            cur->next = newNode;
            cur = newNode;
            next = next->next;
        }
    }
}

template <class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T>&& rhs) noexcept {
    std::swap(head_, rhs.head_);
}

template <class T>
QueueLstPrT<T>& QueueLstPrT<T>::operator=(const QueueLstPrT<T>& rhs) {
    if (this != &rhs) {
        Node* cur = head_;
        Node* rh_cur = rhs.head_;
        Node* pr;
        while (rh_cur != nullptr) {
            if (cur == nullptr) {
                Node* newNode = new Node(rh_cur->f);
                cur = newNode;
                if (head_ != nullptr) {
                    pr->next = newNode;
                }
                else {
                    head_ = newNode;
                }
            }
            cur->f = rh_cur->f;
            pr = cur;
            cur = cur->next;
            rh_cur = rh_cur->next;
        }
        while (cur != nullptr) {
            Node* future_delete = cur;
            cur = cur->next;
            delete future_delete;
            future_delete = nullptr;
        }
        pr->next = nullptr;
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
    Node* newNode = new Node(f);
    if (head_ == nullptr) {
        head_ = newNode;
    }
    else {
        if (newNode->f <= head_->f) {
            newNode->next = head_;
            head_ = newNode;
        }
        else {
            bool flag = 0;
            Node* pred = head_;
            Node* future = head_->next;
            while (future != nullptr) {
                if ((newNode->f >= pred->f) && (newNode->f <= future->f)) {
                    pred->next = newNode;
                    newNode->next = future;
                    flag = 1;
                    break;
                }
                pred = pred->next;
                future = future->next;
            }
            if (future == nullptr && flag == 0) {
                pred->next = newNode;
                flag = 1;
            }
        }
    }
}

template <class T>
void QueueLstPrT<T>::Pop() noexcept {
    if (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

template <class T>
QueueLstPrT<T>::~QueueLstPrT() {
    while (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
    }
}

template <class T>
void QueueLstPrT<T>::Clear() noexcept {
    while (head_ != nullptr) {
        Node* future_delete = head_;
        head_ = head_->next;
        delete future_delete;
        future_delete = nullptr;
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