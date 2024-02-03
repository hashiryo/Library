---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc172_d.enum_quo.test.cpp
    title: test/atcoder/abc172_d.enum_quo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc179_c.enum_quo.test.cpp
    title: test/atcoder/abc179_c.enum_quo.test.cpp
  - icon: ':x:'
    path: test/yosupo/enumerate_quotients.test.cpp
    title: test/yosupo/enumerate_quotients.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1260.test.cpp
    title: test/yukicoder/1260.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1573.enum_quo.test.cpp
    title: test/yukicoder/1573.enum_quo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/NumberTheory/enumerate_quotients.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <tuple>\n#include <cmath>\n#include <cstdint>\n\
    // (q,l,r) : i in (l,r], \u230AN/i\u230B = q\nstd::vector<std::tuple<uint64_t,\
    \ uint64_t, uint64_t>> enumerate_quotients(uint64_t N) {\n uint64_t sq= std::sqrt(N),\
    \ prev= N, x;\n std::vector<std::tuple<uint64_t, uint64_t, uint64_t>> ret;\n for\
    \ (int q= 1, n= (sq * sq + sq <= N ? sq : sq - 1); q <= n; ++q) ret.emplace_back(q,\
    \ x= double(N) / (q + 1), prev), prev= x;\n for (int l= sq; l >= 1; --l) ret.emplace_back(double(N)\
    \ / l, l - 1, l);\n return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <tuple>\n\
    #include <cmath>\n#include <cstdint>\n// (q,l,r) : i in (l,r], \u230AN/i\u230B\
    \ = q\nstd::vector<std::tuple<uint64_t, uint64_t, uint64_t>> enumerate_quotients(uint64_t\
    \ N) {\n uint64_t sq= std::sqrt(N), prev= N, x;\n std::vector<std::tuple<uint64_t,\
    \ uint64_t, uint64_t>> ret;\n for (int q= 1, n= (sq * sq + sq <= N ? sq : sq -\
    \ 1); q <= n; ++q) ret.emplace_back(q, x= double(N) / (q + 1), prev), prev= x;\n\
    \ for (int l= sq; l >= 1; --l) ret.emplace_back(double(N) / l, l - 1, l);\n return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/NumberTheory/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2023-11-25 18:44:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1573.enum_quo.test.cpp
  - test/yukicoder/1260.test.cpp
  - test/atcoder/abc172_d.enum_quo.test.cpp
  - test/atcoder/abc179_c.enum_quo.test.cpp
  - test/yosupo/enumerate_quotients.test.cpp
documentation_of: src/NumberTheory/enumerate_quotients.hpp
layout: document
title: "$\\lfloor N/i \\rfloor$ \u306E\u5217\u6319"
---

$\lbrack N\rbrack = \lbrace1,2,\dots,N\rbrace$ を $\left\lfloor \frac{N}{i} \right\rfloor$ が等しくなるような
$i \in \lbrack N\rbrack$ でグループ分けをする.

返り値は $\lbrace(q_j,l_j,r_j): j=1,\dots,k\rbrace$ で表現しており, 各 $j$ について任意の $i\in ( l_j,r_j\rbrack$ で $\left\lfloor \frac{N}{i} \right\rfloor = q_j$ が成り立つ.
$q_j$ が昇順になるように並べている.


## 計算量
$\mathcal{O} (\sqrt{N})$
