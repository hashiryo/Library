---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Automaton/dfa_dp.hpp
    title: "DFA\u4E0A\u306EDP"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/atcoder/arc066_d.test.cpp
    title: test/atcoder/arc066_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\
      \u30FB\u88DC\u96C6\u5408\u6F14\u7B97"
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
    \      init);\n}\n#line 4 \"src/Automaton/dfa_operations.hpp\"\n/**\n * @title\
    \ DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u30FB\u88DC\u96C6\
    \u5408\u6F14\u7B97\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n */\n\n\
    // BEGIN CUT HERE\ntemplate <class DFA, class S, class F>\nstruct DFA_SymbolMap\
    \ {\n  using state_t = typename DFA::state_t;\n  using symbol_t = S;\n  DFA_SymbolMap(DFA\
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
    \  return DFA_Complement<DFA>(dfa);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Automaton/dfa_dp.hpp\"\
    \n/**\n * @title DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\
    \u30FB\u88DC\u96C6\u5408\u6F14\u7B97\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\
    \u30F3\n */\n\n// BEGIN CUT HERE\ntemplate <class DFA, class S, class F>\nstruct\
    \ DFA_SymbolMap {\n  using state_t = typename DFA::state_t;\n  using symbol_t\
    \ = S;\n  DFA_SymbolMap(DFA dfa_, std::set<symbol_t> alp_, F f_)\n      : dfa(std::move(dfa_)),\
    \ alp(std::move(alp_)), f(std::move(f_)) {\n    static_assert(is_dfa_v<DFA>);\n\
    \  }\n  std::set<symbol_t> alphabet() const { return alp; }\n  state_t initial_state()\
    \ const { return dfa.initial_state(); }\n  state_t transition(const state_t &s,\
    \ const symbol_t &a) const {\n    return dfa.transition(s, f(a));\n  }\n  bool\
    \ is_accept(const state_t &s) const { return dfa.is_accept(s); }\n\n private:\n\
    \  DFA dfa;\n  std::set<symbol_t> alp;\n  F f;\n};\n\ntemplate <class DFA0, class\
    \ DFA1>\nstruct DFA_Intersection {\n  using state_t = std::pair<typename DFA0::state_t,\
    \ typename DFA1::state_t>;\n  using symbol_t = typename DFA0::symbol_t;\n  static_assert(std::is_same_v<symbol_t,\
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
    \  return DFA_Complement<DFA>(dfa);\n}"
  dependsOn:
  - src/Automaton/dfa_dp.hpp
  isVerificationFile: false
  path: src/Automaton/dfa_operations.hpp
  requiredBy: []
  timestamp: '2022-06-23 14:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/abc208_e.test.cpp
  - test/atcoder/arc066_d.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc129_e.test.cpp
documentation_of: src/Automaton/dfa_operations.hpp
layout: document
redirect_from:
- /library/src/Automaton/dfa_operations.hpp
- /library/src/Automaton/dfa_operations.hpp.html
title: "DFA\u306E\u6587\u5B57\u96C6\u5408\u306E\u5909\u63DB\u3068\u7A4D\u30FB\u88DC\
  \u96C6\u5408\u6F14\u7B97"
---
