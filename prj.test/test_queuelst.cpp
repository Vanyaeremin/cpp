#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelst/queuelst.hpp>

TEST_CASE("queuelst ctor") {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);
    QueueLst queue;
    QueueLst queue2;
    queue2.Push(c3);
    CHECK_EQ(c3, queue2.Top());

    queue.Pop();
    CHECK_THROWS(queue.Top());
    CHECK_EQ(1, queue.IsEmpty());
    queue.Push(c1);
    CHECK_EQ(c1, queue.Top());
    CHECK_EQ(0, queue.IsEmpty());

    queue2 = queue;
    CHECK_EQ(c1, queue2.Top());

    queue.Push(c2);
    CHECK_EQ(c1, queue.Top());

    queue2 = queue;
    CHECK_EQ(c1, queue2.Top());
    queue2.Pop();
    CHECK_EQ(c2, queue2.Top());

    queue.Push(c3);
    CHECK_EQ(c1, queue.Top());
    queue.Push(c4);
    CHECK_EQ(c1, queue.Top());
    CHECK_EQ(0, queue.IsEmpty());
    QueueLst queue_copy(queue);
    QueueLst queue3 = queue;
    queue2 = queue;

    queue.Pop();
    CHECK_EQ(c2, queue.Top());
    queue.Pop();
    CHECK_EQ(c3, queue.Top());
    queue.Pop();
    CHECK_EQ(c4, queue.Top());
    CHECK_EQ(0, queue.IsEmpty());
    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());
    queue.Pop();
    CHECK_THROWS(queue.Top());

    CHECK_EQ(c1, queue_copy.Top());
    queue_copy.Push(c1);
    CHECK_EQ(c1, queue_copy.Top());
    CHECK_EQ(0, queue_copy.IsEmpty());
    queue_copy.Pop();
    queue_copy.Pop();
    CHECK_EQ(c3, queue_copy.Top());
    queue_copy.Pop();
    CHECK_EQ(c4, queue_copy.Top());
    queue_copy.Pop();
    CHECK_EQ(c1, queue_copy.Top());
    CHECK_EQ(0, queue_copy.IsEmpty());
    queue_copy.Pop();
    CHECK_EQ(1, queue_copy.IsEmpty());
    queue_copy.Pop();
    CHECK_THROWS(queue_copy.Top());

    CHECK_EQ(c1, queue2.Top());
    queue2.Clear();
    CHECK_EQ(1, queue2.IsEmpty());
    CHECK_THROWS(queue2.Top());
    queue2.Push(c1);
    CHECK_EQ(c1, queue2.Top());
    CHECK_EQ(c1, queue3.Top());
    queue3 = queue2;
    CHECK_EQ(c1, queue3.Top());
    queue3.Push(c2);
    queue3.Push(c3);
    CHECK_EQ(c1, queue3.Top());
    queue2 = queue3;
    CHECK_EQ(c1, queue2.Top());
    queue2.Pop();
    CHECK_EQ(c2, queue2.Top());
    queue2.Pop();
    CHECK_EQ(c3, queue2.Top());
}