---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/DQuery.hpp
    title: "\u533A\u9593\u5185\u306E\u7A2E\u985E\u6570\u3092\u7B54\u3048\u308B\u30AF\
      \u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.WM.test.cpp
    title: test/aoj/1549.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674.WM.test.cpp
    title: test/aoj/2674.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc174_f.WM.test.cpp
    title: test/atcoder/abc174_f.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.WM.test.cpp
    title: test/yosupo/range_kth_smallest.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_frequency.WM.test.cpp
    title: test/yosupo/static_range_frequency.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/728.WM.test.cpp
    title: test/yukicoder/728.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/919.WM.test.cpp
    title: test/yukicoder/919.WM.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/DataStructure/WaveletMatrix.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <array>\n#include <cassert>\ntemplate <class T=\
    \ long long> class WaveletMatrix {\n struct SuccinctIndexableDictionary {\n  std::size_t\
    \ len, blocks, zeros;\n  std::vector<unsigned> bit, sum;\n  SuccinctIndexableDictionary()=\
    \ default;\n  SuccinctIndexableDictionary(std::size_t len): len(len), blocks((len\
    \ >> 5) + 1), bit(blocks, 0), sum(blocks, 0) {}\n  void set(int k) { bit[k >>\
    \ 5]|= 1U << (k & 31); }\n  void build() {\n   for (std::size_t i= 1; i < blocks;\
    \ i++) sum[i]= sum[i - 1] + __builtin_popcount(bit[i - 1]);\n   zeros= rank0(len);\n\
    \  }\n  bool operator[](int k) const { return (bit[k >> 5] >> (k & 31)) & 1; }\n\
    \  std::size_t rank(std::size_t k) const { return (sum[k >> 5] + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1))); }\n  std::size_t rank0(std::size_t k) const\
    \ { return k - rank(k); }\n };\n std::size_t len, lg;\n std::vector<SuccinctIndexableDictionary>\
    \ mat;\n std::vector<T> vec;\npublic:\n WaveletMatrix()= default;\n WaveletMatrix(const\
    \ std::vector<T> &v): len(v.size()), lg(32 - __builtin_clz(std::max<int>(len,\
    \ 1))), mat(lg, len), vec(v) {\n  std::sort(vec.begin(), vec.end());\n  vec.erase(std::unique(vec.begin(),\
    \ vec.end()), vec.end());\n  std::vector<unsigned> cur(len), nex(len);\n  for\
    \ (int i= len; i--;) cur[i]= std::lower_bound(vec.begin(), vec.end(), v[i]) -\
    \ vec.begin();\n  for (auto h= lg; h--; cur.swap(nex)) {\n   for (std::size_t\
    \ i= 0; i < len; i++)\n    if ((cur[i] >> h) & 1) mat[h].set(i);\n   mat[h].build();\n\
    \   std::array it{nex.begin(), nex.begin() + mat[h].zeros};\n   for (std::size_t\
    \ i= 0; i < len; i++) *it[mat[h][i]]++= cur[i];\n  }\n }\n // k-th(0-indexed)\
    \ smallest number in v[l,r)\n T kth_smallest(int l, int r, int k) const {\n  assert(k\
    \ < r - l);\n  std::size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0=\
    \ mat[h].rank0(l), r0= mat[h].rank0(r); k >= r0 - l0) {\n    k-= r0 - l0, ret|=\
    \ 1 << h;\n    l+= mat[h].zeros - l0, r+= mat[h].zeros - r0;\n   } else l= l0,\
    \ r= r0;\n  return vec[ret];\n }\n // k-th(0-indexed) largest number in v[l,r)\n\
    \ T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r - l -\
    \ k - 1); }\n // count i s.t. (l <= i < r) && (v[i] < ub)\n std::size_t count(int\
    \ l, int r, T ub) const {\n  std::size_t x= std::lower_bound(vec.begin(), vec.end(),\
    \ ub) - vec.begin();\n  if (x >= 1u << lg) return r - l;\n  if (x == 0) return\
    \ 0;\n  std::size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0= mat[h].rank0(l),\
    \ r0= mat[h].rank0(r); (x >> h) & 1) ret+= r0 - l0, l+= mat[h].zeros - l0, r+=\
    \ mat[h].zeros - r0;\n   else l= l0, r= r0;\n  return ret;\n }\n // count i s.t.\
    \ (l <= i < r) && (lb <= v[i] < ub)\n std::size_t count(int l, int r, T lb, T\
    \ ub) const { return count(l, r, ub) - count(l, r, lb); }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\ntemplate <class T= long long> class WaveletMatrix {\n struct\
    \ SuccinctIndexableDictionary {\n  std::size_t len, blocks, zeros;\n  std::vector<unsigned>\
    \ bit, sum;\n  SuccinctIndexableDictionary()= default;\n  SuccinctIndexableDictionary(std::size_t\
    \ len): len(len), blocks((len >> 5) + 1), bit(blocks, 0), sum(blocks, 0) {}\n\
    \  void set(int k) { bit[k >> 5]|= 1U << (k & 31); }\n  void build() {\n   for\
    \ (std::size_t i= 1; i < blocks; i++) sum[i]= sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n   zeros= rank0(len);\n  }\n  bool operator[](int k) const { return\
    \ (bit[k >> 5] >> (k & 31)) & 1; }\n  std::size_t rank(std::size_t k) const {\
    \ return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\
    \ }\n  std::size_t rank0(std::size_t k) const { return k - rank(k); }\n };\n std::size_t\
    \ len, lg;\n std::vector<SuccinctIndexableDictionary> mat;\n std::vector<T> vec;\n\
    public:\n WaveletMatrix()= default;\n WaveletMatrix(const std::vector<T> &v):\
    \ len(v.size()), lg(32 - __builtin_clz(std::max<int>(len, 1))), mat(lg, len),\
    \ vec(v) {\n  std::sort(vec.begin(), vec.end());\n  vec.erase(std::unique(vec.begin(),\
    \ vec.end()), vec.end());\n  std::vector<unsigned> cur(len), nex(len);\n  for\
    \ (int i= len; i--;) cur[i]= std::lower_bound(vec.begin(), vec.end(), v[i]) -\
    \ vec.begin();\n  for (auto h= lg; h--; cur.swap(nex)) {\n   for (std::size_t\
    \ i= 0; i < len; i++)\n    if ((cur[i] >> h) & 1) mat[h].set(i);\n   mat[h].build();\n\
    \   std::array it{nex.begin(), nex.begin() + mat[h].zeros};\n   for (std::size_t\
    \ i= 0; i < len; i++) *it[mat[h][i]]++= cur[i];\n  }\n }\n // k-th(0-indexed)\
    \ smallest number in v[l,r)\n T kth_smallest(int l, int r, int k) const {\n  assert(k\
    \ < r - l);\n  std::size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0=\
    \ mat[h].rank0(l), r0= mat[h].rank0(r); k >= r0 - l0) {\n    k-= r0 - l0, ret|=\
    \ 1 << h;\n    l+= mat[h].zeros - l0, r+= mat[h].zeros - r0;\n   } else l= l0,\
    \ r= r0;\n  return vec[ret];\n }\n // k-th(0-indexed) largest number in v[l,r)\n\
    \ T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r - l -\
    \ k - 1); }\n // count i s.t. (l <= i < r) && (v[i] < ub)\n std::size_t count(int\
    \ l, int r, T ub) const {\n  std::size_t x= std::lower_bound(vec.begin(), vec.end(),\
    \ ub) - vec.begin();\n  if (x >= 1u << lg) return r - l;\n  if (x == 0) return\
    \ 0;\n  std::size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0= mat[h].rank0(l),\
    \ r0= mat[h].rank0(r); (x >> h) & 1) ret+= r0 - l0, l+= mat[h].zeros - l0, r+=\
    \ mat[h].zeros - r0;\n   else l= l0, r= r0;\n  return ret;\n }\n // count i s.t.\
    \ (l <= i < r) && (lb <= v[i] < ub)\n std::size_t count(int l, int r, T lb, T\
    \ ub) const { return count(l, r, ub) - count(l, r, lb); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/WaveletMatrix.hpp
  requiredBy:
  - src/DataStructure/DQuery.hpp
  timestamp: '2023-01-21 19:30:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2674.WM.test.cpp
  - test/aoj/1549.WM.test.cpp
  - test/yosupo/range_kth_smallest.WM.test.cpp
  - test/yosupo/static_range_frequency.WM.test.cpp
  - test/yukicoder/919.WM.test.cpp
  - test/yukicoder/728.WM.test.cpp
  - test/atcoder/abc174_f.WM.test.cpp
documentation_of: src/DataStructure/WaveletMatrix.hpp
layout: document
title: "Wavelet\u884C\u5217"
---
内部で座圧される
