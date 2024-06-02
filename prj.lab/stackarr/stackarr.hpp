#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include "complex/complex.hpp"

class StackArr final {
public:
    StackArr() = default;
    StackArr(const StackArr& rhs);
    StackArr(StackArr&& rhs) noexcept;

    ~StackArr() = default;
    StackArr& operator=(const StackArr& rhs) noexcept;
    StackArr& operator=(StackArr&& rhs) noexcept;

    bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const Complex& el);
    Complex& Top() &;
    const Complex& Top() const &;
    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t i_top_ = -1;
    std::unique_ptr<Complex[]> data_ = std::make_unique<Complex[]>(size_);
};

#endif