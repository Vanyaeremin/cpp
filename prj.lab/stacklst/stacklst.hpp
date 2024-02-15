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
    ~StackLst() { 
        delete head_;
        head_ = nullptr;
    }

    [[nodiscard]] StackLst& operator=(const StackLst& rhs);
    void Push(const Complex& c);
    void Pop() noexcept;
    bool IsEmpty() noexcept;
    [[nodiscard]] const Complex& Top();
    void Clear() noexcept;

private:
    struct Node {
        Complex v;
        Node* next = nullptr;
        Node(const Complex& val) : v(val), next(nullptr) {}
    };
    Node* head_ = nullptr;
};

#endif