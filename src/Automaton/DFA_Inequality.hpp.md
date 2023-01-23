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
    path: test/atcoder/abc235_f.test.cpp
    title: test/atcoder/abc235_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc127_a.test.cpp
    title: test/atcoder/arc127_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Automaton/DFA_Inequality.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <string>\n#include <cassert>\ntemplate <bool ge=\
    \ false>  // le or ge\nstruct DFA_Inequality {    // view from the top digit\n\
    \ using symbol_t= int;\n DFA_Inequality(std::vector<symbol_t> &&str_, std::vector<symbol_t>\
    \ &&alp_): str(std::move(str_)), alp(std::move(alp_)) {}\n DFA_Inequality(const\
    \ std::string &n, int m) {  // n : m-ary notation\n  assert(2 <= m && m <= 10);\n\
    \  for (int l= n.length(), i= 0; i < l;) str.push_back(n[i++] - '0');\n  for (int\
    \ i= 0; i < m; i++) alp.push_back(i);\n }\n template <class Int>  // m-ary number\n\
    \ DFA_Inequality(Int n, int m, int len= 0) {\n  for (; n; n/= m, len--) str.push_back(n\
    \ % m);\n  while (len-- > 0) str.push_back(0);\n  for (int i= 0; i < m; i++) alp.push_back(i);\n\
    \  std::reverse(str.begin(), str.end());\n }\n inline std::vector<symbol_t> alphabet()\
    \ const { return alp; }\n inline int initial_state() const { return 0; }\n inline\
    \ int transition(int s, const symbol_t &a, int i) const {\n  if (s != 0) return\
    \ s;\n  if (i >= (int)str.size()) return -1;\n  if (a == str[i]) return 0;\n \
    \ if constexpr (ge) return a < str[i] ? -1 : 1;\n  else return a > str[i] ? -1\
    \ : 1;\n }\n inline bool is_accept(int s) const { return s >= 0; }\n inline int\
    \ state_size() const { return 2; }\nprivate:\n std::vector<symbol_t> str, alp;\n\
    };\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <string>\n\
    #include <cassert>\ntemplate <bool ge= false>  // le or ge\nstruct DFA_Inequality\
    \ {    // view from the top digit\n using symbol_t= int;\n DFA_Inequality(std::vector<symbol_t>\
    \ &&str_, std::vector<symbol_t> &&alp_): str(std::move(str_)), alp(std::move(alp_))\
    \ {}\n DFA_Inequality(const std::string &n, int m) {  // n : m-ary notation\n\
    \  assert(2 <= m && m <= 10);\n  for (int l= n.length(), i= 0; i < l;) str.push_back(n[i++]\
    \ - '0');\n  for (int i= 0; i < m; i++) alp.push_back(i);\n }\n template <class\
    \ Int>  // m-ary number\n DFA_Inequality(Int n, int m, int len= 0) {\n  for (;\
    \ n; n/= m, len--) str.push_back(n % m);\n  while (len-- > 0) str.push_back(0);\n\
    \  for (int i= 0; i < m; i++) alp.push_back(i);\n  std::reverse(str.begin(), str.end());\n\
    \ }\n inline std::vector<symbol_t> alphabet() const { return alp; }\n inline int\
    \ initial_state() const { return 0; }\n inline int transition(int s, const symbol_t\
    \ &a, int i) const {\n  if (s != 0) return s;\n  if (i >= (int)str.size()) return\
    \ -1;\n  if (a == str[i]) return 0;\n  if constexpr (ge) return a < str[i] ? -1\
    \ : 1;\n  else return a > str[i] ? -1 : 1;\n }\n inline bool is_accept(int s)\
    \ const { return s >= 0; }\n inline int state_size() const { return 2; }\nprivate:\n\
    \ std::vector<symbol_t> str, alp;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Automaton/DFA_Inequality.hpp
  requiredBy: []
  timestamp: '2023-01-21 18:41:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc208_e.test.cpp
  - test/atcoder/abc235_f.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc117_d.test.cpp
  - test/atcoder/abc129_e.test.cpp
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/arc127_a.test.cpp
documentation_of: src/Automaton/DFA_Inequality.hpp
layout: document
title: "$N$\u4EE5\u4E0B(\u4EE5\u4E0A)\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D7\u7406\
  \u3059\u308BDFA"
---
0-fill