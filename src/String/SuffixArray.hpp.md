---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/String/SuffixTree.hpp
    title: "Suffix Tree (\u63A5\u5C3E\u8F9E\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.SA.test.cpp
    title: test/aoj/3112.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.SA.test.cpp
    title: test/aoj/ALDS1_14_B.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.SA.test.cpp
    title: test/aoj/ALDS1_14_D.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc141_e.SuffixTree.test.cpp
    title: test/atcoder/abc141_e.SuffixTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_f.SA.test.cpp
    title: test/atcoder/abc213_f.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc213_f.SuffixTree.test.cpp
    title: test/atcoder/abc213_f.SuffixTree.test.cpp
  - icon: ':x:'
    path: test/hackerrank/ashton-and-string.SuffixTree.test.cpp
    title: test/hackerrank/ashton-and-string.SuffixTree.test.cpp
  - icon: ':x:'
    path: test/hackerrank/string-function-calculation.SuffixTree.test.cpp
    title: test/hackerrank/string-function-calculation.SuffixTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/longest_common_substring.test.cpp
    title: test/yosupo/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.SA.test.cpp
    title: test/yosupo/number_of_substrings.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2361.SuffixTree.test.cpp
    title: test/yukicoder/2361.SuffixTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/SuffixArray.hpp\"\n#include <string>\n#include\
    \ <vector>\n#include <algorithm>\ntemplate <class String> struct SuffixArray {\n\
    \ String s;\n std::vector<int> sa;\n static inline std::vector<int> sa_is(const\
    \ std::vector<int> &s, int K) {\n  const int n= s.size();\n  std::vector<char>\
    \ t(n);\n  std::vector<int> bkt(K, 0), bkt_l(K), bkt_r(K), sa(n), p1;\n  t.back()=\
    \ true;\n  for (int i= n; --i;)\n   if (t[i - 1]= (s[i - 1] < s[i] || (t[i] &&\
    \ s[i - 1] == s[i])); t[i] && !t[i - 1]) p1.push_back(i);\n  std::reverse(p1.begin(),\
    \ p1.end());\n  const int n1= p1.size();\n  for (int i= n; i--;) ++bkt[s[i]];\n\
    \  for (int i= 0, sum= 0; i < K; ++i) sum+= bkt[i], bkt_r[i]= sum, bkt_l[i]= sum\
    \ - bkt[i];\n  std::vector<int> s1(n1), sa1(n1);\n  std::fill_n(sa.begin(), n,\
    \ -1), std::copy_n(bkt_r.begin(), K, bkt.begin());\n  for (int i= n1; i--;) sa[--bkt[s[p1[i]]]]=\
    \ p1[i];\n  std::copy_n(bkt_l.begin(), K, bkt.begin());\n  for (int i= 0, j; i\
    \ < n; ++i)\n   if ((j= sa[i] - 1) >= 0 && !t[j]) sa[bkt[s[j]]++]= j;\n  std::copy_n(bkt_r.begin(),\
    \ K, bkt.begin());\n  for (int i= n, j; i--;)\n   if ((j= sa[i] - 1) >= 0 && t[j])\
    \ sa[--bkt[s[j]]]= j;\n  for (int i= 0, j= 0; i < n; ++i)\n   if (t[sa[i]] &&\
    \ sa[i] > 0 && !t[sa[i] - 1]) sa1[j++]= sa[i];\n  int name= 0;\n  for (int i=\
    \ 0, prev= -1, j, pos; i < n1; ++i, sa[pos]= name - 1)\n   for (j= 0, pos= sa1[i];;\
    \ ++j)\n    if (prev == -1 || s[pos + j] != s[prev + j] || t[pos + j] != t[prev\
    \ + j]) {\n     prev= pos, ++name;\n     break;\n    } else if (j && ((t[pos +\
    \ j] && !t[pos + j - 1]) || (t[prev + j] && !t[prev + j - 1]))) break;\n  for\
    \ (int i= n1; i--;) s1[i]= sa[p1[i]];\n  if (name != n1) sa1= sa_is(s1, name);\n\
    \  else\n   for (int i= n1; i--;) sa1[s1[i]]= i;\n  std::copy_n(bkt_r.begin(),\
    \ K, bkt.begin()), std::fill_n(sa.begin(), n, -1);\n  for (int i= n1; i--;) sa[--bkt[s[p1[sa1[i]]]]]=\
    \ p1[sa1[i]];\n  for (int i= 0, j; i < n; ++i)\n   if ((j= sa[i] - 1) >= 0 &&\
    \ !t[j]) sa[bkt_l[s[j]]++]= j;\n  for (int i= n, j; i--;)\n   if ((j= sa[i] -\
    \ 1) >= 0 && t[j]) sa[--bkt_r[s[j]]]= j;\n  return sa;\n }\npublic:\n SuffixArray(const\
    \ String &S): s(S) {\n  std::vector<int> s_cpy(s.size() + 1);\n  if constexpr\
    \ (std::is_convertible_v<String, std::string>) std::copy(s.begin(), s.end(), s_cpy.begin()),\
    \ sa= sa_is(s_cpy, 128), sa.erase(sa.begin());\n  else {\n   auto v= s;\n   sort(v.begin(),\
    \ v.end()), v.erase(unique(v.begin(), v.end()), v.end());\n   for (int i= s.size();\
    \ i--;) s_cpy[i]= std::lower_bound(v.begin(), v.end(), s[i]) - v.begin() + 1;\n\
    \   sa= sa_is(s_cpy, v.size() + 1), sa.erase(sa.begin());\n  }\n }\n int operator[](int\
    \ i) const { return sa[i]; }\n size_t size() const { return sa.size(); }\n auto\
    \ begin() const { return sa.begin(); }\n auto end() const { return sa.end(); }\n\
    \ // return {l,r} s.t. P is a prefix of S[sa[i]:] ( i in [l,r) )\n // l == r if\
    \ P is not a substring of S\n // O(|P|log|S|)\n std::pair<int, int> pattern_matching(const\
    \ String &P) const {\n  const int n= s.size(), m= P.size();\n  if (n < m) return\
    \ {0, 0};\n  auto f1= [&](int h) {\n   auto t= s.begin() + h;\n   for (int j=\
    \ 0, e= std::min(n - h, m); j < e; ++j) {\n    if (t[j] < P[j]) return true;\n\
    \    if (t[j] > P[j]) return false;\n   }\n   return n - h < m;\n  };\n  auto\
    \ f2= [&](int h) {\n   auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n\
    \ - h, m); j < e; ++j)\n    if (t[j] > P[j]) return false;\n   return true;\n\
    \  };\n  auto L= std::partition_point(sa.begin(), sa.end(), f1), R= std::partition_point(L,\
    \ sa.end(), f2);\n  return {L - sa.begin(), R - sa.begin()};\n }\n};\nstruct LCPArray\
    \ {\n std::vector<int> rnk;\n template <class String> LCPArray(const SuffixArray<String>\
    \ &sa): rnk(sa.size()) {\n  const int n= sa.size(), log= n > 2 ? 31 - __builtin_clz(n\
    \ - 2) : 0;\n  dat.resize(log + 1), dat[0].resize(n - 1);\n  auto &lcp= dat[0];\n\
    \  for (int i= n; i--;) rnk[sa[i]]= i;\n  for (int i= 0, h= 0; i < n; ++i) {\n\
    \   if (rnk[i] == n - 1) {\n    h= 0;\n    continue;\n   }\n   for (int j= sa[rnk[i]\
    \ + 1]; i + h < n && j + h < n && sa.s[i + h] == sa.s[j + h];) ++h;\n   if ((lcp[rnk[i]]=\
    \ h)) --h;\n  }\n  for (int i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i\
    \ + 1].resize(j= dat[i].size() - I); j--;) dat[i + 1][j]= std::min(dat[i][j],\
    \ dat[i][j + I]);\n }\n int operator[](int i) const { return dat[0][i]; }\n size_t\
    \ size() const { return dat[0].size(); }\n auto begin() const { return dat[0].begin();\
    \ }\n auto end() const { return dat[0].end(); }\n int operator()(int i, int j)\
    \ const {\n  if (i == j) return rnk.size() - i;\n  auto [l, r]= std::minmax(rnk[i],\
    \ rnk[j]);\n  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r\
    \ - l - 1);\n  return std::min(dat[k][l], dat[k][r - (1 << k)]);\n }\nprivate:\n\
    \ std::vector<std::vector<int>> dat;\n};\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    template <class String> struct SuffixArray {\n String s;\n std::vector<int> sa;\n\
    \ static inline std::vector<int> sa_is(const std::vector<int> &s, int K) {\n \
    \ const int n= s.size();\n  std::vector<char> t(n);\n  std::vector<int> bkt(K,\
    \ 0), bkt_l(K), bkt_r(K), sa(n), p1;\n  t.back()= true;\n  for (int i= n; --i;)\n\
    \   if (t[i - 1]= (s[i - 1] < s[i] || (t[i] && s[i - 1] == s[i])); t[i] && !t[i\
    \ - 1]) p1.push_back(i);\n  std::reverse(p1.begin(), p1.end());\n  const int n1=\
    \ p1.size();\n  for (int i= n; i--;) ++bkt[s[i]];\n  for (int i= 0, sum= 0; i\
    \ < K; ++i) sum+= bkt[i], bkt_r[i]= sum, bkt_l[i]= sum - bkt[i];\n  std::vector<int>\
    \ s1(n1), sa1(n1);\n  std::fill_n(sa.begin(), n, -1), std::copy_n(bkt_r.begin(),\
    \ K, bkt.begin());\n  for (int i= n1; i--;) sa[--bkt[s[p1[i]]]]= p1[i];\n  std::copy_n(bkt_l.begin(),\
    \ K, bkt.begin());\n  for (int i= 0, j; i < n; ++i)\n   if ((j= sa[i] - 1) >=\
    \ 0 && !t[j]) sa[bkt[s[j]]++]= j;\n  std::copy_n(bkt_r.begin(), K, bkt.begin());\n\
    \  for (int i= n, j; i--;)\n   if ((j= sa[i] - 1) >= 0 && t[j]) sa[--bkt[s[j]]]=\
    \ j;\n  for (int i= 0, j= 0; i < n; ++i)\n   if (t[sa[i]] && sa[i] > 0 && !t[sa[i]\
    \ - 1]) sa1[j++]= sa[i];\n  int name= 0;\n  for (int i= 0, prev= -1, j, pos; i\
    \ < n1; ++i, sa[pos]= name - 1)\n   for (j= 0, pos= sa1[i];; ++j)\n    if (prev\
    \ == -1 || s[pos + j] != s[prev + j] || t[pos + j] != t[prev + j]) {\n     prev=\
    \ pos, ++name;\n     break;\n    } else if (j && ((t[pos + j] && !t[pos + j -\
    \ 1]) || (t[prev + j] && !t[prev + j - 1]))) break;\n  for (int i= n1; i--;) s1[i]=\
    \ sa[p1[i]];\n  if (name != n1) sa1= sa_is(s1, name);\n  else\n   for (int i=\
    \ n1; i--;) sa1[s1[i]]= i;\n  std::copy_n(bkt_r.begin(), K, bkt.begin()), std::fill_n(sa.begin(),\
    \ n, -1);\n  for (int i= n1; i--;) sa[--bkt[s[p1[sa1[i]]]]]= p1[sa1[i]];\n  for\
    \ (int i= 0, j; i < n; ++i)\n   if ((j= sa[i] - 1) >= 0 && !t[j]) sa[bkt_l[s[j]]++]=\
    \ j;\n  for (int i= n, j; i--;)\n   if ((j= sa[i] - 1) >= 0 && t[j]) sa[--bkt_r[s[j]]]=\
    \ j;\n  return sa;\n }\npublic:\n SuffixArray(const String &S): s(S) {\n  std::vector<int>\
    \ s_cpy(s.size() + 1);\n  if constexpr (std::is_convertible_v<String, std::string>)\
    \ std::copy(s.begin(), s.end(), s_cpy.begin()), sa= sa_is(s_cpy, 128), sa.erase(sa.begin());\n\
    \  else {\n   auto v= s;\n   sort(v.begin(), v.end()), v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n   for (int i= s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(),\
    \ v.end(), s[i]) - v.begin() + 1;\n   sa= sa_is(s_cpy, v.size() + 1), sa.erase(sa.begin());\n\
    \  }\n }\n int operator[](int i) const { return sa[i]; }\n size_t size() const\
    \ { return sa.size(); }\n auto begin() const { return sa.begin(); }\n auto end()\
    \ const { return sa.end(); }\n // return {l,r} s.t. P is a prefix of S[sa[i]:]\
    \ ( i in [l,r) )\n // l == r if P is not a substring of S\n // O(|P|log|S|)\n\
    \ std::pair<int, int> pattern_matching(const String &P) const {\n  const int n=\
    \ s.size(), m= P.size();\n  if (n < m) return {0, 0};\n  auto f1= [&](int h) {\n\
    \   auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\
    \ {\n    if (t[j] < P[j]) return true;\n    if (t[j] > P[j]) return false;\n \
    \  }\n   return n - h < m;\n  };\n  auto f2= [&](int h) {\n   auto t= s.begin()\
    \ + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\n    if (t[j] > P[j])\
    \ return false;\n   return true;\n  };\n  auto L= std::partition_point(sa.begin(),\
    \ sa.end(), f1), R= std::partition_point(L, sa.end(), f2);\n  return {L - sa.begin(),\
    \ R - sa.begin()};\n }\n};\nstruct LCPArray {\n std::vector<int> rnk;\n template\
    \ <class String> LCPArray(const SuffixArray<String> &sa): rnk(sa.size()) {\n \
    \ const int n= sa.size(), log= n > 2 ? 31 - __builtin_clz(n - 2) : 0;\n  dat.resize(log\
    \ + 1), dat[0].resize(n - 1);\n  auto &lcp= dat[0];\n  for (int i= n; i--;) rnk[sa[i]]=\
    \ i;\n  for (int i= 0, h= 0; i < n; ++i) {\n   if (rnk[i] == n - 1) {\n    h=\
    \ 0;\n    continue;\n   }\n   for (int j= sa[rnk[i] + 1]; i + h < n && j + h <\
    \ n && sa.s[i + h] == sa.s[j + h];) ++h;\n   if ((lcp[rnk[i]]= h)) --h;\n  }\n\
    \  for (int i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j=\
    \ dat[i].size() - I); j--;) dat[i + 1][j]= std::min(dat[i][j], dat[i][j + I]);\n\
    \ }\n int operator[](int i) const { return dat[0][i]; }\n size_t size() const\
    \ { return dat[0].size(); }\n auto begin() const { return dat[0].begin(); }\n\
    \ auto end() const { return dat[0].end(); }\n int operator()(int i, int j) const\
    \ {\n  if (i == j) return rnk.size() - i;\n  auto [l, r]= std::minmax(rnk[i],\
    \ rnk[j]);\n  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r\
    \ - l - 1);\n  return std::min(dat[k][l], dat[k][r - (1 << k)]);\n }\nprivate:\n\
    \ std::vector<std::vector<int>> dat;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/SuffixArray.hpp
  requiredBy:
  - src/String/SuffixTree.hpp
  timestamp: '2023-11-22 11:53:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/hackerrank/string-function-calculation.SuffixTree.test.cpp
  - test/hackerrank/ashton-and-string.SuffixTree.test.cpp
  - test/yosupo/longest_common_substring.test.cpp
  - test/yosupo/suffixarray.test.cpp
  - test/yosupo/number_of_substrings.SA.test.cpp
  - test/yukicoder/2361.SuffixTree.test.cpp
  - test/aoj/ALDS1_14_D.SA.test.cpp
  - test/aoj/2644.test.cpp
  - test/aoj/3112.SA.test.cpp
  - test/aoj/ALDS1_14_B.SA.test.cpp
  - test/atcoder/abc141_e.SuffixTree.test.cpp
  - test/atcoder/abc213_f.SA.test.cpp
  - test/atcoder/abc213_f.SuffixTree.test.cpp
documentation_of: src/String/SuffixArray.hpp
layout: document
title: "Suffix Array (\u63A5\u5C3E\u8F9E\u914D\u5217)"
---

$\newcommand{\SA}{\mathrm{SA}}$
文字列 $S$ に対して構築することにする. \
文字列 $S$ の $k$ 文字目から開始した接尾辞を $S_{k:}$ と表すことにする.\
また $n = \lvert S\rvert$ とおく. 

## `SuffixArray<String>` クラス
` String`: 対象とする文字列を表現する型. `string` か `vector<int>` を想定.

接尾辞配列を $\SA$ とおく.\
$\SA_k=i \Leftrightarrow$ 接尾辞を辞書順で並べたときの $k$ 番目 (0-index) が $S_{i:}$ 
|メンバ変数|概要|
|---|---|
|`sa`| 接尾辞配列 $\SA$. <br>`vector<int>` 型でサイズは $n$.|
|`s`| 元の文字列.  <br> `String` 型でサイズは $n$.|

|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixArray(S)`|コンストラクタ. 文字列 $S$ を渡す. <br> 引数は通常 `vector<T>` か `string` を想定.|$\mathcal{O}(n)$ か $\mathcal{O}(n\log n)$|
|`operator[](k)`| $\SA_k$ を返す.||
|`begin()`|$\SA$ の `begin()` を返す.||
|`end()`|$\SA$ の `end()` を返す||
|`size()`|$n$ を返す.||
|`pattern_matching(P)`|文字列 $S$ の部分文字列でパターン文字列 $P$ と一致する箇所を探す.<br> 返り値は二つの非負整数 $l, r$ <br>s.t. $\lbrace \SA_k\;\vert\; l \leq k \lt r \rbrace = \lbrace i \;\vert\;P$ が $S_{i:}$ の接頭辞$\rbrace$ <br> ただし $P$ が $S$ の部分文字列でないとき $l=r$ .<br> 引数は `String`.|$\mathcal{O}(\lvert P\rvert \log n)$|

## `LCPArray` クラス
$\mathrm{LCP}_k:=$ $S_{\SA_k:}$ と $S_{\SA_{k+1}:}$ の共通接頭辞の長さ

|メンバ変数|概要|
|---|---|
|`rnk`| 配列 $\mathrm{rank}$. <br> $\mathrm{rank}_{i}=k\Leftrightarrow \SA_k=i$ <br>`vector<int>` 型でサイズは $n$.|

|メンバ関数|概要|計算量|
|---|---|---|
|`LCPArray(sa)`|コンストラクタ.<br> `SuffixArray`クラスを渡す.|$\mathcal{O}(n\log n)$|
|`operator[](k)`| $\mathrm{LCP}_k$ を返す.||
|`begin()`| $\mathrm{LCP}$ の `begin()` を返す.||
|`end()`|$\mathrm{LCP}$ の `end()` を返す||
|`lcp(i,j)`|$S_{\SA_i:}$ と $S_{\SA_j:}$ の共通接頭辞の長さを返す. |$\mathcal{O}(1)$|
## 問題例
[AtCoder Beginner Contest 240 Ex - Sequence of Substrings](https://atcoder.jp/contests/abc240/tasks/abc240_h) (lcp(i,j), 部分文字列ソート, ロリハでTLE)\
[square869120Contest #2 E - 部分文字列](https://atcoder.jp/contests/s8pc-2/tasks/s8pc_2_e) (lcp配列)\
[DISCO presents ディスカバリーチャンネル プログラミングコンテスト2016 予選 C - アメージングな文字列は、きみが作る！](https://atcoder.jp/contests/discovery2016-qual/tasks/discovery_2016_qual_c)\
[DISCO presents ディスカバリーチャンネル コードコンテスト2020 本戦 C - Smaller-Suffix-Free Sequences](https://atcoder.jp/contests/ddcc2020-final/tasks/ddcc2020_final_c)