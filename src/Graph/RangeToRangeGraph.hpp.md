---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3506.test.cpp
    title: test/aoj/3506.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1170.test.cpp
    title: test/yukicoder/1170.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1868.test.cpp
    title: test/yukicoder/1868.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/RangeToRangeGraph.hpp\"\n#include <vector>\n#include\
    \ <tuple>\ntemplate <typename T= int> class RangeToRangeGraph {\n const int n;\n\
    \ int nn;\n std::vector<std::tuple<int, int, T>> es;\n inline int to_upper_idx(int\
    \ i) const { return i >= n ? i - n : n + i; }\n inline int to_lower_idx(int i)\
    \ const { return i >= n ? i - n : n + n + i; }\npublic:\n RangeToRangeGraph(int\
    \ n): n(n), nn(n * 3) {\n  for (int i= 2; i < n + n; ++i) add(to_upper_idx(i /\
    \ 2), to_upper_idx(i));\n  for (int i= 2; i < n + n; ++i) add(to_lower_idx(i),\
    \ to_lower_idx(i / 2));\n }\n void add(int s, int t, T w= 0) { es.emplace_back(s,\
    \ t, w); }\n // [s_l, s_r) -> t\n void add_from_range(int s_l, int s_r, int t,\
    \ T w= 0) {\n  for (int l= s_l + n, r= s_r + n; l < r; l>>= 1, r>>= 1) {\n   if\
    \ (l & 1) add(to_lower_idx(l++), t, w);\n   if (r & 1) add(to_lower_idx(--r),\
    \ t, w);\n  }\n }\n // s -> [t_l, t_r)\n void add_to_range(int s, int t_l, int\
    \ t_r, T w= 0) {\n  for (int l= t_l + n, r= t_r + n; l < r; l>>= 1, r>>= 1) {\n\
    \   if (l & 1) add(s, to_upper_idx(l++), w);\n   if (r & 1) add(s, to_upper_idx(--r),\
    \ w);\n  }\n }\n // [s_l, s_r) -> [t_l, t_r)\n void add_from_range_to_range(int\
    \ s_l, int s_r, int t_l, int t_r, T w= 0) { add_from_range(s_l, s_r, nn, w), add_to_range(nn,\
    \ t_l, t_r, 0), ++nn; }\n int node_size() const { return nn; }\n std::vector<std::tuple<int,\
    \ int, T>> get_edges() const { return es; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\ntemplate <typename T=\
    \ int> class RangeToRangeGraph {\n const int n;\n int nn;\n std::vector<std::tuple<int,\
    \ int, T>> es;\n inline int to_upper_idx(int i) const { return i >= n ? i - n\
    \ : n + i; }\n inline int to_lower_idx(int i) const { return i >= n ? i - n :\
    \ n + n + i; }\npublic:\n RangeToRangeGraph(int n): n(n), nn(n * 3) {\n  for (int\
    \ i= 2; i < n + n; ++i) add(to_upper_idx(i / 2), to_upper_idx(i));\n  for (int\
    \ i= 2; i < n + n; ++i) add(to_lower_idx(i), to_lower_idx(i / 2));\n }\n void\
    \ add(int s, int t, T w= 0) { es.emplace_back(s, t, w); }\n // [s_l, s_r) -> t\n\
    \ void add_from_range(int s_l, int s_r, int t, T w= 0) {\n  for (int l= s_l +\
    \ n, r= s_r + n; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) add(to_lower_idx(l++),\
    \ t, w);\n   if (r & 1) add(to_lower_idx(--r), t, w);\n  }\n }\n // s -> [t_l,\
    \ t_r)\n void add_to_range(int s, int t_l, int t_r, T w= 0) {\n  for (int l= t_l\
    \ + n, r= t_r + n; l < r; l>>= 1, r>>= 1) {\n   if (l & 1) add(s, to_upper_idx(l++),\
    \ w);\n   if (r & 1) add(s, to_upper_idx(--r), w);\n  }\n }\n // [s_l, s_r) ->\
    \ [t_l, t_r)\n void add_from_range_to_range(int s_l, int s_r, int t_l, int t_r,\
    \ T w= 0) { add_from_range(s_l, s_r, nn, w), add_to_range(nn, t_l, t_r, 0), ++nn;\
    \ }\n int node_size() const { return nn; }\n std::vector<std::tuple<int, int,\
    \ T>> get_edges() const { return es; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/RangeToRangeGraph.hpp
  requiredBy: []
  timestamp: '2023-02-07 15:39:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1170.test.cpp
  - test/yukicoder/1868.test.cpp
  - test/aoj/3506.test.cpp
documentation_of: src/Graph/RangeToRangeGraph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---
## 問題例
[第二回全国統一プログラミング王決定戦予選 D - Shortest Path on a Line](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d) \
[灘校文化祭コンテスト 2022 Day1 I - NPCA Kingdom](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_i)
## 参考
[https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)