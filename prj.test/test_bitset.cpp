#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <bitset/bitset.hpp>

TEST_CASE("bitset ctor1") {
    BitSet b1;
    CHECK_EQ(b1.Size(), 0);
    CHECK_THROWS(b1.Get(0));

    b1.Resize(15);
    CHECK_THROWS(b1.Get(15));
    CHECK_THROWS(b1.Get(-1));
    CHECK_THROWS(b1.Set(15, 0));
    CHECK_THROWS(b1.Set(-1, 0));
    CHECK_THROWS(b1.Resize(-2));

    CHECK_EQ(b1.Get(0), 0);
    CHECK_EQ(b1.Get(1), 0);
    CHECK_EQ(b1.Get(14), 0);
    CHECK_EQ(b1.Size(), 15);
    b1.Set(0, 1);
    CHECK_EQ(b1.Get(0), 1);
    b1.Set(1, 1);
    CHECK_EQ(b1.Get(1), 1);
    b1.Set(2, 1);
    CHECK_EQ(b1.Get(2), 1);
    b1.Set(3, 1);
    CHECK_EQ(b1.Get(3), 1);
    b1.Set(4, 1);
    CHECK_EQ(b1.Get(4), 1);
    CHECK_EQ(b1.Get(5), 0);
    CHECK_EQ(b1.Get(14), 0);

    BitSet b2(10);
    CHECK_EQ(b2.Size(), 10);
    CHECK_EQ(b2.Get(0), 0);
    CHECK_EQ(b2.Get(1), 0);
    CHECK_EQ(b2.Get(9), 0);
    b2.Fill(1);
    CHECK_EQ(b2.Size(), 10);
    CHECK_EQ(b2.Get(0), 1);
    CHECK_EQ(b2.Get(1), 1);
    CHECK_EQ(b2.Get(9), 1);
    b2.Fill(0);
    CHECK_EQ(b2.Size(), 10);
    CHECK_EQ(b2.Get(0), 0);
    CHECK_EQ(b2.Get(1), 0);
    CHECK_EQ(b2.Get(9), 0);

    CHECK_EQ(b1 == b2, 0);
    CHECK_EQ(b1 != b2, 1);

    b1.Resize(10);
    CHECK_EQ(b1.Size(), 10);
    CHECK_EQ(b1 == b2, 0);
    CHECK_EQ(b1 != b2, 1);
    b1.Fill(0);
    CHECK_EQ(b1.Size(), 10);
    CHECK_EQ(b1 == b2, 1);
    CHECK_EQ(b1 != b2, 0);

    b1.Fill(1);
    CHECK_EQ(b1 == ~b2, 1);
    BitSet b33 = ~b2;
    CHECK_EQ(b33.Get(0), 1);
    CHECK_EQ(b33.Get(1), 1);
    CHECK_EQ(b33.Get(2), 1);
    CHECK_EQ(b33.Get(3), 1);
    CHECK_EQ(b33.Get(4), 1);
    CHECK_EQ(b33.Get(5), 1);
    CHECK_EQ(b33.Get(6), 1);
    CHECK_EQ(b33.Get(7), 1);
    CHECK_EQ(b33.Get(8), 1);
    CHECK_EQ(b33.Get(9), 1);
    CHECK_EQ(~b1 == b2, 1);
    b33 = ~b1;
    CHECK_EQ(b33.Get(0), 0);
    CHECK_EQ(b33.Get(1), 0);
    CHECK_EQ(b33.Get(2), 0);
    CHECK_EQ(b33.Get(3), 0);
    CHECK_EQ(b33.Get(4), 0);
    CHECK_EQ(b33.Get(5), 0);
    CHECK_EQ(b33.Get(6), 0);
    CHECK_EQ(b33.Get(7), 0);
    CHECK_EQ(b33.Get(8), 0);
    CHECK_EQ(b33.Get(9), 0);
    CHECK_EQ(~b1 != ~b2, 1);
}
TEST_CASE("Bitset2") {
    BitSet b3(13);
    b3.Set(0, 1);
    b3.Set(1, 0);
    b3.Set(2, 1);
    b3.Set(3, 0);
    b3.Set(4, 1);
    b3.Set(5, 0);
    b3.Set(6, 1);
    b3.Set(7, 0);
    b3.Set(8, 1);
    b3.Set(9, 0);
    b3.Set(10, 1);
    b3.Set(11, 0);
    b3.Set(12, 1);

    BitSet b4(9);
    b4.Set(0, 1);
    b4.Set(1, 1);
    b4.Set(2, 0);
    b4.Set(3, 0);
    b4.Set(4, 1);
    b4.Set(5, 0);
    b4.Set(6, 0);
    b4.Set(7, 1);
    b4.Set(8, 0);

    b3 |= b4;
    CHECK_EQ(b3.Get(0), 1);
    CHECK_EQ(b3.Get(1), 0);
    CHECK_EQ(b3.Get(2), 1);
    CHECK_EQ(b3.Get(3), 0);
    CHECK_EQ(b3.Get(4), 1);
    CHECK_EQ(b3.Get(5), 1);
    CHECK_EQ(b3.Get(6), 1);
    CHECK_EQ(b3.Get(7), 0);
    CHECK_EQ(b3.Get(8), 1);
    CHECK_EQ(b3.Get(9), 0);
    CHECK_EQ(b3.Get(10), 1);
    CHECK_EQ(b3.Get(11), 1);
    CHECK_EQ(b3.Get(12), 1);

    b3 &= b4;
    CHECK_EQ(b3.Get(0), 0);
    CHECK_EQ(b3.Get(1), 0);
    CHECK_EQ(b3.Get(2), 0);
    CHECK_EQ(b3.Get(3), 0);
    CHECK_EQ(b3.Get(4), 1);
    CHECK_EQ(b3.Get(5), 1);
    CHECK_EQ(b3.Get(6), 0);
    CHECK_EQ(b3.Get(7), 0);
    CHECK_EQ(b3.Get(8), 1);
    CHECK_EQ(b3.Get(9), 0);
    CHECK_EQ(b3.Get(10), 0);
    CHECK_EQ(b3.Get(11), 1);
    CHECK_EQ(b3.Get(12), 0);

    b4.Set(2, 1);
    b3.Set(0, 1);
    b3.Set(2, 1);
    b3.Set(4, 0);

    b3 ^= b4;
    CHECK_EQ(b3.Get(0), 1);
    CHECK_EQ(b3.Get(1), 0);
    CHECK_EQ(b3.Get(2), 1);
    CHECK_EQ(b3.Get(3), 0);
    CHECK_EQ(b3.Get(4), 1);
    CHECK_EQ(b3.Get(5), 0);
    CHECK_EQ(b3.Get(6), 1);
    CHECK_EQ(b3.Get(7), 0);
    CHECK_EQ(b3.Get(8), 0);
    CHECK_EQ(b3.Get(9), 0);
    CHECK_EQ(b3.Get(10), 0);
    CHECK_EQ(b3.Get(11), 0);
    CHECK_EQ(b3.Get(12), 0);

    BitSet b5 = b3 & b4;
    CHECK_EQ(b5.Get(0), 0);
    CHECK_EQ(b5.Get(1), 0);
    CHECK_EQ(b5.Get(2), 0);
    CHECK_EQ(b5.Get(3), 0);
    CHECK_EQ(b5.Get(4), 1);
    CHECK_EQ(b5.Get(5), 0);
    CHECK_EQ(b5.Get(6), 1);
    CHECK_EQ(b5.Get(7), 0);
    CHECK_EQ(b5.Get(8), 0);
    CHECK_EQ(b5.Get(9), 0);
    CHECK_EQ(b5.Get(10), 0);
    CHECK_EQ(b5.Get(11), 0);
    CHECK_EQ(b5.Get(12), 0);

    b5 = b3 | b4;
    CHECK_EQ(b5.Get(0), 1);
    CHECK_EQ(b5.Get(1), 0);
    CHECK_EQ(b5.Get(2), 1);
    CHECK_EQ(b5.Get(3), 0);
    CHECK_EQ(b5.Get(4), 1);
    CHECK_EQ(b5.Get(5), 1);
    CHECK_EQ(b5.Get(6), 1);
    CHECK_EQ(b5.Get(7), 0);
    CHECK_EQ(b5.Get(8), 1);
    CHECK_EQ(b5.Get(9), 0);
    CHECK_EQ(b5.Get(10), 0);
    CHECK_EQ(b5.Get(11), 1);
    CHECK_EQ(b5.Get(12), 0);

    b5 = b3 ^ b4;
    CHECK_EQ(b5.Get(0), 1);
    CHECK_EQ(b5.Get(1), 0);
    CHECK_EQ(b5.Get(2), 1);
    CHECK_EQ(b5.Get(3), 0);
    CHECK_EQ(b5.Get(4), 0);
    CHECK_EQ(b5.Get(5), 1);
    CHECK_EQ(b5.Get(6), 0);
    CHECK_EQ(b5.Get(7), 0);
    CHECK_EQ(b5.Get(8), 1);
    CHECK_EQ(b5.Get(9), 0);
    CHECK_EQ(b5.Get(10), 0);
    CHECK_EQ(b5.Get(11), 1);
    CHECK_EQ(b5.Get(12), 0);
}

TEST_CASE("CHECK_BIA") {
    BitSet b3(13);
    b3.Set(0, 1);
    b3.Set(1, 0);
    b3.Set(2, 1);
    b3.Set(3, 0);
    b3.Set(4, 1);
    b3.Set(5, 0);
    b3.Set(6, 1);
    b3.Set(7, 0);
    b3.Set(8, 1);
    b3.Set(9, 0);
    b3.Set(10, 1);
    b3.Set(11, 0);
    b3.Set(12, 1);
    CHECK_EQ(b3.Get(0), 1);
    CHECK_EQ(b3.Get(4), 1);
    b3[0] = 0;
    b3[4] = 0;
    b3[11] = 1;
    CHECK_EQ(b3.Get(0), 0);
    CHECK_EQ(b3.Get(4), 0);
    CHECK_EQ(b3.Get(11), 1);
    b3[11] = 0;
    CHECK_EQ(b3.Get(11), 0);
    b3.Fill(0);
    BitSet b4(9);
    b4.Set(0, 1);
    b4.Set(1, 1);
    b4.Set(2, 1);
    b4.Set(3, 1);
    b4.Set(4, 1);
    b4.Set(5, 1);
    b4.Set(6, 1);
    b4.Set(7, 1);
    b4.Set(8, 1);
    b3[0] = b4[0];
    b3[1] = b4[1];
    b3[8] = b4[8];
    CHECK_EQ(b3.Get(0), 1);
    CHECK_EQ(b3.Get(1), 1);
    CHECK_EQ(b3.Get(8), 1);
    CHECK_EQ(b4.Get(0), 1);
    CHECK_EQ(b4.Get(1), 1);
    CHECK_EQ(b4.Get(8), 1);
    CHECK_EQ(b3.Get(9), 0);
    CHECK_EQ(b3[0] == b3[1], 1);
    CHECK_EQ(b3[0] != b3[1], 0);
    CHECK_EQ(b3[0] == 1, 1);
    CHECK_EQ(b3[0] == 0, 0);
    CHECK_EQ(b3[0].operator bool(), true);
}

TEST_CASE("CHECK_OPERATOR=") {
    BitSet b3(4);
    b3.Set(0, 1);
    b3.Set(1, 0);
    b3.Set(2, 1);
    b3.Set(3, 0);
    BitSet b4(4);
    b4.Set(0, 0);
    b4.Set(1, 1);
    b4.Set(2, 0);
    b4.Set(3, 1);
    CHECK_EQ(b3[0] == 1, 1);
    CHECK_EQ(b3[1] == 0, 1);
    CHECK_EQ(b4[0] == 0, 1);
    CHECK_EQ(b4[1] == 1, 1);

    b3[0] = b4[0];
    b4[1] = b3[1];
    CHECK_EQ(b3[0] == 0, 1);
    CHECK_EQ(b3[1] == 0, 1);
    CHECK_EQ(b4[0] == 0, 1);
    CHECK_EQ(b4[1] == 0, 1);

    BitSet b5(4);
    b5.Set(0, 1);
    b5.Set(1, 1);
    b5.Set(2, 0);
    b5.Set(3, 0);
    CHECK_EQ(b5[0] == 1, 1);
    CHECK_EQ(b3[0] == 0, 1);
    CHECK_EQ(b4[0] == 0, 1);
    b3[0] = b4[0] = b5[0];
    CHECK_EQ(b3[0] == 1, 1);
    CHECK_EQ(b4[0] == 1, 1);
    CHECK_EQ(b5[0] == 1, 1);
}