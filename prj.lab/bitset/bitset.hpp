#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <stdexcept>

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
    [[nodiscard]] bool Get(const int32_t idx) const;
    void Set(const int32_t idx, const bool val);
    void Fill(const bool val) noexcept;
    BiA operator[](int32_t i);

    [[nodiscard]] BitSet operator~();
    [[nodiscard]] BitSet& operator|=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator&=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator^=(const BitSet& rhs);
    std::vector<std::uint32_t> same_size(const BitSet& v1, const BitSet& v2);

private:
    class BiA {
    public:
        [[nodiscard]] BiA() = default;
        [[nodiscard]] BiA(const std::int32_t i, BitSet& b) : i_(i), b_{b} {}
        ~BiA() = default;

        [[nodiscard]] operator bool() const { return b_.Get(i_); }
        [[nodiscard]] bool operator=(const bool value);
        [[nodiscard]] BiA& operator=(const BiA& bia);
        [[nodiscard]] const bool operator= (const bool value) const;
        [[nodiscard]] const BiA& operator= (const BiA& bia) const;
        bool operator==(const BiA& rhs);
        bool operator==(const bool rhs);
        bool operator!=(const BiA& rhs);
        bool operator!=(const bool rhs);
        bool operator==(const int rhs);
        bool operator!=(const int rhs);

    private:
        BitSet& b_ ;
        std::int32_t i_;
    };
    std::int32_t size_ = 0;
    std::vector<std::uint32_t> bits_;
};

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif