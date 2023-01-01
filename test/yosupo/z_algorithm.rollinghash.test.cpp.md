---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/CartesianProduct.hpp
    title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\\
      times K_n$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/z_algorithm.rollinghash.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <bits/stdc++.h>\n\
    \n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y *\
    \ (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo {\n const\
    \ u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr MP_Mo(u64\
    \ m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline u64 mul(u64\
    \ l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l\
    \ op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64 l, u64\
    \ r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64 l, u64\
    \ r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n) const\
    \ { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64 ret=\
    \ reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr inline\
    \ u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n const\
    \ u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e ? inv(n,\
    \ e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const u128& w)\
    \ const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64); }\n};\n\
    template <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\n\
    struct m_b {};\nstruct s_b: m_b {};\nstruct r_b: m_b {};\ntemplate <class mod_t>\
    \ CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_staticmodint_v= is_base_of_v<s_b, mod_t>;\ntemplate <class mod_t> CE bool\
    \ is_runtimemodint_v= is_base_of_v<r_b, mod_t>;\ntemplate <class mpt, u64 MOD>\
    \ struct SB: s_b {\nprotected:\n static CE mpt md= mpt(MOD);\n};\ntemplate <class\
    \ mpt, int id> struct RB: r_b {\n static inline void set_mod(u64 m) { md= mpt(m);\
    \ }\nprotected:\n static inline mpt md;\n};\ntemplate <class Int, class U, class\
    \ B> struct MInt: public B {\n using Uint= U;\n static CE inline auto mod() {\
    \ return B::md.mod; }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n\
    \ template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T\
    \ v): x(B::md.set(v.val() % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod\
    \ - (-n) % B::md.mod : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
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
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using StaticModInt=\
    \ conditional_t < MOD<INT_MAX, MInt<int, u32, SB<MP_Na<u32>, MOD>>, conditional_t<MOD&(MOD\
    \ < LLONG_MAX), MInt<i64, u64, SB<MP_Mo, MOD>>, MInt<i64, u64, SB<MP_Na<u64>,\
    \ MOD>>>>;\nclass Montgomery {};\ntemplate <class Int, int id= -1> using RuntimeModInt=\
    \ conditional_t<is_same_v<Int, Montgomery>, MInt<i64, u64, RB<MP_Mo, id>>, conditional_t<disjunction_v<is_same<Int,\
    \ i64>, is_same<Int, u64>>, MInt<i64, u64, RB<MP_Na<u64>, id>>, MInt<int, u32,\
    \ RB<MP_Na<u32>, id>>>>;\n#undef CE\n}\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\
    \ math_internal::Montgomery, math_internal::is_runtimemodint_v, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LIM> mod_t\
    \ get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m=\
    \ mod_t::mod();\n static mod_t dat[LIM];\n static int l= 1;\n if (l == 1) dat[l++]=\
    \ 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n\
    #line 3 \"src/Math/CartesianProduct.hpp\"\ntemplate <class... Ks> struct CartesianProduct:\
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
    \ { return Self(*this)/= r; }\n};\n#line 3 \"src/String/RollingHash.hpp\"\ntemplate\
    \ <class K> class RollingHash {\n static inline std::vector<K> pw;\n static inline\
    \ K base;\n static inline void set_pw(int n) {\n  if (int m= pw.size(); m < n)\n\
    \   for (pw.resize(n); m < n; m++) pw[m]= pw[m - 1] * base;\n }\n std::vector<K>\
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
    \ l, r}; }\n};\nstd::uint64_t get_rand(std::uint64_t l, std::uint64_t r) {\n static\
    \ std::mt19937_64 gen(std::random_device{}());\n return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n}\n#line 7 \"test/yosupo/z_algorithm.rollinghash.test.cpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<(1ll << 61) - 1>;\n  using K = CartesianProduct<Mint,\
    \ Mint>;\n  using RH = RollingHash<K>;\n  K base = {get_rand(2, (1ll << 61) -\
    \ 2), get_rand(2, (1ll << 61) - 2)};\n  RH::set_base(base);\n  string S;\n  cin\
    \ >> S;\n  RH rh(S);\n  int N = S.length();\n  for (int i = 0; i < N; i++) {\n\
    \    cout << lcp(rh, rh.sub(i, N)) << \" \\n\"[i == N - 1];\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/CartesianProduct.hpp\"\
    \n#include \"src/String/RollingHash.hpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<(1ll\
    \ << 61) - 1>;\n  using K = CartesianProduct<Mint, Mint>;\n  using RH = RollingHash<K>;\n\
    \  K base = {get_rand(2, (1ll << 61) - 2), get_rand(2, (1ll << 61) - 2)};\n  RH::set_base(base);\n\
    \  string S;\n  cin >> S;\n  RH rh(S);\n  int N = S.length();\n  for (int i =\
    \ 0; i < N; i++) {\n    cout << lcp(rh, rh.sub(i, N)) << \" \\n\"[i == N - 1];\n\
    \  }\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/CartesianProduct.hpp
  - src/String/RollingHash.hpp
  isVerificationFile: true
  path: test/yosupo/z_algorithm.rollinghash.test.cpp
  requiredBy: []
  timestamp: '2023-01-01 02:59:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/z_algorithm.rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/z_algorithm.rollinghash.test.cpp
- /verify/test/yosupo/z_algorithm.rollinghash.test.cpp.html
title: test/yosupo/z_algorithm.rollinghash.test.cpp
---