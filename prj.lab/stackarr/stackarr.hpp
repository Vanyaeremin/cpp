#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include "complex/complex.hpp"

class StackArr {
public:
    [[nodiscard]] StackArr() = default;
    [[nodiscard]] StackArr(const StackArr& rhs);

    ~StackArr() { 
        delete[] data_;
        data_ = nullptr;
    }
    [[nodiscard]] StackArr& operator=(const StackArr& rhs) noexcept;

    bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const Complex& el);
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t i_top_ = -1;
    Complex* data_ = nullptr;
};

#endif