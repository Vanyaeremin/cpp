#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("queuelstpr ctor") {
    float f1 = 1;
    float f2 = 2;
    float f3 = 3;
    float f4 = 4;

    QueueLstPr q1;
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.IsEmpty(), 1);
    QueueLstPr q2(q1);
    QueueLstPr q3 = q2;

    q1.Push(f1);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f2);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f3);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f4);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Clear();
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.IsEmpty(), 1);

    q1.Push(f4);
    CHECK_EQ(q1.Top(), f4);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f3);
    CHECK_EQ(q1.Top(), f3);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f2);
    CHECK_EQ(q1.Top(), f2);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f1);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);


    q2.Push(f2);
    CHECK_EQ(q2.Top(), f2);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Push(f4);
    CHECK_EQ(q2.Top(), f2);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Push(f3);
    CHECK_EQ(q2.Top(), f2);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Push(f1);
    CHECK_EQ(q2.Top(), f1);
    CHECK_EQ(q2.IsEmpty(), 0);

    QueueLstPr q_ravno = q2;
    QueueLstPr q_copy(q2);

    q2.Pop();
    CHECK_EQ(q2.Top(), f2);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Pop();
    CHECK_EQ(q2.Top(), f3);
    CHECK_EQ(q2.IsEmpty(), 0);

    q1 = q2;
    CHECK_EQ(q1.Top(), f3);
    CHECK_EQ(q1.IsEmpty(), 0);
    q2.Pop();
    CHECK_EQ(q2.Top(), f4);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Pop();
    CHECK_THROWS(q2.Top());
    CHECK_EQ(q2.IsEmpty(), 1);
    q1.Pop();
    CHECK_EQ(q1.Top(), f4);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Pop();
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.IsEmpty(), 1);

    q_ravno.Pop();
    CHECK_EQ(q_ravno.Top(), f2);
    CHECK_EQ(q_ravno.IsEmpty(), 0);
    q_ravno.Pop();
    CHECK_EQ(q_ravno.Top(), f3);
    CHECK_EQ(q_ravno.IsEmpty(), 0);
    q_ravno.Pop();
    CHECK_EQ(q_ravno.Top(), f4);
    CHECK_EQ(q_ravno.IsEmpty(), 0);
    q_ravno.Pop();
    CHECK_THROWS(q_ravno.Top());
    CHECK_EQ(q_ravno.IsEmpty(), 1);

    q_copy.Pop();
    CHECK_EQ(q_copy.Top(), f2);
    CHECK_EQ(q_copy.IsEmpty(), 0);
    q_copy.Pop();
    CHECK_EQ(q_copy.Top(), f3);
    CHECK_EQ(q_copy.IsEmpty(), 0);
    q_copy.Pop();
    CHECK_EQ(q_copy.Top(), f4);
    CHECK_EQ(q_copy.IsEmpty(), 0);
    q_copy.Pop();
    CHECK_THROWS(q_copy.Top());
    CHECK_EQ(q_copy.IsEmpty(), 1);

    q3.Push(f1);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Push(f2);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Push(f3);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Push(f4);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_EQ(q3.Top(), f2);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_EQ(q3.Top(), f3);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_EQ(q3.Top(), f4);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_THROWS(q3.Top());
    CHECK_EQ(q3.IsEmpty(), 1);
}