---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/CartesianProduct.hpp
    title: "\u4EE3\u6570\u7CFB\u3092\u4E26\u5217\u306B\u6271\u3046 ($K_1\\times K_2\\\
      times\\cdots\\times K_n$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Misc/rng.hpp
    title: "\u7591\u4F3C\u4E71\u6570"
  - icon: ':question:'
    path: src/String/RollingHash.hpp
    title: Rolling-Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc135/tasks/abc135_f
    links:
    - https://atcoder.jp/contests/abc135/tasks/abc135_f
  bundledCode: "#line 1 \"test/atcoder/abc135_f.RH.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc135/tasks/abc135_f\"\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"src/String/RollingHash.hpp\"\n#include <string>\n#include\
    \ <array>\n#include <cassert>\ntemplate <class K, class Int= int> class RollingHash\
    \ {\npublic:\n static inline std::vector<K> pw, hsh;\n static inline K bs;\n static\
    \ inline std::vector<Int> str;\n static inline void set_pw(int n) {\n  if (int\
    \ m= pw.size(); m <= n)\n   for (pw.resize(n + 1); m <= n; ++m) pw[m]= pw[m -\
    \ 1] * bs;\n }\n int bg, n;\n RollingHash(int b, int n): bg(b), n(n) {}\n template\
    \ <class C> static int bin_srch(int ok, int ng, const C &check) {\n  for (int\
    \ x; ng - ok > 1;) x= (ok + ng) / 2, (check(x) ? ok : ng)= x;\n  return ok;\n\
    \ }\n template <size_t I> static K concat(const std::array<RollingHash, I> &v)\
    \ {\n  K ret= 0;\n  for (int i= 0; i < I; ++i) ret= ret * pw[v[i].n] + v[i].hash();\n\
    \  return ret;\n }\npublic:\n static void init(K b) { bs= b, pw.assign(1, 1),\
    \ hsh.assign(1, 0); }\n static K base_pow(int i) { return set_pw(i), pw[i]; }\n\
    \ RollingHash()= default;\n RollingHash(const std::vector<Int> &v): bg(hsh.size()\
    \ - 1), n(v.size()) {\n  str.insert(str.end(), v.begin(), v.end()), set_pw(n),\
    \ hsh.resize(bg + n + 1);\n  for (int i= 0; i < n; ++i) hsh[bg + i + 1]= hsh[bg\
    \ + i] * bs + v[i];\n }\n RollingHash(const std::string &s): RollingHash(std::vector<Int>(s.begin(),\
    \ s.end())) {}\n inline size_t length() const { return n; }\n inline K hash()\
    \ const { return hsh[bg + n] - hsh[bg] * pw[n]; }\n RollingHash sub(int b, int\
    \ m) const {\n  assert(b + m <= n), assert(m >= 0);\n  return {bg + b, m};\n }\n\
    \ RollingHash sub(int b) const {\n  assert(b <= n);\n  return {bg + b, n - b};\n\
    \ }\n template <class... Args> friend std::enable_if_t<std::conjunction_v<std::is_same<Args,\
    \ RollingHash>...>, K> concat_hash(const Args &...rh) { return concat(std::array{rh...});\
    \ }\n friend int lcp(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(0, x) == r.sub(0, x); });\n\
    \ }\n friend int lcs(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(l.n - x) == r.sub(r.n - x);\
    \ });\n }\n bool operator==(const RollingHash &r) const { return hash() == r.hash();\
    \ }\n bool operator!=(const RollingHash &r) const { return !(*this == r); }\n\
    \ bool operator<(const RollingHash &r) const {\n  int k= lcp(*this, r);\n  return\
    \ k == std::min(n, r.n) ? n < r.n : str[bg + k] < str[r.bg + k];\n }\n friend\
    \ bool concat_cmp(const RollingHash &l, const RollingHash &r) {\n  int k= lcp(l,\
    \ r);\n  if (l.n < r.n) {\n   if (k < l.n) return str[l.bg + k] < str[r.bg + k];\n\
    \   if (k= lcp(r, r.sub(l.n)); k < r.n - l.n) return str[r.bg + k] < str[r.bg\
    \ + l.n + k];\n   if (k= lcp(r.sub(r.n - l.n), l); k < l.n) return str[r.bg +\
    \ r.n - l.n + k] < str[l.bg + k];\n  } else {\n   if (k < r.n) return str[l.bg\
    \ + k] < str[r.bg + k];\n   if (k= lcp(l.sub(r.n), l); k < l.n - r.n) return str[l.bg\
    \ + r.n + k] < str[l.bg + k];\n   if (k= lcp(r, l.sub(l.n - r.n)); k < r.n) return\
    \ str[r.bg + k] < str[l.bg + l.n - r.n + k];\n  }\n  return false;\n }\n std::string\
    \ to_str() const {  // for debug\n  std::string ret;\n  for (int i= bg; i < bg\
    \ + n; ++i) ret+= (char)str[i];\n  return ret;\n }\n};\n#line 2 \"src/Math/CartesianProduct.hpp\"\
    \n#include <tuple>\n#line 4 \"src/Math/CartesianProduct.hpp\"\n#include <utility>\n\
    template <class... Ks> struct CartesianProduct: std::tuple<Ks...> {\n static constexpr\
    \ int N= sizeof...(Ks);\n using Self= CartesianProduct;\n using std::tuple<Ks...>::tuple;\n\
    \ template <class T> CartesianProduct(const T &v) { fill(v, std::make_index_sequence<N>());\
    \ }\n template <class T, std::size_t... I> std::array<int, N> fill(const T &v,\
    \ std::index_sequence<I...>) { return {{(void(std::get<I>(*this)= v), 0)...}};\
    \ }\n#define HELPER(name, op) \\\n template <std::size_t... I> std::array<int,\
    \ N> name(const Self &y, std::index_sequence<I...>) { return {{(void(std::get<I>(*this)\
    \ op##= std::get<I>(y)), 0)...}}; } \\\n Self &operator op##=(const Self &r) {\
    \ return name(r, std::make_index_sequence<N>()), *this; }\n HELPER(add_assign,\
    \ +)\n HELPER(dif_assign, -)\n HELPER(mul_assign, *)\n HELPER(div_assign, /)\n\
    #undef HELPER\n Self operator+(const Self &r) const { return Self(*this)+= r;\
    \ }\n Self operator-(const Self &r) const { return Self(*this)-= r; }\n Self operator*(const\
    \ Self &r) const { return Self(*this)*= r; }\n Self operator/(const Self &r) const\
    \ { return Self(*this)/= r; }\n};\n#line 2 \"src/Misc/rng.hpp\"\n#include <random>\n\
    #include <cstdint>\nuint64_t rng() {\n static uint64_t x= 10150724397891781847ULL\
    \ * std::random_device{}();\n return x^= x << 7, x^= x >> 9;\n}\nuint64_t rng(uint64_t\
    \ lim) { return rng() % lim; }\nint64_t rng(int64_t l, int64_t r) { return l +\
    \ rng() % (r - l); }\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #line 4 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n\
    \ for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z\
    \ - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing i64= long long;\n\
    using u64= unsigned long long;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return l+= r, l < (M) ? l : l\
    \ - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { return l-=\
    \ r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static CE IL U set(U n) { return\
    \ n; } \\\n static CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n)\
    \ { return n; }\ntemplate <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n\
    \ u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)),\
    \ r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l)\
    \ * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n)\
    \ const { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n\
    \  NORM;\n }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n\
    \ static CE u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >>\
    \ B) + mod - ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n\
    \ CE MP_Na(): mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32\
    \ r) const { return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n\
    };\nstruct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0)\
    \ {}\n CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s)\
    \ + m - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r);\
    \ }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE\
    \ IL u64 quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n)\
    \ const { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n\
    \ u64 mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1)\
    \ << 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r);\
    \ }\n PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64\
    \ n) { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64\
    \ n) const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const\
    \ { return (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n -\
    \ quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1():\
    \ s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m),\
    \ d(m << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
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
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 8 \"test/atcoder/abc135_f.RH.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n using K= CartesianProduct<Mint, Mint>;\n using\
    \ RH= RollingHash<K>;\n RH::init({rng(), rng()});\n string s, t;\n cin >> s >>\
    \ t;\n int N= s.length(), M= t.length();\n string ss= s;\n for (int i= (M + N\
    \ - 1) / N; i--;) ss+= s;\n RH rs(ss), rt(t);\n vector<int> next(N, -1);\n auto\
    \ th= rt.hash();\n for (int i= 0; i < N; ++i)\n  if (rs.sub(i, M).hash() == th)\
    \ next[i]= (i + M) % N;\n vector<int> dep(N, -1);\n int ans= 0;\n for (int i=\
    \ 0; i < N; ++i) {\n  auto dfs= [&](auto dfs, int v) {\n   if (dep[v] != -1) return\
    \ dep[v];\n   int u= next[v];\n   if (u == -1) return dep[v]= 0;\n   if (u ==\
    \ i) return dep[v]= N;\n   return dep[v]= dfs(dfs, u) + 1;\n  };\n  ans= max(ans,\
    \ dfs(dfs, i));\n }\n cout << (ans >= N ? -1 : ans) << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc135/tasks/abc135_f\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/String/RollingHash.hpp\"\n#include\
    \ \"src/Math/CartesianProduct.hpp\"\n#include \"src/Misc/rng.hpp\"\n#include \"\
    src/Math/ModInt.hpp\"\nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n using K= CartesianProduct<Mint, Mint>;\n using\
    \ RH= RollingHash<K>;\n RH::init({rng(), rng()});\n string s, t;\n cin >> s >>\
    \ t;\n int N= s.length(), M= t.length();\n string ss= s;\n for (int i= (M + N\
    \ - 1) / N; i--;) ss+= s;\n RH rs(ss), rt(t);\n vector<int> next(N, -1);\n auto\
    \ th= rt.hash();\n for (int i= 0; i < N; ++i)\n  if (rs.sub(i, M).hash() == th)\
    \ next[i]= (i + M) % N;\n vector<int> dep(N, -1);\n int ans= 0;\n for (int i=\
    \ 0; i < N; ++i) {\n  auto dfs= [&](auto dfs, int v) {\n   if (dep[v] != -1) return\
    \ dep[v];\n   int u= next[v];\n   if (u == -1) return dep[v]= 0;\n   if (u ==\
    \ i) return dep[v]= N;\n   return dep[v]= dfs(dfs, u) + 1;\n  };\n  ans= max(ans,\
    \ dfs(dfs, i));\n }\n cout << (ans >= N ? -1 : ans) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/String/RollingHash.hpp
  - src/Math/CartesianProduct.hpp
  - src/Misc/rng.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  isVerificationFile: true
  path: test/atcoder/abc135_f.RH.test.cpp
  requiredBy: []
  timestamp: '2024-01-29 15:51:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc135_f.RH.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc135_f.RH.test.cpp
- /verify/test/atcoder/abc135_f.RH.test.cpp.html
title: test/atcoder/abc135_f.RH.test.cpp
---
