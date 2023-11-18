---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SparseTable.hpp
    title: Sparse-Table
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.SA.test.cpp
    title: test/aoj/ALDS1_14_B.SA.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.SA.test.cpp
    title: test/aoj/ALDS1_14_D.SA.test.cpp
  - icon: ':x:'
    path: test/yosupo/longest_common_substring.test.cpp
    title: test/yosupo/longest_common_substring.test.cpp
  - icon: ':x:'
    path: test/yosupo/number_of_substrings.SA.test.cpp
    title: test/yosupo/number_of_substrings.SA.test.cpp
  - icon: ':x:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/SuffixArray.hpp\"\n#include <string>\n#include\
    \ <algorithm>\n#include <cassert>\n#line 2 \"src/DataStructure/SparseTable.hpp\"\
    \n#include <vector>\ntemplate <class T, class F> class SparseTable {\n std::vector<std::vector<T>>\
    \ dat;\n F f;\npublic:\n SparseTable() {}\n SparseTable(const std::vector<T> &v,\
    \ const F &f): f(f) {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n -\
    \ 1) : 0;\n  dat.resize(log + 1), dat[0].assign(v.begin(), v.end());\n  for (int\
    \ i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size()\
    \ - I); j--;) dat[i + 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T\
    \ fold(int l, int r) const {\n  if (r == l + 1) return dat[0][l];\n  int k= 31\
    \ - __builtin_clz(r - l - 1);\n  return f(dat[k][l], dat[k][r - (1 << k)]);\n\
    \ }\n};\n#line 6 \"src/String/SuffixArray.hpp\"\ntemplate <bool use_lcp_query=\
    \ false, class Int= int> struct SuffixArray {\n std::vector<int> SA, ISA, LCP;\n\
    \ SuffixArray(const std::vector<Int> &S): s(S) {\n  auto v= s;\n  sort(v.begin(),\
    \ v.end()), v.erase(unique(v.begin(), v.end()), v.end());\n  std::vector<int>\
    \ s_cpy(s.size() + 1);\n  for (int i= s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(),\
    \ v.end(), s[i]) - v.begin() + 1;\n  SA= sa_is(s_cpy, v.size() + 1), SA.erase(SA.begin()),\
    \ build();\n }\n SuffixArray(const std::string &S): s(S.begin(), S.end()) {\n\
    \  std::vector<int> s_cpy(s.size() + 1);\n  std::copy(s.begin(), s.end(), s_cpy.begin()),\
    \ SA= sa_is(s_cpy, 128), SA.erase(SA.begin()), build();\n }\n // lcp of S[i:]\
    \ and S[j:]\n int lcp(int i, int j) const {\n  static_assert(use_lcp_query);\n\
    \  assert(i < SA.size() && j < SA.size());\n  if (i == j) return SA.size() - i;\n\
    \  auto [l, r]= std::minmax(ISA[i], ISA[j]);\n  return lcp_mn.fold(l, r);\n }\n\
    \ int operator[](int i) const { return SA[i]; }\n int size() const { return SA.size();\
    \ }\n // return {l,r} s.t. P is a prefix of S[SA[i]:] ( i in [l,r) )\n // l ==\
    \ r if P is not a substring of S\n // O(|P|log|S|)\n std::pair<int, int> pattern_matching(const\
    \ std::vector<Int> &P) const {\n  const int n= s.size(), m= P.size();\n  if (n\
    \ < m) return {0, 0};\n  auto f1= [&](int h) {\n   for (int j= 0; h + j < n &&\
    \ j < m; ++j) {\n    if (s[h + j] < P[j]) return true;\n    if (s[h + j] > P[j])\
    \ return false;\n   }\n   return n - h < m;\n  };\n  auto f2= [&](int h) {\n \
    \  for (int j= 0; h + j < n && j < m; ++j)\n    if (s[h + j] > P[j]) return false;\n\
    \   return true;\n  };\n  auto L= std::partition_point(SA.begin(), SA.end(), f1),\
    \ R= std::partition_point(L, SA.end(), f2);\n  return {L - SA.begin(), R - SA.begin()};\n\
    \ }\n std::pair<int, int> pattern_matching(const std::string &P) const { return\
    \ pattern_matching(std::vector<Int>(P.begin(), P.end())); }\nprivate:\n std::vector<Int>\
    \ s;\n using ST= SparseTable<int, int (*)(int, int)>;\n ST lcp_mn;\n void build()\
    \ {\n  const int n= SA.size();\n  ISA.resize(n), LCP.resize(n - 1);\n  for (int\
    \ i= SA.size(); i--;) ISA[SA[i]]= i;\n  for (int i= 0, h= 0; i < n; ++i) {\n \
    \  if (ISA[i] == n - 1) {\n    h= 0;\n    continue;\n   }\n   for (int j= SA[ISA[i]\
    \ + 1]; i + h < n && j + h < n && s[i + h] == s[j + h];) ++h;\n   if ((LCP[ISA[i]]=\
    \ h)) --h;\n  }\n  if constexpr (use_lcp_query) lcp_mn= ST(LCP, [](int a, int\
    \ b) { return std::min(a, b); });\n }\n std::vector<int> static sa_is(const std::vector<int>\
    \ &s, int K) {\n  const int n= s.size();\n  std::vector<char> t(n);\n  std::vector<int>\
    \ bkt(K, 0), bkt_l(K), bkt_r(K), sa(n), p1;\n  t.back()= true;\n  for (int i=\
    \ n; --i;)\n   if (t[i - 1]= (s[i - 1] < s[i] || (t[i] && s[i - 1] == s[i]));\
    \ t[i] && !t[i - 1]) p1.push_back(i);\n  std::reverse(p1.begin(), p1.end());\n\
    \  const int n1= p1.size();\n  for (int i= n; i--;) ++bkt[s[i]];\n  for (int i=\
    \ 0, sum= 0; i < K; ++i) sum+= bkt[i], bkt_r[i]= sum, bkt_l[i]= sum - bkt[i];\n\
    \  std::vector<int> s1(n1), sa1(n1);\n  std::fill_n(sa.begin(), n, -1), std::copy_n(bkt_r.begin(),\
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
    \ j;\n  return sa;\n }\n};\n"
  code: "#pragma once\n#include <string>\n#include <algorithm>\n#include <cassert>\n\
    #include \"src/DataStructure/SparseTable.hpp\"\ntemplate <bool use_lcp_query=\
    \ false, class Int= int> struct SuffixArray {\n std::vector<int> SA, ISA, LCP;\n\
    \ SuffixArray(const std::vector<Int> &S): s(S) {\n  auto v= s;\n  sort(v.begin(),\
    \ v.end()), v.erase(unique(v.begin(), v.end()), v.end());\n  std::vector<int>\
    \ s_cpy(s.size() + 1);\n  for (int i= s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(),\
    \ v.end(), s[i]) - v.begin() + 1;\n  SA= sa_is(s_cpy, v.size() + 1), SA.erase(SA.begin()),\
    \ build();\n }\n SuffixArray(const std::string &S): s(S.begin(), S.end()) {\n\
    \  std::vector<int> s_cpy(s.size() + 1);\n  std::copy(s.begin(), s.end(), s_cpy.begin()),\
    \ SA= sa_is(s_cpy, 128), SA.erase(SA.begin()), build();\n }\n // lcp of S[i:]\
    \ and S[j:]\n int lcp(int i, int j) const {\n  static_assert(use_lcp_query);\n\
    \  assert(i < SA.size() && j < SA.size());\n  if (i == j) return SA.size() - i;\n\
    \  auto [l, r]= std::minmax(ISA[i], ISA[j]);\n  return lcp_mn.fold(l, r);\n }\n\
    \ int operator[](int i) const { return SA[i]; }\n int size() const { return SA.size();\
    \ }\n // return {l,r} s.t. P is a prefix of S[SA[i]:] ( i in [l,r) )\n // l ==\
    \ r if P is not a substring of S\n // O(|P|log|S|)\n std::pair<int, int> pattern_matching(const\
    \ std::vector<Int> &P) const {\n  const int n= s.size(), m= P.size();\n  if (n\
    \ < m) return {0, 0};\n  auto f1= [&](int h) {\n   for (int j= 0; h + j < n &&\
    \ j < m; ++j) {\n    if (s[h + j] < P[j]) return true;\n    if (s[h + j] > P[j])\
    \ return false;\n   }\n   return n - h < m;\n  };\n  auto f2= [&](int h) {\n \
    \  for (int j= 0; h + j < n && j < m; ++j)\n    if (s[h + j] > P[j]) return false;\n\
    \   return true;\n  };\n  auto L= std::partition_point(SA.begin(), SA.end(), f1),\
    \ R= std::partition_point(L, SA.end(), f2);\n  return {L - SA.begin(), R - SA.begin()};\n\
    \ }\n std::pair<int, int> pattern_matching(const std::string &P) const { return\
    \ pattern_matching(std::vector<Int>(P.begin(), P.end())); }\nprivate:\n std::vector<Int>\
    \ s;\n using ST= SparseTable<int, int (*)(int, int)>;\n ST lcp_mn;\n void build()\
    \ {\n  const int n= SA.size();\n  ISA.resize(n), LCP.resize(n - 1);\n  for (int\
    \ i= SA.size(); i--;) ISA[SA[i]]= i;\n  for (int i= 0, h= 0; i < n; ++i) {\n \
    \  if (ISA[i] == n - 1) {\n    h= 0;\n    continue;\n   }\n   for (int j= SA[ISA[i]\
    \ + 1]; i + h < n && j + h < n && s[i + h] == s[j + h];) ++h;\n   if ((LCP[ISA[i]]=\
    \ h)) --h;\n  }\n  if constexpr (use_lcp_query) lcp_mn= ST(LCP, [](int a, int\
    \ b) { return std::min(a, b); });\n }\n std::vector<int> static sa_is(const std::vector<int>\
    \ &s, int K) {\n  const int n= s.size();\n  std::vector<char> t(n);\n  std::vector<int>\
    \ bkt(K, 0), bkt_l(K), bkt_r(K), sa(n), p1;\n  t.back()= true;\n  for (int i=\
    \ n; --i;)\n   if (t[i - 1]= (s[i - 1] < s[i] || (t[i] && s[i - 1] == s[i]));\
    \ t[i] && !t[i - 1]) p1.push_back(i);\n  std::reverse(p1.begin(), p1.end());\n\
    \  const int n1= p1.size();\n  for (int i= n; i--;) ++bkt[s[i]];\n  for (int i=\
    \ 0, sum= 0; i < K; ++i) sum+= bkt[i], bkt_r[i]= sum, bkt_l[i]= sum - bkt[i];\n\
    \  std::vector<int> s1(n1), sa1(n1);\n  std::fill_n(sa.begin(), n, -1), std::copy_n(bkt_r.begin(),\
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
    \ j;\n  return sa;\n }\n};"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  isVerificationFile: false
  path: src/String/SuffixArray.hpp
  requiredBy: []
  timestamp: '2023-11-18 09:59:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/suffixarray.test.cpp
  - test/yosupo/number_of_substrings.SA.test.cpp
  - test/yosupo/longest_common_substring.test.cpp
  - test/aoj/ALDS1_14_D.SA.test.cpp
  - test/aoj/ALDS1_14_B.SA.test.cpp
  - test/aoj/2644.test.cpp
documentation_of: src/String/SuffixArray.hpp
layout: document
title: "Suffix Array (\u63A5\u5C3E\u8F9E\u914D\u5217)"
---

$\newcommand{\SA}{\mathrm{SA}}$

## `SuffixArray<use_lcp_query=false, Int=int>` クラス
`use_lcp_query`: bool値. true だと前処理時間とメモリが余計に増えるが関数 `lcp(i,j)` が使用可. \
（ `lcp(i,j)` では `SparseTable` を使うため）\
`Int`: 対象とする文字列のアルファベットを表現する型. 通常 `char` か `int`.\
（辞書順による比較のために `operator<` が定義されていて欲しい）

以下, 文字列 $S$ に対して構築することにする. また $n = \lvert S\rvert$ とする.

|メンバ変数|概要|
|---|---|
|`SA`| 接尾辞配列. <br> $\SA_i=k \Leftrightarrow$ 接尾辞を辞書順で並べたときの $i$ 番目 (0-index) が $S\lbrack k:\rbrack$  <br>`vector<int>` 型でサイズは $n$.|
|`ISA`| 接尾辞のランクを表す配列.<br> $\mathrm{ISA}_k=i \Leftrightarrow \SA_i=k$ <br> `vector<int>` 型でサイズは $n$.|
|`LCP`|LCP配列. <br> $\mathrm{LCP}\lbrack i\rbrack\stackrel{\mathrm{def}}{=}$ $S\lbrack \SA_i: \rbrack$ と $S\lbrack \SA_{i+1}: \rbrack$ の共通接頭辞の長さ<br> `vector<int>` 型でサイズは $n-1$.|


|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixArray(S)`|コンストラクタ. <br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(n)$ か $\mathcal{O}(n\log n)$|
|`operator[](i)`| `SA[i]` を返す.||
|`size()`|$S$ の長さ $n$ を返す.||
|`lcp(i,j)`|$S\lbrack \SA_i: \rbrack$ と $S\lbrack \SA_j: \rbrack$ の共通接頭辞の長さを返す.|$\mathcal{O}(1)$|
|`pattern_matching(P)`|文字列 $S$ の部分文字列でパターン文字列 $P$ と一致する箇所を探す.<br> 返り値は二つの非負整数 $l, r$ <br>s.t. $\lbrace \SA_i\;\vert\; l \leq i \lt r \rbrace = \lbrace k \;\vert\;P$ が $S\lbrack k:\rbrack$ の接頭辞$\rbrace$ <br> ただし $P$ が $S$ の部分文字列でないとき $l=r$ .<br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(\lvert P\rvert \log n)$|

## 問題例
[AtCoder Beginner Contest 240 Ex - Sequence of Substrings](https://atcoder.jp/contests/abc240/tasks/abc240_h) (lcp, 部分文字列ソート, ロリハでTLE)