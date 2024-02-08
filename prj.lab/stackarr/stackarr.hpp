#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <algorithm>
#include "complex/complex.hpp"

class StackArr {
public:
    [[nodiscard]] StackArr();
    [[nodiscard]] StackArr(const StackArr& rhs);

    ~StackArr() { delete[] data_; }
    [[nodiscard]] StackArr& operator=(const StackArr& rhs) noexcept;

    [[nodiscard]] bool IsEmpty() noexcept;
    void Pop() noexcept;
    void Push(const Complex& el);
    [[nodiscard]] Complex& Top();

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    Complex* data_ = nullptr;
};

#endif