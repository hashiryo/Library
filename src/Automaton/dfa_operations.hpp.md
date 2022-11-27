---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc129_e.test.cpp
    title: test/atcoder/abc129_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc138_f.test.cpp
    title: test/atcoder/abc138_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc154_e.test.cpp
    title: test/atcoder/abc154_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc208_e.test.cpp
    title: test/atcoder/abc208_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc235_f.test.cpp
    title: test/atcoder/abc235_f.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc127_a.test.cpp
    title: test/atcoder/arc127_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\
      \u96C6\u5408\u6F14\u7B97"
    links: []
  bundledCode: "#line 2 \"src/Automaton/dfa_operations.hpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Automaton/dfa_dp.hpp\"\n/**\n * @title DFA\u4E0A\u306EDP\n * @category\
    \ \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @see https://kuretchi.github.io/blog/entries/automaton-dp/\n\
    \ */\n// verify\u7528:\n// https://atcoder.jp/contests/tdpc/tasks/tdpc_number\n\
    // https://atcoder.jp/contests/abc029/tasks/abc029_d\n// https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2\n\
    // https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f\n\n// BEGIN CUT HERE\n\
    #ifndef HAS_CHECK\n#define HAS_CHECK(member, Dummy)                          \
    \    \\\n  template <class T>                                          \\\n  struct\
    \ has_##member {                                       \\\n    template <class\
    \ U, Dummy>                                 \\\n    static std::true_type check(U\
    \ *);                         \\\n    static std::false_type check(...);     \
    \                   \\\n    static T *mClass;                                \
    \         \\\n    static const bool value = decltype(check(mClass))::value; \\\
    \n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
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
    \ DFA::symbol_t &, int) { return v; }, t0,\n      init);\n}\n#line 4 \"src/Automaton/dfa_operations.hpp\"\
    \n/**\n * @title DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\
    \u96C6\u5408\u6F14\u7B97\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n\
    \ */\n\n// BEGIN CUT HERE\ntemplate <class DFA, class S, class F>\nstruct DFA_SymbolMap\
    \ {\n  using symbol_t = S;\n  DFA_SymbolMap(const DFA &dfa_, const std::vector<symbol_t>\
    \ &alp_, const F &f_)\n      : dfa(dfa_), alp(alp_), f(f_) {\n    static_assert(is_dfa_v<DFA>);\n\
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
    \ DFA1>(dfa0, dfa1);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n/**\n * @title DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\
    \u96C6\u5408\u6F14\u7B97\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n\
    \ */\n\n// BEGIN CUT HERE\ntemplate <class DFA, class S, class F>\nstruct DFA_SymbolMap\
    \ {\n  using symbol_t = S;\n  DFA_SymbolMap(const DFA &dfa_, const std::vector<symbol_t>\
    \ &alp_, const F &f_)\n      : dfa(dfa_), alp(alp_), f(f_) {\n    static_assert(is_dfa_v<DFA>);\n\
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
    \ DFA1>(dfa0, dfa1);\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/dfa_operations.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:04:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/abc235_f.test.cpp
  - test/atcoder/abc129_e.test.cpp
  - test/atcoder/arc127_a.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc208_e.test.cpp
documentation_of: src/Automaton/dfa_operations.hpp
layout: document
redirect_from:
- /library/src/Automaton/dfa_operations.hpp
- /library/src/Automaton/dfa_operations.hpp.html
title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u96C6\u5408\
  \u6F14\u7B97"
---
