#include "bitset.hpp"

bool BitSet::BiA::operator==(const BiA& rhs) {
    return b_.bits_[i_] == rhs.b_.bits_[i_];
}

bool BitSet::BiA::operator==(const bool rhs) {
    return b_.bits_[i_] == rhs;
}

bool BitSet::BiA::operator==(const int rhs) {
    return b_.bits_[i_] == static_cast<bool>(rhs);
}

bool BitSet::BiA::operator!=(const BiA& rhs) {
    return b_.bits_[i_] != rhs.b_.bits_[i_];
}

bool BitSet::BiA::operator!=(const bool rhs) {
    return b_.bits_[i_] != rhs;
}

bool BitSet::BiA::operator!=(const int rhs) {
    return b_.bits_[i_] != static_cast<bool>(rhs);
}

bool BitSet::BiA::operator=(const bool value) {
    b_.bits_[i_] = value;
    return static_cast<bool>(b_.bits_[i_]);
}

BitSet::BiA& BitSet::BiA::operator=(const BiA& bia) {
    b_.bits_[i_] = bia.b_.bits_[bia.i_];
    return *this;
}

const bool BitSet::BiA::operator=(const bool value) const {
    b_.bits_[i_] = value;
    return static_cast<bool>(b_.bits_[i_]);
}

BitSet::BiA BitSet::operator[](int32_t i) {
    BiA bia(i, *this);
    return bia;
}

const BitSet::BiA& BitSet::BiA::operator=(const BiA& bia) const {
    b_.bits_[i_] = bia.b_.bits_[bia.i_];
    return *this;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept {
    return ((bits_ == rhs.bits_) && (size_ == rhs.size_));
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept {
    return !((bits_ == rhs.bits_) && (size_ == rhs.size_));
}

void BitSet::Resize(const std::int32_t size) {
    if (size <= 0) {
        throw std::invalid_argument("The size must be greater than zero");
    }
    else if (size_ != size) {
        size_ = size;
        bits_.resize(size);
    }
}

bool BitSet::Get(const std::int32_t idx) const {
    if (idx >= 0 && idx < size_) {
        return bits_[idx];
    }
    else {
        throw std::out_of_range("Not correct index");
    }
}

void BitSet::Set(const int32_t idx, const bool val) {
    if (idx >= 0 && idx < size_) {
        bits_[idx] = val;
    }
    else {
        throw std::out_of_range("Not correct index");
    }
}

void BitSet::Fill(const bool val) noexcept {
    bits_ = std::vector<std::uint32_t>(size_, val);
}

BitSet BitSet::operator~() {
    BitSet otr(size_);
    for (std::size_t i = 0; i < size_; ++i) {
        otr.bits_[i] = !bits_[i];
    }
    return otr;
}

std::vector<std::uint32_t> BitSet::same_size(const BitSet& v1, const BitSet& v2) {
    std::ptrdiff_t max_len = std::max(v1.size_, v2.size_);
    std::vector<std::uint32_t> data(max_len - v1.size_, 0);
    data.insert(data.end(), v1.bits_.begin(), v1.bits_.end());
    return data;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] | data2[i]);
    }
    return *this;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result |= rhs;
    return result;
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] & data2[i]);
    }
    return *this;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result &= rhs;
    return result;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
    std::vector<std::uint32_t> data1 = same_size(*this, rhs);
    std::vector<std::uint32_t> data2 = same_size(rhs, *this);
    this->Resize(data1.size());
    for (std::size_t i = 0; i < data1.size(); ++i) {
        bits_[i] = (data1[i] ^ data2[i]);
    }
    return *this;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
    BitSet result(lhs);
    result ^= rhs;
    return result;
}

std::ostream& BitSet::WriteTxt(std::ostream& ostrm) const
{
    std::uint32_t c = 0;

    ostrm << size_ << std::endl;
    for (size_t i = 0; i != size_; ++i) {
        ostrm << bits_[i];
        if ((i + 1) % 20 == 0) {
            ostrm << ' ' << c++ << std::endl;
        }

    }
    if (size_ % 20 != 0) {
        std::string end(20 - size_ % 20 + 1, ' ');
        ostrm << end << c << std::endl;
    }
    return ostrm;
}

std::istream& BitSet::ReadTxt(std::istream& istrm)
{
    istrm >> size_;
    std::string bits;
    istrm >> bits;

    if (bits.size() != size_) {
        throw std::logic_error("Incorrect number of characters");
    }

    if (istrm.good()) {
        for (char const& c : bits) {
            if (!istrm || (c != '1' && c != '0')) {
                istrm.setstate(std::ios_base::failbit);
                return istrm;
            }
            else {
                bits_.push_back(c - '0');
            }
        }
    }

    return istrm;
}
