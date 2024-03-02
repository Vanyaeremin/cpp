#include "queuearr.hpp"

QueueArr::QueueArr(const QueueArr& rhs) {
    if (rhs.head_ != -1) {
        data_ = new Complex[rhs.capacity_];
        capacity_ = rhs.capacity_;
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.tail_, data_);
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.capacity_, data_);
            std::copy(rhs.data_, rhs.data_ + rhs.tail_, data_ + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
    if (this != &rhs) {
        if (capacity_ < rhs.capacity_) {
            data_ = new Complex[rhs.capacity_];
            capacity_ = rhs.capacity_;
        }
        head_ = 0;
        if (rhs.tail_ > rhs.head_) {
            std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.tail_, data_);
            tail_ = rhs.tail_ - rhs.head_;
        }
        else {
            std::copy(rhs.data_ + rhs.head_, rhs.data_ + rhs.capacity_, data_);
            std::copy(rhs.data_, rhs.data_ + rhs.tail_, data_ + (rhs.capacity_ - rhs.head_));
            tail_ = rhs.capacity_ - rhs.head_ + rhs.tail_;
        }
    }
    return *this;
}

void QueueArr::Push(const Complex& c) {
    if (head_ == -1) {
        capacity_ = 8;
        data_ = new Complex[capacity_];
        head_ = 0;
        tail_ = 0;
    }
    data_[tail_] = c;
    if (head_ == (tail_ + 1) % capacity_) {
        Complex* newData = new Complex[capacity_ * 2];
        std::copy(data_ + head_, data_ + capacity_, newData);
        if (tail_ < head_) {
            std::copy(data_, data_ + tail_, newData + (capacity_ - head_));
        }
        std::swap(data_, newData);
        capacity_ *= 2;
        head_ = 0;
        tail_ = capacity_ / 2;
    }
    else {
        tail_ = (tail_ + 1) % capacity_;
    }
}

void QueueArr::Pop() noexcept {
    if (head_ != -1) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % capacity_;
        }
        if (head_ == tail_) {
            head_ = -1;
        }
        
    }
}

Complex& QueueArr::Top() {
    if (head_ < 0) {
        throw std::logic_error("QueueArr Is Empty!");
    }
    else {
        return data_[head_];
    }
}

const Complex& QueueArr::Top() const {
    if (head_ < 0) {
        throw std::logic_error("QueueArr Is Empty!");
    }
    else {
        return data_[head_];
    }
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ < 0;
}

std::ptrdiff_t QueueArr::Count() const {
    return (head_ == -1) ? 0 : (tail_ + capacity_ - head_) % capacity_;
}

void QueueArr::Clear() noexcept {
    head_ = -1;
}