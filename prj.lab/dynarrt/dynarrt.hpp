#pragma once
#ifndef DYNARRT_HPP
#define DYNARRT_HPP

#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>

template <class T>
class DynArrT {
public:
    DynArrT() = default;
    DynArrT(const DynArrT& d);
    DynArrT(DynArrT&& d) noexcept;
    explicit DynArrT(std::ptrdiff_t size);
    ~DynArrT() = default;

    DynArrT& operator=(const DynArrT& d) noexcept;
    DynArrT& operator=(DynArrT&& d) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);

    [[nodiscard]] T& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const T& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    std::unique_ptr<T[]> data_ = std::make_unique<T[]>(capacity_);
};

template <class T>
DynArrT<T>::DynArrT(const DynArrT<T>& d) {
    size_ = d.size_;
    capacity_ = d.capacity_;
    data_ = std::make_unique<T[]>(size_);
    std::copy(d.data_.get(), d.data_.get() + d.size_, data_.get());
}

template <class T>
DynArrT<T>::DynArrT(DynArrT<T>&& d) noexcept {
    std::swap(capacity_, d.capacity_);
    std::swap(size_, d.size_);
    std::swap(data_, d.data_);
}

template <class T>
DynArrT<T>::DynArrT(const std::ptrdiff_t size) {
    if (size > 0) {
        size_ = size;
        capacity_ = size;
        data_ = std::make_unique<T[]>(size);
        std::fill(data_.get(), data_.get() + size, 0);
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else if (size == 0) {
        throw std::invalid_argument("Array of zero size\n");
    }
}

template <class T>
std::ptrdiff_t DynArrT<T>::Size() const noexcept {
    return size_;
}

template <class T>
DynArrT<T>& DynArrT<T>::operator=(const DynArrT<T>& d) noexcept {
    if (this != &d) {
        if (d.size_ > capacity_) {
            capacity_ = d.capacity_;
            data_ = std::make_unique<T[]>(d.size_);
        }
        std::copy(d.data_.get(), d.data_.get() + d.size_, data_.get());
        size_ = d.size_;
        return *this;
    }
}

template <class T>
DynArrT<T>& DynArrT<T>::operator=(DynArrT<T>&& d) noexcept {
    if (this != &d) {
        std::swap(capacity_, d.capacity_);
        std::swap(size_, d.size_);
        std::swap(data_, d.data_);
    }
    return *this;
}

template <class T>
T& DynArrT<T>::operator[](const std::ptrdiff_t i) {
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}

template <class T>
const T& DynArrT<T>::operator[](const std::ptrdiff_t i) const {
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}

template <class T>
void DynArrT<T>::Resize(const std::ptrdiff_t size) {
    if (size > 0) {
        if (size > size_ && size <= capacity_) {
            std::fill(data_.get() + size_, data_.get() + size, 0);
        }
        else if (size > capacity_) {
            std::unique_ptr<T[]> new_data = std::make_unique<T[]>(size);
            std::copy(data_.get(), data_.get() + size_, new_data.get());
            std::fill(new_data.get() + size_, new_data.get() + size, 0);
            std::swap(data_, new_data);
            capacity_ = size;
        }
        size_ = size;
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else {
        throw std::invalid_argument("Array of zero size\n");
    }
}

#endif