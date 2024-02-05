#pragma once
#ifndef STACKARR
#define STACKARR

#include <iostream>

class Stackarr {
public:
    Stackarr() = default;

    ~StackArr();
private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    float* data_ = nullptr;
};

#endif