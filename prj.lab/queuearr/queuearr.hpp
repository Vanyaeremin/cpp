#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <cstddef>
#include "complex/complex.hpp"

class QueueArr {
public:
    [[nodiscard]] QueueArr() = default;
    [[nodiscard]] QueueArr(const QueueArr& rhs);
    ~QueueArr() = default;
    [[nodiscard]] QueueArr& operator=(const QueueArr& rhs);
    [[nodiscard]] QueueArr& operator=(QueueArr&&) noexcept;
    [[nodiscard]] QueueArr(QueueArr&&) noexcept;

    void Push(const Complex& c);
    void Pop() noexcept;
    void Clear() noexcept;
    [[nodiscard]] Complex& Top();
    [[nodiscard]] const Complex& Top() const;
    bool IsEmpty() const noexcept;
    std::ptrdiff_t Count() const;

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t head_ = -1;
    std::ptrdiff_t tail_ = -1;
    std::unique_ptr<Complex[]> data_ = std::make_unique<Complex[]>(capacity_);
};

#endif