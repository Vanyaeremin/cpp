#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "unittest.hpp"
#include <queuearrt/queuearrt.hpp>
#include <cstdint>
#include <string>
#include <vector>

#define TYPES int,double, std::string
int con = 0;

TEST_CASE_TEMPLATE_DEFINE("queuearrt", T, queuearrt) {

    std::vector<T> data;
    FillData(8, data);
    T c11 = data[0];
    T c12 = data[1];
    T c21 = data[2];
    T c22 = data[3];
    T c31 = data[4];
    T c32 = data[5];
    T c41 = data[6];
    T c42 = data[7];

    QueueArrT<T> q1;
    CHECK_EQ(q1.IsEmpty(), 1);
    CHECK_THROWS(q1.Top());
    q1.Pop();
    QueueArrT<T> cp(q1);
    QueueArrT<T> cpp = q1;

    cp.Push(c11);
    CHECK_EQ(cp.Top(), c11);
    CHECK_EQ(cp.IsEmpty(), 0);

    cpp.Push(c11);
    CHECK_EQ(cpp.Top(), c11);
    CHECK_EQ(cpp.IsEmpty(), 0);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c21);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c22);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c31);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c32);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c41);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArrT<T> test_copy_1(q1);
    QueueArrT<T> ravno1 = q1;

    q1.Pop();
    CHECK_EQ(q1.Top(), c12);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c21);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c22);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c31);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c32);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c41);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.IsEmpty(), 1);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArrT<T> q2;
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c22);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c31);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    QueueArrT<T> test_copy_2(q2);
    QueueArrT<T> ravno2 = q2;

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Clear();
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Pop();
    CHECK_THROWS(q2.Top());
    CHECK_EQ(q2.IsEmpty(), 1);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c12);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c21);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c22);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c31);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c32);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c41);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_THROWS(test_copy_1.Top());
    CHECK_EQ(test_copy_1.IsEmpty(), 1);

    test_copy_1.Push(c11);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Push(c12);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c12);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c21);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c22);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c31);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c32);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c41);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_THROWS(ravno1.Top());
    CHECK_EQ(ravno1.IsEmpty(), 1);

    ravno1.Push(c11);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Push(c12);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c32);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c41);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Clear();
    CHECK_EQ(ravno2.IsEmpty(), 1);
    CHECK_THROWS(ravno2.Top());
    ravno2.Pop();

    ravno2.Push(c11);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c12);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_THROWS(ravno2.Top());
    CHECK_EQ(ravno2.IsEmpty(), 1);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c32);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c41);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Clear();
    CHECK_EQ(test_copy_2.IsEmpty(), 1);
    CHECK_THROWS(test_copy_2.Top());
    test_copy_2.Pop();

    test_copy_2.Push(c11);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c12);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_THROWS(test_copy_2.Top());
    CHECK_EQ(test_copy_2.IsEmpty(), 1);
}

TEST_CASE_TEMPLATE_INVOKE(queuearrt, TYPES);