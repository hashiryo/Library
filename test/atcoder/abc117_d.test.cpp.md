---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Automaton/DFA_Le.hpp
    title: "$N$\u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\u308B\
      DFA"
  - icon: ':heavy_check_mark:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc117/tasks/abc117_d
    links:
    - https://atcoder.jp/contests/abc117/tasks/abc117_d
  bundledCode: "#line 1 \"test/atcoder/abc117_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc117/tasks/abc117_d\"\
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
    \ alp;\n};\n#line 5 \"test/atcoder/abc117_d.test.cpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  long long\
    \ N, K;\n  cin >> N >> K;\n  long long A[N];\n  for (int i = 0; i < N; i++) cin\
    \ >> A[i];\n  auto add = [](long long &l, const long long &r) {\n    if (l < r)\
    \ l = r;\n  };\n  auto f = [&](const long long &x, int b, int k) {\n    long long\
    \ val = x;\n    for (int i = N; i--;) val += (((A[i] >> k) & 1) ^ b) << k;\n \
    \   return val;\n  };\n  cout << dfa_dp<long long>(DFA_Le(K, 2, 41), 41, add,\
    \ f, 0, 0) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc117/tasks/abc117_d\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\n#include \"src/Automaton/DFA_Le.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  long long N, K;\n  cin >> N >> K;\n  long long A[N];\n  for (int i = 0; i <\
    \ N; i++) cin >> A[i];\n  auto add = [](long long &l, const long long &r) {\n\
    \    if (l < r) l = r;\n  };\n  auto f = [&](const long long &x, int b, int k)\
    \ {\n    long long val = x;\n    for (int i = N; i--;) val += (((A[i] >> k) &\
    \ 1) ^ b) << k;\n    return val;\n  };\n  cout << dfa_dp<long long>(DFA_Le(K,\
    \ 2, 41), 41, add, f, 0, 0) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  - src/Automaton/DFA_Le.hpp
  isVerificationFile: true
  path: test/atcoder/abc117_d.test.cpp
  requiredBy: []
  timestamp: '2022-06-23 14:03:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc117_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc117_d.test.cpp
- /verify/test/atcoder/abc117_d.test.cpp.html
title: test/atcoder/abc117_d.test.cpp
---
