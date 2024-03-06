#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("queuelstpr ctor") {
    float f1 = 1;
    float f2 = 2;
    float f3 = 3;

    QueueLstPr q1;
    QueueLstPr q2(q1);
    QueueLstPr q3 = q1;

    q3.Push(f1);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Push(f2);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Push(f3);
    CHECK_EQ(q3.Top(), f1);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_EQ(q3.Top(), f2);
    CHECK_EQ(q3.IsEmpty(), 0);
    q3.Pop();
    CHECK_EQ(q3.Top(), f3);

    q1.Push(f1);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f2);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Push(f3);
    CHECK_EQ(q1.Top(), f1);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Pop();
    CHECK_EQ(q1.Top(), f2);
    CHECK_EQ(q1.IsEmpty(), 0);
    q1.Pop();
    CHECK_EQ(q1.Top(), f3);

    q2.Push(f1);
    CHECK_EQ(q2.Top(), f1);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Push(f3);
    CHECK_EQ(q2.Top(), f1);
    q2.Push(f2);
    QueueLstPr copy_q(q2);
    QueueLstPr ravno = q2;
    q3 = q2;

    CHECK_EQ(q2.Top(), f1);
    q2.Pop();
    CHECK_EQ(q2.Top(), f2);
    q2.Pop();
    CHECK_EQ(q2.Top(), f3);

    CHECK_EQ(copy_q.Top(), f1);
    copy_q.Pop();
    CHECK_EQ(copy_q.Top(), f2);
    copy_q.Pop();
    CHECK_EQ(copy_q.Top(), f3);
    copy_q.Push(f1);
    CHECK_EQ(copy_q.Top(), f1);
    CHECK_EQ(copy_q.IsEmpty(), 0);
    copy_q.Push(f3);
    CHECK_EQ(copy_q.Top(), f1);
    copy_q.Pop();
    CHECK_EQ(copy_q.Top(), f3);

    CHECK_EQ(ravno.Top(), f1);
    ravno.Pop();
    CHECK_EQ(ravno.Top(), f2);
    ravno.Pop();
    CHECK_EQ(ravno.Top(), f3);

    CHECK_EQ(q3.Top(), f1);
    q3.Pop();
    CHECK_EQ(q3.Top(), f2);
    q3.Push(f3);
    q3.Push(f1);
    q3 = ravno;
    CHECK_EQ(q3.Top(), f3);
    q3.Push(f1);
    q3.Push(f2);
    CHECK_EQ(f1, q3.Top());
    CHECK_EQ(0, q3.IsEmpty());
}