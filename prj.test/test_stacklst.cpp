#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("stacklst ctor") {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);
    StackLst stack;
    StackLst stack2;
    stack2.Push(c3);
    CHECK_EQ(c3, stack2.Top());

    stack.Pop();
    CHECK_THROWS(stack.Top());
    CHECK_EQ(1, stack.IsEmpty());
    stack.Push(c1);
    CHECK_EQ(c1, stack.Top());
    CHECK_EQ(0, stack.IsEmpty());

    stack2 = stack;
    CHECK_EQ(c1, stack2.Top());

    stack.Push(c2);
    CHECK_EQ(c2, stack.Top());

    stack2 = stack;
    CHECK_EQ(c2, stack2.Top());

    stack.Push(c3);
    CHECK_EQ(c3, stack.Top());
    stack.Push(c4);
    CHECK_EQ(c4, stack.Top());
    CHECK_EQ(0, stack.IsEmpty());
    StackLst copy_stack(stack);
    StackLst stack3 = stack;
    stack2 = stack;

    stack.Pop();
    CHECK_EQ(c3, stack.Top());
    stack.Pop();
    CHECK_EQ(c2, stack.Top());
    stack.Pop();
    CHECK_EQ(c1, stack.Top());
    CHECK_EQ(0, stack.IsEmpty());
    stack.Pop();
    CHECK_EQ(1, stack.IsEmpty());
    stack.Pop();
    CHECK_THROWS(stack.Top());

    CHECK_EQ(c4, copy_stack.Top());
    copy_stack.Push(c1);
    CHECK_EQ(c1, copy_stack.Top());
    CHECK_EQ(0, copy_stack.IsEmpty());
    copy_stack.Pop();
    copy_stack.Pop();
    CHECK_EQ(c3, copy_stack.Top());
    copy_stack.Pop();
    CHECK_EQ(c2, copy_stack.Top());
    copy_stack.Pop();
    CHECK_EQ(c1, copy_stack.Top());
    CHECK_EQ(0, copy_stack.IsEmpty());
    copy_stack.Pop();
    CHECK_EQ(1, copy_stack.IsEmpty());
    copy_stack.Pop();
    CHECK_THROWS(copy_stack.Top());

    CHECK_EQ(c4, stack2.Top());
    stack2.Clear();
    CHECK_EQ(1, stack2.IsEmpty());
    CHECK_THROWS(stack2.Top());
    stack2.Push(c1);
    CHECK_EQ(c1, stack2.Top());
    CHECK_EQ(c4, stack3.Top());
    stack3 = stack2;
    CHECK_EQ(c1, stack3.Top());
}