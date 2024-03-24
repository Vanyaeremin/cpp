#include "dynarr.hpp"

DynArr::DynArr(const DynArr& d) {
    size_ = d.size_;
    capacity_ = d.capacity_;
    data_ = std::make_unique<float[]>(capacity_);
    std::copy(d.data_.get(), d.data_.get() + d.size_, data_.get());
}

DynArr::DynArr(DynArr&& d) noexcept {
    std::swap(capacity_, d.capacity_);
    std::swap(size_, d.size_);
    std::swap(data_, d.data_);
}

DynArr::DynArr(const std::ptrdiff_t size){
    if (size > 0) {
        size_ = size;
        capacity_ = size;
        data_ = std::make_unique<float[]>(capacity_);
        std::fill(data_.get(), data_.get() + size, 0);
    }
    else if(size<0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else if (size == 0) {
        throw std::invalid_argument("Array of zero size\n");
    }
}

std::ptrdiff_t DynArr::Size() const noexcept{
    return size_;
}

DynArr& DynArr::operator=(const DynArr& d) noexcept {
    if (this != &d) {
        if (d.size_ > capacity_) {
            capacity_ = d.capacity_;
            data_ = std::make_unique<float[]>(capacity_);
        }
        std::copy(d.data_.get(), d.data_.get() + d.size_, data_.get());
        size_ = d.size_;
        return *this;
    }
}

DynArr& DynArr::operator=(DynArr&& d) noexcept {
    if (this != &d) {
        std::swap(capacity_, d.capacity_);
        std::swap(size_, d.size_);
        std::swap(data_, d.data_);
    }
    return *this;
}

float& DynArr::operator[](const std::ptrdiff_t i){
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

const float& DynArr::operator[](const std::ptrdiff_t i) const {
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

void DynArr::Resize(std::ptrdiff_t size) {
    if (size > 0) {
        if (size > size_ && size <= capacity_) {
            std::fill(data_.get() + size_, data_.get() + size, 0);
        }
        else if (size > capacity_){
            std::unique_ptr<float[]> new_data = std::make_unique<float[]>(size);
            std::copy(data_.get(), data_.get() + size_, new_data.get());
            std::fill(new_data.get() + size_, new_data.get() + size, 0);
            std::swap(data_, new_data);
            capacity_ = size;
        }
        size_ = size;
    }
    else if(size<0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else {
        throw std::invalid_argument("Array of zero size\n");
    }
}