#pragma once
#include <bits/stdc++.h>
/**
 * @title ModInt
 * @category 数学
 */

// BEGIN CUT HERE
namespace internal {
template <std::uint64_t mod, std::uint64_t prim_root, class ModInt>
struct ModIntImpl {
  static constexpr std::uint64_t modulo() { return mod; }
  static constexpr std::uint64_t pr_rt() { return prim_root; }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {
    return os << rhs.val();
  }
};
}  // namespace internal
template <std::uint64_t mod, std::uint64_t prim_root = 0>
class ModInt
    : public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {
  using u64 = std::uint64_t;
  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {
    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }
  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;
  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }
  static constexpr u64 reduce(const __uint128_t w) {
    return u64(w >> 64) + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);
  }
  u64 x;

 public:
  constexpr ModInt() : x(0) {}
  constexpr ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}
  static constexpr u64 norm(u64 w) { return w - (mod & -(w >= mod)); }
  constexpr ModInt operator-() const {
    ModInt ret;
    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;
  }
  constexpr ModInt &operator+=(const ModInt &rhs) {
    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >> 63), *this;
  }
  constexpr ModInt &operator-=(const ModInt &rhs) {
    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;
  }
  constexpr ModInt &operator*=(const ModInt &rhs) {
    return this->x = reduce(__uint128_t(this->x) * rhs.x), *this;
  }
  constexpr ModInt &operator/=(const ModInt &rhs) {
    return this->operator*=(rhs.inverse());
  }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x); }
  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }
  constexpr ModInt pow(std::uint64_t k) const {
    ModInt ret = ModInt(1);
    for (ModInt base = *this; k; k >>= 1, base *= base)
      if (k & 1) ret *= base;
    return ret;
  }
  constexpr ModInt inverse() const { return pow(mod - 2); }
  constexpr ModInt sqrt() const {
    if (*this == ModInt(0) || mod == 2) return *this;
    if (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions
    ModInt ONE = 1, b(2), w(b * b - *this);
    while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;
    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {
      ModInt a = (u.first * v.first + u.second * v.second * w);
      ModInt b = (u.first * v.second + u.second * v.first);
      return std::make_pair(a, b);
    };
    std::uint64_t e = (mod + 1) >> 1;
    auto ret = std::make_pair(ONE, ModInt(0));
    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))
      if (e & 1) ret = mul(ret, bs);
    return ret.first.val() * 2 < mod ? ret.first : -ret.first;
  }
  constexpr u64 val() const {
    u64 ret = reduce(x) - mod;
    return ret + (mod & -(ret >> 63));
  }
  friend std::istream &operator>>(std::istream &is, ModInt &rhs) {
    return is >> rhs.x, rhs.x = init(rhs.x), is;
  }
};
template <std::uint64_t pr_rt>
struct ModInt<2, pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {
  constexpr ModInt(std::int64_t n = 0) : x(n & 1) {}
  constexpr ModInt operator-() const { return *this; }
  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this; }
  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this; }
  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this; }
  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this; }
  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs; }
  bool operator==(const ModInt &rhs) const { return x == rhs.x; }
  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }
  constexpr ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }
  constexpr ModInt sqrt() const { return *this; }
  constexpr ModInt inverse() const { return *this; }
  constexpr std::uint64_t val() const { return x; }
  friend std::istream &operator>>(std::istream &is, ModInt &rhs) {
    return is >> rhs.x, is;
  }

 private:
  bool x;
};