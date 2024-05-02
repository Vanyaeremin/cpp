#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "unittest.hpp"
#include <dynarrt/dynarrt.hpp>
#include <cstdint>
#include <string>
#include <vector>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("dynarrt", T, dynarrt) {
    std::vector<T> data;
    FillData(4, data);
    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2]; 
    T c4 = data[3];

    DynArrT<T> d1;
    CHECK_EQ(0, d1.Size());

    
    DynArrT<T> d2(4);
    CHECK_EQ(4, d2.Size());
    
    d2[0] = c1;
    d2[1] = c2;
    d2[2] = c3;
    d2[3] = c4;
    CHECK_EQ(c1, d2[0]);
    CHECK_EQ(c2, d2[1]);
    CHECK_EQ(c3, d2[2]);
    CHECK_EQ(c4, d2[3]);

    DynArrT<T> d3(d2);
    CHECK_EQ(4, d3.Size());
    CHECK_EQ(c1, d3[0]);
    CHECK_EQ(c2, d3[1]);
    CHECK_EQ(c3, d3[2]);
    CHECK_EQ(c4, d3[3]);
    d3[0] = c2;
    CHECK_EQ(c2, d3[0]);
    CHECK_EQ(c1, d2[0]);
    d3[0] = c1;

    d3.Resize(8);
    d3[5] = c3;
    CHECK_EQ(8, d3.Size());
    CHECK_EQ(c1, d3[0]);
    CHECK_EQ(c2, d3[1]);
    CHECK_EQ(c3, d3[2]);
    CHECK_EQ(c4, d3[3]);
    CHECK_EQ(c3, d3[5]);
    CHECK_THROWS(d3[8]);

    d3.Resize(4);
    CHECK_EQ(4, d3.Size());
    CHECK_EQ(c1, d3[0]);
    CHECK_EQ(c2, d3[1]);
    CHECK_EQ(c3, d3[2]);
    CHECK_EQ(c4, d3[3]);
    CHECK_THROWS(d3[4]);

    d3.Resize(6);
    CHECK_EQ(6, d3.Size());
    CHECK_EQ(c1, d3[0]);
    CHECK_EQ(c2, d3[1]);
    CHECK_EQ(c3, d3[2]);
    CHECK_EQ(c4, d3[3]);
    CHECK_THROWS(d3[6]);

    d1 = d3;
    CHECK_EQ(6, d1.Size());
    CHECK_EQ(c1, d1[0]);
    CHECK_EQ(c2, d1[1]);
    CHECK_EQ(c3, d1[2]);
    CHECK_EQ(c4, d1[3]);

    d1 = d2;
    CHECK_EQ(4, d1.Size());
    CHECK_EQ(c1, d1[0]);
    CHECK_EQ(c2, d1[1]);
    CHECK_EQ(c3, d1[2]);
    CHECK_EQ(c4, d1[3]);

    CHECK_THROWS(void(DynArrT<T>(-5)));
    CHECK_THROWS(d1.Resize(-2));
    CHECK_THROWS(void(DynArrT<T>(0)));
    CHECK_THROWS(d1.Resize(0));
    CHECK_THROWS(d1[-10]);
    CHECK_THROWS(d1[80]);
}

TEST_CASE_TEMPLATE_INVOKE(dynarrt, TYPES);