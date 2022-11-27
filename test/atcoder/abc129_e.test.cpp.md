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
    PROBLEM: https://atcoder.jp/contests/abc129/tasks/abc129_e
    links:
    - https://atcoder.jp/contests/abc129/tasks/abc129_e
  bundledCode: "#line 1 \"test/atcoder/abc129_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc129/tasks/abc129_e\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Automaton/dfa_dp.hpp\"\n/**\n * @title\
    \ DFA\u4E0A\u306EDP\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @see\
    \ https://kuretchi.github.io/blog/entries/automaton-dp/\n */\n// verify\u7528\
    :\n// https://atcoder.jp/contests/tdpc/tasks/tdpc_number\n// https://atcoder.jp/contests/abc029/tasks/abc029_d\n\
    // https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2\n// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f\n\
    \n// BEGIN CUT HERE\n#ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)     \
    \                         \\\n  template <class T>                           \
    \               \\\n  struct has_##member {                                  \
    \     \\\n    template <class U, Dummy>                                 \\\n \
    \   static std::true_type check(U *);                         \\\n    static std::false_type\
    \ check(...);                        \\\n    static T *mClass;               \
    \                          \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    #endif\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(state_size);\nHAS_MEMBER(eps_transition);\n\
    HAS_MEMBER(is_reject);\n#undef HAS_TYPE\n#undef HAS_MEMBER\n#undef HAS_CHECK\n\
    template <class A>\nusing is_automaton =\n    std::conjunction<has_symbol_t<A>,\
    \ has_alphabet<A>, has_initial_state<A>,\n                     has_transition<A>,\
    \ has_is_accept<A>>;\ntemplate <class A>\nusing trans_t = std::invoke_result_t<decltype(&A::transition),\
    \ A, int,\n                                     typename A::symbol_t, int>;\n\
    template <class DFA>\nconstexpr bool is_dfa_v =\n    std::conjunction_v<has_state_size<DFA>,\
    \ is_automaton<DFA>,\n                       std::is_same<trans_t<DFA>, int>>;\n\
    template <class T, class DFA, class Add, class F>\nT dfa_dp(const DFA &dfa, int\
    \ len, const Add &add, const F &f, const T t0 = T(0),\n         const T init =\
    \ T(1)) {\n  static_assert(is_dfa_v<DFA>);\n  const auto alphabet = dfa.alphabet();\n\
    \  const int S = dfa.state_size();\n  std::vector<T> dp(S, t0);\n  std::vector<char>\
    \ visit(S, false);\n  dp[dfa.initial_state()] = init, visit[dfa.initial_state()]\
    \ = true;\n  for (int i = 0; i < len; i++) {\n    std::vector<T> next(S, t0);\n\
    \    std::vector<char> next_visit(S, false);\n    for (int s = S; s--;)\n    \
    \  if (visit[s])\n        for (const auto &a : alphabet)\n          if (int q\
    \ = dfa.transition(s, a, i); q != -1)\n            add(next[q], f(dp[s], a, i)),\
    \ next_visit[q] = true;\n    dp.swap(next), visit.swap(next_visit);\n  }\n  T\
    \ ret = t0;\n  for (int s = S; s--;)\n    if (dfa.is_accept(s)) add(ret, dp[s]);\n\
    \  return ret;\n}\ntemplate <class T, class DFA>\nT dfa_dp(const DFA &dfa, int\
    \ len, const T t0 = T(0), const T init = T(1)) {\n  return dfa_dp<T>(\n      dfa,\
    \ len, [](T &l, const T &r) { l += r; },\n      [](const T &v, const typename\
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 3 \"src/Automaton/DFA_Inequality.hpp\"\
    \n/**\n * @title $N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\
    \u53D7\u7406\u3059\u308BDFA\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\
    \n * @brief 0-fill\n */\n\n// BEGIN CUT HERE\ntemplate <bool ge = false>  // le\
    \ or ge\nstruct DFA_Inequality {     // view from the top digit\n  using symbol_t\
    \ = int;\n  DFA_Inequality(std::vector<symbol_t> &&str_, std::vector<symbol_t>\
    \ &&alp_)\n      : str(std::move(str_)), alp(std::move(alp_)) {}\n  DFA_Inequality(const\
    \ std::string &n, int m) {  // n : m-ary notation\n    assert(2 <= m && m <= 10);\n\
    \    for (int l = n.length(), i = 0; i < l;) str.push_back(n[i++] - '0');\n  \
    \  for (int i = 0; i < m; i++) alp.push_back(i);\n  }\n  template <class Int>\
    \  // m-ary number\n  DFA_Inequality(Int n, int m, int len = 0) {\n    for (;\
    \ n; n /= m, len--) str.push_back(n % m);\n    while (len-- > 0) str.push_back(0);\n\
    \    for (int i = 0; i < m; i++) alp.push_back(i);\n    std::reverse(str.begin(),\
    \ str.end());\n  }\n  inline std::vector<symbol_t> alphabet() const { return alp;\
    \ }\n  inline int initial_state() const { return 0; }\n  inline int transition(int\
    \ s, const symbol_t &a, int i) const {\n    if (s != 0) return s;\n    if (i >=\
    \ (int)str.size()) return -1;\n    if (a == str[i]) return 0;\n    if constexpr\
    \ (ge)\n      return a < str[i] ? -1 : 1;\n    else\n      return a > str[i] ?\
    \ -1 : 1;\n  }\n  inline bool is_accept(int s) const { return s >= 0; }\n  inline\
    \ int state_size() const { return 2; }\n\n private:\n  std::vector<symbol_t> str,\
    \ alp;\n};\n#line 4 \"src/Automaton/dfa_operations.hpp\"\n/**\n * @title DFA\u306E\
    \u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\u6F14\u7B97\
    \n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n */\n\n// BEGIN CUT HERE\n\
    template <class DFA, class S, class F>\nstruct DFA_SymbolMap {\n  using symbol_t\
    \ = S;\n  DFA_SymbolMap(const DFA &dfa_, const std::vector<symbol_t> &alp_, const\
    \ F &f_)\n      : dfa(dfa_), alp(alp_), f(f_) {\n    static_assert(is_dfa_v<DFA>);\n\
    \  }\n  std::vector<symbol_t> alphabet() const { return alp; }\n  inline int initial_state()\
    \ const { return dfa.initial_state(); }\n  inline int transition(int s, const\
    \ symbol_t &a, int i) const {\n    return dfa.transition(s, f(a), i);\n  }\n \
    \ inline bool is_accept(int s) const { return dfa.is_accept(s); }\n  inline int\
    \ state_size() const { return dfa.state_size(); }\n\n private:\n  const DFA dfa;\n\
    \  const std::vector<symbol_t> alp;\n  const F f;\n};\n\ntemplate <class DFA0,\
    \ class DFA1>\nstruct DFA_Intersection {\n  using symbol_t = typename DFA0::symbol_t;\n\
    \  static_assert(std::is_same_v<symbol_t, typename DFA1::symbol_t>);\n  DFA_Intersection(const\
    \ DFA0 &dfa0_, const DFA1 &dfa1_)\n      : dfa0(dfa0_), dfa1(dfa1_) {\n    static_assert(is_dfa_v<DFA0>);\n\
    \    static_assert(is_dfa_v<DFA1>);\n  }\n  inline std::vector<symbol_t> alphabet()\
    \ const {\n    auto alphabet = dfa0.alphabet();\n    assert(alphabet == dfa1.alphabet());\n\
    \    return alphabet;\n  }\n  inline int initial_state() const {\n    return product(dfa0.initial_state(),\
    \ dfa1.initial_state());\n  }\n  inline int transition(int s, const symbol_t &c,\
    \ int i) const {\n    auto [s0, s1] = projection(s);\n    return product(dfa0.transition(s0,\
    \ c, i), dfa1.transition(s1, c, i));\n  }\n  inline bool is_accept(int s) const\
    \ {\n    auto [s0, s1] = projection(s);\n    return dfa0.is_accept(s0) && dfa1.is_accept(s1);\n\
    \  }\n  inline int state_size() const {\n    return dfa0.state_size() * dfa1.state_size();\n\
    \  }\n\n private:\n  inline int product(int s0, int s1) const {\n    return s0\
    \ == -1 || s1 == -1 ? -1 : s0 + s1 * dfa0.state_size();\n  }\n  inline std::pair<int,\
    \ int> projection(int s) const {\n    return {s % dfa0.state_size(), s / dfa0.state_size()};\n\
    \  }\n  const DFA0 dfa0;\n  const DFA1 dfa1;\n};\ntemplate <class DFA0, class\
    \ DFA1,\n          typename std::enable_if_t<is_dfa_v<DFA0> && is_dfa_v<DFA1>,\n\
    \                                    std::nullptr_t> = nullptr>\nDFA_Intersection<DFA0,\
    \ DFA1> operator&(const DFA0 &dfa0, const DFA1 &dfa1) {\n  return DFA_Intersection<DFA0,\
    \ DFA1>(dfa0, dfa1);\n}\n#line 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\
    \u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n * @category \u6570\u5B66\n */\n\n// BEGIN\
    \ CUT HERE\ntemplate <class Int>\nconstexpr inline Int mod_inv(Int a, Int mod)\
    \ {\n  static_assert(std::is_signed_v<Int>);\n  Int x = 1, y = 0, b = mod;\n \
    \ for (Int q = 0, z = 0, c = 0; b;)\n    z = x, c = a, x = y, y = z - y * (q =\
    \ a / b), a = b, b = c - b * q;\n  return assert(a == 1), x < 0 ? mod - (-x) %\
    \ mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n * @title\
    \ ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\u5B66\n\
    \ * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using u128 = __uint128_t;\nclass MIntPro_Montg {\n  u64 mod, iv, r2;\n  constexpr\
    \ u64 inv(u64 n, int e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2\
    \ - x * n)) : x;\n  }\n  constexpr inline u64 reduce(const u128 &w) const {\n\
    \    return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n\n public:\n\
    \  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0) {}\n  constexpr MIntPro_Montg(u64\
    \ m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr inline u64 mul(u64\
    \ l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op, a) return l\
    \ op## = a, l += (mod << 1) & -(l >> 63)\n  constexpr inline u64 plus(u64 l, u64\
    \ r) const { BOP(+, r - (mod << 1)); }\n  constexpr inline u64 diff(u64 l, u64\
    \ r) const { BOP(-, r); }\n#undef BOP\n  constexpr inline u64 set(u64 n) const\
    \ { return mul(n, r2); }\n  constexpr inline u64 get(u64 n) const {\n    u64 ret\
    \ = reduce(n) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\n  constexpr\
    \ u64 modulo() const { return mod; }\n};\ntemplate <class Uint>\nclass MIntPro_Na\
    \ {\n  using DUint = conditional_t<is_same_v<Uint, u32>, u64, u128>;\n  Uint mod;\n\
    \n public:\n  constexpr MIntPro_Na() : mod(0){};\n  constexpr MIntPro_Na(Uint\
    \ m) : mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r) const { return DUint(l)\
    \ * r % mod; }\n#define BOP(m, p) return l m## = mod & -((l p## = r) >= mod)\n\
    \  constexpr inline Uint plus(Uint l, Uint r) const { BOP(-, +); }\n  constexpr\
    \ inline Uint diff(Uint l, Uint r) const { BOP(+, -); }\n#undef BOP\n  constexpr\
    \ inline Uint set(Uint n) const { return n % mod; }\n  static constexpr inline\
    \ Uint get(Uint n) { return n; }\n  static constexpr inline Uint norm(Uint n)\
    \ { return n; }\n  constexpr Uint modulo() const { return mod; }\n};\ntemplate\
    \ <class Uint, class mod_pro_t>\nconstexpr Uint pow(Uint x, u64 k, const mod_pro_t\
    \ &md) {\n  for (Uint ret = md.set(1);; x = md.mul(x, x))\n    if (k & 1 ? ret\
    \ = md.mul(ret, x) : 0; !(k >>= 1)) return ret;\n}\n}  // namespace math_internal\n\
    #line 5 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\nstruct modint_base {};\n\
    struct sta_mint_base : modint_base {};\nstruct run_mint_base : modint_base {};\n\
    template <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class Uint, class B>\nstruct ModInt : public B\
    \ {\n  static constexpr inline auto modulo() { return B::md.modulo(); }\n  constexpr\
    \ ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x) {}\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt(T\
    \ v) : ModInt(v.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt(T n)\n      : x(B::md.set(n\
    \ < 0 ? modulo() - ((-n) % modulo()) : n)) {}\n  constexpr ModInt operator-()\
    \ const { return ModInt() - *this; }\n#define FUNC(name, op)          \\\n  constexpr\
    \ ModInt name const { \\\n    ModInt ret;                 \\\n    return ret.x\
    \ = op, ret;     \\\n  }\n  FUNC(operator+(const ModInt &r), B::md.plus(x, r.x))\n\
    \  FUNC(operator-(const ModInt &r), B::md.diff(x, r.x))\n  FUNC(operator*(const\
    \ ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64 k), math_internal::pow(x, k,\
    \ B::md))\n#undef FUNC\n  constexpr ModInt operator/(const ModInt &r) const {\
    \ return *this * r.inv(); }\n  constexpr ModInt &operator+=(const ModInt &r) {\
    \ return *this = *this + r; }\n  constexpr ModInt &operator-=(const ModInt &r)\
    \ { return *this = *this - r; }\n  constexpr ModInt &operator*=(const ModInt &r)\
    \ { return *this = *this * r; }\n  constexpr ModInt &operator/=(const ModInt &r)\
    \ { return *this = *this / r; }\n  constexpr bool operator==(const ModInt &r)\
    \ const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr bool\
    \ operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr bool\
    \ operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), modulo());\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 7 \"test/atcoder/abc129_e.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using\
    \ Mint = StaticModInt<int(1e9 + 7)>;\n  string L;\n  cin >> L;\n  vector<tuple<int,\
    \ int, int>> alphabet{{0, 0, 0}, {0, 1, 1}, {1, 0, 1}};\n  auto dfa_le =\n   \
    \   DFA_SymbolMap(DFA_Inequality(L, 2), alphabet,\n                    [](const\
    \ tuple<int, int, int> &a) { return get<2>(a); });\n  cout << dfa_dp<Mint>(dfa_le,\
    \ L.length()) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc129/tasks/abc129_e\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\n#include \"src/Automaton/DFA_Inequality.hpp\"\
    \n#include \"src/Automaton/dfa_operations.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = StaticModInt<int(1e9 + 7)>;\n  string L;\n  cin >> L;\n  vector<tuple<int,\
    \ int, int>> alphabet{{0, 0, 0}, {0, 1, 1}, {1, 0, 1}};\n  auto dfa_le =\n   \
    \   DFA_SymbolMap(DFA_Inequality(L, 2), alphabet,\n                    [](const\
    \ tuple<int, int, int> &a) { return get<2>(a); });\n  cout << dfa_dp<Mint>(dfa_le,\
    \ L.length()) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/DFA_Inequality.hpp
  - src/Automaton/dfa_operations.hpp
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/atcoder/abc129_e.test.cpp
  requiredBy: []
  timestamp: '2022-11-27 14:04:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc129_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc129_e.test.cpp
- /verify/test/atcoder/abc129_e.test.cpp.html
title: test/atcoder/abc129_e.test.cpp
---
