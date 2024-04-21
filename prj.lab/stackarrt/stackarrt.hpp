#pragma once
#ifndef STACKARRT_HPP
#define STACKARRT_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <stdexcept>

template <class T>
class StackArrT final {
public:
    StackArrT() = default;
    StackArrT(const StackArrT& rhs);
    StackArrT(StackArrT&& rhs) noexcept;

    ~StackArrT() = default;
    StackArrT& operator=(const StackArrT& rhs) noexcept;
    StackArrT& operator=(StackArrT&& rhs) noexcept;

    bool IsEmpty() const noexcept;
    void Pop() noexcept;
    void Push(const T& el);
    [[nodiscard]] T& Top()&;
    [[nodiscard]] const T& Top() const&;
    void Clear() noexcept;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t i_top_ = -1;
    std::unique_ptr<T[]> data_ = std::make_unique<T[]>(size_);
};

template <class T>
StackArrT<T>::StackArrT(const StackArrT<T>& rhs) {
    size_ = rhs.size_;
    i_top_ = rhs.i_top_;
    data_ = std::make_unique<T[]>(size_);
    std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
}

template <class T>
StackArrT<T>::StackArrT(StackArrT<T>&& rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
    std::swap(i_top_, rhs.i_top_);
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) noexcept {
    if (this != &rhs) {
        if (rhs.size_ > size_) {
            data_ = std::make_unique<T[]>(rhs.size_);
        }
        std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
        i_top_ = rhs.i_top_;
        size_ = rhs.size_;
        return *this;
    }
}

template <class T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT<T>&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(data_, rhs.data_);
        std::swap(size_, rhs.size_);
        std::swap(i_top_, rhs.i_top_);
    }
    return *this;
}

template <class T>
bool StackArrT<T>::IsEmpty() const noexcept {
    return (i_top_ == -1 ? 1 : 0);
}

template <class T>
void StackArrT<T>::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

template <class T>
void StackArrT<T>::Push(const T& el) {
    if (i_top_ == -1) {
        size_ = 8;
        data_ = std::make_unique<T[]>(size_);
    }
    else if (size_ == i_top_ + 1) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(size_ * 2);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        std::swap(data_, new_data);
        size_ *= 2;
    }
    i_top_ += 1;
    data_[i_top_] = el;
}

template <class T>
T& StackArrT<T>::Top()& {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

template <class T>
const T& StackArrT<T>::Top() const& {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

template <class T>
void StackArrT<T>::Clear() noexcept {
    i_top_ = -1;
}

#endif