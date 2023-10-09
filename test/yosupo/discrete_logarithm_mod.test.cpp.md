---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/function_type.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: src/Math/DiscreteLogarithm.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt_Runtime.hpp
    title: "ModInt(\u5B9F\u884C\u6642mod\u30BB\u30C3\u30C8)"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#include <iostream>\n\
    #line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include <cassert>\n\
    template <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q=\
    \ a / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n\
    \ CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod)\
    \ DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const\
    \ { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n)\
    \ * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2():\
    \ mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL\
    \ u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod <<\
    \ 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE\
    \ IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\n\
    private:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return (n * x) >> 84;\
    \ }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod; }\n};\nstruct\
    \ MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0)\
    \ {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    };\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n\
    \ for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x)\
    \ : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
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
    \ return dat[n];\n}\n#line 3 \"src/Math/ModInt_Runtime.hpp\"\nnamespace math_internal\
    \ {\nstruct r_b: m_b {};\ntemplate <class mod_t> constexpr bool is_runtimemodint_v=\
    \ is_base_of_v<r_b, mod_t>;\ntemplate <class MP, u64 M, int id> struct RB: r_b\
    \ {\n static inline void set_mod(u64 m) { md= MP(m); }\n static inline u64 max()\
    \ { return M; }\nprotected:\n static inline MP md;\n};\nclass Montgomery32 {};\n\
    class Montgomery64 {};\nclass Barrett {};\nclass Barrett2 {};\ntemplate <class\
    \ Int, int id= -1> using ModInt_Runtime= conditional_t<is_same_v<Int, Montgomery32>,\
    \ MInt<int, u32, RB<MP_Mo<u32, u64, 32, 31>, (1 << 30), id>>, conditional_t<is_same_v<Int,\
    \ Montgomery64>, MInt<i64, u64, RB<MP_Mo<u64, u128, 64, 63>, (1ull << 62), id>>,\
    \ conditional_t<is_same_v<Int, Barrett>, MInt<int, u32, RB<MP_Br, (1u << 31),\
    \ id>>, conditional_t<is_same_v<Int, Barrett2>, MInt<i64, u64, RB<MP_Br2, (1ull\
    \ << 41), id>>, conditional_t<disjunction_v<is_same<Int, i64>, is_same<Int, u64>>,\
    \ MInt<i64, u64, RB<MP_D2B1, u64(-1), id>>, MInt<int, u32, RB<MP_Na, u32(-1),\
    \ id>>>>>>>;\ntemplate <class T, enable_if_t<is_runtimemodint_v<T>, nullptr_t>\
    \ = nullptr> constexpr u64 mv() { return T::max(); }\n}\nusing math_internal::ModInt_Runtime,\
    \ math_internal::Montgomery32, math_internal::Montgomery64, math_internal::Barrett,\
    \ math_internal::Barrett2, math_internal::is_runtimemodint_v;\n#line 2 \"src/Math/DiscreteLogarithm.hpp\"\
    \n#include <cmath>\n#include <vector>\n#line 3 \"src/Internal/function_type.hpp\"\
    \ntemplate <class C> struct is_function_object {\n template <class U, int dummy=\
    \ (&U::operator(), 0)> static std::true_type check(U *);\n static std::false_type\
    \ check(...);\n static C *m;\n static constexpr bool value= decltype(check(m))::value;\n\
    };\ntemplate <class F, bool, bool> struct function_type_impl {\n using type= void;\n\
    };\ntemplate <class F> struct function_type_impl<F, true, false> {\n using type=\
    \ F *;\n};\ntemplate <class F> struct function_type_impl<F, false, true> {\n using\
    \ type= decltype(&F::operator());\n};\ntemplate <class F> using function_type_t=\
    \ typename function_type_impl<F, std::is_function_v<F>, is_function_object<F>::value>::type;\n\
    template <class... Args> struct result_type_impl {\n using type= void;\n};\ntemplate\
    \ <class R, class... Args> struct result_type_impl<R (*)(Args...)> {\n using type=\
    \ R;\n};\ntemplate <class C, class R, class... Args> struct result_type_impl<R\
    \ (C::*)(Args...)> {\n using type= R;\n};\ntemplate <class C, class R, class...\
    \ Args> struct result_type_impl<R (C::*)(Args...) const> {\n using type= R;\n\
    };\ntemplate <class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n\
    #line 5 \"src/Math/DiscreteLogarithm.hpp\"\n// mp : E \xD7 T -> T\n// op : E \xD7\
    \ E -> E\n// hash : T -> int\n// s,t \u2208 T, x \u2208 E\n// return min{ i :\
    \ x^i(s) = t and i \u2208 [0,N) } or -1 (not found)\ntemplate <class F, class\
    \ G, class H> class DiscreteLogarithm {\n const F &mp;\n const G &op;\n const\
    \ H &hash;\n const int64_t lim;\n using T= result_type_t<F>;\n using E= result_type_t<G>;\n\
    public:\n DiscreteLogarithm(const F &mp, const G &op, const H &hash, int64_t lim=\
    \ 1ll << 50): mp(mp), op(op), hash(hash), lim(lim) { static_assert(std::is_convertible_v<std::invoke_result_t<H,\
    \ T>, int>); }\n int64_t operator()(const E &x, T s, const T &t, int64_t N= -1)\
    \ const {\n  if (N < 0) N= lim;\n  const int m= 1 << std::__lg(int(std::sqrt(N)\
    \ + 1)), mask= m - 1;\n  std::vector<T> val(m), vs(m);\n  std::vector<int> os(m\
    \ + 1), so(m);\n  T s1= t;\n  for (int i= 0; i < m; ++i) ++os[so[i]= hash(val[i]=\
    \ s1= mp(x, s1)) & mask];\n  for (int i= 0; i < m; ++i) os[i + 1]+= os[i];\n \
    \ for (int i= 0; i < m; ++i) vs[--os[so[i]]]= val[i];\n  E y= x;\n  for (int k=\
    \ m; k>>= 1;) y= op(y, y);\n  bool failed= false;\n  for (int64_t n= 0;; s= s1)\
    \ {\n   for (int a= hash(s1= mp(y, s)) & mask, j= os[a]; j < os[a + 1]; ++j) {\n\
    \    if (s1 == vs[j]) {\n     for (int i= 0;; s= mp(x, s)) {\n      if (s == t)\
    \ return n + i < N ? n + i : -1;\n      if (++i == m) break;\n     }\n     if\
    \ (failed) return -1;\n     failed= true;\n     break;\n    }\n   }\n   if ((n+=\
    \ m) >= N) break;\n  }\n  return -1;\n }\n};\n#line 5 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt_Runtime<int>;\n auto f= [](Mint a, Mint b) { return a * b;\
    \ };\n DiscreteLogarithm log(\n     f, f, [](Mint x) { return x.val(); }, 1e9);\n\
    \ int T;\n cin >> T;\n while (T--) {\n  int X, Y, M;\n  cin >> X >> Y >> M;\n\
    \  Mint::set_mod(M);\n  cout << log(X, 1, Y) << '\\n';\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include <iostream>\n#include \"src/Math/ModInt_Runtime.hpp\"\n#include \"src/Math/DiscreteLogarithm.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt_Runtime<int>;\n auto f= [](Mint a, Mint b) { return a * b;\
    \ };\n DiscreteLogarithm log(\n     f, f, [](Mint x) { return x.val(); }, 1e9);\n\
    \ int T;\n cin >> T;\n while (T--) {\n  int X, Y, M;\n  cin >> X >> Y >> M;\n\
    \  Mint::set_mod(M);\n  cout << log(X, 1, Y) << '\\n';\n }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt_Runtime.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Math/DiscreteLogarithm.hpp
  - src/Internal/function_type.hpp
  isVerificationFile: true
  path: test/yosupo/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2023-09-21 00:43:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp.html
title: test/yosupo/discrete_logarithm_mod.test.cpp
---
