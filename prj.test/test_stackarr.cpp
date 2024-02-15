#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stackarr/stackarr.hpp>

TEST_CASE("stackarr ctor") {
    StackArr stack;
    CHECK_THROWS(stack.Top());
    CHECK_EQ(1, stack.IsEmpty());
    stack.Push({ 8,9 });
    stack.Push({ 10,0 });
    stack.Push({ 10,4 });
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(Complex(10, 4), stack.Top());
    StackArr stack_new = stack;
    CHECK_EQ(0, stack_new.IsEmpty());
    CHECK_EQ(Complex(10, 4), stack_new.Top());
    stack_new.Pop();
    stack_new.Pop();
    CHECK_EQ(Complex(8, 9), stack_new.Top());
    StackArr stack_copy(stack_new);
    CHECK_EQ(0, stack_copy.IsEmpty());
    CHECK_EQ(Complex(8, 9), stack_copy.Top());
    stack_copy.Pop();
    CHECK_EQ(1, stack_copy.IsEmpty());
    stack_new.Clear();
    CHECK_EQ(1, stack_new.IsEmpty());
    stack_new.Push({ 8,9 });
    stack_new.Push({ 10,0 });
    stack_new.Push({ 10,4 });
    CHECK_EQ(0, stack_new.IsEmpty());
    CHECK_EQ(Complex(10, 4), stack_new.Top());
    stack_new.Pop();
    CHECK_EQ(Complex(10, 0), stack_new.Top());
    stack_new.Clear();
    CHECK_EQ(1, stack_new.IsEmpty());
}