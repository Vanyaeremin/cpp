#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include "complex/complex.hpp"

class QueueLst final {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& rhs);
    QueueLst(QueueLst&& rhs) noexcept;
    ~QueueLst();
    QueueLst& operator=(const QueueLst& rhs);
    QueueLst& operator=(QueueLst&& rhs) noexcept;

    void Push(const Complex& c);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] Complex& Top() &;
    [[nodiscard]] const Complex& Top() const &;
    void Clear() noexcept;

private:
    struct Node {
        Complex v;
        Node* next = nullptr;
        Node(const Complex& val) : v(val) {}
        ~Node() = default;
    };
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};



#endif