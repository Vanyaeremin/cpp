#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iosfwd>

class BitSet {
private:
    class BiA;
public:
    BitSet() = default;
    BitSet(const BitSet& rhs) = default;
    BitSet(BitSet&& rhs) = default;
    explicit BitSet(const std::int32_t size): size_(size), bits_(size) {}
    BitSet& operator=(const BitSet& rhs) = default;
    BitSet& operator=(BitSet&& rhs) = default;
    ~BitSet() = default;

    [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;
    std::int32_t Size() const noexcept { return size_; }
    void Resize(const std::int32_t size);
    bool Get(const int32_t idx) const;
    void Set(const int32_t idx, const bool val);
    void Fill(const bool val) noexcept;
    BiA operator[](int32_t i);

    BitSet operator~();
    BitSet& operator|=(const BitSet& rhs);
    BitSet& operator&=(const BitSet& rhs);
    BitSet& operator^=(const BitSet& rhs);
    std::vector<std::uint32_t> same_size(const BitSet& v1, const BitSet& v2);

    [[nodiscard]] std::ostream& WriteTxt(std::ostream& ostrm) const;
    //std::ostream& WriteBinary(std::ostream&);
    [[nodiscard]] std::istream& ReadTxt(std::istream& istrm);
    //std::istream& ReadBinary(std::istream&);

private:
    class BiA {
    public:
        BiA() = default;
        BiA(const std::int32_t i, BitSet& b) : i_(i), b_{b} {}
        ~BiA() = default;

        operator bool() const { return b_.Get(i_); }
        bool operator=(const bool value);
        BiA& operator=(const BiA& bia);
        const bool operator= (const bool value) const;
        const BiA& operator= (const BiA& bia) const;
        [[nodiscard]] bool operator==(const BiA& rhs);
        [[nodiscard]] bool operator==(const bool rhs);
        [[nodiscard]] bool operator!=(const BiA& rhs);
        [[nodiscard]] bool operator!=(const bool rhs);
        [[nodiscard]] bool operator==(const int rhs);
        [[nodiscard]] bool operator!=(const int rhs);

    private:
        BitSet& b_ ;
        std::int32_t i_;
    };
    std::int32_t size_ = 0;
    std::vector<std::uint32_t> bits_;
};

BitSet operator&(const BitSet& lhs, const BitSet& rhs);

BitSet operator|(const BitSet& lhs, const BitSet& rhs);

BitSet operator^(const BitSet& lhs, const BitSet& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const BitSet& rhs) {
    return rhs.WriteTxt(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, BitSet& rhs) {
    return rhs.ReadTxt(istrm);
}

#endif