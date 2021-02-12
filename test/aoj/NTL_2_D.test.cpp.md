---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/BigInt.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_D
  bundledCode: "#line 1 \"test/aoj/NTL_2_D.test.cpp\"\n#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_D\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t\
    \ mod, std::uint64_t prim_root = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n\
    \  using u128 = __uint128_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6,\
    \ u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n\
    \  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(u128(w) * r2); }\n  static\
    \ constexpr u64 reduce(const u128 w) {\n    return u64(w >> 64) + mod - ((u128(u64(w)\
    \ * inv) * mod) >> 64);\n  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt()\
    \ = default;\n  static constexpr u64 modulo() { return mod; }\n  static constexpr\
    \ u64 norm(u64 w) { return w - (mod & -(w >= mod)); }\n  static constexpr u64\
    \ pr_rt() { return prim_root; }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(u128(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return norm(x) != norm(rhs.x); }\n  u64 val() const {\n\
    \    u64 ret = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n\
    \  constexpr ModInt pow(u64 k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt\
    \ base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret *= base;\n   \
    \ return ret;\n  }\n  constexpr ModInt inverse() const { return pow(mod - 2);\
    \ }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0) || mod == 2)\
    \ return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n\
    \    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1)\
    \ == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt>\
    \ u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first + u.second\
    \ * v.second * w);\n      ModInt b = (u.first * v.second + u.second * v.first);\n\
    \      return std::make_pair(a, b);\n    };\n    u64 e = (mod + 1) >> 1;\n   \
    \ auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto bs = std::make_pair(b,\
    \ ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1) ret = mul(ret, bs);\n\
    \    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n  }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n  u64 x;\n};\n\
    #line 4 \"src/Math/BigInt.hpp\"\n/**\n * @title \u591A\u500D\u9577\u6574\u6570\
    \n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\nstruct BigInt {\n  static\
    \ constexpr int bdig = 26, base = 1 << bdig;\n  bool neg;\n\n private:\n  std::vector<unsigned>\
    \ dat;\n  using ModB = ModInt<4611615649683210241, 11>;\n  template <class mod_t>\n\
    \  static inline void idft(int n, mod_t x[]) {\n    static mod_t iW[1 << 20];\n\
    \    static constexpr std::uint64_t mod = mod_t::modulo();\n    static constexpr\
    \ mod_t G(mod_t::pr_rt());\n    static int lim = 0;\n    if (lim == 0) iW[0] =\
    \ 1, lim = 1;\n    for (int m = lim; m < n / 2; m *= 2) {\n      mod_t idw = G.pow(mod\
    \ - 1 - (mod - 1) / (4 * m));\n      for (int i = 0; i < m; i++) iW[m + i] = iW[i]\
    \ * idw;\n      lim = n / 2;\n    }\n    for (int m = 1; m < n; m *= 2)\n    \
    \  for (int s = 0, k = 0; s < n; s += 2 * m, ++k)\n        for (int i = s, j =\
    \ s + m; i < s + m; ++i, ++j) {\n          mod_t u = x[i], v = x[j];\n       \
    \   x[i] = u + v, x[j] = (u - v) * iW[k];\n        }\n    mod_t iv(mod - (mod\
    \ - 1) / n);\n    for (int i = 0; i < n; i++) x[i] *= iv;\n  }\n  template <class\
    \ mod_t>\n  static inline void dft(int n, mod_t x[]) {\n    static mod_t W[1 <<\
    \ 20];\n    static constexpr std::uint64_t mod = mod_t::modulo();\n    static\
    \ constexpr mod_t G(mod_t::pr_rt());\n    static int lim = 0;\n    if (lim ==\
    \ 0) W[0] = 1, lim = 1;\n    for (int m = lim; m < n / 2; m *= 2) {\n      mod_t\
    \ dw = G.pow((mod - 1) / (4 * m));\n      for (int i = 0; i < m; i++) W[m + i]\
    \ = W[i] * dw;\n      lim = n / 2;\n    }\n    for (int m = n; m >>= 1;)\n   \
    \   for (int s = 0, k = 0; s < n; s += 2 * m, ++k)\n        for (int i = s, j\
    \ = s + m; i < s + m; ++i, ++j) {\n          mod_t u = x[i], v = x[j] * W[k];\n\
    \          x[i] = u + v, x[j] = u - v;\n        }\n  }\n  static inline int get_len(int\
    \ n) {\n    return --n, n |= n >> 1, n |= n >> 2, n |= n >> 4, n |= n >> 8,\n\
    \           n |= n >> 16, ++n;\n  }\n  BigInt base_shift_r(int size) const {\n\
    \    BigInt ret;\n    return ret.dat = std::vector<unsigned>(dat.begin() + size,\
    \ dat.end()), ret;\n  }\n  BigInt base_shift_l(int size) const {\n    BigInt ret\
    \ = *this;\n    return ret.dat.insert(ret.dat.begin(), size, 0), ret;\n  }\n\n\
    \ public:\n  BigInt() : neg(false), dat() {}\n  BigInt(long long v) { *this =\
    \ v; }\n  BigInt(const std::string &s) { read(s); }\n  void shrink() {\n    while\
    \ (dat.size() && !dat.back()) dat.pop_back();\n    if (dat.empty()) neg = false;\n\
    \  }\n  bool is_zero() const { return dat.empty() || (dat.size() == 1 && !dat[0]);\
    \ }\n  bool able_ll() const {\n    return dat.size() <= 2\n           || (dat.size()\
    \ == 3 && !(dat.back() >> (63 - 2 * bdig)));\n  }\n  int ctz() const {\n    if\
    \ (is_zero()) return -1;\n    int ret = 0, i;\n    for (i = 0; i < (int)dat.size()\
    \ && !dat[i]; i++) ret += bdig;\n    return ret + __builtin_ctz(dat[i]);\n  }\n\
    \  void read(const std::string &s) {\n    dat.clear(), neg = s[0] == '-';\n  \
    \  std::vector<short> v;\n    for (int i = s.length() - 1; i >= 0 && '0' <= s[i]\
    \ && s[i] <= '9'; i--)\n      v.emplace_back(s[i] - '0');\n    for (int rem =\
    \ 0; !v.empty(); dat.emplace_back(rem), rem = 0) {\n      for (int i = v.size()\
    \ - 1, cur; i >= 0; i--)\n        cur = rem * 10 + v[i], v[i] = cur >> bdig, rem\
    \ = cur & (base - 1);\n      while (v.size() && !v.back()) v.pop_back();\n   \
    \ }\n  }\n  std::string to_str() const {\n    if (is_zero()) return \"0\";\n \
    \   auto v = dat;\n    std::string ret;\n    for (short rem = 0; !v.empty(); ret\
    \ += rem + '0', rem = 0) {\n      for (int i = v.size() - 1, cur; i >= 0; i--)\n\
    \        cur = (rem << bdig) + v[i], v[i] = cur / 10, rem = cur % 10;\n      while\
    \ (v.size() && !v.back()) v.pop_back();\n    }\n    if (neg) ret += '-';\n   \
    \ std::reverse(ret.begin(), ret.end());\n    return ret;\n  }\n  BigInt &operator=(long\
    \ long r) {\n    neg = false, dat.clear();\n    if (r < 0) neg = true, r = -r;\n\
    \    for (; r; r >>= bdig) dat.emplace_back(r & (base - 1));\n    return *this;\n\
    \  }\n  bool operator<(const BigInt &r) const {\n    if (neg != r.neg) return\
    \ neg;\n    if (dat.size() != r.dat.size()) return (dat.size() < r.dat.size())\
    \ ^ neg;\n    for (int i = dat.size() - 1; i >= 0; i--)\n      if (dat[i] != r.dat[i])\
    \ return (dat[i] < r.dat[i]) ^ neg;\n    return false;\n  }\n  bool operator>(const\
    \ BigInt &r) const { return r < *this; }\n  bool operator<=(const BigInt &r) const\
    \ { return !(r < *this); }\n  bool operator>=(const BigInt &r) const { return\
    \ !(*this < r); }\n  bool operator==(const BigInt &r) const {\n    return neg\
    \ == r.neg && dat == r.dat;\n  }\n  bool operator!=(const BigInt &r) const { return\
    \ !(*this == r); }\n  BigInt abs() const {\n    BigInt ret = *this;\n    return\
    \ ret.neg = false, ret;\n  }\n  BigInt operator-() const {\n    BigInt ret = *this;\n\
    \    return ret.neg = !ret.neg, ret;\n  }\n  BigInt operator+(const BigInt &r)\
    \ const {\n    if (neg != r.neg) return *this - (-r);\n    BigInt ret = r;\n \
    \   for (int i = 0, ed = std::max(dat.size(), r.dat.size()), carry = 0;\n    \
    \     i < ed || carry; i++) {\n      if (i == (int)ret.dat.size()) ret.dat.emplace_back(0);\n\
    \      ret.dat[i] += carry + (i < (int)dat.size() ? dat[i] : 0);\n      if ((carry\
    \ = (ret.dat[i] >= base))) ret.dat[i] -= base;\n    }\n    return ret;\n  }\n\
    \  BigInt operator-(const BigInt &r) const {\n    if (neg != r.neg) return *this\
    \ + (-r);\n    if (abs() < r.abs()) return -(r - *this);\n    BigInt ret = *this;\n\
    \    for (unsigned i = 0, carry = 0; i < r.dat.size() || carry; i++) {\n     \
    \ ret.dat[i] += base - (carry + (i < r.dat.size() ? r.dat[i] : 0));\n      if\
    \ (!(carry = (ret.dat[i] < base))) ret.dat[i] -= base;\n    }\n    return ret.shrink(),\
    \ ret;\n  }\n  BigInt &operator+=(const BigInt &r) { return *this = *this + r;\
    \ }\n  BigInt &operator-=(const BigInt &r) { return *this = *this - r; }\n  BigInt\
    \ &operator*=(long long r) {\n    if (r < 0) neg = !neg, r = -r;\n    for (long\
    \ long i = 0, carry = 0; i < (long long)dat.size() || carry; i++) {\n      if\
    \ (i == (long long)dat.size()) dat.emplace_back(0);\n      __uint128_t cur = (__uint128_t)r\
    \ * dat[i] + carry;\n      carry = cur >> bdig, dat[i] = cur & (base - 1);\n \
    \   }\n    return shrink(), *this;\n  }\n  BigInt &operator/=(long long r) {\n\
    \    if (r < 0) neg = !neg, r = -r;\n    for (__int128_t i = dat.size() - 1, cur,\
    \ rem = 0; i >= 0; i--)\n      cur = dat[i] + (rem << bdig), dat[i] = cur / r,\
    \ rem = cur % r;\n    return shrink(), *this;\n  }\n  long long operator%(long\
    \ long r) const {\n    long long ret = 0;\n    for (int i = dat.size(); i;)\n\
    \      ret = (dat[--i] + (__uint128_t(ret) << bdig)) % r;\n    return ret;\n \
    \ }\n  BigInt operator*(long long r) const { return BigInt(*this) *= r; }\n  BigInt\
    \ operator/(long long r) const { return BigInt(*this) /= r; }\n  BigInt operator*(const\
    \ BigInt &r) const {\n    static ModB f[1 << 20], g[1 << 20];\n    static long\
    \ long h[1 << 20];\n    int n = dat.size(), m = r.dat.size(), sz = n + m - 1;\n\
    \    if (n <= 8 || m <= 8) {\n      std::fill_n(h, sz, 0);\n      for (int i =\
    \ 0; i < n; i++)\n        for (int j = 0; j < m; j++) h[i + j] += (long long)dat[i]\
    \ * r.dat[j];\n    } else {\n      for (int i = 0; i < n; i++) f[i] = dat[i];\n\
    \      for (int i = 0; i < m; i++) g[i] = r.dat[i];\n      int len = get_len(sz);\n\
    \      std::fill(f + n, f + len, 0), std::fill(g + m, g + len, 0);\n      dft(len,\
    \ f), dft(len, g);\n      for (int i = 0; i < len; i++) f[i] *= g[i];\n      idft(len,\
    \ f);\n      for (int i = 0; i < sz; i++) h[i] = f[i].val();\n    }\n    BigInt\
    \ ret;\n    for (long long i = 0, carry = 0, cur; i < sz || carry; i++)\n    \
    \  cur = carry + (i < sz ? h[i] : 0), carry = cur >> bdig,\n      ret.dat.emplace_back(cur\
    \ & (base - 1));\n    return ret.neg = neg ^ r.neg, ret;\n  }\n  BigInt &operator*=(const\
    \ BigInt &r) { return *this = *this * r; }\n  BigInt operator/(const BigInt &r)\
    \ const {\n    if (r.dat.size() == 1 && r.dat.back() == 1) return *this;\n   \
    \ if (r.able_ll()) return *this / r.convert_ll();\n    static ModB f[1 << 20],\
    \ g[1 << 20];\n    int pb = dat.size(), qb = r.dat.size(), prec = std::max(pb\
    \ - qb, 1),\n        lim = std::min(prec, 3), rlim = std::min(qb, 6);\n    BigInt\
    \ x, prev, rr = r.base_shift_r(qb - rlim), c;\n    x.dat.resize(lim + 1, 0), x.dat.back()\
    \ = 1;\n    c.dat.resize(rlim + lim + 1, 0), c.dat.back() = 2;\n    while (x !=\
    \ prev) prev = x, x *= c - rr * x, x = x.base_shift_r(lim + rlim);\n    if (lim\
    \ != prec) {\n      for (prev.dat.clear(); x != prev;) {\n        prev = x;\n\
    \        int n = x.dat.size(), m = rr.dat.size(), sz = n + m - 1,\n          \
    \  len1 = get_len(sz), len2 = get_len(rlim + lim + n),\n            nlim = std::min(lim\
    \ * 2 + 1, prec),\n            nrlim = std::min(rlim * 2 + 1, qb);\n        for\
    \ (int i = 0; i < n; i++) g[i] = x.dat[i];\n        for (int i = 0; i < m; i++)\
    \ f[i] = rr.dat[i];\n        std::fill(g + n, g + len2, 0), std::fill(f + m, f\
    \ + len1, 0);\n        dft(len1, f), dft(len2, g);\n        for (int i = 0; i\
    \ < len1; i++) f[i] *= g[i];\n        idft(len1, f), x.dat.clear();\n        for\
    \ (long long i = 0, carry = 0, cur; i < sz || carry; i++)\n          cur = carry\
    \ + (i < sz ? f[i].val() : 0), carry = cur >> bdig,\n          x.dat.emplace_back(cur\
    \ & (base - 1));\n        x = c - x, m = x.dat.size(), sz = n + m - 1;\n     \
    \   for (int i = 0; i < m; i++) f[i] = x.dat[i];\n        std::fill(f + m, f +\
    \ len2, 0), dft(len2, f);\n        for (int i = 0; i < len2; i++) f[i] *= g[i];\n\
    \        idft(len2, f), x.dat.clear();\n        for (long long i = 0, carry =\
    \ 0, cur; i < sz || carry; i++) {\n          cur = carry + (i < sz ? f[i].val()\
    \ : 0), carry = cur >> bdig;\n          if (i >= 2 * lim - nlim + rlim) x.dat.emplace_back(cur\
    \ & (base - 1));\n        }\n        if (nrlim != rlim) rr = r.base_shift_r(qb\
    \ - nrlim);\n        if (nrlim != rlim || nlim != lim)\n          c.dat.back()\
    \ = 0, c.dat.resize(nrlim + nlim + 1, 0), c.dat.back() = 2;\n        lim = nlim,\
    \ rlim = nrlim;\n      }\n    }\n    x *= this->abs(), x = x.base_shift_r(pb +\
    \ (pb == qb));\n    if (this->abs() >= (x + 1) * r) x += 1;\n    return x.neg\
    \ = neg ^ r.neg, x.shrink(), x;\n  }\n  BigInt &operator/=(const BigInt &r) {\
    \ return *this = *this / r; }\n  BigInt &operator%=(const BigInt &r) { return\
    \ *this -= (*this / r) * r; }\n  BigInt operator%(const BigInt &r) const { return\
    \ BigInt(*this) %= r; }\n  BigInt &operator>>=(unsigned size) {\n    if (dat.size()\
    \ * bdig <= size) return *this = 0;\n    unsigned i = 0, j = size / bdig, k =\
    \ size % bdig, mask = (1 << k) - 1;\n    for (; j + 1 < dat.size(); i++, j++)\n\
    \      dat[i] = (dat[j] >> k) | ((dat[j + 1] & mask) << (bdig - k));\n    return\
    \ dat[i] = (dat[j] >> k), dat.resize(i + 1), shrink(), *this;\n  }\n  BigInt &operator<<=(unsigned\
    \ size) {\n    if (is_zero()) return *this;\n    int i = dat.size(), k = size\
    \ % bdig;\n    for (dat.emplace_back(0); i > 0; i--)\n      dat[i] = ((dat[i]\
    \ << k) & (base - 1)) | (dat[i - 1] >> (bdig - k));\n    dat[0] = (dat[0] << k)\
    \ & (base - 1);\n    return shrink(), dat.insert(dat.begin(), size / bdig, 0),\
    \ *this;\n  }\n  BigInt operator>>(unsigned size) const { return BigInt(*this)\
    \ >>= size; }\n  BigInt operator<<(unsigned size) const { return BigInt(*this)\
    \ <<= size; }\n  long long convert_ll() const {\n    assert(able_ll());\n    long\
    \ long ret = 0;\n    for (int i = dat.size() - 1; i >= 0; i--) ret = (ret << bdig)\
    \ + dat[i];\n    return neg ? -ret : ret;\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, BigInt &v) {\n    std::string s;\n    return is >> s, v.read(s), is;\n\
    \  }\n  friend std::ostream &operator<<(std::ostream &os, const BigInt &v) {\n\
    \    return os << v.to_str(), os;\n  }\n};\n\nBigInt gcd(const BigInt &a, const\
    \ BigInt &b) {\n  assert(!a.neg && !b.neg);\n  if (a.is_zero()) return b;\n  if\
    \ (b.is_zero()) return a;\n  int y = a.ctz(), z = b.ctz();\n  BigInt x[2] = {a,\
    \ b};\n  x[0] >>= y, x[1] >>= z;\n  bool id = 0;\n  while (true) {\n    if (x[id]\
    \ < x[!id]) id = !id;\n    if ((x[id] -= x[!id]).is_zero()) break;\n    x[id]\
    \ >>= x[id].ctz();\n  }\n  return x[!id] << std::min(y, z);\n}\n\nBigInt lcm(const\
    \ BigInt &a, const BigInt &b) { return (a / gcd(a, b)) * b; }\n#line 5 \"test/aoj/NTL_2_D.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  BigInt A, B;\n  cin >> A >> B;\n  cout << A / B << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_D\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/BigInt.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  BigInt\
    \ A, B;\n  cin >> A >> B;\n  cout << A / B << endl;\n  return 0;\n}"
  dependsOn:
  - src/Math/BigInt.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/aoj/NTL_2_D.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 13:37:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_2_D.test.cpp
- /verify/test/aoj/NTL_2_D.test.cpp.html
title: test/aoj/NTL_2_D.test.cpp
---
