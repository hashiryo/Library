---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/DFA_Inequality.hpp
    title: "$N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\
      \u7406\u3059\u308BDFA"
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  - icon: ':question:'
    path: src/Automaton/dfa_operations.hpp
    title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\
      \u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    template <class A>\nusing is_automaton =\n    std::conjunction<has_symbol_t<A>,\
    \ has_alphabet<A>, has_initial_state<A>,\n                     has_transition<A>,\
    \ has_is_accept<A>>;\ntemplate <class A>\nusing trans_t = std::invoke_result_t<decltype(&A::transition),\
    \ A, int,\n                                     typename A::symbol_t, int>;\n\
    template <class DFA>\nconstexpr bool is_dfa_v =\n    std::conjunction_v<has_state_size<DFA>,\
    \ is_automaton<DFA>,\n                       std::is_same<trans_t<DFA>, int>>;\n\
    template <class T, class DFA, class Add, class F>\nT dfa_dp(const DFA &dfa, int\
    \ len, const Add &add, const F &f, const T t0 = T(0),\n         const T init =\
    \ T(1)) {\n  static_assert(is_dfa_v<DFA>);\n  const auto alphabet = dfa.alphabet();\n\
    \  const int S = dfa.state_size;\n  std::vector<T> dp(S, t0);\n  std::vector<char>\
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
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 4 \"src/Automaton/DFA_Inequality.hpp\"\
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
    \ -1 : 1;\n  }\n  inline bool is_accept(int s) const { return s >= 0; }\n  const\
    \ int state_size = 2;\n\n private:\n  std::vector<symbol_t> str, alp;\n};\n#line\
    \ 4 \"src/Automaton/dfa_operations.hpp\"\n/**\n * @title DFA\u306E\u6587\u5B57\
    \u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\u6F14\u7B97\n * @category\
    \ \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ DFA, class S, class F>\nstruct DFA_SymbolMap {\n  using symbol_t = S;\n  DFA_SymbolMap(const\
    \ DFA &dfa_, const std::vector<symbol_t> &alp_, const F &f_)\n      : state_size(dfa_.state_size),\
    \ dfa(dfa_), alp(alp_), f(f_) {\n    static_assert(is_dfa_v<DFA>);\n  }\n  std::vector<symbol_t>\
    \ alphabet() const { return alp; }\n  inline int initial_state() const { return\
    \ dfa.initial_state(); }\n  inline int transition(int s, const symbol_t &a, int\
    \ i) const {\n    return dfa.transition(s, f(a), i);\n  }\n  inline bool is_accept(int\
    \ s) const { return dfa.is_accept(s); }\n  const int state_size;\n\n private:\n\
    \  const DFA dfa;\n  const std::vector<symbol_t> alp;\n  const F f;\n};\n\ntemplate\
    \ <class DFA0, class DFA1>\nstruct DFA_Intersection {\n  using symbol_t = typename\
    \ DFA0::symbol_t;\n  static_assert(std::is_same_v<symbol_t, typename DFA1::symbol_t>);\n\
    \  DFA_Intersection(const DFA0 &dfa0_, const DFA1 &dfa1_)\n      : state_size(dfa0_.state_size\
    \ * dfa1_.state_size),\n        dfa0(dfa0_),\n        dfa1(dfa1_) {\n    static_assert(is_dfa_v<DFA0>);\n\
    \    static_assert(is_dfa_v<DFA1>);\n  }\n  inline std::vector<symbol_t> alphabet()\
    \ const {\n    auto alphabet = dfa0.alphabet();\n    assert(alphabet == dfa1.alphabet());\n\
    \    return alphabet;\n  }\n  inline int initial_state() const {\n    return product(dfa0.initial_state(),\
    \ dfa1.initial_state());\n  }\n  inline int transition(int s, const symbol_t &c,\
    \ int i) const {\n    auto [s0, s1] = projection(s);\n    return product(dfa0.transition(s0,\
    \ c, i), dfa1.transition(s1, c, i));\n  }\n  inline bool is_accept(int s) const\
    \ {\n    auto [s0, s1] = projection(s);\n    return dfa0.is_accept(s0) && dfa1.is_accept(s1);\n\
    \  }\n  const int state_size;\n\n private:\n  inline int product(int s0, int s1)\
    \ const {\n    return s0 == -1 || s1 == -1 ? -1 : s0 + s1 * dfa0.state_size;\n\
    \  }\n  inline std::pair<int, int> projection(int s) const {\n    return {s %\
    \ dfa0.state_size, s / dfa0.state_size};\n  }\n  const DFA0 dfa0;\n  const DFA1\
    \ dfa1;\n};\ntemplate <class DFA0, class DFA1,\n          typename std::enable_if_t<is_dfa_v<DFA0>\
    \ && is_dfa_v<DFA1>,\n                                    std::nullptr_t> = nullptr>\n\
    DFA_Intersection<DFA0, DFA1> operator&(const DFA0 &dfa0, const DFA1 &dfa1) {\n\
    \  return DFA_Intersection<DFA0, DFA1>(dfa0, dfa1);\n}\n#line 3 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    namespace internal {\ntemplate <std::uint64_t mod, std::uint64_t prim_root, class\
    \ ModInt>\nstruct ModIntImpl {\n  static constexpr std::uint64_t modulo() { return\
    \ mod; }\n  static constexpr std::uint64_t pr_rt() { return prim_root; }\n  friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt &rhs) {\n    return\
    \ os << rhs.val();\n  }\n};\n}  // namespace internal\ntemplate <std::uint64_t\
    \ mod, std::uint64_t prim_root = 0>\nclass ModInt\n    : public internal::ModIntImpl<mod,\
    \ prim_root, ModInt<mod, prim_root>> {\n  using u64 = std::uint64_t;\n  static\
    \ constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e == 0 ? x\
    \ : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv = mul_inv(mod,\
    \ 6, 1), r2 = -__uint128_t(mod) % mod;\n  static constexpr u64 init(u64 w) { return\
    \ reduce(__uint128_t(w) * r2); }\n  static constexpr u64 reduce(const __uint128_t\
    \ w) {\n    return u64(w >> 64) + mod - ((__uint128_t(u64(w) * inv) * mod) >>\
    \ 64);\n  }\n  u64 x;\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr\
    \ ModInt(std::int64_t n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  static\
    \ constexpr u64 norm(u64 w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt\
    \ operator-() const {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x !=\
    \ 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n  \
    \  return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n\
    \  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x\
    \ += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(__uint128_t(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n\
    \  constexpr ModInt pow(std::uint64_t k) const {\n    ModInt ret = ModInt(1);\n\
    \    for (ModInt base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret\
    \ *= base;\n    return ret;\n  }\n  constexpr ModInt inverse() const { return\
    \ pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0)\
    \ || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);\
    \  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod\
    \ - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt,\
    \ ModInt> u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first\
    \ + u.second * v.second * w);\n      ModInt b = (u.first * v.second + u.second\
    \ * v.first);\n      return std::make_pair(a, b);\n    };\n    std::uint64_t e\
    \ = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto\
    \ bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1)\
    \ ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n\
    \  }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    };\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2, pr_rt> : internal::ModIntImpl<2,\
    \ pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t n = 0) : x(n & 1)\
    \ {}\n  constexpr ModInt operator-() const { return *this; }\n  constexpr ModInt\
    \ &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs)\
    \ const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t k) const\
    \ { return !k ? ModInt(1) : *this; }\n  constexpr ModInt sqrt() const { return\
    \ *this; }\n  constexpr ModInt inverse() const { return *this; }\n  constexpr\
    \ std::uint64_t val() const { return x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n  }\n\n private:\n  bool x;\n\
    };\n#line 7 \"test/atcoder/abc129_e.test.cpp\"\nusing namespace std;\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint = ModInt<int(1e9\
    \ + 7)>;\n  string L;\n  cin >> L;\n  vector<tuple<int, int, int>> alphabet{{0,\
    \ 0, 0}, {0, 1, 1}, {1, 0, 1}};\n  auto dfa_le =\n      DFA_SymbolMap(DFA_Inequality(L,\
    \ 2), alphabet,\n                    [](const tuple<int, int, int> &a) { return\
    \ get<2>(a); });\n  cout << dfa_dp<Mint>(dfa_le, L.length()) << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc129/tasks/abc129_e\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\n#include \"src/Automaton/DFA_Inequality.hpp\"\
    \n#include \"src/Automaton/dfa_operations.hpp\"\n#include \"src/Math/ModInt.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<int(1e9 + 7)>;\n  string L;\n  cin >> L;\n  vector<tuple<int,\
    \ int, int>> alphabet{{0, 0, 0}, {0, 1, 1}, {1, 0, 1}};\n  auto dfa_le =\n   \
    \   DFA_SymbolMap(DFA_Inequality(L, 2), alphabet,\n                    [](const\
    \ tuple<int, int, int> &a) { return get<2>(a); });\n  cout << dfa_dp<Mint>(dfa_le,\
    \ L.length()) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/DFA_Inequality.hpp
  - src/Automaton/dfa_operations.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/atcoder/abc129_e.test.cpp
  requiredBy: []
  timestamp: '2022-07-07 13:36:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc129_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc129_e.test.cpp
- /verify/test/atcoder/abc129_e.test.cpp.html
title: test/atcoder/abc129_e.test.cpp
---
