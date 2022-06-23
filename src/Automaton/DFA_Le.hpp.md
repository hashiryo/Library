---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc117_d.test.cpp
    title: test/atcoder/abc117_d.test.cpp
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
    document_title: "$N$\u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\
      \u3059\u308BDFA"
    links: []
  bundledCode: "#line 2 \"src/Automaton/DFA_Le.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title $N$\u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\
    \u308BDFA\n * @category \u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\n * @brief 0-fill\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class S = int>\nstruct DFA_Le {\n  using\
    \ state_t = int;\n  using symbol_t = S;\n  DFA_Le(std::vector<symbol_t> str_,\
    \ std::set<symbol_t> alp_)\n      : str(std::move(str_)), alp(std::move(alp_))\
    \ {}\n  DFA_Le(const std::string &n, int m, int len = 0) {  // n : m-ary notation\n\
    \    assert(2 <= m && m <= 10);\n    for (int l = n.length(), i = l; i--; len--)\
    \ str.push_back(n[i] - '0');\n    while (len-- > 0) str.push_back(0);\n    while\
    \ (m--) alp.insert(m);\n  }\n  template <class Int>  // m-ary number\n  DFA_Le(Int\
    \ n, int m, int len = 0) {\n    for (; n; n /= m, len--) str.push_back(n % m);\n\
    \    while (len-- > 0) str.push_back(0);\n    while (m--) alp.insert(m);\n  }\n\
    \  std::set<symbol_t> alphabet() const { return alp; }\n  state_t initial_state()\
    \ const { return 0; }\n  state_t transition(const state_t s, const symbol_t &a)\
    \ const {\n    const int i = s >> 1;\n    if (i >= str.size()) return (i << 1)\
    \ | 1;\n    if (a < str[i]) return ((i + 1) << 1) | 0;\n    if (a > str[i]) return\
    \ ((i + 1) << 1) | 1;\n    return s + 2;\n  }\n  bool is_accept(const state_t\
    \ s) const { return s == str.size() << 1; }\n\n private:\n  std::vector<symbol_t>\
    \ str;\n  std::set<symbol_t> alp;\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title $N$\u4EE5\u4E0B\u306E\
    \u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\u308BDFA\n * @category \u30AA\
    \u30FC\u30C8\u30DE\u30C8\u30F3\n * @brief 0-fill\n */\n\n// BEGIN CUT HERE\n\n\
    template <class S = int>\nstruct DFA_Le {\n  using state_t = int;\n  using symbol_t\
    \ = S;\n  DFA_Le(std::vector<symbol_t> str_, std::set<symbol_t> alp_)\n      :\
    \ str(std::move(str_)), alp(std::move(alp_)) {}\n  DFA_Le(const std::string &n,\
    \ int m, int len = 0) {  // n : m-ary notation\n    assert(2 <= m && m <= 10);\n\
    \    for (int l = n.length(), i = l; i--; len--) str.push_back(n[i] - '0');\n\
    \    while (len-- > 0) str.push_back(0);\n    while (m--) alp.insert(m);\n  }\n\
    \  template <class Int>  // m-ary number\n  DFA_Le(Int n, int m, int len = 0)\
    \ {\n    for (; n; n /= m, len--) str.push_back(n % m);\n    while (len-- > 0)\
    \ str.push_back(0);\n    while (m--) alp.insert(m);\n  }\n  std::set<symbol_t>\
    \ alphabet() const { return alp; }\n  state_t initial_state() const { return 0;\
    \ }\n  state_t transition(const state_t s, const symbol_t &a) const {\n    const\
    \ int i = s >> 1;\n    if (i >= str.size()) return (i << 1) | 1;\n    if (a <\
    \ str[i]) return ((i + 1) << 1) | 0;\n    if (a > str[i]) return ((i + 1) << 1)\
    \ | 1;\n    return s + 2;\n  }\n  bool is_accept(const state_t s) const { return\
    \ s == str.size() << 1; }\n\n private:\n  std::vector<symbol_t> str;\n  std::set<symbol_t>\
    \ alp;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Automaton/DFA_Le.hpp
  requiredBy: []
  timestamp: '2022-06-23 14:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/abc208_e.test.cpp
  - test/atcoder/arc066_d.test.cpp
  - test/atcoder/abc117_d.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc129_e.test.cpp
documentation_of: src/Automaton/DFA_Le.hpp
layout: document
redirect_from:
- /library/src/Automaton/DFA_Le.hpp
- /library/src/Automaton/DFA_Le.hpp.html
title: "$N$\u4EE5\u4E0B\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\u3059\u308B\
  DFA"
---
