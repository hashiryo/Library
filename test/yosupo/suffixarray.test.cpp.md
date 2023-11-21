---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/String/SuffixArray.hpp
    title: "Suffix Array (\u63A5\u5C3E\u8F9E\u914D\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/yosupo/suffixarray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n#include <iostream>\n#include <string>\n#line 3 \"src/String/SuffixArray.hpp\"\
    \n#include <vector>\n#include <algorithm>\ntemplate <class String> struct SuffixArray\
    \ {\n String s;\n std::vector<int> sa;\n static inline std::vector<int> sa_is(const\
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
    \ P is not a substring of S\n // O(|P|log|S|)\n auto pattern_matching(const String\
    \ &P) const {\n  const int n= s.size(), m= P.size();\n  if (n < m) return {0,\
    \ 0};\n  auto f1= [&](int h) {\n   auto t= s.begin() + h;\n   for (int j= 0, e=\
    \ std::min(n - h, m); j < e; ++j) {\n    if (t[j] < P[j]) return true;\n    if\
    \ (t[j] > P[j]) return false;\n   }\n   return n - h < m;\n  };\n  auto f2= [&](int\
    \ h) {\n   auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n - h, m); j\
    \ < e; ++j)\n    if (t[j] > P[j]) return false;\n   return true;\n  };\n  auto\
    \ L= std::partition_point(sa.begin(), sa.end(), f1), R= std::partition_point(L,\
    \ sa.end(), f2);\n  return std::make_pair(L, R);\n }\n};\nclass LCPArray {\n std::vector<int>\
    \ rnk;\n std::vector<std::vector<int>> dat;\npublic:\n template <class String>\
    \ LCPArray(const SuffixArray<String> &sa): rnk(sa.size()) {\n  const int n= sa.size(),\
    \ log= n > 2 ? 31 - __builtin_clz(n - 2) : 0;\n  dat.resize(log + 1), dat[0].resize(n\
    \ - 1);\n  auto &lcp= dat[0];\n  for (int i= n; i--;) rnk[sa[i]]= i;\n  for (int\
    \ i= 0, h= 0; i < n; ++i) {\n   if (rnk[i] == n - 1) {\n    h= 0;\n    continue;\n\
    \   }\n   for (int j= sa[rnk[i] + 1]; i + h < n && j + h < n && sa.s[i + h] ==\
    \ sa.s[j + h];) ++h;\n   if ((lcp[rnk[i]]= h)) --h;\n  }\n  for (int i= 0, I=\
    \ 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size() - I);\
    \ j--;) dat[i + 1][j]= std::min(dat[i][j], dat[i][j + I]);\n }\n int operator[](int\
    \ i) const { return dat[0][i]; }\n size_t size() const { return dat[0].size();\
    \ }\n auto begin() const { return dat[0].begin(); }\n auto end() const { return\
    \ dat[0].end(); }\n int operator()(int i, int j) const {\n  if (i == j) return\
    \ rnk.size() - i;\n  auto [l, r]= std::minmax(rnk[i], rnk[j]);\n  if (r == l +\
    \ 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r - l - 1);\n  return std::min(dat[k][l],\
    \ dat[k][r - (1 << k)]);\n }\n};\n#line 5 \"test/yosupo/suffixarray.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ string S;\n cin >> S;\n int n= S.length();\n SuffixArray sa(S);\n for (int i=\
    \ 0; i < n; ++i) cout << sa[i] << \" \\n\"[i + 1 == n];\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ <iostream>\n#include <string>\n#include \"src/String/SuffixArray.hpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string\
    \ S;\n cin >> S;\n int n= S.length();\n SuffixArray sa(S);\n for (int i= 0; i\
    \ < n; ++i) cout << sa[i] << \" \\n\"[i + 1 == n];\n return 0;\n}"
  dependsOn:
  - src/String/SuffixArray.hpp
  isVerificationFile: true
  path: test/yosupo/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2023-11-21 13:51:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/suffixarray.test.cpp
- /verify/test/yosupo/suffixarray.test.cpp.html
title: test/yosupo/suffixarray.test.cpp
---
