---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/runenumerate.zalgo.test.cpp
    title: test/yosupo/runenumerate.zalgo.test.cpp
  - icon: ':x:'
    path: test/yosupo/z_algorithm.test.cpp
    title: test/yosupo/z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/z_algorithm.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <string>\n#include <tuple>\ntemplate <class Int> std::vector<int>\
    \ z_algorithm(const std::vector<Int> &s) {\n const int n= s.size();\n if (n ==\
    \ 0) return {};\n std::vector<int> z(n);\n for (int i= 1, j= 0; i < n; ++i) {\n\
    \  int &k= z[i];\n  for (k= (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i -\
    \ j]); i + k < n && s[k] == s[i + k];) ++k;\n  if (j + z[j] < i + z[i]) j= i;\n\
    \ }\n return z[0]= n, z;\n}\nstd::vector<int> z_algorithm(const std::string &s)\
    \ { return z_algorithm(std::vector<int>(s.begin(), s.end())); }\nnamespace string_internal\
    \ {\ntemplate <class String> auto run_enumerate_(const String &s, typename String::value_type\
    \ a= 0) {\n using Run= std::tuple<int, int, int>;\n std::vector<Run> glb;\n auto\
    \ rec= [&](auto rec, int l, int r) -> std::vector<Run> {\n  if (r - l <= 1) return\
    \ {};\n  const int m= (l + r) / 2, lsz= m - l, rsz= r - m;\n  std::vector<Run>\
    \ run_l= lsz > 1 ? rec(rec, l, m) : std::vector<Run>(), run_r= rsz > 1 ? rec(rec,\
    \ m, r) : std::vector<Run>();\n  std::vector<typename String::value_type> rl(r\
    \ - l + 1, a);\n  std::copy(s.begin() + m, s.begin() + r, rl.begin()), std::copy(s.begin()\
    \ + l, s.begin() + m, rl.begin() + rsz + 1);\n  std::vector<int> zrl= z_algorithm(rl);\n\
    \  std::reverse(rl.begin(), rl.end());\n  std::vector<int> zrl_r= z_algorithm(rl);\n\
    \  const int sz= rl.size();\n  std::vector<Run> ret;\n  auto push= [&](int p,\
    \ int b, int e) { (b == l || e == r ? ret : glb).emplace_back(p, b, e); };\n \
    \ std::vector<Run> run_m(rsz / 2 + 1);\n  for (auto [p, b, e]: run_r) {\n   if\
    \ (b != m) ret.emplace_back(p, b, e);\n   else run_m[p]= Run{p, b, e};\n  }\n\
    \  for (auto [p, b, e]: run_l)\n   if (e != m) ret.emplace_back(p, b, e);\n  \
    \ else if (zrl[sz - p] == p) {\n    if (std::get<0>(run_m[p])) push(p, b, std::get<2>(run_m[p])),\
    \ run_m[p]= Run{};\n    else push(p, b, m + p + zrl[p]);\n   } else push(p, b,\
    \ m + zrl[sz - p]);\n  for (auto [p, b, e]: run_m)\n   if (p) {\n    if (zrl[sz\
    \ - p] != p) push(p, m - zrl_r[sz - p], e);\n    else if (2 * p > lsz || zrl[sz\
    \ - 2 * p] < p) push(p, m - p - zrl_r[p], e);\n   }\n  for (int p= 1; p <= lsz;\
    \ ++p)\n   if (bool skpr= 2 * p <= rsz && zrl[p] >= p, skpl= 2 * p <= lsz && zrl[sz\
    \ - 2 * p] >= p; zrl[sz - p] == p) {\n    if (!skpl && !skpr) push(p, m - p -\
    \ zrl_r[p], m + p + zrl[p]);\n   } else {\n    if (!skpr)\n     if (int b= m -\
    \ zrl_r[sz - p], e= m + p + zrl[p]; e - b >= 2 * p) push(p, b, e);\n    if (!skpl)\n\
    \     if (int b= m - p - zrl_r[p], e= m + zrl[sz - p]; e - b >= 2 * p) push(p,\
    \ b, e);\n   }\n  return ret;\n };\n std::vector<std::tuple<int, int, int>> runs=\
    \ rec(rec, 0, s.size());\n std::copy(glb.begin(), glb.end(), std::back_inserter(runs));\n\
    \ int rn= runs.size(), n= s.size();\n glb.resize(rn);\n std::vector<int> pt(n);\n\
    #define RADIX(A, B, C, D, E) \\\n for (auto [p, l, r]: A) ++pt[C]; \\\n for (int\
    \ i= 1; E < n; ++i) pt[i]+= pt[i - 1]; \\\n for (int i= rn; i--;) B[--pt[D]]=\
    \ A[i];\n RADIX(runs, glb, r - 1, std::get<2>(runs[i]) - 1, i)\n pt.assign(n,\
    \ 0);\n RADIX(glb, runs, l, std::get<1>(glb[i]), i)\n runs.erase(std::unique(runs.begin(),\
    \ runs.end(), [](auto &r1, auto &r2) { return std::get<1>(r1) == std::get<1>(r2)\
    \ && std::get<2>(r1) == std::get<2>(r2); }), runs.end()), glb.resize(rn= runs.size()),\
    \ pt.assign(n / 2, 0);\n RADIX(runs, glb, p - 1, std::get<0>(runs[i]) - 1, i +\
    \ i)\n#undef RADIX\n return glb;\n}\ntemplate <class Int> auto run_enumerate(const\
    \ std::vector<Int> &s) { return run_enumerate_(s, *std::max_element(s.begin(),\
    \ s.end()) + 1); }\nauto run_enumerate(const std::string &s) { return run_enumerate_(s);\
    \ }\n}\nusing string_internal::run_enumerate;\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <string>\n\
    #include <tuple>\ntemplate <class Int> std::vector<int> z_algorithm(const std::vector<Int>\
    \ &s) {\n const int n= s.size();\n if (n == 0) return {};\n std::vector<int> z(n);\n\
    \ for (int i= 1, j= 0; i < n; ++i) {\n  int &k= z[i];\n  for (k= (j + z[j] <=\
    \ i) ? 0 : std::min(j + z[j] - i, z[i - j]); i + k < n && s[k] == s[i + k];) ++k;\n\
    \  if (j + z[j] < i + z[i]) j= i;\n }\n return z[0]= n, z;\n}\nstd::vector<int>\
    \ z_algorithm(const std::string &s) { return z_algorithm(std::vector<int>(s.begin(),\
    \ s.end())); }\nnamespace string_internal {\ntemplate <class String> auto run_enumerate_(const\
    \ String &s, typename String::value_type a= 0) {\n using Run= std::tuple<int,\
    \ int, int>;\n std::vector<Run> glb;\n auto rec= [&](auto rec, int l, int r) ->\
    \ std::vector<Run> {\n  if (r - l <= 1) return {};\n  const int m= (l + r) / 2,\
    \ lsz= m - l, rsz= r - m;\n  std::vector<Run> run_l= lsz > 1 ? rec(rec, l, m)\
    \ : std::vector<Run>(), run_r= rsz > 1 ? rec(rec, m, r) : std::vector<Run>();\n\
    \  std::vector<typename String::value_type> rl(r - l + 1, a);\n  std::copy(s.begin()\
    \ + m, s.begin() + r, rl.begin()), std::copy(s.begin() + l, s.begin() + m, rl.begin()\
    \ + rsz + 1);\n  std::vector<int> zrl= z_algorithm(rl);\n  std::reverse(rl.begin(),\
    \ rl.end());\n  std::vector<int> zrl_r= z_algorithm(rl);\n  const int sz= rl.size();\n\
    \  std::vector<Run> ret;\n  auto push= [&](int p, int b, int e) { (b == l || e\
    \ == r ? ret : glb).emplace_back(p, b, e); };\n  std::vector<Run> run_m(rsz /\
    \ 2 + 1);\n  for (auto [p, b, e]: run_r) {\n   if (b != m) ret.emplace_back(p,\
    \ b, e);\n   else run_m[p]= Run{p, b, e};\n  }\n  for (auto [p, b, e]: run_l)\n\
    \   if (e != m) ret.emplace_back(p, b, e);\n   else if (zrl[sz - p] == p) {\n\
    \    if (std::get<0>(run_m[p])) push(p, b, std::get<2>(run_m[p])), run_m[p]= Run{};\n\
    \    else push(p, b, m + p + zrl[p]);\n   } else push(p, b, m + zrl[sz - p]);\n\
    \  for (auto [p, b, e]: run_m)\n   if (p) {\n    if (zrl[sz - p] != p) push(p,\
    \ m - zrl_r[sz - p], e);\n    else if (2 * p > lsz || zrl[sz - 2 * p] < p) push(p,\
    \ m - p - zrl_r[p], e);\n   }\n  for (int p= 1; p <= lsz; ++p)\n   if (bool skpr=\
    \ 2 * p <= rsz && zrl[p] >= p, skpl= 2 * p <= lsz && zrl[sz - 2 * p] >= p; zrl[sz\
    \ - p] == p) {\n    if (!skpl && !skpr) push(p, m - p - zrl_r[p], m + p + zrl[p]);\n\
    \   } else {\n    if (!skpr)\n     if (int b= m - zrl_r[sz - p], e= m + p + zrl[p];\
    \ e - b >= 2 * p) push(p, b, e);\n    if (!skpl)\n     if (int b= m - p - zrl_r[p],\
    \ e= m + zrl[sz - p]; e - b >= 2 * p) push(p, b, e);\n   }\n  return ret;\n };\n\
    \ std::vector<std::tuple<int, int, int>> runs= rec(rec, 0, s.size());\n std::copy(glb.begin(),\
    \ glb.end(), std::back_inserter(runs));\n int rn= runs.size(), n= s.size();\n\
    \ glb.resize(rn);\n std::vector<int> pt(n);\n#define RADIX(A, B, C, D, E) \\\n\
    \ for (auto [p, l, r]: A) ++pt[C]; \\\n for (int i= 1; E < n; ++i) pt[i]+= pt[i\
    \ - 1]; \\\n for (int i= rn; i--;) B[--pt[D]]= A[i];\n RADIX(runs, glb, r - 1,\
    \ std::get<2>(runs[i]) - 1, i)\n pt.assign(n, 0);\n RADIX(glb, runs, l, std::get<1>(glb[i]),\
    \ i)\n runs.erase(std::unique(runs.begin(), runs.end(), [](auto &r1, auto &r2)\
    \ { return std::get<1>(r1) == std::get<1>(r2) && std::get<2>(r1) == std::get<2>(r2);\
    \ }), runs.end()), glb.resize(rn= runs.size()), pt.assign(n / 2, 0);\n RADIX(runs,\
    \ glb, p - 1, std::get<0>(runs[i]) - 1, i + i)\n#undef RADIX\n return glb;\n}\n\
    template <class Int> auto run_enumerate(const std::vector<Int> &s) { return run_enumerate_(s,\
    \ *std::max_element(s.begin(), s.end()) + 1); }\nauto run_enumerate(const std::string\
    \ &s) { return run_enumerate_(s); }\n}\nusing string_internal::run_enumerate;"
  dependsOn: []
  isVerificationFile: false
  path: src/String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-11-20 22:04:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/runenumerate.zalgo.test.cpp
  - test/yosupo/z_algorithm.test.cpp
documentation_of: src/String/z_algorithm.hpp
layout: document
title: Z-Algorithm
---

文字列 $S$ に対して構築することにする. \
文字列 $S$ の $l$ 文字目から $r-1$ 文字目までの部分文字列を $S_{l:r}$ と表すことにする.\
文字列 $S$ の $k$ 文字目から開始した接尾辞を $S_{k:}$ と表すことにする.\
また $n = \lvert S\rvert$ とおく. 

|関数|概要|計算量|
|---|---|---|
|`z_algorithm(S)`| 長さ $n$ の配列 $Z$ を返す. <br> $Z_k := $ $S$ と $S_{k:}$ の最長共通接頭辞の長さ. <br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(n)$|
|`run_enumerate(S)`|文字列 $S$ の [**連 (run)**](https://www.iss.is.tohoku.ac.jp/stringology/Algorithms/Basic/run.html) を列挙する. <br> タプル $(t,l,r)$ で部分文字列 $S_{l:r}$ の最小周期が $t$ であることを表現する. <br> 返り値は `vector<tuple<int,int,int>>`. <br> 引数は `vector<Int>` か `string` を渡せる.|$\mathcal{O}(n\log n)$|
