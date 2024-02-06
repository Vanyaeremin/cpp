#include "stackarr.hpp"

StackArr::StackArr(const StackArr& rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    data_ = new Complex[size_];
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
}

StackArr& StackArr::operator=(const StackArr& rhs) noexcept {
    if (rhs.size_ > capacity_) {
        capacity_ = rhs.size_;
        delete[] data_;
        data_ = new Complex(rhs.size_);
    }
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
    size_ = rhs.size_;
    return *this;
}

bool StackArr::IsEmpty() noexcept {
    return (size_ == 0) ? 1 : 0;
}

void StackArr::Pop() noexcept {
    if (size_ > 0) {
        size_ -= 1;
    }
}

void StackArr::Push(const Complex& el) {
    if (size_ + 1 > capacity_) {
        Complex* newData = new Complex[capacity_ * 2];
        std::copy(data_, data_ + size_, newData);
        delete[] data_;
        data_ = newData;
        capacity_ *= 2;
    }
    size_ += 1;
    data_[size_] = el;
}

Complex& StackArr::Top() {
    if (size_ > 0) {
        return data_[size_];
    }
    else {
        throw std::out_of_range("Stack is empty!\n");
    }
}