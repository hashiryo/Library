---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/Nimber.hpp
    title: Nimber $\mathbb{F}_{2^{64}}$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/unit_test/nimber_log.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#include <bits/stdc++.h>\n#line 3 \"\
    src/Math/Nimber.hpp\"\n/**\n * @title Nimber $\\mathbb{F}_{2^{64}}$\n * @category\
    \ \u6570\u5B66\n * @see https://en.wikipedia.org/wiki/Nimber\n * @see https://natsugiri.hatenablog.com/entry/2020/03/29/073605\n\
    \ */\n// verify\u7528:\n// https://codeforces.com/contest/1314/problem/F (\u96E2\
    \u6563\u5BFE\u6570)\n// https://atcoder.jp/contests/wtf19-open/tasks/wtf19_c2\
    \ (\u96E2\u6563\u5BFE\u6570)\n// https://atcoder.jp/contests/abc274/tasks/abc274_h\
    \ (\u30ED\u30EA\u30CF\u306B\u4E57\u305B\u308B)\n\n// BEGIN CUT HERE\nclass Nimber\
    \ {\n  using u64 = std::uint64_t;\n  using u32 = std::uint32_t;\n  using u16 =\
    \ std::uint16_t;\n  static inline std::array<u16, 65536> pw, ln;\n  template <u16\
    \ h = 3>\n  static inline u16 half(u16 A) {\n    return A ? pw[(ln[A] + h) % 65535]\
    \ : 0;\n  }\n  template <u16 h = 0>\n  static inline u16 mul(u16 A, u16 B) {\n\
    \    return A && B ? pw[(ln[A] + ln[B] + h) % 65535] : 0;\n  }\n  template <u16\
    \ h = 0>\n  static inline u16 mul(u16 A, u16 B, u16 C) {\n    return A && B &&\
    \ C ? pw[(ln[A] + ln[B] + ln[C] + h) % 65535] : 0;\n  }\n  static inline u16 inv(u16\
    \ A) { return assert(A), pw[65535 - ln[A]]; }\n  static inline u16 sqrt(u16 A)\
    \ {\n    return A ? pw[u16((65537 * u32(ln[A])) >> 1)] : 0;\n  }\n  static inline\
    \ u64 mul(u64 A, u64 B) {\n    u16 a0 = u16(A), a1 = u16(A >> 16), a2 = u16(A\
    \ >> 32), a3 = A >> 48;\n    u16 b0 = u16(B), b1 = u16(B >> 16), b2 = u16(B >>\
    \ 32), b3 = B >> 48;\n    u16 x0 = a1 ^ a0, x1 = a3 ^ a2, y0 = b1 ^ b0, y1 = b3\
    \ ^ b2;\n    u16 c0 = mul(a0, b0), c1 = mul(x0, y0) ^ c0, c2 = mul<0>(a2 ^ a0,\
    \ b2 ^ b0);\n    u16 c3 = mul<0>(x0 ^ x1, y0 ^ y1) ^ c2 ^ c1;\n    c2 ^= (c0 ^=\
    \ mul<3>(a1, b1)) ^ mul<3>(u16(a3 ^ a1), u16(b3 ^ b1));\n    c1 ^= mul<6>(a3,\
    \ b3) ^ mul<3>(x1, y1);\n    c0 ^= mul<6>(a2, b2) ^ mul<6>(x1, y1);\n    return\
    \ (u64(c3) << 48) | (u64(c2) << 32) | (u32(c1) << 16) | c0;\n  }\n  static inline\
    \ u64 inv(u64 A) {\n    u16 a0 = u16(A), a1 = u16(A >> 16), a2 = u16(A >> 32),\
    \ a3 = A >> 48;\n    u16 x = a2 ^ a3, y = a1 ^ a3, w = a0 ^ a2, v = a0 ^ a1;\n\
    \    u16 b3 = mul(a1, a2, a1 ^ x), b2 = mul(a0, a2, a0 ^ x),\n        b1 = mul(a0,\
    \ a1, a0 ^ y), b0 = mul(a0, v, w), t = mul<3>(w, x, x);\n    b0 ^= b1 ^ b2, b1\
    \ ^= b3, b2 ^= b3, b0 ^= b3 ^= mul(a0, a0, a3);\n    b1 ^= t ^ mul<3>(a1, y, y),\
    \ b0 ^= t ^ mul<3>(v, y, y);\n    b3 ^= t = mul<3>(a1, a3, y) ^ mul<3>(a2, x,\
    \ x);\n    b2 ^= t ^ mul<3>(a0, a3, a3) ^ mul<3>(a1, a1, a2), b3 ^= mul<6>(a3,\
    \ a3, x);\n    b2 ^= mul<6>(a3, x, x), b1 ^= mul<6>(a3, a3, y ^ w), b0 ^= mul<6>(y,\
    \ x, x);\n    b2 ^= mul<9>(a3, a3, a3), b0 ^= mul<9>(a3, a3, y);\n    t = mul<6>(x,\
    \ b3) ^ mul<6>(a3, b2) ^ mul<3>(a1, b1) ^ mul(a0, b0);\n    return t = inv(t),\
    \ (u64(mul(b3, t)) << 48) | (u64(mul(b2, t)) << 32) |\n                      \
    \     (u32(mul(b1, t)) << 16) | mul(b0, t);\n  }\n  static inline u64 square(u64\
    \ A) {\n    u16 a0 = u16(A), a1 = u16(A >> 16), a2 = u16(A >> 32), a3 = A >> 48;\n\
    \    a3 = mul(a3, a3), a2 = mul(a2, a2), a1 = mul(a1, a1), a0 = mul(a0, a0);\n\
    \    a0 ^= half(a1) ^ half<6>(a3), a2 ^= half(a3), a1 ^= half(a3 ^ a2);\n    return\
    \ (u64(a3) << 48) | (u64(a2) << 32) | (u32(a1) << 16) | a0;\n  }\n  static inline\
    \ u64 pow(u64 A, u64 k) {\n    for (u64 ret = 1;; A = square(A))\n      if (k\
    \ & 1 ? ret = mul(ret, A) : 0; !(k >>= 1)) return ret;\n  }\n  template <int mod>\n\
    \  static inline int mdif(int a, int b) {\n    return a += mod & -((a -= b) <\
    \ 0);\n  }\n  template <int mod>\n  static inline int mmul(int a, int b) {\n \
    \   return u64(a) * b % mod;\n  }\n  static inline int minv(int a, int mod) {\n\
    \    int x = 1, y = 0, t = mod;\n    for (int q, z, u; t;)\n      z = x, u = a,\
    \ x = y, y = z - y * (q = a / t), a = t, t = u - t * q;\n    return x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n  }\n  static inline int log16(u16 A, u16 B) {\n  \
    \  int a = ln[A], b = ln[B], mod = 65535;\n    if (a == 0) return b == 0 ? 1 :\
    \ -1;\n    if (int g = std::gcd(a, mod); g != 1) {\n      if (b % g != 0) return\
    \ -1;\n      a /= g, b /= g, mod /= g;\n    }\n    return u32(b) * minv(a, mod)\
    \ % mod;\n  }\n  template <int pa, int mid>\n  static inline int bsgs(u64 x, u64\
    \ y) {\n    std::unordered_map<u64, int> memo;\n    u64 big = 1, now = 1;\n  \
    \  for (int i = 0; i < mid; i++) memo[y] = i, y = mul(y, x), big = mul(big, x);\n\
    \    for (int step = 0; step < pa; step += mid) {\n      now = mul(now, big);\n\
    \      if (auto it = memo.find(now); it != memo.end())\n        return (step +\
    \ mid) - it->second;\n    }\n    return -1;\n  }\n  static inline u64 log(u64\
    \ A, u64 B) {\n    if (B == 1) return 0;\n    if (!A && !B) return 1;\n    if\
    \ (!A || !B) return u64(-1);\n    static constexpr int P0 = 641, P1 = 65535, P2\
    \ = 65537, P3 = 6700417;\n    static constexpr int iv10 = 40691, iv21 = 32768,\
    \ iv20 = 45242,\n                         iv32 = 3317441, iv31 = 3350208, iv30\
    \ = 3883315;\n    int a0 = bsgs<651, 26>(pow(A, 0x663d80ff99c27f), pow(B, 0x663d80ff99c27f));\n\
    \    if (a0 == -1) return u64(-1);\n    int a1 = log16(pow(A, 0x1000100010001),\
    \ pow(B, 0x1000100010001));\n    if (a1 == -1) return u64(-1);\n    int a2 = bsgs<65547,\
    \ 257>(pow(A, 0xffff0000ffff), pow(B, 0xffff0000ffff));\n    if (a2 == -1) return\
    \ u64(-1);\n    int a3 = bsgs<6700427, 2589>(pow(A, 0x280fffffd7f), pow(B, 0x280fffffd7f));\n\
    \    if (a3 == -1) return u64(-1);\n    int x1 = mmul<P1>(mdif<P1>(a1, a0), iv10);\n\
    \    int x2 = mdif<P2>(mmul<P2>(mdif<P2>(a2, a0), iv20), mmul<P2>(x1, iv21));\n\
    \    int x3 =\n        mdif<P3>(mdif<P3>(mmul<P3>(mdif<P3>(a3, a0), iv30), mmul<P3>(x1,\
    \ iv31)),\n                 mmul<P3>(x2, iv32));\n    return u64(P0) * (u64(P1)\
    \ * (u64(P2) * x3 + x2) + x1) + a0;\n  }\n  u64 x;\n\n public:\n  static inline\
    \ void init(u32 x = 0, u32 y = 0) {\n    constexpr u16 f2n[16] = {\n        0x0001u,\
    \ 0x2827u, 0x392bu, 0x8000u, 0x20fdu, 0x4d1du, 0xde4au, 0x0a17u,\n        0x3464u,\
    \ 0xe3a9u, 0x6d8du, 0x34bcu, 0xa921u, 0xa173u, 0x0ebcu, 0x0e69u};\n    for (int\
    \ i = pw[0] = pw[65535] = 1; i < 65535; ++i)\n      pw[i] = (pw[i - 1] << 1) ^\
    \ (0x1681fu & (-(pw[i - 1] >= 0x8000u)));\n    for (int i = 1; i < 65535; ln[pw[i]\
    \ = y] = i, i++)\n      for (x = pw[i], y = 0; x; x &= x - 1) y ^= f2n[__builtin_ctz(x)];\n\
    \  }\n  Nimber(u64 x_ = 0) : x(x_) {}\n  Nimber &operator+=(const Nimber &r) {\
    \ return x ^= r.x, *this; }\n  Nimber &operator-=(const Nimber &r) { return x\
    \ ^= r.x, *this; }\n  Nimber &operator*=(const Nimber &r) { return x = mul(x,\
    \ r.x), *this; }\n  Nimber &operator/=(const Nimber &r) { return x = mul(x, inv(r.x)),\
    \ *this; }\n  Nimber operator+(const Nimber &r) const { return Nimber(x ^ r.x);\
    \ }\n  Nimber operator-(const Nimber &r) const { return Nimber(x ^ r.x); }\n \
    \ Nimber operator*(const Nimber &r) const { return Nimber(mul(x, r.x)); }\n  Nimber\
    \ operator/(const Nimber &r) const { return Nimber(mul(x, inv(r.x))); }\n  Nimber\
    \ inv() const { return Nimber(inv(x)); }\n  Nimber square() const { return Nimber(square(x));\
    \ }\n  Nimber sqrt() const {\n    u16 a0 = u16(x), a1 = u16(x >> 16), a2 = u16(x\
    \ >> 32), a3 = x >> 48;\n    a1 ^= half(a3 ^ a2), a2 ^= half(a3), a0 ^= half(a1)\
    \ ^ half<6>(a3);\n    return Nimber((u64(sqrt(a3)) << 48) | (u64(sqrt(a2)) <<\
    \ 32) |\n                  (u32(sqrt(a1)) << 16) | sqrt(a0));\n  }\n  u64 val()\
    \ const { return x; }\n  Nimber pow(u64 k) const { return Nimber(pow(x, k)); }\n\
    \  u64 log(const Nimber &r) const { return log(x, r.x); }\n  bool operator==(const\
    \ Nimber &r) const { return x == r.x; }\n  bool operator!=(const Nimber &r) const\
    \ { return x != r.x; }\n  bool operator<(const Nimber &r) const { return x < r.x;\
    \ }\n  bool operator>(const Nimber &r) const { return x > r.x; }\n  bool operator<=(const\
    \ Nimber &r) const { return x <= r.x; }\n  bool operator>=(const Nimber &r) const\
    \ { return x >= r.x; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ Nimber &r) {\n    return os << r.x;\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, Nimber &r) {\n    return is >> r.x, is;\n  }\n};\n#line 4 \"test/unit_test/nimber_log.test.cpp\"\
    \nusing namespace std;\n\nvoid test(int X) {\n  mt19937 mt(X);\n  uniform_int_distribution<uint64_t>\
    \ rng(0, ULLONG_MAX);\n  static constexpr int N = 1000;\n  static Nimber a[N],\
    \ b[N];\n  static uint64_t x[N];\n  for (int i = 0; i < N; i++)\n    a[i] = rng(mt),\
    \ x[i] = rng(mt), b[i] = a[i].pow(x[i]);\n  for (int i = 0; i < N; i++) {\n  \
    \  uint64_t ans = a[i].log(b[i]);\n    assert(a[i].pow(ans) == b[i]);\n  }\n}\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  Nimber::init();\n\
    \  int A, B;\n  cin >> A >> B;\n  test(A), test(B);\n  cout << A + B << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include <bits/stdc++.h>\n\
    #include \"src/Math/Nimber.hpp\"\nusing namespace std;\n\nvoid test(int X) {\n\
    \  mt19937 mt(X);\n  uniform_int_distribution<uint64_t> rng(0, ULLONG_MAX);\n\
    \  static constexpr int N = 1000;\n  static Nimber a[N], b[N];\n  static uint64_t\
    \ x[N];\n  for (int i = 0; i < N; i++)\n    a[i] = rng(mt), x[i] = rng(mt), b[i]\
    \ = a[i].pow(x[i]);\n  for (int i = 0; i < N; i++) {\n    uint64_t ans = a[i].log(b[i]);\n\
    \    assert(a[i].pow(ans) == b[i]);\n  }\n}\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  Nimber::init();\n  int A, B;\n  cin >> A >>\
    \ B;\n  test(A), test(B);\n  cout << A + B << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/Nimber.hpp
  isVerificationFile: true
  path: test/unit_test/nimber_log.test.cpp
  requiredBy: []
  timestamp: '2022-11-06 00:20:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit_test/nimber_log.test.cpp
layout: document
redirect_from:
- /verify/test/unit_test/nimber_log.test.cpp
- /verify/test/unit_test/nimber_log.test.cpp.html
title: test/unit_test/nimber_log.test.cpp
---
