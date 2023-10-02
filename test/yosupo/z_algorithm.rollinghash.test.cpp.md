---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':heavy_check_mark:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: src/Math/CartesianProduct.hpp
    title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\\
      times K_n$)"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Misc/rng.hpp
    title: "\u7591\u4F3C\u4E71\u6570"
  - icon: ':heavy_check_mark:'
    path: src/String/RollingHash.hpp
    title: Rolling-Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/z_algorithm.rollinghash.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <iostream>\n\
    #include <string>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b\
    \ * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate\
    \ <class mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Math/CartesianProduct.hpp\"\n#include <tuple>\n\
    #include <array>\n#include <utility>\ntemplate <class... Ks> struct CartesianProduct:\
    \ std::tuple<Ks...> {\n static constexpr int N= sizeof...(Ks);\n using Self= CartesianProduct;\n\
    \ using std::tuple<Ks...>::tuple;\n template <class T> CartesianProduct(const\
    \ T &v) { fill(v, std::make_index_sequence<N>()); }\n template <class T, std::size_t...\
    \ I> std::array<int, N> fill(const T &v, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)=\
    \ v), 0)...}}; }\n#define HELPER(name, op) \\\n template <std::size_t... I> std::array<int,\
    \ N> name(const Self &y, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)\
    \ op##= std::get<I>(y)), 0)...}}; } \\\n Self &operator op##=(const Self &r) {\
    \ return name(r, std::make_index_sequence<N>()), *this; }\n HELPER(add_assign,\
    \ +)\n HELPER(dif_assign, -)\n HELPER(mul_assign, *)\n HELPER(div_assign, /)\n\
    #undef HELPER\n Self operator+(const Self &r) const { return Self(*this)+= r;\
    \ }\n Self operator-(const Self &r) const { return Self(*this)-= r; }\n Self operator*(const\
    \ Self &r) const { return Self(*this)*= r; }\n Self operator/(const Self &r) const\
    \ { return Self(*this)/= r; }\n};\n#line 2 \"src/Misc/rng.hpp\"\n#include <random>\n\
    uint64_t rng() {\n static uint64_t x= 10150724397891781847ULL * std::random_device{}();\n\
    \ return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t lim) { return rng()\
    \ % lim; }\nint64_t rng(int64_t l, int64_t r) { return l + rng() % (r - l); }\n\
    #line 2 \"src/String/RollingHash.hpp\"\n#include <vector>\n#line 4 \"src/String/RollingHash.hpp\"\
    \ntemplate <class K> class RollingHash {\n static inline std::vector<K> pw;\n\
    \ static inline K base;\n static inline void set_pw(int n) {\n  if (int m= pw.size();\
    \ m < n)\n   for (pw.resize(n); m < n; m++) pw[m]= pw[m - 1] * base;\n }\n std::vector<K>\
    \ hash;\npublic:\n class SubString {\n  const RollingHash *instance;\n  const\
    \ int bg, ed;\n public:\n  SubString(const RollingHash &rh): instance(&rh), bg(0),\
    \ ed(rh.hash.size()) {}\n  SubString(const RollingHash *i, int b, int e): instance(i),\
    \ bg(b), ed(e) {}\n  inline K get_hash(int l= 0, int r= -1) const { return instance->get_hash(bg\
    \ + l, (r == -1 ? ed : bg + r)); }\n  friend int lcp(const SubString &l, const\
    \ SubString &r) {\n   int ok= 0, ng= std::min(l.ed - l.bg, r.ed - r.bg) + 1;\n\
    \   for (int x; ng - ok > 1;) x= (ok + ng) / 2, (l.get_hash(0, x) == r.get_hash(0,\
    \ x) ? ok : ng)= x;\n   return ok;\n  }\n };\n static void set_base(K b) { base=\
    \ b, pw.assign(1, 1); }\n static K base_pow(int i) { return pw[i]; }\n RollingHash()=\
    \ default;\n template <class T> RollingHash(const std::vector<T> &v): hash(v.size()\
    \ + 1, 0) {\n  set_pw(hash.size());\n  for (int i= 0, ed= v.size(); i < ed; i++)\
    \ hash[i + 1]= hash[i] * base + v[i];\n }\n RollingHash(const std::string &s):\
    \ RollingHash(std::vector<char>(s.begin(), s.end())) {}\n inline K get_hash(int\
    \ l= 0, int r= -1) const {\n  if (r < 0) r= hash.size() - 1;\n  return hash[r]\
    \ - hash[l] * pw[r - l];\n }\n SubString sub(int l, int r) const { return SubString{this,\
    \ l, r}; }\n};\n#line 8 \"test/yosupo/z_algorithm.rollinghash.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using\
    \ Mint= ModInt<(1ll << 61) - 1>;\n using K= CartesianProduct<Mint, Mint>;\n using\
    \ RH= RollingHash<K>;\n K base= {rng(2, Mint::mod() - 1), rng(2, Mint::mod() -\
    \ 1)};\n RH::set_base(base);\n string S;\n cin >> S;\n RH rh(S);\n int N= S.length();\n\
    \ for (int i= 0; i < N; i++) {\n  cout << lcp(rh, rh.sub(i, N)) << \" \\n\"[i\
    \ == N - 1];\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <iostream>\n#include <string>\n#include \"src/Math/ModInt.hpp\"\n#include \"\
    src/Math/CartesianProduct.hpp\"\n#include \"src/Misc/rng.hpp\"\n#include \"src/String/RollingHash.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<(1ll << 61) - 1>;\n using K= CartesianProduct<Mint, Mint>;\n\
    \ using RH= RollingHash<K>;\n K base= {rng(2, Mint::mod() - 1), rng(2, Mint::mod()\
    \ - 1)};\n RH::set_base(base);\n string S;\n cin >> S;\n RH rh(S);\n int N= S.length();\n\
    \ for (int i= 0; i < N; i++) {\n  cout << lcp(rh, rh.sub(i, N)) << \" \\n\"[i\
    \ == N - 1];\n }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/CartesianProduct.hpp
  - src/Misc/rng.hpp
  - src/String/RollingHash.hpp
  isVerificationFile: true
  path: test/yosupo/z_algorithm.rollinghash.test.cpp
  requiredBy: []
  timestamp: '2023-08-05 18:38:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/z_algorithm.rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/z_algorithm.rollinghash.test.cpp
- /verify/test/yosupo/z_algorithm.rollinghash.test.cpp.html
title: test/yosupo/z_algorithm.rollinghash.test.cpp
---
