---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Graph/BipartiteGraph.hpp
    title: "(\u6697\u9ED9\u7684\u306A)\u4E8C\u90E8\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/Graph/DulmageMendelsohn.hpp
    title: "Dulmage-Mendelsohn \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/Graph/StronglyConnectedComponents.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/Math/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0366.test.cpp
    title: test/aoj/0366.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3168.bm.test.cpp
    title: test/aoj/3168.bm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc223_g.dm.test.cpp
    title: test/atcoder/abc223_g.dm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.bipatite_graph.test.cpp
    title: test/yosupo/bipartitematching.bipatite_graph.test.cpp
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
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1813.test.cpp
    title: test/yukicoder/1813.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/CsrArray.hpp\"\n#include <vector>\n#include\
    \ <iterator>\ntemplate <class T> struct ListRange {\n using Iterator= typename\
    \ std::vector<T>::const_iterator;\n Iterator bg, ed;\n Iterator begin() const\
    \ { return bg; }\n Iterator end() const { return ed; }\n size_t size() const {\
    \ return std::distance(bg, ed); }\n const T &operator[](int i) const { return\
    \ bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T> csr;\n std::vector<int>\
    \ pos;\npublic:\n CsrArray()= default;\n CsrArray(const std::vector<T> &c, const\
    \ std::vector<int> &p): csr(c), pos(p) {}\n size_t size() const { return pos.size()\
    \ - 1; }\n const ListRange<T> operator[](int i) const { return {csr.begin() +\
    \ pos[i], csr.begin() + pos[i + 1]}; }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <iterator>\ntemplate <class T>\
    \ struct ListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n\
    \ Iterator bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const\
    \ { return ed; }\n size_t size() const { return std::distance(bg, ed); }\n const\
    \ T &operator[](int i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray\
    \ {\n std::vector<T> csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n\
    \ CsrArray(const std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p)\
    \ {}\n size_t size() const { return pos.size() - 1; }\n const ListRange<T> operator[](int\
    \ i) const { return {csr.begin() + pos[i], csr.begin() + pos[i + 1]}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/CsrArray.hpp
  requiredBy:
  - src/Graph/BipartiteGraph.hpp
  - src/Graph/StronglyConnectedComponents.hpp
  - src/Graph/DulmageMendelsohn.hpp
  - src/Math/TwoSatisfiability.hpp
  timestamp: '2023-03-07 14:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/scc.test.cpp
  - test/yosupo/bipartitematching.bipatite_graph.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/aoj/3168.bm.test.cpp
  - test/aoj/0366.test.cpp
  - test/atcoder/abc223_g.dm.test.cpp
  - test/yukicoder/1170.test.cpp
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1813.test.cpp
  - test/yukicoder/1293.scc.test.cpp
  - test/yukicoder/1745.test.cpp
documentation_of: src/DataStructure/CsrArray.hpp
layout: document
title: "CSR\u5F62\u5F0F"
---
## 参考
[https://ja.wikipedia.org/wiki/疎行列#圧縮行格納](https://ja.wikipedia.org/wiki/%E7%96%8E%E8%A1%8C%E5%88%97#%E5%9C%A7%E7%B8%AE%E8%A1%8C%E6%A0%BC%E7%B4%8D) \
[https://nachiavivias.github.io/cp-library/column/2022/03.html](https://nachiavivias.github.io/cp-library/column/2022/03.html)
