---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_2_A.test.cpp
    title: test/aoj/NTL_2_A.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_2_B.test.cpp
    title: test/aoj/NTL_2_B.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_2_C.test.cpp
    title: test/aoj/NTL_2_C.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_2_D.test.cpp
    title: test/aoj/NTL_2_D.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_2_E.test.cpp
    title: test/aoj/NTL_2_E.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_2_F.test.cpp
    title: test/aoj/NTL_2_F.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u591A\u500D\u9577\u6574\u6570"
    links: []
  bundledCode: "#line 2 \"src/Math/BigInt.hpp\"\n#include <bits/stdc++.h>\n/**\n *\
    \ @title \u591A\u500D\u9577\u6574\u6570\n * @category \u6570\u5B66\n * python\u306E\
    \u591A\u500D\u9577\u6574\u6570\u3092\u4F7F\u3046\u3079\u304D\n */\n\n// BEGIN\
    \ CUT HERE\n\nnamespace ntt {\nstruct ModB {\n  static constexpr std::uint64_t\
    \ mask = (1ull << 32) - 1;\n  static constexpr std::uint64_t mod = (((1ull <<\
    \ 32) - 1) << 32) + 1;\n  static constexpr std::uint64_t prim_root = 7;\n  static\
    \ constexpr int level = 32;\n  std::uint64_t x;\n  ModB() : x(0) {}\n  ModB(std::uint64_t\
    \ n) : x(n >= mod ? n - mod : n) {}\n  static constexpr std::uint64_t modulo()\
    \ { return mod; }\n  static ModB omega() { return ModB(prim_root).pow(mask); }\n\
    \  std::uint64_t get() const { return this->x; }\n  ModB operator+(ModB rhs) const\
    \ {\n    std::uint64_t tmp = mod - rhs.x;\n    return ModB(this->x >= tmp ? this->x\
    \ - tmp : this->x + rhs.x);\n  }\n  ModB operator-(ModB rhs) const {\n    return\
    \ ModB(this->x < rhs.x ? this->x + (mod - rhs.x) : this->x - rhs.x);\n  }\n  ModB\
    \ operator*(ModB rhs) const {\n    std::uint64_t lu = this->x >> 32, ld = uint32_t(this->x);\n\
    \    std::uint64_t ru = rhs.x >> 32, rd = uint32_t(rhs.x);\n    std::uint64_t\
    \ a = lu * ru, c = ld * ru, d = ld * rd;\n    std::uint64_t b = lu * rd + (d >>\
    \ 32);\n    std::uint64_t x = ~b;\n    if (c <= x) {\n      c += b;\n      a +=\
    \ c >> 32;\n    } else {\n      c -= x + 1;\n      a += (c >> 32) + (1ull << 32);\n\
    \    }\n    d = uint32_t(a) * mask + uint32_t(d);\n    c = (std::uint64_t(uint32_t(c))\
    \ << 32);\n    c = c ? c - (a >> 32) : mod - (a >> 32);\n    b = mod - c;\n  \
    \  return (d < b) ? ModB(d + c) : ModB(d - b);\n  }\n  ModB &operator+=(ModB rhs)\
    \ { return *this = *this + rhs; }\n  ModB &operator-=(ModB rhs) { return *this\
    \ = *this - rhs; }\n  ModB &operator*=(ModB rhs) { return *this = *this * rhs;\
    \ }\n  ModB pow(std::uint64_t exp) const {\n    ModB ret = ModB(1);\n    for (ModB\
    \ base = *this; exp; exp >>= 1, base *= base)\n      if (exp & 1) ret *= base;\n\
    \    return ret;\n  }\n  ModB inverse() const { return pow(mod - 2); }\n  bool\
    \ operator==(const ModB &p) const { return x == p.x; }\n  bool operator!=(const\
    \ ModB &p) const { return x != p.x; }\n};\n\ntemplate <typename mod_t>\nvoid convolute(mod_t\
    \ *A, int s1, mod_t *B, int s2, bool cyclic = false) {\n  int s = (cyclic ? std::max(s1,\
    \ s2) : s1 + s2 - 1);\n  int size = 1;\n  while (size < s) size <<= 1;\n  mod_t\
    \ roots[mod_t::level] = {mod_t::omega()};\n  for (int i = 1; i < mod_t::level;\
    \ i++) roots[i] = roots[i - 1] * roots[i - 1];\n  std::fill(A + s1, A + size,\
    \ 0);\n  ntt_dit4(A, size, 1, roots);\n  if (A == B && s1 == s2) {\n    for (int\
    \ i = 0; i < size; i++) A[i] *= A[i];\n  } else {\n    std::fill(B + s2, B + size,\
    \ 0);\n    ntt_dit4(B, size, 1, roots);\n    for (int i = 0; i < size; i++) A[i]\
    \ *= B[i];\n  }\n  ntt_dit4(A, size, -1, roots);\n  mod_t inv = mod_t(size).inverse();\n\
    \  for (int i = 0; i < (cyclic ? size : s); i++) A[i] *= inv;\n}\n\ntemplate <typename\
    \ mod_t>\nvoid rev_permute(mod_t *A, int n) {\n  int r = 0, nh = n >> 1;\n  for\
    \ (int i = 1; i < n; i++) {\n    int h = nh;\n    while (!((r ^= h) & h)) h >>=\
    \ 1;\n    if (r > i) srd::swap(A[i], A[r]);\n  }\n}\n\ntemplate <typename mod_t>\n\
    void ntt_dit4(mod_t *A, int n, int sign, mod_t *roots) {\n  rev_permute(A, n);\n\
    \  int logn = __builtin_ctz(n);\n  if (logn & 1)\n    for (int i = 0; i < n; i\
    \ += 2) {\n      mod_t a = A[i], b = A[i + 1];\n      A[i] = a + b, A[i + 1] =\
    \ a - b;\n    }\n  mod_t imag = roots[mod_t::level - 2];\n  if (sign < 0) imag\
    \ = imag.inverse();\n  mod_t one = mod_t(1);\n  for (int e = 2 + (logn & 1); e\
    \ < logn + 1; e += 2) {\n    const int m = 1 << e;\n    const int m4 = m >> 2;\n\
    \    mod_t dw = roots[mod_t::level - e];\n    if (sign < 0) dw = dw.inverse();\n\
    \    const int block_size = std::max(m, (1 << 15) / int(sizeof(A[0])));\n    for\
    \ (int k = 0; k < n; k += block_size) {\n      mod_t w = one, w2 = one, w3 = one;\n\
    \      for (int j = 0; j < m4; j++) {\n        for (int i = k + j; i < k + block_size;\
    \ i += m) {\n          mod_t a0 = A[i + m4 * 0] * one, a2 = A[i + m4 * 1] * w2;\n\
    \          mod_t a1 = A[i + m4 * 2] * w, a3 = A[i + m4 * 3] * w3;\n          mod_t\
    \ t02 = a0 + a2, t13 = a1 + a3;\n          A[i + m4 * 0] = t02 + t13, A[i + m4\
    \ * 2] = t02 - t13;\n          t02 = a0 - a2, t13 = (a1 - a3) * imag;\n      \
    \    A[i + m4 * 1] = t02 + t13, A[i + m4 * 3] = t02 - t13;\n        }\n      \
    \  w *= dw, w2 = w * w, w3 = w2 * w;\n      }\n    }\n  }\n}\n\nconst int size\
    \ = 1 << 22;\nModB ff[size], gg[size];\n}  // namespace ntt\n\nstruct BigInt {\n\
    \  constexpr static std::int64_t base = 1000000000, base_digits = 9;\n\n private:\n\
    \  bool minus;\n  std::vector<std::int64_t> dat;\n\n public:\n  BigInt() : minus(false),\
    \ dat() {}\n  BigInt(std::int64_t v) { *this = v; }\n  BigInt(const std::string\
    \ &s) { read(s); }\n\n public:\n  void shrink() {\n    while (dat.size() && !dat.back())\
    \ dat.pop_back();\n    if (dat.empty()) minus = false;\n  }\n  void read(const\
    \ std::string &s) {\n    minus = false;\n    dat.clear();\n    std::int64_t pos\
    \ = 0;\n    while (pos < (std::int64_t)s.size() && (s[pos] == '-' || s[pos] ==\
    \ '+')) {\n      if (s[pos] == '-') minus = !minus;\n      ++pos;\n    }\n   \
    \ for (std::int64_t i = s.size() - 1; i >= pos; i -= base_digits) {\n      std::int64_t\
    \ x = 0;\n      for (std::int64_t j = std::max(pos, i - base_digits + 1); j <=\
    \ i; j++)\n        x = x * 10 + s[j] - '0';\n      dat.push_back(x);\n    }\n\
    \    shrink();\n  }\n  std::string to_string() const {\n    std::stringstream\
    \ ss;\n    if (minus) ss << '-';\n    ss << (dat.empty() ? 0 : dat.back());\n\
    \    for (std::int64_t i = (std::int64_t)dat.size() - 2; i >= 0; --i)\n      ss\
    \ << std::setw(base_digits) << std::setfill('0') << dat[i];\n    std::string ret;\n\
    \    ss >> ret;\n    return ret;\n  }\n  int convert_int() const { return stoi(this->to_string());\
    \ }\n  long long convert_ll() const { return stoll(this->to_string()); }\n  BigInt\
    \ &operator=(std::int64_t v) {\n    minus = false;\n    dat.clear();\n    if (v\
    \ < 0) minus = true, v = -v;\n    for (; v > 0; v = v / base) dat.push_back(v\
    \ % base);\n    return *this;\n  }\n  bool is_zero() const { return dat.empty()\
    \ || (dat.size() == 1 && !dat[0]); }\n  BigInt operator>>(std::size_t size) const\
    \ {\n    if (dat.size() <= size) return {};\n    BigInt ret;\n    ret.dat = std::vector<std::int64_t>(dat.begin()\
    \ + size, dat.end());\n    return ret;\n  }\n  BigInt operator<<(std::size_t size)\
    \ const {\n    BigInt ret(*this);\n    ret.dat.insert(ret.dat.begin(), size, 0);\n\
    \    return ret;\n  }\n\n private:\n  static std::vector<std::int64_t> mul_n(const\
    \ std::vector<std::int64_t> &f,\n                                         const\
    \ std::vector<std::int64_t> &g) {\n    std::vector<std::int64_t> ret(f.size()\
    \ + g.size() - 1, 0);\n    for (std::size_t i = 0; i < f.size(); i++)\n      for\
    \ (std::size_t j = 0; j < g.size(); j++) ret[i + j] += f[i] * g[j];\n    return\
    \ ret;\n  }\n  static void conv(const std::vector<std::int64_t> &f,\n        \
    \           const std::vector<std::int64_t> &g, bool cyclic = false) {\n    using\
    \ namespace ntt;\n    for (int i = 0; i < (int)f.size(); i++) ff[i] = f[i];\n\
    \    if (&f == &g) {\n      convolute(ff, f.size(), ff, f.size(), cyclic);\n \
    \   } else {\n      for (int i = 0; i < (int)g.size(); i++) gg[i] = g[i];\n  \
    \    convolute(ff, f.size(), gg, g.size(), cyclic);\n    }\n  }\n  static std::vector<std::int64_t>\
    \ convert_base(\n      const std::vector<std::int64_t> &a, std::int64_t old_digits,\n\
    \      std::int64_t new_digits) {\n    std::vector<std::int64_t> p(std::max(old_digits,\
    \ new_digits) + 1);\n    p[0] = 1;\n    for (std::int64_t i = 1; i < (std::int64_t)p.size();\
    \ i++)\n      p[i] = p[i - 1] * 10;\n    std::vector<std::int64_t> res;\n    std::int64_t\
    \ cur = 0;\n    std::int64_t cur_digits = 0;\n    for (std::int64_t i = 0; i <\
    \ (std::int64_t)a.size(); i++) {\n      cur += a[i] * p[cur_digits];\n      cur_digits\
    \ += old_digits;\n      while (cur_digits >= new_digits) {\n        res.push_back((cur\
    \ % p[new_digits]));\n        cur /= p[new_digits];\n        cur_digits -= new_digits;\n\
    \      }\n    }\n    res.push_back(cur);\n    while (!res.empty() && !res.back())\
    \ res.pop_back();\n    return res;\n  }\n  BigInt mul(const BigInt &v) const {\n\
    \    if (this->is_zero() || v.is_zero()) return BigInt();\n    constexpr static\
    \ std::int64_t nbase = 10000, nbase_digits = 4;\n    std::vector<std::int64_t>\
    \ f\n        = convert_base(this->dat, base_digits, nbase_digits);\n    std::vector<std::int64_t>\
    \ g\n        = convert_base(v.dat, base_digits, nbase_digits);\n    while (f.size()\
    \ < g.size()) f.push_back(0);\n    while (g.size() < f.size()) g.push_back(0);\n\
    \    while (f.size() & (f.size() - 1)) f.push_back(0), g.push_back(0);\n    std::vector<std::int64_t>\
    \ h;\n    if (f.size() + g.size() < 750 || f.size() < 8 || g.size() < 8) {\n \
    \     h = mul_n(f, g);\n    } else {\n      using namespace ntt;\n      h.resize(f.size()\
    \ + g.size() - 1);\n      conv(f, g, false);\n      for (std::size_t i = 0; i\
    \ < h.size(); i++) h[i] = ff[i].get();\n    }\n    BigInt res = 0;\n    res.minus\
    \ = minus ^ v.minus;\n    for (std::int64_t i = 0, carry = 0; i < (std::int64_t)h.size();\
    \ i++) {\n      std::int64_t cur = h[i] + carry;\n      res.dat.push_back((std::int64_t)(cur\
    \ % nbase));\n      carry = (std::int64_t)(cur / nbase);\n      if (i + 1 == (int)h.size()\
    \ && carry > 0) h.push_back(0);\n    }\n    res.dat = convert_base(res.dat, nbase_digits,\
    \ base_digits);\n    res.shrink();\n    return res;\n  }\n  static std::pair<BigInt,\
    \ BigInt> divmod(const BigInt &a1, const BigInt &b1) {\n    std::int64_t norm\
    \ = base / (b1.dat.back() + 1);\n    BigInt a = a1.abs() * norm;\n    BigInt b\
    \ = b1.abs() * norm;\n    BigInt q, r;\n    q.dat.resize(a.dat.size());\n    for\
    \ (std::int64_t i = a.dat.size() - 1; i >= 0; i--) {\n      r *= base;\n     \
    \ r += a.dat[i];\n      std::int64_t s1 = r.dat.size() <= b.dat.size() ? 0 : r.dat[b.dat.size()];\n\
    \      std::int64_t s2\n          = r.dat.size() <= b.dat.size() - 1 ? 0 : r.dat[b.dat.size()\
    \ - 1];\n      std::int64_t d = ((std::int64_t)base * s1 + s2) / b.dat.back();\n\
    \      r -= b * d;\n      while (r < 0) r += b, --d;\n      q.dat[i] = d;\n  \
    \  }\n    q.minus = a1.minus ^ b1.minus;\n    r.minus = a1.minus;\n    q.shrink(),\
    \ r.shrink();\n    return std::make_pair(q, r / norm);\n  }\n  BigInt quo(const\
    \ BigInt &b) const {\n    std::size_t preci = dat.size() - b.dat.size();\n   \
    \ BigInt t(1);\n    BigInt pre;\n    std::size_t lim = min(int(preci), 3);\n \
    \   std::size_t blim = min(int(b.dat.size()), 6);\n    t = t << lim;\n    while\
    \ (pre != t) {\n      BigInt rb = b >> (b.dat.size() - blim);\n      if (blim\
    \ != b.dat.size()) rb += BigInt(1);\n      pre = t;\n      t *= (BigInt(2) <<\
    \ (blim + lim)) - rb * t;\n      t.dat\n          = std::vector<std::int64_t>(t.dat.begin()\
    \ + lim + blim, t.dat.end());\n    }\n    if (lim != preci) {\n      pre = BigInt();\n\
    \      while (pre != t) {\n        BigInt rb = b >> (b.dat.size() - blim);\n \
    \       if (blim != b.dat.size()) rb += BigInt({1});\n        pre = t;\n     \
    \   t *= (BigInt(2) << (blim + lim)) - rb * t;\n        t.dat = std::vector<std::int64_t>(t.dat.begin()\
    \ + lim + blim,\n                                          t.dat.end());\n   \
    \     std::size_t next_lim = min(lim * 2 + 1, preci);\n        if (next_lim !=\
    \ lim) t = t << next_lim - lim;\n        std::size_t next_blim = min(blim * 2\
    \ + 1, b.dat.size());\n        lim = next_lim;\n        blim = next_blim;\n  \
    \    }\n    }\n    BigInt ret = this->abs() * t;\n    ret.dat = std::vector<std::int64_t>(ret.dat.begin()\
    \ + dat.size(),\n                                        ret.dat.end());\n   \
    \ while ((ret + BigInt(1)) * b <= this->abs()) ret += BigInt(1);\n    ret.minus\
    \ = this->minus ^ b.minus;\n    ret.shrink();\n    return ret;\n  }\n\n public:\n\
    \  bool operator<(const BigInt &v) const {\n    if (minus != v.minus) return minus;\n\
    \    if (dat.size() != v.dat.size()) return (dat.size() < v.dat.size()) ^ minus;\n\
    \    for (std::int64_t i = dat.size() - 1; i >= 0; i--)\n      if (dat[i] != v.dat[i])\
    \ return (dat[i] < v.dat[i]) ^ minus;\n    return false;\n  }\n  bool operator>(const\
    \ BigInt &v) const { return v < *this; }\n  bool operator<=(const BigInt &v) const\
    \ { return !(v < *this); }\n  bool operator>=(const BigInt &v) const { return\
    \ !(*this < v); }\n  bool operator==(const BigInt &v) const {\n    return minus\
    \ == v.minus && dat == v.dat;\n  }\n  bool operator!=(const BigInt &v) const {\
    \ return !(*this == v); }\n\n public:\n  friend std::istream &operator>>(std::istream\
    \ &stream, BigInt &v) {\n    std::string s;\n    stream >> s;\n    v.read(s);\n\
    \    return stream;\n  }\n  friend std::ostream &operator<<(std::ostream &stream,\
    \ const BigInt &v) {\n    stream << v.to_string();\n    return stream;\n  }\n\
    \  BigInt abs() const {\n    BigInt res = *this;\n    res.minus = false;\n   \
    \ return res;\n  }\n  BigInt operator-() const {\n    BigInt res = *this;\n  \
    \  res.minus = !res.minus;\n    return res;\n  }\n  BigInt &operator*=(std::int64_t\
    \ v) {\n    if (v < 0) minus = !minus, v = -v;\n    for (std::int64_t i = 0, carry\
    \ = 0; i < (std::int64_t)dat.size() || carry;\n         ++i) {\n      if (i ==\
    \ (std::int64_t)dat.size()) dat.push_back(0);\n      std::int64_t cur = dat[i]\
    \ * (std::int64_t)v + carry;\n      carry = (std::int64_t)(cur / base);\n    \
    \  dat[i] = (std::int64_t)(cur % base);\n    }\n    shrink();\n    return *this;\n\
    \  }\n  BigInt operator*(std::int64_t v) const { return BigInt(*this) *= v; }\n\
    \  BigInt &operator/=(std::int64_t v) {\n    if (v < 0) minus = !minus, v = -v;\n\
    \    for (std::int64_t i = (std::int64_t)dat.size() - 1, rem = 0; i >= 0; --i)\
    \ {\n      std::int64_t cur = dat[i] + rem * (std::int64_t)base;\n      dat[i]\
    \ = (std::int64_t)(cur / v);\n      rem = (std::int64_t)(cur % v);\n    }\n  \
    \  shrink();\n    return *this;\n  }\n  BigInt operator/(std::int64_t v) const\
    \ { return BigInt(*this) /= v; }\n  std::int64_t operator%(std::int64_t v) const\
    \ {\n    assert(v > 0 && !minus);\n    std::int64_t ret = 0;\n    for (std::int64_t\
    \ i = dat.size() - 1; i >= 0; --i)\n      ret = (dat[i] + ret * (std::int64_t)base)\
    \ % v;\n    return ret;\n  }\n  BigInt operator+(const BigInt &v) const {\n  \
    \  if (minus != v.minus) return *this - (-v);\n    BigInt res = v;\n    for (std::int64_t\
    \ i = 0, carry = 0;\n         i < (std::int64_t)std::max(dat.size(), v.dat.size())\
    \ || carry; ++i) {\n      if (i == (std::int64_t)res.dat.size()) res.dat.push_back(0);\n\
    \      res.dat[i] += carry + (i < (std::int64_t)dat.size() ? dat[i] : 0);\n  \
    \    carry = res.dat[i] >= base;\n      if (carry) res.dat[i] -= base;\n    }\n\
    \    return res;\n  }\n  BigInt operator-(const BigInt &v) const {\n    if (minus\
    \ != v.minus) return *this + (-v);\n    if (abs() < v.abs()) return -(v - *this);\n\
    \    BigInt res = *this;\n    for (std::int64_t i = 0, carry = 0; i < (std::int64_t)v.dat.size()\
    \ || carry;\n         ++i) {\n      res.dat[i] -= carry + (i < (std::int64_t)v.dat.size()\
    \ ? v.dat[i] : 0);\n      carry = res.dat[i] < 0;\n      if (carry) res.dat[i]\
    \ += base;\n    }\n    res.shrink();\n    return res;\n  }\n  BigInt operator*(const\
    \ BigInt &v) const { return this->mul(v); }\n  BigInt operator/(const BigInt &v)\
    \ const {\n    if (this->abs() < v.abs()) return BigInt(0);\n    return dat.size()\
    \ < 730 ? divmod(*this, v).first : quo(v);\n  }\n  BigInt operator%(const BigInt\
    \ &v) const {\n    if (this->abs() < v.abs()) return *this;\n    return dat.size()\
    \ < 730 ? divmod(*this, v).second : *this - v * quo(v);\n  }\n  BigInt &operator+=(const\
    \ BigInt &v) { return *this = *this + v; }\n  BigInt &operator-=(const BigInt\
    \ &v) { return *this = *this - v; }\n  BigInt &operator*=(const BigInt &v) { return\
    \ *this = *this * v; }\n  BigInt &operator/=(const BigInt &v) { return *this =\
    \ *this / v; }\n  BigInt &operator%=(const BigInt &v) { return *this = *this %\
    \ v; }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u591A\u500D\u9577\
    \u6574\u6570\n * @category \u6570\u5B66\n * python\u306E\u591A\u500D\u9577\u6574\
    \u6570\u3092\u4F7F\u3046\u3079\u304D\n */\n\n// BEGIN CUT HERE\n\nnamespace ntt\
    \ {\nstruct ModB {\n  static constexpr std::uint64_t mask = (1ull << 32) - 1;\n\
    \  static constexpr std::uint64_t mod = (((1ull << 32) - 1) << 32) + 1;\n  static\
    \ constexpr std::uint64_t prim_root = 7;\n  static constexpr int level = 32;\n\
    \  std::uint64_t x;\n  ModB() : x(0) {}\n  ModB(std::uint64_t n) : x(n >= mod\
    \ ? n - mod : n) {}\n  static constexpr std::uint64_t modulo() { return mod; }\n\
    \  static ModB omega() { return ModB(prim_root).pow(mask); }\n  std::uint64_t\
    \ get() const { return this->x; }\n  ModB operator+(ModB rhs) const {\n    std::uint64_t\
    \ tmp = mod - rhs.x;\n    return ModB(this->x >= tmp ? this->x - tmp : this->x\
    \ + rhs.x);\n  }\n  ModB operator-(ModB rhs) const {\n    return ModB(this->x\
    \ < rhs.x ? this->x + (mod - rhs.x) : this->x - rhs.x);\n  }\n  ModB operator*(ModB\
    \ rhs) const {\n    std::uint64_t lu = this->x >> 32, ld = uint32_t(this->x);\n\
    \    std::uint64_t ru = rhs.x >> 32, rd = uint32_t(rhs.x);\n    std::uint64_t\
    \ a = lu * ru, c = ld * ru, d = ld * rd;\n    std::uint64_t b = lu * rd + (d >>\
    \ 32);\n    std::uint64_t x = ~b;\n    if (c <= x) {\n      c += b;\n      a +=\
    \ c >> 32;\n    } else {\n      c -= x + 1;\n      a += (c >> 32) + (1ull << 32);\n\
    \    }\n    d = uint32_t(a) * mask + uint32_t(d);\n    c = (std::uint64_t(uint32_t(c))\
    \ << 32);\n    c = c ? c - (a >> 32) : mod - (a >> 32);\n    b = mod - c;\n  \
    \  return (d < b) ? ModB(d + c) : ModB(d - b);\n  }\n  ModB &operator+=(ModB rhs)\
    \ { return *this = *this + rhs; }\n  ModB &operator-=(ModB rhs) { return *this\
    \ = *this - rhs; }\n  ModB &operator*=(ModB rhs) { return *this = *this * rhs;\
    \ }\n  ModB pow(std::uint64_t exp) const {\n    ModB ret = ModB(1);\n    for (ModB\
    \ base = *this; exp; exp >>= 1, base *= base)\n      if (exp & 1) ret *= base;\n\
    \    return ret;\n  }\n  ModB inverse() const { return pow(mod - 2); }\n  bool\
    \ operator==(const ModB &p) const { return x == p.x; }\n  bool operator!=(const\
    \ ModB &p) const { return x != p.x; }\n};\n\ntemplate <typename mod_t>\nvoid convolute(mod_t\
    \ *A, int s1, mod_t *B, int s2, bool cyclic = false) {\n  int s = (cyclic ? std::max(s1,\
    \ s2) : s1 + s2 - 1);\n  int size = 1;\n  while (size < s) size <<= 1;\n  mod_t\
    \ roots[mod_t::level] = {mod_t::omega()};\n  for (int i = 1; i < mod_t::level;\
    \ i++) roots[i] = roots[i - 1] * roots[i - 1];\n  std::fill(A + s1, A + size,\
    \ 0);\n  ntt_dit4(A, size, 1, roots);\n  if (A == B && s1 == s2) {\n    for (int\
    \ i = 0; i < size; i++) A[i] *= A[i];\n  } else {\n    std::fill(B + s2, B + size,\
    \ 0);\n    ntt_dit4(B, size, 1, roots);\n    for (int i = 0; i < size; i++) A[i]\
    \ *= B[i];\n  }\n  ntt_dit4(A, size, -1, roots);\n  mod_t inv = mod_t(size).inverse();\n\
    \  for (int i = 0; i < (cyclic ? size : s); i++) A[i] *= inv;\n}\n\ntemplate <typename\
    \ mod_t>\nvoid rev_permute(mod_t *A, int n) {\n  int r = 0, nh = n >> 1;\n  for\
    \ (int i = 1; i < n; i++) {\n    int h = nh;\n    while (!((r ^= h) & h)) h >>=\
    \ 1;\n    if (r > i) srd::swap(A[i], A[r]);\n  }\n}\n\ntemplate <typename mod_t>\n\
    void ntt_dit4(mod_t *A, int n, int sign, mod_t *roots) {\n  rev_permute(A, n);\n\
    \  int logn = __builtin_ctz(n);\n  if (logn & 1)\n    for (int i = 0; i < n; i\
    \ += 2) {\n      mod_t a = A[i], b = A[i + 1];\n      A[i] = a + b, A[i + 1] =\
    \ a - b;\n    }\n  mod_t imag = roots[mod_t::level - 2];\n  if (sign < 0) imag\
    \ = imag.inverse();\n  mod_t one = mod_t(1);\n  for (int e = 2 + (logn & 1); e\
    \ < logn + 1; e += 2) {\n    const int m = 1 << e;\n    const int m4 = m >> 2;\n\
    \    mod_t dw = roots[mod_t::level - e];\n    if (sign < 0) dw = dw.inverse();\n\
    \    const int block_size = std::max(m, (1 << 15) / int(sizeof(A[0])));\n    for\
    \ (int k = 0; k < n; k += block_size) {\n      mod_t w = one, w2 = one, w3 = one;\n\
    \      for (int j = 0; j < m4; j++) {\n        for (int i = k + j; i < k + block_size;\
    \ i += m) {\n          mod_t a0 = A[i + m4 * 0] * one, a2 = A[i + m4 * 1] * w2;\n\
    \          mod_t a1 = A[i + m4 * 2] * w, a3 = A[i + m4 * 3] * w3;\n          mod_t\
    \ t02 = a0 + a2, t13 = a1 + a3;\n          A[i + m4 * 0] = t02 + t13, A[i + m4\
    \ * 2] = t02 - t13;\n          t02 = a0 - a2, t13 = (a1 - a3) * imag;\n      \
    \    A[i + m4 * 1] = t02 + t13, A[i + m4 * 3] = t02 - t13;\n        }\n      \
    \  w *= dw, w2 = w * w, w3 = w2 * w;\n      }\n    }\n  }\n}\n\nconst int size\
    \ = 1 << 22;\nModB ff[size], gg[size];\n}  // namespace ntt\n\nstruct BigInt {\n\
    \  constexpr static std::int64_t base = 1000000000, base_digits = 9;\n\n private:\n\
    \  bool minus;\n  std::vector<std::int64_t> dat;\n\n public:\n  BigInt() : minus(false),\
    \ dat() {}\n  BigInt(std::int64_t v) { *this = v; }\n  BigInt(const std::string\
    \ &s) { read(s); }\n\n public:\n  void shrink() {\n    while (dat.size() && !dat.back())\
    \ dat.pop_back();\n    if (dat.empty()) minus = false;\n  }\n  void read(const\
    \ std::string &s) {\n    minus = false;\n    dat.clear();\n    std::int64_t pos\
    \ = 0;\n    while (pos < (std::int64_t)s.size() && (s[pos] == '-' || s[pos] ==\
    \ '+')) {\n      if (s[pos] == '-') minus = !minus;\n      ++pos;\n    }\n   \
    \ for (std::int64_t i = s.size() - 1; i >= pos; i -= base_digits) {\n      std::int64_t\
    \ x = 0;\n      for (std::int64_t j = std::max(pos, i - base_digits + 1); j <=\
    \ i; j++)\n        x = x * 10 + s[j] - '0';\n      dat.push_back(x);\n    }\n\
    \    shrink();\n  }\n  std::string to_string() const {\n    std::stringstream\
    \ ss;\n    if (minus) ss << '-';\n    ss << (dat.empty() ? 0 : dat.back());\n\
    \    for (std::int64_t i = (std::int64_t)dat.size() - 2; i >= 0; --i)\n      ss\
    \ << std::setw(base_digits) << std::setfill('0') << dat[i];\n    std::string ret;\n\
    \    ss >> ret;\n    return ret;\n  }\n  int convert_int() const { return stoi(this->to_string());\
    \ }\n  long long convert_ll() const { return stoll(this->to_string()); }\n  BigInt\
    \ &operator=(std::int64_t v) {\n    minus = false;\n    dat.clear();\n    if (v\
    \ < 0) minus = true, v = -v;\n    for (; v > 0; v = v / base) dat.push_back(v\
    \ % base);\n    return *this;\n  }\n  bool is_zero() const { return dat.empty()\
    \ || (dat.size() == 1 && !dat[0]); }\n  BigInt operator>>(std::size_t size) const\
    \ {\n    if (dat.size() <= size) return {};\n    BigInt ret;\n    ret.dat = std::vector<std::int64_t>(dat.begin()\
    \ + size, dat.end());\n    return ret;\n  }\n  BigInt operator<<(std::size_t size)\
    \ const {\n    BigInt ret(*this);\n    ret.dat.insert(ret.dat.begin(), size, 0);\n\
    \    return ret;\n  }\n\n private:\n  static std::vector<std::int64_t> mul_n(const\
    \ std::vector<std::int64_t> &f,\n                                         const\
    \ std::vector<std::int64_t> &g) {\n    std::vector<std::int64_t> ret(f.size()\
    \ + g.size() - 1, 0);\n    for (std::size_t i = 0; i < f.size(); i++)\n      for\
    \ (std::size_t j = 0; j < g.size(); j++) ret[i + j] += f[i] * g[j];\n    return\
    \ ret;\n  }\n  static void conv(const std::vector<std::int64_t> &f,\n        \
    \           const std::vector<std::int64_t> &g, bool cyclic = false) {\n    using\
    \ namespace ntt;\n    for (int i = 0; i < (int)f.size(); i++) ff[i] = f[i];\n\
    \    if (&f == &g) {\n      convolute(ff, f.size(), ff, f.size(), cyclic);\n \
    \   } else {\n      for (int i = 0; i < (int)g.size(); i++) gg[i] = g[i];\n  \
    \    convolute(ff, f.size(), gg, g.size(), cyclic);\n    }\n  }\n  static std::vector<std::int64_t>\
    \ convert_base(\n      const std::vector<std::int64_t> &a, std::int64_t old_digits,\n\
    \      std::int64_t new_digits) {\n    std::vector<std::int64_t> p(std::max(old_digits,\
    \ new_digits) + 1);\n    p[0] = 1;\n    for (std::int64_t i = 1; i < (std::int64_t)p.size();\
    \ i++)\n      p[i] = p[i - 1] * 10;\n    std::vector<std::int64_t> res;\n    std::int64_t\
    \ cur = 0;\n    std::int64_t cur_digits = 0;\n    for (std::int64_t i = 0; i <\
    \ (std::int64_t)a.size(); i++) {\n      cur += a[i] * p[cur_digits];\n      cur_digits\
    \ += old_digits;\n      while (cur_digits >= new_digits) {\n        res.push_back((cur\
    \ % p[new_digits]));\n        cur /= p[new_digits];\n        cur_digits -= new_digits;\n\
    \      }\n    }\n    res.push_back(cur);\n    while (!res.empty() && !res.back())\
    \ res.pop_back();\n    return res;\n  }\n  BigInt mul(const BigInt &v) const {\n\
    \    if (this->is_zero() || v.is_zero()) return BigInt();\n    constexpr static\
    \ std::int64_t nbase = 10000, nbase_digits = 4;\n    std::vector<std::int64_t>\
    \ f\n        = convert_base(this->dat, base_digits, nbase_digits);\n    std::vector<std::int64_t>\
    \ g\n        = convert_base(v.dat, base_digits, nbase_digits);\n    while (f.size()\
    \ < g.size()) f.push_back(0);\n    while (g.size() < f.size()) g.push_back(0);\n\
    \    while (f.size() & (f.size() - 1)) f.push_back(0), g.push_back(0);\n    std::vector<std::int64_t>\
    \ h;\n    if (f.size() + g.size() < 750 || f.size() < 8 || g.size() < 8) {\n \
    \     h = mul_n(f, g);\n    } else {\n      using namespace ntt;\n      h.resize(f.size()\
    \ + g.size() - 1);\n      conv(f, g, false);\n      for (std::size_t i = 0; i\
    \ < h.size(); i++) h[i] = ff[i].get();\n    }\n    BigInt res = 0;\n    res.minus\
    \ = minus ^ v.minus;\n    for (std::int64_t i = 0, carry = 0; i < (std::int64_t)h.size();\
    \ i++) {\n      std::int64_t cur = h[i] + carry;\n      res.dat.push_back((std::int64_t)(cur\
    \ % nbase));\n      carry = (std::int64_t)(cur / nbase);\n      if (i + 1 == (int)h.size()\
    \ && carry > 0) h.push_back(0);\n    }\n    res.dat = convert_base(res.dat, nbase_digits,\
    \ base_digits);\n    res.shrink();\n    return res;\n  }\n  static std::pair<BigInt,\
    \ BigInt> divmod(const BigInt &a1, const BigInt &b1) {\n    std::int64_t norm\
    \ = base / (b1.dat.back() + 1);\n    BigInt a = a1.abs() * norm;\n    BigInt b\
    \ = b1.abs() * norm;\n    BigInt q, r;\n    q.dat.resize(a.dat.size());\n    for\
    \ (std::int64_t i = a.dat.size() - 1; i >= 0; i--) {\n      r *= base;\n     \
    \ r += a.dat[i];\n      std::int64_t s1 = r.dat.size() <= b.dat.size() ? 0 : r.dat[b.dat.size()];\n\
    \      std::int64_t s2\n          = r.dat.size() <= b.dat.size() - 1 ? 0 : r.dat[b.dat.size()\
    \ - 1];\n      std::int64_t d = ((std::int64_t)base * s1 + s2) / b.dat.back();\n\
    \      r -= b * d;\n      while (r < 0) r += b, --d;\n      q.dat[i] = d;\n  \
    \  }\n    q.minus = a1.minus ^ b1.minus;\n    r.minus = a1.minus;\n    q.shrink(),\
    \ r.shrink();\n    return std::make_pair(q, r / norm);\n  }\n  BigInt quo(const\
    \ BigInt &b) const {\n    std::size_t preci = dat.size() - b.dat.size();\n   \
    \ BigInt t(1);\n    BigInt pre;\n    std::size_t lim = min(int(preci), 3);\n \
    \   std::size_t blim = min(int(b.dat.size()), 6);\n    t = t << lim;\n    while\
    \ (pre != t) {\n      BigInt rb = b >> (b.dat.size() - blim);\n      if (blim\
    \ != b.dat.size()) rb += BigInt(1);\n      pre = t;\n      t *= (BigInt(2) <<\
    \ (blim + lim)) - rb * t;\n      t.dat\n          = std::vector<std::int64_t>(t.dat.begin()\
    \ + lim + blim, t.dat.end());\n    }\n    if (lim != preci) {\n      pre = BigInt();\n\
    \      while (pre != t) {\n        BigInt rb = b >> (b.dat.size() - blim);\n \
    \       if (blim != b.dat.size()) rb += BigInt({1});\n        pre = t;\n     \
    \   t *= (BigInt(2) << (blim + lim)) - rb * t;\n        t.dat = std::vector<std::int64_t>(t.dat.begin()\
    \ + lim + blim,\n                                          t.dat.end());\n   \
    \     std::size_t next_lim = min(lim * 2 + 1, preci);\n        if (next_lim !=\
    \ lim) t = t << next_lim - lim;\n        std::size_t next_blim = min(blim * 2\
    \ + 1, b.dat.size());\n        lim = next_lim;\n        blim = next_blim;\n  \
    \    }\n    }\n    BigInt ret = this->abs() * t;\n    ret.dat = std::vector<std::int64_t>(ret.dat.begin()\
    \ + dat.size(),\n                                        ret.dat.end());\n   \
    \ while ((ret + BigInt(1)) * b <= this->abs()) ret += BigInt(1);\n    ret.minus\
    \ = this->minus ^ b.minus;\n    ret.shrink();\n    return ret;\n  }\n\n public:\n\
    \  bool operator<(const BigInt &v) const {\n    if (minus != v.minus) return minus;\n\
    \    if (dat.size() != v.dat.size()) return (dat.size() < v.dat.size()) ^ minus;\n\
    \    for (std::int64_t i = dat.size() - 1; i >= 0; i--)\n      if (dat[i] != v.dat[i])\
    \ return (dat[i] < v.dat[i]) ^ minus;\n    return false;\n  }\n  bool operator>(const\
    \ BigInt &v) const { return v < *this; }\n  bool operator<=(const BigInt &v) const\
    \ { return !(v < *this); }\n  bool operator>=(const BigInt &v) const { return\
    \ !(*this < v); }\n  bool operator==(const BigInt &v) const {\n    return minus\
    \ == v.minus && dat == v.dat;\n  }\n  bool operator!=(const BigInt &v) const {\
    \ return !(*this == v); }\n\n public:\n  friend std::istream &operator>>(std::istream\
    \ &stream, BigInt &v) {\n    std::string s;\n    stream >> s;\n    v.read(s);\n\
    \    return stream;\n  }\n  friend std::ostream &operator<<(std::ostream &stream,\
    \ const BigInt &v) {\n    stream << v.to_string();\n    return stream;\n  }\n\
    \  BigInt abs() const {\n    BigInt res = *this;\n    res.minus = false;\n   \
    \ return res;\n  }\n  BigInt operator-() const {\n    BigInt res = *this;\n  \
    \  res.minus = !res.minus;\n    return res;\n  }\n  BigInt &operator*=(std::int64_t\
    \ v) {\n    if (v < 0) minus = !minus, v = -v;\n    for (std::int64_t i = 0, carry\
    \ = 0; i < (std::int64_t)dat.size() || carry;\n         ++i) {\n      if (i ==\
    \ (std::int64_t)dat.size()) dat.push_back(0);\n      std::int64_t cur = dat[i]\
    \ * (std::int64_t)v + carry;\n      carry = (std::int64_t)(cur / base);\n    \
    \  dat[i] = (std::int64_t)(cur % base);\n    }\n    shrink();\n    return *this;\n\
    \  }\n  BigInt operator*(std::int64_t v) const { return BigInt(*this) *= v; }\n\
    \  BigInt &operator/=(std::int64_t v) {\n    if (v < 0) minus = !minus, v = -v;\n\
    \    for (std::int64_t i = (std::int64_t)dat.size() - 1, rem = 0; i >= 0; --i)\
    \ {\n      std::int64_t cur = dat[i] + rem * (std::int64_t)base;\n      dat[i]\
    \ = (std::int64_t)(cur / v);\n      rem = (std::int64_t)(cur % v);\n    }\n  \
    \  shrink();\n    return *this;\n  }\n  BigInt operator/(std::int64_t v) const\
    \ { return BigInt(*this) /= v; }\n  std::int64_t operator%(std::int64_t v) const\
    \ {\n    assert(v > 0 && !minus);\n    std::int64_t ret = 0;\n    for (std::int64_t\
    \ i = dat.size() - 1; i >= 0; --i)\n      ret = (dat[i] + ret * (std::int64_t)base)\
    \ % v;\n    return ret;\n  }\n  BigInt operator+(const BigInt &v) const {\n  \
    \  if (minus != v.minus) return *this - (-v);\n    BigInt res = v;\n    for (std::int64_t\
    \ i = 0, carry = 0;\n         i < (std::int64_t)std::max(dat.size(), v.dat.size())\
    \ || carry; ++i) {\n      if (i == (std::int64_t)res.dat.size()) res.dat.push_back(0);\n\
    \      res.dat[i] += carry + (i < (std::int64_t)dat.size() ? dat[i] : 0);\n  \
    \    carry = res.dat[i] >= base;\n      if (carry) res.dat[i] -= base;\n    }\n\
    \    return res;\n  }\n  BigInt operator-(const BigInt &v) const {\n    if (minus\
    \ != v.minus) return *this + (-v);\n    if (abs() < v.abs()) return -(v - *this);\n\
    \    BigInt res = *this;\n    for (std::int64_t i = 0, carry = 0; i < (std::int64_t)v.dat.size()\
    \ || carry;\n         ++i) {\n      res.dat[i] -= carry + (i < (std::int64_t)v.dat.size()\
    \ ? v.dat[i] : 0);\n      carry = res.dat[i] < 0;\n      if (carry) res.dat[i]\
    \ += base;\n    }\n    res.shrink();\n    return res;\n  }\n  BigInt operator*(const\
    \ BigInt &v) const { return this->mul(v); }\n  BigInt operator/(const BigInt &v)\
    \ const {\n    if (this->abs() < v.abs()) return BigInt(0);\n    return dat.size()\
    \ < 730 ? divmod(*this, v).first : quo(v);\n  }\n  BigInt operator%(const BigInt\
    \ &v) const {\n    if (this->abs() < v.abs()) return *this;\n    return dat.size()\
    \ < 730 ? divmod(*this, v).second : *this - v * quo(v);\n  }\n  BigInt &operator+=(const\
    \ BigInt &v) { return *this = *this + v; }\n  BigInt &operator-=(const BigInt\
    \ &v) { return *this = *this - v; }\n  BigInt &operator*=(const BigInt &v) { return\
    \ *this = *this * v; }\n  BigInt &operator/=(const BigInt &v) { return *this =\
    \ *this / v; }\n  BigInt &operator%=(const BigInt &v) { return *this = *this %\
    \ v; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/BigInt.hpp
  requiredBy: []
  timestamp: '2020-10-24 17:22:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_2_E.test.cpp
  - test/aoj/NTL_2_B.test.cpp
  - test/aoj/NTL_2_A.test.cpp
  - test/aoj/NTL_2_C.test.cpp
  - test/aoj/NTL_2_D.test.cpp
  - test/aoj/NTL_2_F.test.cpp
documentation_of: src/Math/BigInt.hpp
layout: document
redirect_from:
- /library/src/Math/BigInt.hpp
- /library/src/Math/BigInt.hpp.html
title: "\u591A\u500D\u9577\u6574\u6570"
---
