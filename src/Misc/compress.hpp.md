---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0265.test.cpp
    title: test/aoj/0265.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0655.test.cpp
    title: test/aoj/0655.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1047.test.cpp
    title: test/aoj/1047.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2256.test.cpp
    title: test/aoj/2256.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2514.test.cpp
    title: test/aoj/2514.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2893.test.cpp
    title: test/aoj/2893.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3506.test.cpp
    title: test/aoj/3506.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.mo.test.cpp
    title: test/yosupo/static_range_inversions_query.mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1467.test.cpp
    title: test/yukicoder/1467.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2114.test.cpp
    title: test/yukicoder/2114.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.BIT.test.cpp
    title: test/yukicoder/649.BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.SegTree.test.cpp
    title: test/yukicoder/649.SegTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/738.BIT.test.cpp
    title: test/yukicoder/738.BIT.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/compress.hpp\"\n#include <vector>\n#include <algorithm>\n\
    template <class T> auto compress(std::vector<T> &v) {\n return std::sort(v.begin(),\
    \ v.end()), v.erase(std::unique(v.begin(), v.end()), v.end()), [&v](T x) { return\
    \ std::lower_bound(v.begin(), v.end(), x) - v.begin(); };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\ntemplate <class T>\
    \ auto compress(std::vector<T> &v) {\n return std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(),\
    \ v.end()), v.end()), [&v](T x) { return std::lower_bound(v.begin(), v.end(),\
    \ x) - v.begin(); };\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/compress.hpp
  requiredBy: []
  timestamp: '2023-01-21 15:27:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/rooted_tree_isomorphism_classification.test.cpp
  - test/yosupo/static_range_inversions_query.mo.test.cpp
  - test/aoj/1047.test.cpp
  - test/aoj/2893.test.cpp
  - test/aoj/0655.test.cpp
  - test/aoj/2256.test.cpp
  - test/aoj/0265.test.cpp
  - test/aoj/2514.test.cpp
  - test/aoj/3506.test.cpp
  - test/yukicoder/1467.test.cpp
  - test/yukicoder/2114.test.cpp
  - test/yukicoder/649.BIT.test.cpp
  - test/yukicoder/649.SegTree.test.cpp
  - test/yukicoder/738.BIT.test.cpp
documentation_of: src/Misc/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---
