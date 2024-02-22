#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelst/queuelst.hpp>

TEST_CASE("queuelst ctor") {
    Complex c1(2, 0);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);

    QueueLst queue;
    QueueLst queue4;

    queue4.Push(c4);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c4, queue4.Top());

    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());
    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue4 = queue;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue4 = queue;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());

    queue.Push(c3);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c4);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    QueueLst copu_queue_1(queue);
    QueueLst queue2 = queue;
    queue4 = queue;

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c2, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c3, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c4, queue.Top());

    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Clear();
    CHECK_EQ(1, queue.IsEmpty());
    CHECK_THROWS(queue.Top());

    QueueLst copu_queue_2(queue);
    QueueLst queue3 = queue;

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());


    SUBCASE("copu_queue_1") {
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c2, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c3, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c4, copu_queue_1.Top());

        copu_queue_1.Pop();
        CHECK_EQ(1, copu_queue_1.IsEmpty());
        CHECK_THROWS(copu_queue_1.Top());

        copu_queue_1.Push(c1);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Push(c2);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Clear();
        CHECK_EQ(1, copu_queue_1.IsEmpty());
        CHECK_THROWS(copu_queue_1.Top());

        copu_queue_1.Push(c1);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());

        copu_queue_1.Push(c2);
        CHECK_EQ(0, copu_queue_1.IsEmpty());
        CHECK_EQ(c1, copu_queue_1.Top());
    }

    SUBCASE("copu_queue_2") {
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());
        copu_queue_2.Pop();
        CHECK_EQ(1, copu_queue_2.IsEmpty());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c3);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c4);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c2, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c3, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c4, copu_queue_2.Top());

        copu_queue_2.Pop();
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Clear();
        CHECK_EQ(1, copu_queue_2.IsEmpty());
        CHECK_THROWS(copu_queue_2.Top());

        copu_queue_2.Push(c1);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());

        copu_queue_2.Push(c2);
        CHECK_EQ(0, copu_queue_2.IsEmpty());
        CHECK_EQ(c1, copu_queue_2.Top());
    }

    SUBCASE("queue2") {
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c2, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c3, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c4, queue2.Top());

        queue2.Pop();
        CHECK_EQ(1, queue2.IsEmpty());
        CHECK_THROWS(queue2.Top());

        queue2.Push(c1);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Push(c2);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Clear();
        CHECK_EQ(1, queue2.IsEmpty());
        CHECK_THROWS(queue2.Top());

        queue2.Push(c1);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Push(c2);
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c1, queue2.Top());

        queue2.Pop();
        CHECK_EQ(0, queue2.IsEmpty());
        CHECK_EQ(c2, queue2.Top());
    }

    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());
    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c3);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c4);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c2, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c3, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c4, queue3.Top());

    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Clear();
    CHECK_EQ(1, queue3.IsEmpty());
    CHECK_THROWS(queue3.Top());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c3, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c4, queue4.Top());

    queue4.Pop();
    CHECK_EQ(1, queue4.IsEmpty());
    CHECK_THROWS(queue4.Top());

    queue4.Push(c1);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c2);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Clear();
    CHECK_EQ(1, queue4.IsEmpty());
    CHECK_THROWS(queue4.Top());

    queue4.Push(c1);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c2);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Push(c3);
    queue4.Push(c4);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4 = queue3;
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c1, queue4.Top());

    queue4.Pop();
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c2, queue4.Top());

}