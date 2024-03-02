#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("queuearr ctor") {
    Complex c11(1, 2);
    Complex c12(2, 1);
    Complex c21(3, 4);
    Complex c22(4, 3);
    Complex c31(5, 6);
    Complex c32(6, 5);
    Complex c41(7, 8);
    Complex c42(8, 7);
    QueueArr q1;
    CHECK_EQ(q1.Count(), 0);
    CHECK_EQ(q1.IsEmpty(), 1);
    CHECK_THROWS(q1.Top());
    q1.Pop();
    QueueArr cp(q1);
    QueueArr cpp = q1;

    cp.Push(c11);
    CHECK_EQ(cp.Top(), c11);
    CHECK_EQ(cp.Count(), 1);
    CHECK_EQ(cp.IsEmpty(), 0);

    cpp.Push(c11);
    CHECK_EQ(cpp.Top(), c11);
    CHECK_EQ(cpp.Count(), 1);
    CHECK_EQ(cpp.IsEmpty(), 0);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 1);
    CHECK_EQ(q1.IsEmpty(), 0);
        
    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 2);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c21);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 3);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c22);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 4);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c31);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 5);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c32);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 6);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c41);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 7);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 8);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 9);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 10);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArr test_copy_1(q1);
    QueueArr ravno1 = q1;

    q1.Pop();
    CHECK_EQ(q1.Top(), c12);
    CHECK_EQ(q1.Count(), 9);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c21);
    CHECK_EQ(q1.Count(), 8);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c22);
    CHECK_EQ(q1.Count(), 7);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c31);
    CHECK_EQ(q1.Count(), 6);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c32);
    CHECK_EQ(q1.Count(), 5);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c41);
    CHECK_EQ(q1.Count(), 4);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.Count(), 3);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.Count(), 2);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.Count(), 1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.Count(), 0);
    CHECK_EQ(q1.IsEmpty(), 1);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.Count(), 2);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArr q2;
    CHECK_EQ(q2.Count(), 0);
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 1);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 2);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 3);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.Count(), 2);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 1);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 2);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 3);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 4);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c22);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 5);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c31);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 6);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.Count(), 7);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 6);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 7);
    CHECK_EQ(q2.IsEmpty(), 0);

    QueueArr test_copy_2(q2);
    QueueArr ravno2 = q2;

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 8);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 9);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.Count(), 8);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.Count(), 9);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.Count(), 10);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Clear();
    CHECK_EQ(q2.Count(), 0);
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 1);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.Count(), 2);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.Count(), 1);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Pop();
    CHECK_THROWS(q2.Top());
    CHECK_EQ(q2.Count(), 0);
    CHECK_EQ(q2.IsEmpty(), 1);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c12);
    CHECK_EQ(test_copy_1.Count(), 9);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c21);
    CHECK_EQ(test_copy_1.Count(), 8);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c22);
    CHECK_EQ(test_copy_1.Count(), 7);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c31);
    CHECK_EQ(test_copy_1.Count(), 6);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c32);
    CHECK_EQ(test_copy_1.Count(), 5);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c41);
    CHECK_EQ(test_copy_1.Count(), 4);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.Count(), 3);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.Count(), 2);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.Count(), 1);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_THROWS(test_copy_1.Top());
    CHECK_EQ(test_copy_1.Count(), 0);
    CHECK_EQ(test_copy_1.IsEmpty(), 1);

    test_copy_1.Push(c11);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.Count(), 1);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Push(c12);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.Count(), 2);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c12);
    CHECK_EQ(ravno1.Count(), 9);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c21);
    CHECK_EQ(ravno1.Count(), 8);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c22);
    CHECK_EQ(ravno1.Count(), 7);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c31);
    CHECK_EQ(ravno1.Count(), 6);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c32);
    CHECK_EQ(ravno1.Count(), 5);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c41);
    CHECK_EQ(ravno1.Count(), 4);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.Count(), 3);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.Count(), 2);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.Count(), 1);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_THROWS(ravno1.Top());
    CHECK_EQ(ravno1.Count(), 0);
    CHECK_EQ(ravno1.IsEmpty(), 1);

    ravno1.Push(c11);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.Count(), 1);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Push(c12);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.Count(), 2);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.Count(), 8);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c32);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.Count(), 9);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.Count(), 8);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c41);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.Count(), 9);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.Count(), 10);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Clear();
    CHECK_EQ(ravno2.Count(), 0);
    CHECK_EQ(ravno2.IsEmpty(), 1);
    CHECK_THROWS(ravno2.Top());
    ravno2.Pop();

    ravno2.Push(c11);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.Count(), 1);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c12);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.Count(), 2);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.Count(), 1);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_THROWS(ravno2.Top());
    CHECK_EQ(ravno2.Count(), 0);
    CHECK_EQ(ravno2.IsEmpty(), 1);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.Count(), 8);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c32);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.Count(), 9);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.Count(), 8);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c41);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.Count(), 9);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.Count(), 10);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Clear();
    CHECK_EQ(test_copy_2.Count(), 0);
    CHECK_EQ(test_copy_2.IsEmpty(), 1);
    CHECK_THROWS(test_copy_2.Top());
    test_copy_2.Pop();

    test_copy_2.Push(c11);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.Count(), 1);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c12);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.Count(), 2);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.Count(), 1);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_THROWS(test_copy_2.Top());
    CHECK_EQ(test_copy_2.Count(), 0);
    CHECK_EQ(test_copy_2.IsEmpty(), 1);

}