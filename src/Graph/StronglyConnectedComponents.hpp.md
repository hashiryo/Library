---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0366.test.cpp
    title: test/aoj/0366.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1170.test.cpp
    title: test/yukicoder/1170.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1293.scc.test.cpp
    title: test/yukicoder/1293.scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1813.test.cpp
    title: test/yukicoder/1813.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/StronglyConnectedComponents.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <array>\n#line 2 \"src/DataStructure/CsrArray.hpp\"\
    \n#include <vector>\n#include <iterator>\ntemplate <class T> struct ListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T>\
    \ csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n CsrArray(const\
    \ std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p) {}\n size_t size()\
    \ const { return pos.size() - 1; }\n const ListRange<T> operator[](int i) const\
    \ { return {csr.begin() + pos[i], csr.begin() + pos[i + 1]}; }\n};\n#line 6 \"\
    src/Graph/StronglyConnectedComponents.hpp\"\nclass StronglyConnectedComponents\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<int> csr, pos, id;\npublic:\n\
    \ StronglyConnectedComponents(int n): csr(n, -2), id(n) {}\n void add_edge(int\
    \ src, int dst) { es.push_back({src, dst}); }\n void build() {\n  const int n=\
    \ id.size();\n  std::vector<int> g(es.size()), sep(n + 1), ord(n);\n  for (auto\
    \ [s, d]: es) ++sep[s];\n  for (int i= 0; i < n; ++i) sep[i + 1]+= sep[i];\n \
    \ for (auto [s, d]: es) g[--sep[s]]= d;\n  std::vector<int> dat(sep.begin(), sep.begin()\
    \ + n);\n  int k= n, p;\n  for (int s= 0; s < n; ++s)\n   if (csr[s] == -2)\n\
    \    for (csr[p= s]= -1; p >= 0;) {\n     if (dat[p] == sep[p + 1]) ord[--k]=\
    \ p, p= csr[p];\n     else if (int q= g[dat[p]++]; csr[q] == -2) csr[q]= p, p=\
    \ q;\n    }\n  sep.assign(n + 1, 0), pos= {p= 0};\n  for (auto [s, d]: es) ++sep[d];\n\
    \  for (int i= 0; i < n; ++i) sep[i + 1]+= sep[i];\n  for (auto [s, d]: es) g[--sep[d]]=\
    \ s;\n  for (int s: ord)\n   if (dat[s] >= 0) {\n    for (csr[k++]= s, dat[s]=\
    \ -1; p < k; ++p)\n     for (int v= csr[p], j= sep[v], u; j < sep[v + 1]; ++j)\n\
    \      if (dat[u= g[j]] >= 0) dat[u]= -1, csr[k++]= u;\n    pos.push_back(k);\n\
    \   }\n  for (int i= pos.size() - 1; i--;)\n   while (k > pos[i]) id[csr[--k]]=\
    \ i;\n }\n int components_num() const { return pos.size() - 1; }\n const ListRange<int>\
    \ block(int k) const { return {csr.begin() + pos[k], csr.begin() + pos[k + 1]};\
    \ }\n int belong(int i) const { return id[i]; }\n const CsrArray<int> dag() const\
    \ {\n  std::vector<std::array<int, 2>> es_;\n  for (auto [s, d]: es)\n   if (s=\
    \ id[s], d= id[d]; s != d) es_.push_back({s, d});\n  std::sort(es_.begin(), es_.end()),\
    \ es_.erase(std::unique(es_.begin(), es_.end()), es_.end());\n  std::vector<int>\
    \ g(es_.size()), p(pos.size());\n  for (auto [s, d]: es_) ++p[s];\n  std::partial_sum(p.begin(),\
    \ p.end(), p.begin());\n  for (auto [s, d]: es_) g[--p[s]]= d;\n  return {g, p};\n\
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <array>\n\
    #include \"src/DataStructure/CsrArray.hpp\"\nclass StronglyConnectedComponents\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<int> csr, pos, id;\npublic:\n\
    \ StronglyConnectedComponents(int n): csr(n, -2), id(n) {}\n void add_edge(int\
    \ src, int dst) { es.push_back({src, dst}); }\n void build() {\n  const int n=\
    \ id.size();\n  std::vector<int> g(es.size()), sep(n + 1), ord(n);\n  for (auto\
    \ [s, d]: es) ++sep[s];\n  for (int i= 0; i < n; ++i) sep[i + 1]+= sep[i];\n \
    \ for (auto [s, d]: es) g[--sep[s]]= d;\n  std::vector<int> dat(sep.begin(), sep.begin()\
    \ + n);\n  int k= n, p;\n  for (int s= 0; s < n; ++s)\n   if (csr[s] == -2)\n\
    \    for (csr[p= s]= -1; p >= 0;) {\n     if (dat[p] == sep[p + 1]) ord[--k]=\
    \ p, p= csr[p];\n     else if (int q= g[dat[p]++]; csr[q] == -2) csr[q]= p, p=\
    \ q;\n    }\n  sep.assign(n + 1, 0), pos= {p= 0};\n  for (auto [s, d]: es) ++sep[d];\n\
    \  for (int i= 0; i < n; ++i) sep[i + 1]+= sep[i];\n  for (auto [s, d]: es) g[--sep[d]]=\
    \ s;\n  for (int s: ord)\n   if (dat[s] >= 0) {\n    for (csr[k++]= s, dat[s]=\
    \ -1; p < k; ++p)\n     for (int v= csr[p], j= sep[v], u; j < sep[v + 1]; ++j)\n\
    \      if (dat[u= g[j]] >= 0) dat[u]= -1, csr[k++]= u;\n    pos.push_back(k);\n\
    \   }\n  for (int i= pos.size() - 1; i--;)\n   while (k > pos[i]) id[csr[--k]]=\
    \ i;\n }\n int components_num() const { return pos.size() - 1; }\n const ListRange<int>\
    \ block(int k) const { return {csr.begin() + pos[k], csr.begin() + pos[k + 1]};\
    \ }\n int belong(int i) const { return id[i]; }\n const CsrArray<int> dag() const\
    \ {\n  std::vector<std::array<int, 2>> es_;\n  for (auto [s, d]: es)\n   if (s=\
    \ id[s], d= id[d]; s != d) es_.push_back({s, d});\n  std::sort(es_.begin(), es_.end()),\
    \ es_.erase(std::unique(es_.begin(), es_.end()), es_.end());\n  std::vector<int>\
    \ g(es_.size()), p(pos.size());\n  for (auto [s, d]: es_) ++p[s];\n  std::partial_sum(p.begin(),\
    \ p.end(), p.begin());\n  for (auto [s, d]: es_) g[--p[s]]= d;\n  return {g, p};\n\
    \ }\n};"
  dependsOn:
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: false
  path: src/Graph/StronglyConnectedComponents.hpp
  requiredBy:
  - src/Math/TwoSatisfiability.hpp
  timestamp: '2023-03-07 14:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1170.test.cpp
  - test/yukicoder/1813.test.cpp
  - test/yukicoder/1293.scc.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
  - test/aoj/0366.test.cpp
documentation_of: src/Graph/StronglyConnectedComponents.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
`get_block` : 強連結成分をトポロジカルソート順にしたものを返す \
`get_index` : 元の頂点が所属する強連結成分のidを返す \
`get_dag`   : 縮約したDAGを返す
## 計算量
$\mathcal{O}(V)$
