#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include "complex/complex.hpp"

class StackLst {
public:
    [[nodiscard]] StackLst() = default;
    [[nodiscard]] StackLst(const StackLst& rhs);
    [[nodiscard]] StackLst(StackLst&& rhs) noexcept;
    ~StackLst();

    [[nodiscard]] StackLst& operator=(const StackLst& rhs) noexcept;
    [[nodiscard]] StackLst& operator=(StackLst&& rhs) noexcept;
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
};

#endif