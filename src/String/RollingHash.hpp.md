---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0322.RH.test.cpp
    title: test/aoj/0322.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.RH.test.cpp
    title: test/aoj/2614.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.RH.test.cpp
    title: test/aoj/2711.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2763.RH.test.cpp
    title: test/aoj/2763.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.RH.test.cpp
    title: test/aoj/ALDS1_14_B.RH.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc135_f.RH.test.cpp
    title: test/atcoder/abc135_f.RH.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc141_e.RH.test.cpp
    title: test/atcoder/abc141_e.RH.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc150_f.RH.Nimber.test.cpp
    title: test/atcoder/abc150_f.RH.Nimber.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc272_f.RH.test.cpp
    title: test/atcoder/abc272_f.RH.test.cpp
  - icon: ':x:'
    path: test/atcoder/agc047_b.RH.test.cpp
    title: test/atcoder/agc047_b.RH.test.cpp
  - icon: ':x:'
    path: test/yosupo/enumerate_palindromes.RH.test.cpp
    title: test/yosupo/enumerate_palindromes.RH.test.cpp
  - icon: ':x:'
    path: test/yosupo/z_algorithm.RH.test.cpp
    title: test/yosupo/z_algorithm.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2332.RH.test.cpp
    title: test/yukicoder/2332.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2454.RH.test.cpp
    title: test/yukicoder/2454.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/599.RH.test.cpp
    title: test/yukicoder/599.RH.test.cpp
  - icon: ':x:'
    path: test/yukicoder/765.RH.test.cpp
    title: test/yukicoder/765.RH.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/RollingHash.hpp\"\n#include <vector>\n#include\
    \ <string>\n#include <array>\n#include <cassert>\ntemplate <class K, class Int=\
    \ int> class RollingHash {\npublic:\n static inline std::vector<K> pw, hsh;\n\
    \ static inline K bs;\n static inline std::vector<Int> str;\n static inline void\
    \ set_pw(int n) {\n  if (int m= pw.size(); m <= n)\n   for (pw.resize(n + 1);\
    \ m <= n; ++m) pw[m]= pw[m - 1] * bs;\n }\n int bg, n;\n RollingHash(int b, int\
    \ n): bg(b), n(n) {}\n template <class C> static int bin_srch(int ok, int ng,\
    \ const C &check) {\n  for (int x; ng - ok > 1;) x= (ok + ng) / 2, (check(x) ?\
    \ ok : ng)= x;\n  return ok;\n }\n template <size_t I> static K concat(const std::array<RollingHash,\
    \ I> &v) {\n  K ret= 0;\n  for (int i= 0; i < I; ++i) ret= ret * pw[v[i].n] +\
    \ v[i].hash();\n  return ret;\n }\npublic:\n static void init(K b) { bs= b, pw.assign(1,\
    \ 1), hsh.assign(1, 0); }\n static K base_pow(int i) { return set_pw(i), pw[i];\
    \ }\n RollingHash()= default;\n RollingHash(const std::vector<Int> &v): bg(hsh.size()\
    \ - 1), n(v.size()) {\n  str.insert(str.end(), v.begin(), v.end()), set_pw(n),\
    \ hsh.resize(bg + n + 1);\n  for (int i= 0; i < n; ++i) hsh[bg + i + 1]= hsh[bg\
    \ + i] * bs + v[i];\n }\n RollingHash(const std::string &s): RollingHash(std::vector<Int>(s.begin(),\
    \ s.end())) {}\n inline size_t length() const { return n; }\n inline K hash()\
    \ const { return hsh[bg + n] - hsh[bg] * pw[n]; }\n RollingHash sub(int b, int\
    \ m) const {\n  assert(b + m <= n), assert(m >= 0);\n  return {bg + b, m};\n }\n\
    \ RollingHash sub(int b) const {\n  assert(b <= n);\n  return {bg + b, n - b};\n\
    \ }\n template <class... Args> friend std::enable_if_t<std::conjunction_v<std::is_same<Args,\
    \ RollingHash>...>, K> concat_hash(const Args &...rh) { return concat(std::array{rh...});\
    \ }\n friend int lcp(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(0, x) == r.sub(0, x); });\n\
    \ }\n friend int lcs(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(l.n - x) == r.sub(r.n - x);\
    \ });\n }\n bool operator==(const RollingHash &r) const { return hash() == r.hash();\
    \ }\n bool operator!=(const RollingHash &r) const { return !(*this == r); }\n\
    \ bool operator<(const RollingHash &r) const {\n  int k= lcp(*this, r);\n  return\
    \ k == std::min(n, r.n) ? n < r.n : str[bg + k] < str[r.bg + k];\n }\n friend\
    \ bool concat_cmp(const RollingHash &l, const RollingHash &r) {\n  int k= lcp(l,\
    \ r);\n  if (l.n < r.n) {\n   if (k < l.n) return str[l.bg + k] < str[r.bg + k];\n\
    \   if (k= lcp(r, r.sub(l.n)); k < r.n - l.n) return str[r.bg + k] < str[r.bg\
    \ + l.n + k];\n   if (k= lcp(r.sub(r.n - l.n), l); k < l.n) return str[r.bg +\
    \ r.n - l.n + k] < str[l.bg + k];\n  } else {\n   if (k < r.n) return str[l.bg\
    \ + k] < str[r.bg + k];\n   if (k= lcp(l.sub(r.n), l); k < l.n - r.n) return str[l.bg\
    \ + r.n + k] < str[l.bg + k];\n   if (k= lcp(r, l.sub(l.n - r.n)); k < r.n) return\
    \ str[r.bg + k] < str[l.bg + l.n - r.n + k];\n  }\n  return false;\n }\n std::string\
    \ to_str() const {  // for debug\n  std::string ret;\n  for (int i= bg; i < bg\
    \ + n; ++i) ret+= (char)str[i];\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <array>\n#include\
    \ <cassert>\ntemplate <class K, class Int= int> class RollingHash {\npublic:\n\
    \ static inline std::vector<K> pw, hsh;\n static inline K bs;\n static inline\
    \ std::vector<Int> str;\n static inline void set_pw(int n) {\n  if (int m= pw.size();\
    \ m <= n)\n   for (pw.resize(n + 1); m <= n; ++m) pw[m]= pw[m - 1] * bs;\n }\n\
    \ int bg, n;\n RollingHash(int b, int n): bg(b), n(n) {}\n template <class C>\
    \ static int bin_srch(int ok, int ng, const C &check) {\n  for (int x; ng - ok\
    \ > 1;) x= (ok + ng) / 2, (check(x) ? ok : ng)= x;\n  return ok;\n }\n template\
    \ <size_t I> static K concat(const std::array<RollingHash, I> &v) {\n  K ret=\
    \ 0;\n  for (int i= 0; i < I; ++i) ret= ret * pw[v[i].n] + v[i].hash();\n  return\
    \ ret;\n }\npublic:\n static void init(K b) { bs= b, pw.assign(1, 1), hsh.assign(1,\
    \ 0); }\n static K base_pow(int i) { return set_pw(i), pw[i]; }\n RollingHash()=\
    \ default;\n RollingHash(const std::vector<Int> &v): bg(hsh.size() - 1), n(v.size())\
    \ {\n  str.insert(str.end(), v.begin(), v.end()), set_pw(n), hsh.resize(bg + n\
    \ + 1);\n  for (int i= 0; i < n; ++i) hsh[bg + i + 1]= hsh[bg + i] * bs + v[i];\n\
    \ }\n RollingHash(const std::string &s): RollingHash(std::vector<Int>(s.begin(),\
    \ s.end())) {}\n inline size_t length() const { return n; }\n inline K hash()\
    \ const { return hsh[bg + n] - hsh[bg] * pw[n]; }\n RollingHash sub(int b, int\
    \ m) const {\n  assert(b + m <= n), assert(m >= 0);\n  return {bg + b, m};\n }\n\
    \ RollingHash sub(int b) const {\n  assert(b <= n);\n  return {bg + b, n - b};\n\
    \ }\n template <class... Args> friend std::enable_if_t<std::conjunction_v<std::is_same<Args,\
    \ RollingHash>...>, K> concat_hash(const Args &...rh) { return concat(std::array{rh...});\
    \ }\n friend int lcp(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(0, x) == r.sub(0, x); });\n\
    \ }\n friend int lcs(const RollingHash &l, const RollingHash &r) {\n  return bin_srch(0,\
    \ std::min(l.n, r.n) + 1, [&](int x) { return l.sub(l.n - x) == r.sub(r.n - x);\
    \ });\n }\n bool operator==(const RollingHash &r) const { return hash() == r.hash();\
    \ }\n bool operator!=(const RollingHash &r) const { return !(*this == r); }\n\
    \ bool operator<(const RollingHash &r) const {\n  int k= lcp(*this, r);\n  return\
    \ k == std::min(n, r.n) ? n < r.n : str[bg + k] < str[r.bg + k];\n }\n friend\
    \ bool concat_cmp(const RollingHash &l, const RollingHash &r) {\n  int k= lcp(l,\
    \ r);\n  if (l.n < r.n) {\n   if (k < l.n) return str[l.bg + k] < str[r.bg + k];\n\
    \   if (k= lcp(r, r.sub(l.n)); k < r.n - l.n) return str[r.bg + k] < str[r.bg\
    \ + l.n + k];\n   if (k= lcp(r.sub(r.n - l.n), l); k < l.n) return str[r.bg +\
    \ r.n - l.n + k] < str[l.bg + k];\n  } else {\n   if (k < r.n) return str[l.bg\
    \ + k] < str[r.bg + k];\n   if (k= lcp(l.sub(r.n), l); k < l.n - r.n) return str[l.bg\
    \ + r.n + k] < str[l.bg + k];\n   if (k= lcp(r, l.sub(l.n - r.n)); k < r.n) return\
    \ str[r.bg + k] < str[l.bg + l.n - r.n + k];\n  }\n  return false;\n }\n std::string\
    \ to_str() const {  // for debug\n  std::string ret;\n  for (int i= bg; i < bg\
    \ + n; ++i) ret+= (char)str[i];\n  return ret;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2023-11-17 14:39:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/765.RH.test.cpp
  - test/yukicoder/2454.RH.test.cpp
  - test/yukicoder/2332.RH.test.cpp
  - test/yukicoder/599.RH.test.cpp
  - test/yosupo/z_algorithm.RH.test.cpp
  - test/yosupo/enumerate_palindromes.RH.test.cpp
  - test/atcoder/abc272_f.RH.test.cpp
  - test/atcoder/abc135_f.RH.test.cpp
  - test/atcoder/abc150_f.RH.Nimber.test.cpp
  - test/atcoder/abc141_e.RH.test.cpp
  - test/atcoder/agc047_b.RH.test.cpp
  - test/aoj/ALDS1_14_B.RH.test.cpp
  - test/aoj/0322.RH.test.cpp
  - test/aoj/2711.RH.test.cpp
  - test/aoj/2614.RH.test.cpp
  - test/aoj/2763.RH.test.cpp
documentation_of: src/String/RollingHash.hpp
layout: document
title: Rolling-Hash
---
## `RollingHash<K, Int=int>` クラス

`K`: 演算子オーバーロード `+`, `-`, `*` が定義されているクラス.\
（衝突確率のことを考慮しても有限体をなす代数的構造であることが望ましい. ） \
`Int`: 対象とする文字列のアルファベットを表現する型. 通常 `char` か `int`.\
（辞書順による比較のために `operator<` が定義されていて欲しい）



|`static` 関数|概要|
|---|---|
|`init(b)`|基底 $b$ をセットして初期化する. 最初に必ず呼ぶ.|
|`base_pow(i)`|$b^i$ を返す.|

|メンバ関数|概要|
|---|---|
|`RollingHash(s)`|コンストラクタ. 文字列 $S$ を渡す. <br> 引数のクラスは`vector<Int>`か`string` を想定している.|
|`length()`|文字列の長さを返す.|
|`hash()`|文字列を指すハッシュ値を返す.|
|`sub(int b,int n)`|部分文字列 $S_{b:b+n}$ に対応する `RollingHash` クラスのインスタンスを返す. |
|`sub(int b)`|接尾辞 $S_{b:}$ に対応する `RollingHash` クラスのインスタンスを返す. |
|`to_str()`|文字列に直して`string`で返す. デバッグ用.|

|演算子オーバーロード|概要|計算量|
|---|---|---|
|`operator==(r)`|文字列が等しいなら `true`.|$\mathcal{O}(1)$|
|`operator!=(r)`|文字列が等しくないなら `true`.|$\mathcal{O}(1)$|
|`operator<(r)`|対応する2つの文字列 $L,R$ について辞書順比較 $L\lt R$ (`bool`値) を返す . |$\mathcal{O}(\log n)$<br> ただし $n=\min(\lvert L\rvert,\lvert R\rvert)$|

|関数|概要|
|---|---|
|`concat_hash(rh...)`| 複数の `RollingHash` クラスのインスタンスを与える. <br> 対応する文字列をその順にconcatしたときのハッシュ値を返す.|
|`lcp(l,r)`|2つの `RollingHash` クラスのインスタンスを与える. <br>対応する2つの文字列のLCP(最長共通接頭辞; Longest Common Prefix)の長さを返す.|
|`lcs(l,r)`|2つの `RollingHash` クラスのインスタンスを与える. <br>対応する2つの文字列の最長共通接尾辞(Longest Common Suffix)の長さを返す.|
|`concat_cmp(l,r)`|2つの `RollingHash` クラスのインスタンスを与える. <br>対応する2つの文字列 $L,R$ についてconcatの前後を変えた際辞書順比較 $LR < RL$ (`bool`値) を返す .|


### 備考
比較が $\mathcal{O}(1)$ じゃないので sort をするときは [stable_sort](https://cpprefjp.github.io/reference/algorithm/stable_sort.html) を使うと良さげ.



## 問題例
[AtCoder Regular Contest 050 D - Suffix Concat](https://atcoder.jp/contests/arc050/tasks/arc050_d) (concat_cmp)\
[AtCoder Regular Contest 055 C - ABCAC](https://atcoder.jp/contests/arc055/tasks/arc055_c) \
[AtCoder Beginner Contest 274 Ex - XOR Sum of Arrays](https://atcoder.jp/contests/abc274/tasks/abc274_h) (標数2の体 e.g. Nimber)\
[AtCoder Beginner Contest 284 F - ABCBAC](https://atcoder.jp/contests/abc284/tasks/abc284_f) (sp judge)\
[競プロ典型 90 問 047 - Monochromatic Diagonal（★7）](https://atcoder.jp/contests/typical90/tasks/typical90_au)\
[早稲田大学プログラミングコンテスト2019 E - Artist](https://atcoder.jp/contests/wupc2019/tasks/wupc2019_e)\
[HackerRank Save Humanity](https://www.hackerrank.com/challenges/save-humanity")\
[HackerRank Morgan and a String](https://www.hackerrank.com/challenges/morgan-and-a-string)