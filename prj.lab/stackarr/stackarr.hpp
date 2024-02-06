#pragma once
#ifndef STACKARR
#define STACKARR

#include <iostream>
#include "complex/complex.hpp"

class StackArr {
public:
    StackArr() = default;
    StackArr(const StackArr& rhs);

    ~StackArr() { delete[] data_; }
    StackArr& operator=(const StackArr& rhs) noexcept;

    bool IsEmpty() noexcept;
    void Pop() noexcept;
    void Push(const Complex& el);
    Complex& Top();

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    Complex* data_ = nullptr;
};

#endif