---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':x:'
    path: test/aoj/ALDS1_14_B.SA.test.cpp
    title: test/aoj/ALDS1_14_B.SA.test.cpp
  - icon: ':x:'
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/SuffixArray.hpp\"\n#include <string>\n#include\
    \ <vector>\n#include <algorithm>\ntemplate <class Int= int> struct SuffixArray\
    \ {\n std::vector<Int> s;\n std::vector<int> sa;\n std::vector<int> static sa_is(const\
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
    \ std::vector<Int> &S): s(S) {\n  auto v= s;\n  std::sort(v.begin(), v.end()),\
    \ v.erase(std::unique(v.begin(), v.end()), v.end());\n  std::vector<int> s_cpy(s.size()\
    \ + 1);\n  for (int i= s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(), v.end(),\
    \ s[i]) - v.begin() + 1;\n  sa= sa_is(s_cpy, v.size() + 1), sa.erase(sa.begin());\n\
    \ }\n SuffixArray(const std::string &S): s(S.begin(), S.end()) {\n  std::vector<int>\
    \ s_cpy(s.size() + 1);\n  std::copy(s.begin(), s.end(), s_cpy.begin()), sa= sa_is(s_cpy,\
    \ 128), sa.erase(sa.begin());\n }\n int operator[](int i) const { return sa[i];\
    \ }\n size_t size() const { return sa.size(); }\n auto begin() const { return\
    \ sa.begin(); }\n auto end() const { return sa.end(); }\n auto &to_vec() const\
    \ { return sa; }\n auto &string() const { return s; }\n // return {l,r} s.t. P\
    \ is a prefix of S[sa[i]:] ( i in [l,r) )\n // l == r if P is not a substring\
    \ of S\n // O(|P|log|S|)\n auto pattern_matching(const std::vector<Int> &P) const\
    \ {\n  const int n= s.size(), m= P.size();\n  if (n < m) return {0, 0};\n  auto\
    \ f1= [&](int h) {\n   auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n\
    \ - h, m); j < e; ++j) {\n    if (t[j] < P[j]) return true;\n    if (t[j] > P[j])\
    \ return false;\n   }\n   return n - h < m;\n  };\n  auto f2= [&](int h) {\n \
    \  auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\n\
    \    if (t[j] > P[j]) return false;\n   return true;\n  };\n  auto L= std::partition_point(sa.begin(),\
    \ sa.end(), f1), R= std::partition_point(L, sa.end(), f2);\n  return std::make_pair(L\
    \ - sa.begin(), R - sa.begin());\n }\n auto pattern_matching(const std::string\
    \ &P) const { return pattern_matching(std::vector<Int>(P.begin(), P.end())); }\n\
    };\nclass LCPArray {\n std::vector<int> rnk;\n std::vector<std::vector<int>> dat;\n\
    public:\n template <class Int> LCPArray(const SuffixArray<Int> &sa): rnk(sa.size())\
    \ {\n  const int n= sa.size(), log= n > 2 ? 31 - __builtin_clz(n - 2) : 0;\n \
    \ dat.resize(log + 1), dat[0].resize(n - 1);\n  auto &lcp= dat[0];\n  auto &s=\
    \ sa.string();\n  for (int i= n; i--;) rnk[sa[i]]= i;\n  for (int i= 0, h= 0;\
    \ i < n; ++i) {\n   if (rnk[i] == n - 1) {\n    h= 0;\n    continue;\n   }\n \
    \  for (int j= sa[rnk[i] + 1]; i + h < n && j + h < n && s[i + h] == s[j + h];)\
    \ ++h;\n   if ((lcp[rnk[i]]= h)) --h;\n  }\n  for (int i= 0, I= 1, j; i < log;\
    \ ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size() - I); j--;) dat[i +\
    \ 1][j]= std::min(dat[i][j], dat[i][j + I]);\n }\n int operator[](int i) const\
    \ { return dat[0][i]; }\n size_t size() const { return dat[0].size(); }\n auto\
    \ begin() const { return dat[0].begin(); }\n auto end() const { return dat[0].end();\
    \ }\n int operator()(int i, int j) const {\n  if (i == j) return rnk.size() -\
    \ i;\n  auto [l, r]= std::minmax(rnk[i], rnk[j]);\n  if (r == l + 1) return dat[0][l];\n\
    \  int k= 31 - __builtin_clz(r - l - 1);\n  return std::min(dat[k][l], dat[k][r\
    \ - (1 << k)]);\n }\n};\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    template <class Int= int> struct SuffixArray {\n std::vector<Int> s;\n std::vector<int>\
    \ sa;\n std::vector<int> static sa_is(const std::vector<int> &s, int K) {\n  const\
    \ int n= s.size();\n  std::vector<char> t(n);\n  std::vector<int> bkt(K, 0), bkt_l(K),\
    \ bkt_r(K), sa(n), p1;\n  t.back()= true;\n  for (int i= n; --i;)\n   if (t[i\
    \ - 1]= (s[i - 1] < s[i] || (t[i] && s[i - 1] == s[i])); t[i] && !t[i - 1]) p1.push_back(i);\n\
    \  std::reverse(p1.begin(), p1.end());\n  const int n1= p1.size();\n  for (int\
    \ i= n; i--;) ++bkt[s[i]];\n  for (int i= 0, sum= 0; i < K; ++i) sum+= bkt[i],\
    \ bkt_r[i]= sum, bkt_l[i]= sum - bkt[i];\n  std::vector<int> s1(n1), sa1(n1);\n\
    \  std::fill_n(sa.begin(), n, -1), std::copy_n(bkt_r.begin(), K, bkt.begin());\n\
    \  for (int i= n1; i--;) sa[--bkt[s[p1[i]]]]= p1[i];\n  std::copy_n(bkt_l.begin(),\
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
    \ j;\n  return sa;\n }\npublic:\n SuffixArray(const std::vector<Int> &S): s(S)\
    \ {\n  auto v= s;\n  std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n  std::vector<int> s_cpy(s.size() + 1);\n  for (int i=\
    \ s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(), v.end(), s[i]) - v.begin()\
    \ + 1;\n  sa= sa_is(s_cpy, v.size() + 1), sa.erase(sa.begin());\n }\n SuffixArray(const\
    \ std::string &S): s(S.begin(), S.end()) {\n  std::vector<int> s_cpy(s.size()\
    \ + 1);\n  std::copy(s.begin(), s.end(), s_cpy.begin()), sa= sa_is(s_cpy, 128),\
    \ sa.erase(sa.begin());\n }\n int operator[](int i) const { return sa[i]; }\n\
    \ size_t size() const { return sa.size(); }\n auto begin() const { return sa.begin();\
    \ }\n auto end() const { return sa.end(); }\n auto &to_vec() const { return sa;\
    \ }\n auto &string() const { return s; }\n // return {l,r} s.t. P is a prefix\
    \ of S[sa[i]:] ( i in [l,r) )\n // l == r if P is not a substring of S\n // O(|P|log|S|)\n\
    \ auto pattern_matching(const std::vector<Int> &P) const {\n  const int n= s.size(),\
    \ m= P.size();\n  if (n < m) return {0, 0};\n  auto f1= [&](int h) {\n   auto\
    \ t= s.begin() + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j) {\n\
    \    if (t[j] < P[j]) return true;\n    if (t[j] > P[j]) return false;\n   }\n\
    \   return n - h < m;\n  };\n  auto f2= [&](int h) {\n   auto t= s.begin() + h;\n\
    \   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\n    if (t[j] > P[j]) return\
    \ false;\n   return true;\n  };\n  auto L= std::partition_point(sa.begin(), sa.end(),\
    \ f1), R= std::partition_point(L, sa.end(), f2);\n  return std::make_pair(L -\
    \ sa.begin(), R - sa.begin());\n }\n auto pattern_matching(const std::string &P)\
    \ const { return pattern_matching(std::vector<Int>(P.begin(), P.end())); }\n};\n\
    class LCPArray {\n std::vector<int> rnk;\n std::vector<std::vector<int>> dat;\n\
    public:\n template <class Int> LCPArray(const SuffixArray<Int> &sa): rnk(sa.size())\
    \ {\n  const int n= sa.size(), log= n > 2 ? 31 - __builtin_clz(n - 2) : 0;\n \
    \ dat.resize(log + 1), dat[0].resize(n - 1);\n  auto &lcp= dat[0];\n  auto &s=\
    \ sa.string();\n  for (int i= n; i--;) rnk[sa[i]]= i;\n  for (int i= 0, h= 0;\
    \ i < n; ++i) {\n   if (rnk[i] == n - 1) {\n    h= 0;\n    continue;\n   }\n \
    \  for (int j= sa[rnk[i] + 1]; i + h < n && j + h < n && s[i + h] == s[j + h];)\
    \ ++h;\n   if ((lcp[rnk[i]]= h)) --h;\n  }\n  for (int i= 0, I= 1, j; i < log;\
    \ ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size() - I); j--;) dat[i +\
    \ 1][j]= std::min(dat[i][j], dat[i][j + I]);\n }\n int operator[](int i) const\
    \ { return dat[0][i]; }\n size_t size() const { return dat[0].size(); }\n auto\
    \ begin() const { return dat[0].begin(); }\n auto end() const { return dat[0].end();\
    \ }\n int operator()(int i, int j) const {\n  if (i == j) return rnk.size() -\
    \ i;\n  auto [l, r]= std::minmax(rnk[i], rnk[j]);\n  if (r == l + 1) return dat[0][l];\n\
    \  int k= 31 - __builtin_clz(r - l - 1);\n  return std::min(dat[k][l], dat[k][r\
    \ - (1 << k)]);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/SuffixArray.hpp
  requiredBy: []
  timestamp: '2023-11-20 13:31:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
`use_lcp_query`: `bool` 値. `true` だと前処理時間とメモリが余計に増えるが関数 `lcp(i,j)` が使用可. \
（ `lcp(i,j)` では `SparseTable` を使うため）\
`Int`: 対象とする文字列のアルファベットを表現する型. 通常 `char` か `int`.\
（辞書順による比較のために `operator<` が定義されていて欲しい）

以下, 文字列 $S$ に対して構築することにする. \
文字列 $S$ の $k$ 文字目から開始した接尾辞を $S_{k:}$ と表すことにする.\
また $n = \lvert S\rvert$ とおく.

|メンバ変数|概要|
|---|---|
|`SA`| 接尾辞配列. <br> $\SA_k=i \Leftrightarrow$ 接尾辞を辞書順で並べたときの $k$ 番目 (0-index) が $S_{i:}$  <br>`vector<int>` 型でサイズは $n$.|
|`ISA`| 接尾辞のランクを表す配列.<br> $\mathrm{ISA}_i=k \Leftrightarrow \SA_k=i$ <br> `vector<int>` 型でサイズは $n$.|
|`LCP`|LCP配列. <br> $\mathrm{LCP}\lbrack k\rbrack:=$ $S_{\SA_k:}$ と $S_{\SA_{k+1}:}$ の共通接頭辞の長さ<br> `vector<int>` 型でサイズは $n-1$.|


|メンバ関数|概要|計算量|
|---|---|---|
|`SuffixArray(S)`|コンストラクタ. 文字列 $S$ を渡す. <br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(n)$ か $\mathcal{O}(n\log n)$|
|`operator[](i)`| `SA[i]` を返す.||
|`lcp(i,j)`|$S_{\SA_i:}$ と $S_{\SA_j:}$ の共通接頭辞の長さを返す. <br> クラステンプレートの第一引数が `true` でないと`static_assert` で落ちる. |$\mathcal{O}(1)$|
|`pattern_matching(P)`|文字列 $S$ の部分文字列でパターン文字列 $P$ と一致する箇所を探す.<br> 返り値は二つの非負整数 $l, r$ <br>s.t. $\lbrace \SA_k\;\vert\; l \leq k \lt r \rbrace = \lbrace i \;\vert\;P$ が $S_{i:}$ の接頭辞$\rbrace$ <br> ただし $P$ が $S$ の部分文字列でないとき $l=r$ .<br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(\lvert P\rvert \log n)$|

## 問題例
[AtCoder Beginner Contest 240 Ex - Sequence of Substrings](https://atcoder.jp/contests/abc240/tasks/abc240_h) (lcp, 部分文字列ソート, ロリハでTLE)