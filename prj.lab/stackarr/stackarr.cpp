#include "stackarr.hpp"

StackArr::StackArr(const StackArr& rhs) {
    size_ = rhs.size_;
    i_top_ = rhs.i_top_;
    data_ = new Complex[size_];
    std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
}

StackArr::StackArr(StackArr&& rhs) noexcept {
    size_ = rhs.size_;
    i_top_ = rhs.i_top_;
    data_ = rhs.data_;
    rhs.data_ = nullptr;
}

StackArr& StackArr::operator=(const StackArr& rhs) noexcept {
    if (this != &rhs) {
        if (rhs.size_ > size_) {
            delete[] data_;
            data_ = new Complex[rhs.size_];
        }
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
        i_top_ = rhs.i_top_;
        size_ = rhs.size_;
        return *this;
    }
}

StackArr& StackArr::operator=(StackArr&& d) noexcept {
    if (this != &d) {
        std::swap(data_, d.data_);
    }
    return *this;
}

bool StackArr::IsEmpty() const noexcept {
    return (i_top_ == -1 ? 1 : 0);
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

void StackArr::Push(const Complex& el) {
    if (nullptr == data_) {
        size_ = 8;
        data_ = new Complex[size_];
    }
    else if(size_ == i_top_ + 1) {
        Complex* new_data = new Complex[size_ * 2];
        std::copy(data_, data_ + size_, new_data);
        std::swap(data_, new_data);
        delete[] new_data;
        size_ *= 2;
    }
    i_top_ += 1;
    data_[i_top_] = el;
}

Complex& StackArr::Top() {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

const Complex& StackArr::Top() const {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}