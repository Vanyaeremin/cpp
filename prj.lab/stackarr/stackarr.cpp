#include "stackarr.h"

~Stackarr() {
    delete[] data_;
    data_ = nullptr;
}