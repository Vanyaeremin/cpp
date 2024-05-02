#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "unittest.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include <stackarrt/stackarrt.hpp>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("stackarrt", T, stackarrt) {
    std::vector<T> data;
    FillData(3, data);
    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];

    StackArrT<T> stack;
    CHECK_THROWS(stack.Top());
    CHECK_EQ(1, stack.IsEmpty());
    stack.Push(c1);
    stack.Push(c2);
    stack.Push(c3);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c3, stack.Top());
    StackArrT<T> stack_new = stack;
    CHECK_EQ(0, stack_new.IsEmpty());
    CHECK_EQ(c3, stack_new.Top());
    stack_new.Pop();
    stack_new.Pop();
    CHECK_EQ(c1, stack_new.Top());
    StackArrT<T> stack_copy(stack_new);
    CHECK_EQ(0, stack_copy.IsEmpty());
    CHECK_EQ(c1, stack_copy.Top());
    stack_copy.Pop();
    CHECK_EQ(1, stack_copy.IsEmpty());
    stack_new.Clear();
    CHECK_EQ(1, stack_new.IsEmpty());
    stack_new.Push(c1);
    stack_new.Push(c2);
    stack_new.Push(c3);
    CHECK_EQ(0, stack_new.IsEmpty());
    CHECK_EQ(c3, stack_new.Top());
    stack_new.Pop();
    CHECK_EQ(c2, stack_new.Top());
    stack_new.Clear();
    CHECK_EQ(1, stack_new.IsEmpty());
}

TEST_CASE_TEMPLATE_INVOKE(stackarrt, TYPES);