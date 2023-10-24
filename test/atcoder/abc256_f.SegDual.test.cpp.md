---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_f
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.SegDual.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n#include <iostream>\n\
    #include <array>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include\
    \ <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for (Int\
    \ q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b * q;\n\
    \ return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\
    \nnamespace math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32=\
    \ uint32_t;\nusing u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n \
    \ if (l+= r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n\
    \ CE IL U diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return\
    \ l; \\\n }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static\
    \ CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\n\
    template <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, enable_if_t<is_modint_v<T> && !is_same_v<T,\
    \ MInt>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod))\
    \ {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/DataStructure/SegmentTree_Dual.hpp\"\n#include\
    \ <vector>\ntemplate <typename M> struct SegmentTree_Dual {\n using T= typename\
    \ M::T;\n using E= typename M::E;\n SegmentTree_Dual() {}\n SegmentTree_Dual(int\
    \ n_, T v1= T()): n(n_), height(n == 1 ? 0 : std::__lg(n - 1) + 1), val(n, v1),\
    \ laz(n * 2, {E(), false}) {}\n SegmentTree_Dual(const std::vector<T> &v): n(v.size()),\
    \ height(n == 1 ? 1 : std::__lg(n - 1) + 1), val(v), laz(n * 2, {E(), false})\
    \ {}\n void apply(int a, int b, E x) {\n  a+= n, b+= n;\n  for (int i= height;\
    \ i >= 1; i--)\n   if (((a >> i) << i) != a) eval(a >> i);\n  for (int i= height;\
    \ i >= 1; i--)\n   if (((b >> i) << i) != b) eval((b - 1) >> i);\n  for (int l=\
    \ a, r= b; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) propagate(l++, x);\n   if (r\
    \ & 1) propagate(--r, x);\n  }\n }\n void set(int k, T x) {\n  for (int i= height;\
    \ i; i--) eval((k + n) >> i);\n  val[k]= x, laz[k + n].flg= false;\n }\n T &operator[](const\
    \ int k) {\n  for (int i= height; i; i--) eval((k + n) >> i);\n  if (laz[k + n].flg)\
    \ M::mapping(val[k], laz[k + n].val), laz[k + n].flg= false;\n  return val[k];\n\
    \ }\nprivate:\n const int n, height;\n struct Lazy {\n  E val;\n  bool flg;\n\
    \ };\n std::vector<T> val;\n std::vector<Lazy> laz;\n inline void eval(int k)\
    \ {\n  if (!laz[k].flg) return;\n  propagate(k << 1 | 0, laz[k].val), propagate(k\
    \ << 1 | 1, laz[k].val);\n  laz[k].flg= false;\n }\n inline void propagate(int\
    \ k, const E &x) {\n  laz[k].flg ? (M::composition(laz[k].val, x), x) : laz[k].val=\
    \ x;\n  laz[k].flg= true;\n }\n};\n#line 6 \"test/atcoder/abc256_f.SegDual.test.cpp\"\
    \nusing namespace std;\nusing Mint= ModInt<998244353>;\nstruct Mono {\n struct\
    \ T {\n  Mint val, coef[2];\n  T()= default;\n  T(Mint id, Mint v): val(v), coef{(id\
    \ + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using E= array<Mint, 3>;\n\
    \ static void mapping(T &x, const E &mapp) { x.val+= mapp[0] * x.coef[0] - mapp[1]\
    \ * x.coef[1] + mapp[2]; }\n static void composition(E &pre, const E &suf) { pre[0]+=\
    \ suf[0], pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned main() {\n cin.tie(0);\n\
    \ ios::sync_with_stdio(false);\n int N, Q;\n cin >> N >> Q;\n Mint A[N], D[N];\n\
    \ for (int i= 0; i < N; i++) cin >> A[i], D[i]= A[i];\n for (int j= 0; j < 3;\
    \ j++)\n  for (int i= 1; i < N; i++) D[i]+= D[i - 1];\n SegmentTree_Dual<Mono>\
    \ seg(N);\n for (int i= 0; i < N; i++) seg.set(i, {i, D[i]});\n while (Q--) {\n\
    \  int op, x;\n  cin >> op >> x, x--;\n  if (op == 1) {\n   Mint v;\n   cin >>\
    \ v, v-= A[x], A[x]+= v;\n   seg.apply(x, N, {v, v * x, v * x * x / 2});\n  }\
    \ else {\n   cout << seg[x].val << '\\n';\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n#include\
    \ <iostream>\n#include <array>\n#include \"src/Math/ModInt.hpp\"\n#include \"\
    src/DataStructure/SegmentTree_Dual.hpp\"\nusing namespace std;\nusing Mint= ModInt<998244353>;\n\
    struct Mono {\n struct T {\n  Mint val, coef[2];\n  T()= default;\n  T(Mint id,\
    \ Mint v): val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using\
    \ E= array<Mint, 3>;\n static void mapping(T &x, const E &mapp) { x.val+= mapp[0]\
    \ * x.coef[0] - mapp[1] * x.coef[1] + mapp[2]; }\n static void composition(E &pre,\
    \ const E &suf) { pre[0]+= suf[0], pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n int N, Q;\n cin >> N\
    \ >> Q;\n Mint A[N], D[N];\n for (int i= 0; i < N; i++) cin >> A[i], D[i]= A[i];\n\
    \ for (int j= 0; j < 3; j++)\n  for (int i= 1; i < N; i++) D[i]+= D[i - 1];\n\
    \ SegmentTree_Dual<Mono> seg(N);\n for (int i= 0; i < N; i++) seg.set(i, {i, D[i]});\n\
    \ while (Q--) {\n  int op, x;\n  cin >> op >> x, x--;\n  if (op == 1) {\n   Mint\
    \ v;\n   cin >> v, v-= A[x], A[x]+= v;\n   seg.apply(x, N, {v, v * x, v * x *\
    \ x / 2});\n  } else {\n   cout << seg[x].val << '\\n';\n  }\n }\n return 0;\n\
    }"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.SegDual.test.cpp
  requiredBy: []
  timestamp: '2023-10-25 00:54:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.SegDual.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.SegDual.test.cpp
- /verify/test/atcoder/abc256_f.SegDual.test.cpp.html
title: test/atcoder/abc256_f.SegDual.test.cpp
---
