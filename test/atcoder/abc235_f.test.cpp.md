---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Automaton/DFA_Inequality.hpp
    title: "$N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\
      \u7406\u3059\u308BDFA"
  - icon: ':heavy_check_mark:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  - icon: ':heavy_check_mark:'
    path: src/Automaton/dfa_operations.hpp
    title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\
      \u6F14\u7B97"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
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
    PROBLEM: https://atcoder.jp/contests/abc235/tasks/abc235_f
    links:
    - https://atcoder.jp/contests/abc235/tasks/abc235_f
  bundledCode: "#line 1 \"test/atcoder/abc235_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc235/tasks/abc235_f\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class\
    \ Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
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
    #line 3 \"src/Automaton/dfa_dp.hpp\"\n#ifndef HAS_CHECK\n#define HAS_CHECK(member,\
    \ Dummy) \\\n template <class T> struct has_##member { \\\n  template <class U,\
    \ Dummy> static std::true_type check(U *); \\\n  static std::false_type check(...);\
    \ \\\n  static T *mClass; \\\n  static const bool value= decltype(check(mClass))::value;\
    \ \\\n };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n\
    #endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
    HAS_MEMBER(is_reject);\n#undef HAS_TYPE\n#undef HAS_MEMBER\n#undef HAS_CHECK\n\
    template <class A> using is_automaton= std::conjunction<has_symbol_t<A>, has_alphabet<A>,\
    \ has_initial_state<A>, has_transition<A>, has_is_accept<A>>;\ntemplate <class\
    \ A> using trans_t= std::invoke_result_t<decltype(&A::transition), A, int, typename\
    \ A::symbol_t, int>;\ntemplate <class DFA> constexpr bool is_dfa_v= std::conjunction_v<has_state_size<DFA>,\
    \ is_automaton<DFA>, std::is_same<trans_t<DFA>, int>>;\ntemplate <class T, class\
    \ DFA, class Add, class F> T dfa_dp(const DFA &dfa, int len, const Add &add, const\
    \ F &f, const T t0= T(0), const T init= T(1)) {\n static_assert(is_dfa_v<DFA>);\n\
    \ const auto alphabet= dfa.alphabet();\n const int S= dfa.state_size();\n std::vector<T>\
    \ dp(S, t0);\n std::vector<char> visit(S, false);\n dp[dfa.initial_state()]= init,\
    \ visit[dfa.initial_state()]= true;\n for (int i= 0; i < len; i++) {\n  std::vector<T>\
    \ next(S, t0);\n  std::vector<char> next_visit(S, false);\n  for (int s= S; s--;)\n\
    \   if (visit[s])\n    for (const auto &a: alphabet)\n     if (int q= dfa.transition(s,\
    \ a, i); q != -1) add(next[q], f(dp[s], a, i)), next_visit[q]= true;\n  dp.swap(next),\
    \ visit.swap(next_visit);\n }\n T ret= t0;\n for (int s= S; s--;)\n  if (dfa.is_accept(s))\
    \ add(ret, dp[s]);\n return ret;\n}\ntemplate <class T, class DFA> T dfa_dp(const\
    \ DFA &dfa, int len, const T t0= T(0), const T init= T(1)) {\n return dfa_dp<T>(\n\
    \     dfa, len, [](T &l, const T &r) { l+= r; }, [](const T &v, const typename\
    \ DFA::symbol_t &, int) { return v; }, t0, init);\n}\n#line 4 \"src/Automaton/dfa_operations.hpp\"\
    \ntemplate <class DFA, class S, class F> struct DFA_SymbolMap {\n using symbol_t=\
    \ S;\n DFA_SymbolMap(const DFA &dfa_, const std::vector<symbol_t> &alp_, const\
    \ F &f_): dfa(dfa_), alp(alp_), f(f_) { static_assert(is_dfa_v<DFA>); }\n std::vector<symbol_t>\
    \ alphabet() const { return alp; }\n inline int initial_state() const { return\
    \ dfa.initial_state(); }\n inline int transition(int s, const symbol_t &a, int\
    \ i) const { return dfa.transition(s, f(a), i); }\n inline bool is_accept(int\
    \ s) const { return dfa.is_accept(s); }\n inline int state_size() const { return\
    \ dfa.state_size(); }\nprivate:\n const DFA dfa;\n const std::vector<symbol_t>\
    \ alp;\n const F f;\n};\ntemplate <class DFA0, class DFA1> struct DFA_Intersection\
    \ {\n using symbol_t= typename DFA0::symbol_t;\n static_assert(std::is_same_v<symbol_t,\
    \ typename DFA1::symbol_t>);\n DFA_Intersection(const DFA0 &dfa0_, const DFA1\
    \ &dfa1_): dfa0(dfa0_), dfa1(dfa1_) {\n  static_assert(is_dfa_v<DFA0>);\n  static_assert(is_dfa_v<DFA1>);\n\
    \ }\n inline std::vector<symbol_t> alphabet() const {\n  auto alphabet= dfa0.alphabet();\n\
    \  assert(alphabet == dfa1.alphabet());\n  return alphabet;\n }\n inline int initial_state()\
    \ const { return product(dfa0.initial_state(), dfa1.initial_state()); }\n inline\
    \ int transition(int s, const symbol_t &c, int i) const {\n  auto [s0, s1]= projection(s);\n\
    \  return product(dfa0.transition(s0, c, i), dfa1.transition(s1, c, i));\n }\n\
    \ inline bool is_accept(int s) const {\n  auto [s0, s1]= projection(s);\n  return\
    \ dfa0.is_accept(s0) && dfa1.is_accept(s1);\n }\n inline int state_size() const\
    \ { return dfa0.state_size() * dfa1.state_size(); }\nprivate:\n inline int product(int\
    \ s0, int s1) const { return s0 == -1 || s1 == -1 ? -1 : s0 + s1 * dfa0.state_size();\
    \ }\n inline std::pair<int, int> projection(int s) const { return {s % dfa0.state_size(),\
    \ s / dfa0.state_size()}; }\n const DFA0 dfa0;\n const DFA1 dfa1;\n};\ntemplate\
    \ <class DFA0, class DFA1, typename std::enable_if_t<is_dfa_v<DFA0> && is_dfa_v<DFA1>,\
    \ std::nullptr_t> = nullptr> DFA_Intersection<DFA0, DFA1> operator&(const DFA0\
    \ &dfa0, const DFA1 &dfa1) { return DFA_Intersection<DFA0, DFA1>(dfa0, dfa1);\
    \ }\n#line 3 \"src/Automaton/DFA_Inequality.hpp\"\ntemplate <bool ge= false> \
    \ // le or ge\nstruct DFA_Inequality {    // view from the top digit\n using symbol_t=\
    \ int;\n DFA_Inequality(std::vector<symbol_t> &&str_, std::vector<symbol_t> &&alp_):\
    \ str(std::move(str_)), alp(std::move(alp_)) {}\n DFA_Inequality(const std::string\
    \ &n, int m) {  // n : m-ary notation\n  assert(2 <= m && m <= 10);\n  for (int\
    \ l= n.length(), i= 0; i < l;) str.push_back(n[i++] - '0');\n  for (int i= 0;\
    \ i < m; i++) alp.push_back(i);\n }\n template <class Int>  // m-ary number\n\
    \ DFA_Inequality(Int n, int m, int len= 0) {\n  for (; n; n/= m, len--) str.push_back(n\
    \ % m);\n  while (len-- > 0) str.push_back(0);\n  for (int i= 0; i < m; i++) alp.push_back(i);\n\
    \  std::reverse(str.begin(), str.end());\n }\n inline std::vector<symbol_t> alphabet()\
    \ const { return alp; }\n inline int initial_state() const { return 0; }\n inline\
    \ int transition(int s, const symbol_t &a, int i) const {\n  if (s != 0) return\
    \ s;\n  if (i >= (int)str.size()) return -1;\n  if (a == str[i]) return 0;\n \
    \ if constexpr (ge) return a < str[i] ? -1 : 1;\n  else return a > str[i] ? -1\
    \ : 1;\n }\n inline bool is_accept(int s) const { return s >= 0; }\n inline int\
    \ state_size() const { return 2; }\nprivate:\n std::vector<symbol_t> str, alp;\n\
    };\n#line 7 \"test/atcoder/abc235_f.test.cpp\"\nusing namespace std;\n\nclass\
    \ DFA_Variety {\n  int conclude;\n\n public:\n  using symbol_t = int;\n  DFA_Variety(int\
    \ c) : conclude(c) {}\n  inline std::vector<symbol_t> alphabet() const {\n   \
    \ return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};\n  }\n  inline int initial_state() const\
    \ { return 0; }\n  inline int transition(int s, const symbol_t &a, int) const\
    \ {\n    return s | ((a || s) << a);\n  }\n  inline bool is_accept(int s) const\
    \ { return (s & conclude) == conclude; }\n  inline int state_size() const { return\
    \ 1 << 10; }\n};\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  string N;\n  cin >> N;\n  int M;\n\
    \  cin >> M;\n  int c = 0;\n  for (int i = 0; i < M; i++) {\n    int C;\n    cin\
    \ >> C, c |= 1 << C;\n  }\n  using T = pair<Mint, Mint>;\n  auto add = [](T &l,\
    \ const T &r) { l.first += r.first, l.second += r.second; };\n  auto f = [](const\
    \ T &v, int a, int) -> T {\n    return {v.first * 10 + v.second * a, v.second};\n\
    \  };\n  DFA_Variety dfa_v(c);\n  DFA_Inequality dfa_le(N, 10);\n  cout << dfa_dp<T>(dfa_v\
    \ & dfa_le, N.length(), add, f, {0, 0}, {0, 1}).first\n       << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc235/tasks/abc235_f\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n#include \"src/Automaton/dfa_operations.hpp\"\n#include \"src/Automaton/DFA_Inequality.hpp\"\
    \nusing namespace std;\n\nclass DFA_Variety {\n  int conclude;\n\n public:\n \
    \ using symbol_t = int;\n  DFA_Variety(int c) : conclude(c) {}\n  inline std::vector<symbol_t>\
    \ alphabet() const {\n    return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};\n  }\n  inline\
    \ int initial_state() const { return 0; }\n  inline int transition(int s, const\
    \ symbol_t &a, int) const {\n    return s | ((a || s) << a);\n  }\n  inline bool\
    \ is_accept(int s) const { return (s & conclude) == conclude; }\n  inline int\
    \ state_size() const { return 1 << 10; }\n};\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n  string\
    \ N;\n  cin >> N;\n  int M;\n  cin >> M;\n  int c = 0;\n  for (int i = 0; i <\
    \ M; i++) {\n    int C;\n    cin >> C, c |= 1 << C;\n  }\n  using T = pair<Mint,\
    \ Mint>;\n  auto add = [](T &l, const T &r) { l.first += r.first, l.second +=\
    \ r.second; };\n  auto f = [](const T &v, int a, int) -> T {\n    return {v.first\
    \ * 10 + v.second * a, v.second};\n  };\n  DFA_Variety dfa_v(c);\n  DFA_Inequality\
    \ dfa_le(N, 10);\n  cout << dfa_dp<T>(dfa_v & dfa_le, N.length(), add, f, {0,\
    \ 0}, {0, 1}).first\n       << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/dfa_operations.hpp
  - src/Automaton/DFA_Inequality.hpp
  isVerificationFile: true
  path: test/atcoder/abc235_f.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 22:35:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc235_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc235_f.test.cpp
- /verify/test/atcoder/abc235_f.test.cpp.html
title: test/atcoder/abc235_f.test.cpp
---
