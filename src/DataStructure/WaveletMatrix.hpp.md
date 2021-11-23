---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1549.WM.test.cpp
    title: test/aoj/1549.WM.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2674.WM.test.cpp
    title: test/aoj/2674.WM.test.cpp
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
    document_title: "Wavelet\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/WaveletMatrix.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Wavelet\u884C\u5217\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n * \u4E8B\u524D\u306B\u5EA7\u5727\u3057\u3066\u4F7F\u3046\n */\n\n// BEGIN CUT\
    \ HERE\n\nstruct WaveletMatrix {\n  struct SuccinctIndexableDictionary {\n   \
    \ std::size_t length;\n    std::size_t blocks;\n    std::vector<unsigned> bit,\
    \ sum;\n    SuccinctIndexableDictionary() = default;\n    SuccinctIndexableDictionary(std::size_t\
    \ length)\n        : length(length), blocks((length + 31) >> 5) {\n      bit.assign(blocks,\
    \ 0U);\n      sum.assign(blocks, 0U);\n    }\n    void set(int k) { bit[k >> 5]\
    \ |= 1U << (k & 31); }\n    void build() {\n      sum[0] = 0U;\n      for (std::size_t\
    \ i = 1; i < blocks; i++)\n        sum[i] = sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n    }\n    bool operator[](int k) { return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1)); }\n    int rank(int k) {\n      return (sum[k >> 5]\n        \
    \      + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));\n    }\n \
    \   int rank(bool val, int k) { return (val ? rank(k) : k - rank(k)); }\n  };\n\
    \n private:\n  unsigned sigma, height;\n  std::size_t length;\n  std::vector<SuccinctIndexableDictionary>\
    \ matrix;\n  std::vector<int> mid;\n\n private:\n  std::pair<int, int> succ(bool\
    \ f, int l, int r, int level) {\n    return {matrix[level].rank(f, l) + mid[level]\
    \ * f,\n            matrix[level].rank(f, r) + mid[level] * f};\n  }\n\n public:\n\
    \  WaveletMatrix() = default;\n  WaveletMatrix(std::vector<int> v)\n      : WaveletMatrix(v,\
    \ *max_element(v.begin(), v.end()) + 1) {}\n  WaveletMatrix(std::vector<int> v,\
    \ unsigned s) : sigma(s), length(v.size()) {\n    height = 32 - __builtin_clz(sigma);\n\
    \    matrix.resize(height);\n    mid.resize(height);\n    std::vector<int> l(length),\
    \ r(length);\n    for (int level = height - 1; level >= 0; level--) {\n      matrix[level]\
    \ = SuccinctIndexableDictionary(length + 1);\n      int left = 0, right = 0;\n\
    \      for (std::size_t i = 0; i < length; i++) {\n        if (((v[i] >> level)\
    \ & 1))\n          matrix[level].set(i), r[right++] = v[i];\n        else\n  \
    \        l[left++] = v[i];\n      }\n      mid[level] = left;\n      matrix[level].build();\n\
    \      v.swap(l);\n      for (int i = 0; i < right; i++) v[left + i] = r[i];\n\
    \    }\n  }\n  // v[k]\n  int access(int k) {\n    int ret = 0;\n    for (int\
    \ level = height - 1; level >= 0; level--) {\n      bool f = matrix[level][k];\n\
    \      if (f) ret |= 1 << level;\n      k = matrix[level].rank(f, k) + mid[level]\
    \ * f;\n    }\n    return ret;\n  }\n  int operator[](int k) { return access(k);\
    \ }\n  // count i s.t. (0 <= i < r) && v[i] == x\n  int rank(int x, int r) {\n\
    \    int l = 0;\n    for (int level = height - 1; level >= 0; level--)\n     \
    \ std::tie(l, r) = succ((x >> level) & 1, l, r, level);\n    return r - l;\n \
    \ }\n  // k-th(0-indexed) smallest number in v[l,r)\n  int kth_smallest(int l,\
    \ int r, int k) {\n    assert(0 <= k && k < r - l);\n    int ret = 0;\n    for\
    \ (int level = height - 1; level >= 0; level--) {\n      int cnt = matrix[level].rank(false,\
    \ r) - matrix[level].rank(false, l);\n      bool f = cnt <= k;\n      if (f) ret\
    \ |= 1 << level, k -= cnt;\n      std::tie(l, r) = succ(f, l, r, level);\n   \
    \ }\n    return ret;\n  }\n  // k-th(0-indexed) largest number in v[l,r)\n  int\
    \ kth_largest(int l, int r, int k) {\n    return kth_smallest(l, r, r - l - k\
    \ - 1);\n  }\n  // count i s.t. (l <= i < r) && (v[i] < upper)\n  int range_freq(int\
    \ l, int r, int upper) {\n    upper = std::min(upper, (int)sigma);\n    int ret\
    \ = 0;\n    for (int level = height - 1; level >= 0; level--) {\n      bool f\
    \ = ((upper >> level) & 1);\n      if (f) ret += matrix[level].rank(false, r)\
    \ - matrix[level].rank(false, l);\n      std::tie(l, r) = succ(f, l, r, level);\n\
    \    }\n    return ret;\n  }\n  // count i s.t. (l <= i < r) && (lower <= v[i]\
    \ < upper)\n  int range_freq(int l, int r, int lower, int upper) {\n    return\
    \ range_freq(l, r, upper) - range_freq(l, r, lower);\n  }\n  // max v[i] s.t.\
    \ (l <= i < r) && (v[i] < upper)\n  int prev_value(int l, int r, int upper) {\n\
    \    int cnt = range_freq(l, r, upper);\n    return cnt == 0 ? -1 : kth_smallest(l,\
    \ r, cnt - 1);\n  }\n  // std::min v[i] s.t. (l <= i < r) && (lower <= v[i])\n\
    \  int next_value(int l, int r, int lower) {\n    int cnt = range_freq(l, r, lower);\n\
    \    return cnt == r - l ? -1 : kth_smallest(l, r, cnt);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Wavelet\u884C\u5217\
    \n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * \u4E8B\u524D\u306B\u5EA7\u5727\
    \u3057\u3066\u4F7F\u3046\n */\n\n// BEGIN CUT HERE\n\nstruct WaveletMatrix {\n\
    \  struct SuccinctIndexableDictionary {\n    std::size_t length;\n    std::size_t\
    \ blocks;\n    std::vector<unsigned> bit, sum;\n    SuccinctIndexableDictionary()\
    \ = default;\n    SuccinctIndexableDictionary(std::size_t length)\n        : length(length),\
    \ blocks((length + 31) >> 5) {\n      bit.assign(blocks, 0U);\n      sum.assign(blocks,\
    \ 0U);\n    }\n    void set(int k) { bit[k >> 5] |= 1U << (k & 31); }\n    void\
    \ build() {\n      sum[0] = 0U;\n      for (std::size_t i = 1; i < blocks; i++)\n\
    \        sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n    bool\
    \ operator[](int k) { return (bool((bit[k >> 5] >> (k & 31)) & 1)); }\n    int\
    \ rank(int k) {\n      return (sum[k >> 5]\n              + __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1)));\n    }\n    int rank(bool val, int k) { return\
    \ (val ? rank(k) : k - rank(k)); }\n  };\n\n private:\n  unsigned sigma, height;\n\
    \  std::size_t length;\n  std::vector<SuccinctIndexableDictionary> matrix;\n \
    \ std::vector<int> mid;\n\n private:\n  std::pair<int, int> succ(bool f, int l,\
    \ int r, int level) {\n    return {matrix[level].rank(f, l) + mid[level] * f,\n\
    \            matrix[level].rank(f, r) + mid[level] * f};\n  }\n\n public:\n  WaveletMatrix()\
    \ = default;\n  WaveletMatrix(std::vector<int> v)\n      : WaveletMatrix(v, *max_element(v.begin(),\
    \ v.end()) + 1) {}\n  WaveletMatrix(std::vector<int> v, unsigned s) : sigma(s),\
    \ length(v.size()) {\n    height = 32 - __builtin_clz(sigma);\n    matrix.resize(height);\n\
    \    mid.resize(height);\n    std::vector<int> l(length), r(length);\n    for\
    \ (int level = height - 1; level >= 0; level--) {\n      matrix[level] = SuccinctIndexableDictionary(length\
    \ + 1);\n      int left = 0, right = 0;\n      for (std::size_t i = 0; i < length;\
    \ i++) {\n        if (((v[i] >> level) & 1))\n          matrix[level].set(i),\
    \ r[right++] = v[i];\n        else\n          l[left++] = v[i];\n      }\n   \
    \   mid[level] = left;\n      matrix[level].build();\n      v.swap(l);\n     \
    \ for (int i = 0; i < right; i++) v[left + i] = r[i];\n    }\n  }\n  // v[k]\n\
    \  int access(int k) {\n    int ret = 0;\n    for (int level = height - 1; level\
    \ >= 0; level--) {\n      bool f = matrix[level][k];\n      if (f) ret |= 1 <<\
    \ level;\n      k = matrix[level].rank(f, k) + mid[level] * f;\n    }\n    return\
    \ ret;\n  }\n  int operator[](int k) { return access(k); }\n  // count i s.t.\
    \ (0 <= i < r) && v[i] == x\n  int rank(int x, int r) {\n    int l = 0;\n    for\
    \ (int level = height - 1; level >= 0; level--)\n      std::tie(l, r) = succ((x\
    \ >> level) & 1, l, r, level);\n    return r - l;\n  }\n  // k-th(0-indexed) smallest\
    \ number in v[l,r)\n  int kth_smallest(int l, int r, int k) {\n    assert(0 <=\
    \ k && k < r - l);\n    int ret = 0;\n    for (int level = height - 1; level >=\
    \ 0; level--) {\n      int cnt = matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n      bool f = cnt <= k;\n      if (f) ret |= 1 << level, k -= cnt;\n \
    \     std::tie(l, r) = succ(f, l, r, level);\n    }\n    return ret;\n  }\n  //\
    \ k-th(0-indexed) largest number in v[l,r)\n  int kth_largest(int l, int r, int\
    \ k) {\n    return kth_smallest(l, r, r - l - k - 1);\n  }\n  // count i s.t.\
    \ (l <= i < r) && (v[i] < upper)\n  int range_freq(int l, int r, int upper) {\n\
    \    upper = std::min(upper, (int)sigma);\n    int ret = 0;\n    for (int level\
    \ = height - 1; level >= 0; level--) {\n      bool f = ((upper >> level) & 1);\n\
    \      if (f) ret += matrix[level].rank(false, r) - matrix[level].rank(false,\
    \ l);\n      std::tie(l, r) = succ(f, l, r, level);\n    }\n    return ret;\n\
    \  }\n  // count i s.t. (l <= i < r) && (lower <= v[i] < upper)\n  int range_freq(int\
    \ l, int r, int lower, int upper) {\n    return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\n  }\n  // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n  int prev_value(int\
    \ l, int r, int upper) {\n    int cnt = range_freq(l, r, upper);\n    return cnt\
    \ == 0 ? -1 : kth_smallest(l, r, cnt - 1);\n  }\n  // std::min v[i] s.t. (l <=\
    \ i < r) && (lower <= v[i])\n  int next_value(int l, int r, int lower) {\n   \
    \ int cnt = range_freq(l, r, lower);\n    return cnt == r - l ? -1 : kth_smallest(l,\
    \ r, cnt);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/728.WM.test.cpp
  - test/yukicoder/919.WM.test.cpp
  - test/aoj/2674.WM.test.cpp
  - test/aoj/1549.WM.test.cpp
  - test/yosupo/range_kth_smallest.WM.test.cpp
  - test/yosupo/static_range_frequency.WM.test.cpp
documentation_of: src/DataStructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/src/DataStructure/WaveletMatrix.hpp
- /library/src/DataStructure/WaveletMatrix.hpp.html
title: "Wavelet\u884C\u5217"
---
