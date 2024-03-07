#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include "complex/complex.hpp"

class QueueLst {
public:
    [[nodiscard]] QueueLst() = default;
    [[nodiscard]] QueueLst(const QueueLst& rhs);
    [[nodiscard]] QueueLst(QueueLst&& rhs) noexcept;
    ~QueueLst();
    [[nodiscard]] QueueLst& operator=(const QueueLst& rhs);
    [[nodiscard]] QueueLst& operator=(QueueLst&& rhs) noexcept;

    void Push(const Complex& c);
    void Pop() noexcept;
    bool IsEmpty() const noexcept;
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
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