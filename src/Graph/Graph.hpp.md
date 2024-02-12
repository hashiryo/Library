---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "\u30A4\u30C6\u30EC\u30FC\u30BF\u3060\u3051\u6301\u3063\u3066\u304A\u304F\
      \u3084\u3064"
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/Graph/FunctionalGraph.hpp
    title: "Functional\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Graph/HeavyLightDecomposition.hpp
    title: "\u91CD\u8EFD\u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc136_d.test.cpp
    title: test/atcoder/abc136_d.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc167_d.test.cpp
    title: test/atcoder/abc167_d.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc179_e.test.cpp
    title: test/atcoder/abc179_e.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc241_e.test.cpp
    title: test/atcoder/abc241_e.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1211.test.cpp
    title: test/yukicoder/1211.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <iterator>\ntemplate <class T> struct ListRange {\n using\
    \ Iterator= typename std::vector<T>::iterator;\n Iterator bg, ed;\n Iterator begin()\
    \ const { return bg; }\n Iterator end() const { return ed; }\n size_t size() const\
    \ { return std::distance(bg, ed); }\n T &operator[](int i) const { return bg[i];\
    \ }\n friend std::ostream &operator<<(std::ostream &os, const ListRange &r) {\n\
    \  return os << '[' << r.bg[0], std::for_each(r.bg + 1, r.ed, [&os](const T &x)\
    \ { os << \", \" << x; }), os << ']';\n }\n};\ntemplate <class T> struct ConstListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n friend std::ostream &operator<<(std::ostream &os,\
    \ const ConstListRange &r) {\n  return os << '[' << r.bg[0], std::for_each(r.bg\
    \ + 1, r.ed, [&os](const T &x) { os << \", \" << x; }), os << ']';\n }\n};\n#line\
    \ 3 \"src/Graph/Graph.hpp\"\nstruct Graph {\n struct Edge {\n  int s, d;\n  int\
    \ operator-(int v) const { return s ^ d ^ v; }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const Edge &e) { return os << '(' << e.s << \", \" << e.d << ')'; }\n };\n\
    \ size_t n;\n std::vector<Edge> es;\n std::vector<int> c, p;\n Graph(int n= 0):\
    \ n(n) {}\n void add_edge(int u, int v) { es.push_back({u, v}); }\n void build(bool\
    \ undirect) {\n  if (p.assign(n + 1, 0), c.resize(es.size() << undirect); undirect)\
    \ {\n   for (auto [u, v]: es) ++p[u], ++p[v];\n   for (int i= 0; i < n; ++i) p[i\
    \ + 1]+= p[i];\n   for (int i= es.size(); i--;) c[--p[es[i].s]]= i, c[--p[es[i].d]]=\
    \ i;\n  } else {\n   for (auto [u, v]: es) ++p[u];\n   for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i];\n   for (int i= es.size(); i--;) c[--p[es[i].s]]= i;\n  }\n\
    \ }\n size_t edge_size() const { return es.size(); }\n size_t vertex_size() const\
    \ { return n; }\n Edge &operator[](int e) { return es[e]; }\n const Edge &operator[](int\
    \ e) const { return es[e]; }\n ListRange<int> operator()(int u) { return {c.begin()\
    \ + p[u], c.begin() + p[u + 1]}; }\n ConstListRange<int> operator()(int u) const\
    \ { return {c.cbegin() + p[u], c.cbegin() + p[u + 1]}; }\n auto begin() { return\
    \ es.begin(); }\n auto begin() const { return es.cbegin(); }\n auto end() { return\
    \ es.end(); }\n auto end() const { return es.cend(); }\n};\n"
  code: "#pragma once\n#include \"src/Internal/ListRange.hpp\"\nstruct Graph {\n struct\
    \ Edge {\n  int s, d;\n  int operator-(int v) const { return s ^ d ^ v; }\n  friend\
    \ std::ostream &operator<<(std::ostream &os, const Edge &e) { return os << '('\
    \ << e.s << \", \" << e.d << ')'; }\n };\n size_t n;\n std::vector<Edge> es;\n\
    \ std::vector<int> c, p;\n Graph(int n= 0): n(n) {}\n void add_edge(int u, int\
    \ v) { es.push_back({u, v}); }\n void build(bool undirect) {\n  if (p.assign(n\
    \ + 1, 0), c.resize(es.size() << undirect); undirect) {\n   for (auto [u, v]:\
    \ es) ++p[u], ++p[v];\n   for (int i= 0; i < n; ++i) p[i + 1]+= p[i];\n   for\
    \ (int i= es.size(); i--;) c[--p[es[i].s]]= i, c[--p[es[i].d]]= i;\n  } else {\n\
    \   for (auto [u, v]: es) ++p[u];\n   for (int i= 0; i < n; ++i) p[i + 1]+= p[i];\n\
    \   for (int i= es.size(); i--;) c[--p[es[i].s]]= i;\n  }\n }\n size_t edge_size()\
    \ const { return es.size(); }\n size_t vertex_size() const { return n; }\n Edge\
    \ &operator[](int e) { return es[e]; }\n const Edge &operator[](int e) const {\
    \ return es[e]; }\n ListRange<int> operator()(int u) { return {c.begin() + p[u],\
    \ c.begin() + p[u + 1]}; }\n ConstListRange<int> operator()(int u) const { return\
    \ {c.cbegin() + p[u], c.cbegin() + p[u + 1]}; }\n auto begin() { return es.begin();\
    \ }\n auto begin() const { return es.cbegin(); }\n auto end() { return es.end();\
    \ }\n auto end() const { return es.cend(); }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/Graph.hpp
  requiredBy:
  - src/Graph/FunctionalGraph.hpp
  - src/Graph/HeavyLightDecomposition.hpp
  timestamp: '2024-02-12 20:44:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/abc241_e.test.cpp
  - test/atcoder/abc179_e.test.cpp
  - test/atcoder/abc167_d.test.cpp
  - test/atcoder/abc136_d.test.cpp
  - test/yukicoder/1211.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/1242.test.cpp
documentation_of: src/Graph/Graph.hpp
layout: document
redirect_from:
- /library/src/Graph/Graph.hpp
- /library/src/Graph/Graph.hpp.html
title: src/Graph/Graph.hpp
---
