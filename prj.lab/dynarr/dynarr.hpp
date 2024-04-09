#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>

class DynArr {
public:
    DynArr() = default;
    DynArr(const DynArr& d);
    DynArr(DynArr&& d) noexcept;
    explicit DynArr(std::ptrdiff_t size);
    ~DynArr() = default;

    DynArr& operator=(const DynArr& d) noexcept;
    DynArr& operator=(DynArr&& d) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] float& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::unique_ptr<float[]> data_ = std::make_unique<float[]>(capacity_);
};

#endif