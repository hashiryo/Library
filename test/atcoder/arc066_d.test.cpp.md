---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/DFA_Le.hpp
    title: "$N$\u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\u308B\
      DFA"
  - icon: ':question:'
    path: src/Automaton/NFA_to_DFA.hpp
    title: "NFA\u3092DFA\u306B\u5909\u63DB"
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  - icon: ':question:'
    path: src/Automaton/dfa_operations.hpp
    title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u30FB\u88DC\
      \u96C6\u5408\u6F14\u7B97"
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
    PROBLEM: https://atcoder.jp/contests/arc066/tasks/arc066_b
    links:
    - https://atcoder.jp/contests/arc066/tasks/arc066_b
  bundledCode: "#line 1 \"test/atcoder/arc066_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc066/tasks/arc066_b\"\
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
    #endif\nHAS_TYPE(state_t);\nHAS_TYPE(symbol_t);\nHAS_MEMBER(alphabet);\nHAS_MEMBER(initial_state);\n\
    HAS_MEMBER(transition);\nHAS_MEMBER(is_accept);\nHAS_MEMBER(eps_transition);\n\
    template <class A>\nusing is_automaton =\n    std::conjunction<has_state_t<A>,\
    \ has_symbol_t<A>, has_alphabet<A>,\n                     has_initial_state<A>,\
    \ has_transition<A>, has_is_accept<A>>;\ntemplate <class A>\nusing trans_t = std::invoke_result_t<decltype(&A::transition),\
    \ A,\n                                     typename A::state_t, typename A::symbol_t>;\n\
    template <class DFA>\nconstexpr bool is_dfa_v =\n    std::conjunction_v<is_automaton<DFA>,\n\
    \                       std::is_same<trans_t<DFA>, typename DFA::state_t>>;\n\
    template <class NFA>\nconstexpr bool is_nfa_v = std::conjunction_v<\n    is_automaton<NFA>,\
    \ has_eps_transition<NFA>,\n    std::is_same<trans_t<NFA>, std::set<typename NFA::state_t>>>;\n\
    \ntemplate <class T, class DFA, class Add, class F>\nT dfa_dp(const DFA &dfa,\
    \ int len, const Add &add, const F &f, const T t0 = T(0),\n         const T init\
    \ = T(1)) {\n  static_assert(is_dfa_v<DFA>);\n  const auto alphabet = dfa.alphabet();\n\
    \  std::map<typename DFA::state_t, T> dp;\n  dp[dfa.initial_state()] = init;\n\
    \  for (int i = 0; i < len; i++) {\n    std::map<typename DFA::state_t, T> next;\n\
    \    for (const auto &[k, v] : dp)\n      for (const auto &a : alphabet) {\n \
    \       if (auto q = dfa.transition(k, a); next.count(q))\n          add(next[q],\
    \ f(v, a, i));\n        else\n          next[q] = f(v, a, i);\n      }\n    dp\
    \ = std::move(next);\n  }\n  T ret = t0;\n  for (const auto &[k, v] : dp)\n  \
    \  if (dfa.is_accept(k)) add(ret, v);\n  return ret;\n}\ntemplate <class T, class\
    \ DFA>\nT dfa_dp(const DFA &dfa, int len, const T t0 = T(0), const T init = T(1))\
    \ {\n  return dfa_dp<T>(\n      dfa, len, [](T &l, const T &r) { l += r; },\n\
    \      [](const T &v, const typename DFA::symbol_t &, int) { return v; }, t0,\n\
    \      init);\n}\n#line 3 \"src/Automaton/DFA_Le.hpp\"\n/**\n * @title $N$\u4EE5\
    \u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\u308BDFA\n * @category\
    \ \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @brief 0-fill\n */\n\n// BEGIN CUT\
    \ HERE\n\ntemplate <class S = int>\nstruct DFA_Le {\n  using state_t = int;\n\
    \  using symbol_t = S;\n  DFA_Le(std::vector<symbol_t> str_, std::set<symbol_t>\
    \ alp_)\n      : str(std::move(str_)), alp(std::move(alp_)) {}\n  DFA_Le(const\
    \ std::string &n, int m, int len = 0) {  // n : m-ary notation\n    assert(2 <=\
    \ m && m <= 10);\n    for (int l = n.length(), i = l; i--; len--) str.push_back(n[i]\
    \ - '0');\n    while (len-- > 0) str.push_back(0);\n    while (m--) alp.insert(m);\n\
    \  }\n  template <class Int>  // m-ary number\n  DFA_Le(Int n, int m, int len\
    \ = 0) {\n    for (; n; n /= m, len--) str.push_back(n % m);\n    while (len--\
    \ > 0) str.push_back(0);\n    while (m--) alp.insert(m);\n  }\n  std::set<symbol_t>\
    \ alphabet() const { return alp; }\n  state_t initial_state() const { return 0;\
    \ }\n  state_t transition(const state_t s, const symbol_t &a) const {\n    const\
    \ int i = s >> 1;\n    if (i >= str.size()) return (i << 1) | 1;\n    if (a <\
    \ str[i]) return ((i + 1) << 1) | 0;\n    if (a > str[i]) return ((i + 1) << 1)\
    \ | 1;\n    return s + 2;\n  }\n  bool is_accept(const state_t s) const { return\
    \ s == str.size() << 1; }\n\n private:\n  std::vector<symbol_t> str;\n  std::set<symbol_t>\
    \ alp;\n};\n#line 4 \"src/Automaton/dfa_operations.hpp\"\n/**\n * @title DFA\u306E\
    \u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u30FB\u88DC\u96C6\u5408\
    \u6F14\u7B97\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n */\n\n// BEGIN\
    \ CUT HERE\ntemplate <class DFA, class S, class F>\nstruct DFA_SymbolMap {\n \
    \ using state_t = typename DFA::state_t;\n  using symbol_t = S;\n  DFA_SymbolMap(DFA\
    \ dfa_, std::set<symbol_t> alp_, F f_)\n      : dfa(std::move(dfa_)), alp(std::move(alp_)),\
    \ f(std::move(f_)) {\n    static_assert(is_dfa_v<DFA>);\n  }\n  std::set<symbol_t>\
    \ alphabet() const { return alp; }\n  state_t initial_state() const { return dfa.initial_state();\
    \ }\n  state_t transition(const state_t &s, const symbol_t &a) const {\n    return\
    \ dfa.transition(s, f(a));\n  }\n  bool is_accept(const state_t &s) const { return\
    \ dfa.is_accept(s); }\n\n private:\n  DFA dfa;\n  std::set<symbol_t> alp;\n  F\
    \ f;\n};\n\ntemplate <class DFA0, class DFA1>\nstruct DFA_Intersection {\n  using\
    \ state_t = std::pair<typename DFA0::state_t, typename DFA1::state_t>;\n  using\
    \ symbol_t = typename DFA0::symbol_t;\n  static_assert(std::is_same_v<symbol_t,\
    \ typename DFA1::symbol_t>);\n  DFA_Intersection(DFA0 dfa0_, DFA1 dfa1_)\n   \
    \   : dfa0(std::move(dfa0_)), dfa1(std::move(dfa1_)) {\n    static_assert(is_dfa_v<DFA0>);\n\
    \    static_assert(is_dfa_v<DFA1>);\n  }\n  std::set<symbol_t> alphabet() const\
    \ {\n    auto alphabet = dfa0.alphabet();\n    assert(alphabet == dfa1.alphabet());\n\
    \    return alphabet;\n  }\n  state_t initial_state() const {\n    return {dfa0.initial_state(),\
    \ dfa1.initial_state()};\n  }\n  state_t transition(const state_t &s, const symbol_t\
    \ &c) const {\n    const auto &[s0, s1] = s;\n    return state_t(dfa0.transition(s0,\
    \ c), dfa1.transition(s1, c));\n  }\n  bool is_accept(const state_t &s) const\
    \ {\n    const auto &[s0, s1] = s;\n    return dfa0.is_accept(s0) && dfa1.is_accept(s1);\n\
    \  }\n\n private:\n  DFA0 dfa0;\n  DFA1 dfa1;\n};\ntemplate <class DFA0, class\
    \ DFA1,\n          typename std::enable_if_t<is_dfa_v<DFA0> && is_dfa_v<DFA1>,\n\
    \                                    std::nullptr_t> = nullptr>\nDFA_Intersection<DFA0,\
    \ DFA1> operator&(const DFA0 &dfa0, const DFA1 &dfa1) {\n  return DFA_Intersection<DFA0,\
    \ DFA1>(dfa0, dfa1);\n}\n\ntemplate <class DFA>\nstruct DFA_Complement {\n  using\
    \ state_t = typename DFA::state_t;\n  using symbol_t = typename DFA::symbol_t;\n\
    \  DFA_Complement(DFA dfa_) : dfa(std::move(dfa_)) {\n    static_assert(is_dfa_v<DFA>);\n\
    \  }\n  std::set<symbol_t> alphabet() const { return dfa.alphabet(); }\n  state_t\
    \ initial_state() const { return dfa.initial_state(); }\n  state_t transition(const\
    \ state_t &s, const symbol_t &c) const {\n    return dfa.transition(s, c);\n \
    \ }\n  bool is_accept(const state_t &s) const { return !dfa.is_accept(s); }\n\n\
    \ private:\n  DFA dfa;\n};\ntemplate <class DFA,\n          typename std::enable_if_t<is_dfa_v<DFA>,\
    \ std::nullptr_t> = nullptr>\nDFA_Complement<DFA> operator-(const DFA &dfa) {\n\
    \  return DFA_Complement<DFA>(dfa);\n}\n#line 4 \"src/Automaton/NFA_to_DFA.hpp\"\
    \n/**\n * @title NFA\u3092DFA\u306B\u5909\u63DB\n * @category \u30AA\u30FC\u30C8\
    \u30DE\u30C8\u30F3\n * @see https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836\n\
    \ * @see https://blog.knshnb.com/posts/aoj2587/\n */\n// verify\u7528\n// https://atcoder.jp/contests/abc050/tasks/arc066_b\n\
    \n// BEGIN CUT HERE\n\ntemplate <class NFA>\nstruct NFA_to_DFA {\n  using state_t\
    \ = std::set<typename NFA::state_t>;\n  using symbol_t = typename NFA::symbol_t;\n\
    \  NFA_to_DFA(NFA nfa_) : nfa(std::move(nfa_)) { static_assert(is_nfa_v<NFA>);\
    \ }\n  std::set<symbol_t> alphabet() const { return nfa.alphabet(); }\n  state_t\
    \ initial_state() const { return eps_closure({nfa.initial_state()}); }\n  state_t\
    \ transition(const state_t &s, const symbol_t &c) const {\n    state_t t;\n  \
    \  for (const auto &x : s) {\n      auto ys = nfa.transition(x, c);\n      t.insert(ys.begin(),\
    \ ys.end());\n    }\n    return eps_closure(t);\n  }\n  bool is_accept(const state_t\
    \ &s) const {\n    return std::any_of(s.begin(), s.end(),\n                  \
    \     [&](const auto &x) { return nfa.is_accept(x); });\n  }\n\n private:\n  NFA\
    \ nfa;\n  state_t eps_closure(state_t s) const {\n    for (state_t t; s != t;)\
    \ {\n      t = s;\n      for (const auto &x : t) {\n        auto ys = nfa.eps_transition(x);\n\
    \        s.insert(ys.begin(), ys.end());\n      }\n    }\n    return s;\n  }\n\
    };\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\
    \u5B66\n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate <std::uint64_t\
    \ mod, std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl {\n  static constexpr\
    \ std::uint64_t modulo() { return mod; }\n  static constexpr std::uint64_t pr_rt()\
    \ { return prim_root; }\n  friend std::ostream &operator<<(std::ostream &os, const\
    \ ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace internal\n\
    template <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n    :\
    \ public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n  using\
    \ u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x\
    \ = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n \
    \ static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod) % mod;\n\
    \  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) * r2); }\n\
    \  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w >> 64)\
    \ + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n public:\n\
    \  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n) : x(init(n\
    \ < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64 w) { return\
    \ w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const {\n    ModInt\
    \ ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x - (mod << 1),\
    \ x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator-=(const\
    \ ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n\
    \  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n    return this->x\
    \ = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n  }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return norm(x) == norm(rhs.x); }\n  bool operator!=(const\
    \ ModInt &rhs) const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t\
    \ k) const {\n    ModInt ret = ModInt(1);\n    for (ModInt base = *this; k; k\
    \ >>= 1, base *= base)\n      if (k & 1) ret *= base;\n    return ret;\n  }\n\
    \  constexpr ModInt inverse() const { return pow(mod - 2); }\n  constexpr ModInt\
    \ sqrt() const {\n    if (*this == ModInt(0) || mod == 2) return *this;\n    if\
    \ (pow((mod - 1) >> 1) != 1) return ModInt(0);  // no solutions\n    ModInt ONE\
    \ = 1, b(2), w(b * b - *this);\n    while (w.pow((mod - 1) >> 1) == ONE) b +=\
    \ ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt,\
    \ ModInt> v) {\n      ModInt a = (u.first * v.first + u.second * v.second * w);\n\
    \      ModInt b = (u.first * v.second + u.second * v.first);\n      return std::make_pair(a,\
    \ b);\n    };\n    std::uint64_t e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE,\
    \ ModInt(0));\n    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs,\
    \ bs))\n      if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 <\
    \ mod ? ret.first : -ret.first;\n  }\n  constexpr u64 val() const {\n    u64 ret\
    \ = reduce(x) - mod;\n    return ret + (mod & -(ret >> 63));\n  }\n  friend std::istream\
    \ &operator>>(std::istream &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x\
    \ = init(rhs.x), is;\n  }\n};\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2,\
    \ pr_rt> : internal::ModIntImpl<2, pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t\
    \ n = 0) : x(n & 1) {}\n  constexpr ModInt operator-() const { return *this; }\n\
    \  constexpr ModInt &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator*=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  constexpr ModInt &operator/=(const ModInt &rhs) { return x &= rhs.x, *this;\
    \ }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return x == rhs.x; }\n  bool\
    \ operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n  constexpr\
    \ ModInt pow(std::uint64_t k) const { return !k ? ModInt(1) : *this; }\n  constexpr\
    \ ModInt sqrt() const { return *this; }\n  constexpr ModInt inverse() const {\
    \ return *this; }\n  constexpr std::uint64_t val() const { return x; }\n  friend\
    \ std::istream &operator>>(std::istream &is, ModInt &rhs) {\n    return is >>\
    \ rhs.x, is;\n  }\n\n private:\n  bool x;\n};\n#line 8 \"test/atcoder/arc066_d.test.cpp\"\
    \nusing namespace std;\n\nstruct XorSum {\n  using state_t = int;\n  using symbol_t\
    \ = std::pair<int, int>;\n  std::set<symbol_t> alphabet() const {\n    return\
    \ {{0, 0}, {0, 1}, {1, 0}, {1, 1}};\n  }\n  state_t initial_state() const { return\
    \ 0; }\n  std::set<state_t> transition(const state_t s, const symbol_t &c) const\
    \ {\n    const auto &[u, v] = c;\n    std::set<state_t> ret;\n    for (int a =\
    \ 0; a < 2; a++)\n      for (int b = 0; b < 2; b++)\n        if (((a ^ b) == u)\
    \ && ((a + b + s) % 2 == v))\n          ret.insert((a + b + s) / 2);\n    return\
    \ ret;\n  }\n  std::set<state_t> eps_transition(const state_t) const { return\
    \ {}; }\n  bool is_accept(const state_t s) const { return s == 0; }\n} xor_sum;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using Mint\
    \ = ModInt<int(1e9 + 7)>;\n  long long N;\n  cin >> N;\n  auto alp = xor_sum.alphabet();\n\
    \  auto dfa_le = DFA_Le(N, 2, 60);\n  using S = typename XorSum::symbol_t;\n \
    \ auto dfa_le_l =\n      DFA_SymbolMap(dfa_le, alp, [](const S &a) { return a.first;\
    \ });\n  auto dfa_le_r =\n      DFA_SymbolMap(dfa_le, alp, [](const S &a) { return\
    \ a.second; });\n  cout << dfa_dp<Mint>(NFA_to_DFA(xor_sum) & dfa_le_l & dfa_le_r,\
    \ 60) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc066/tasks/arc066_b\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\n#include \"src/Automaton/DFA_Le.hpp\"\
    \n#include \"src/Automaton/dfa_operations.hpp\"\n#include \"src/Automaton/NFA_to_DFA.hpp\"\
    \n#include \"src/Math/ModInt.hpp\"\nusing namespace std;\n\nstruct XorSum {\n\
    \  using state_t = int;\n  using symbol_t = std::pair<int, int>;\n  std::set<symbol_t>\
    \ alphabet() const {\n    return {{0, 0}, {0, 1}, {1, 0}, {1, 1}};\n  }\n  state_t\
    \ initial_state() const { return 0; }\n  std::set<state_t> transition(const state_t\
    \ s, const symbol_t &c) const {\n    const auto &[u, v] = c;\n    std::set<state_t>\
    \ ret;\n    for (int a = 0; a < 2; a++)\n      for (int b = 0; b < 2; b++)\n \
    \       if (((a ^ b) == u) && ((a + b + s) % 2 == v))\n          ret.insert((a\
    \ + b + s) / 2);\n    return ret;\n  }\n  std::set<state_t> eps_transition(const\
    \ state_t) const { return {}; }\n  bool is_accept(const state_t s) const { return\
    \ s == 0; }\n} xor_sum;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<int(1e9 + 7)>;\n  long long N;\n  cin >> N;\n  auto alp\
    \ = xor_sum.alphabet();\n  auto dfa_le = DFA_Le(N, 2, 60);\n  using S = typename\
    \ XorSum::symbol_t;\n  auto dfa_le_l =\n      DFA_SymbolMap(dfa_le, alp, [](const\
    \ S &a) { return a.first; });\n  auto dfa_le_r =\n      DFA_SymbolMap(dfa_le,\
    \ alp, [](const S &a) { return a.second; });\n  cout << dfa_dp<Mint>(NFA_to_DFA(xor_sum)\
    \ & dfa_le_l & dfa_le_r, 60) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/DFA_Le.hpp
  - src/Automaton/dfa_operations.hpp
  - src/Automaton/NFA_to_DFA.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/atcoder/arc066_d.test.cpp
  requiredBy: []
  timestamp: '2022-06-23 14:03:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/arc066_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc066_d.test.cpp
- /verify/test/atcoder/arc066_d.test.cpp.html
title: test/atcoder/arc066_d.test.cpp
---
