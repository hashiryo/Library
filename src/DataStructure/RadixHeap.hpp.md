---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.RadixHeap.test.cpp
    title: test/aoj/GRL_6_B.RadixHeap.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Radix-Heap
    links:
    - https://codeforces.com/contest/316/problem/C2
    - https://github.com/iwiwi/radix-heap/blob/master/README_ja.md
  bundledCode: "#line 1 \"src/DataStructure/RadixHeap.hpp\"\n/**\n * @title Radix-Heap\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief dijkstra\u306E\u9AD8\u901F\
    \u5316\u306B\u4F7F\u7528\n * @brief \u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3082\
    \u4F7F\u3048\u308B\n * @brief \u5C0F\u3055\u3044\u9806\n * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n// verify\u7528:\n// https://codeforces.com/contest/316/problem/C2\n\
    // (Radix-Heap\u3067\u306A\u3044\u3068TLE\u3057\u305F -> \u5BB9\u91CF\u30B9\u30B1\
    \u30FC\u30EA\u30F3\u30B0\u306A\u3089TLE\u3057\u306A\u3044)\n\nnamespace internal\
    \ {\ntemplate <bool Is64bit>\nclass find_bucket_impl;\ntemplate <>\nclass find_bucket_impl<false>\
    \ {\n public:\n  static inline constexpr size_t find_bucket(uint32_t x, uint32_t\
    \ last) {\n    return x == last ? 0 : 32 - __builtin_clz(x ^ last);\n  }\n};\n\
    template <>\nclass find_bucket_impl<true> {\n public:\n  static inline constexpr\
    \ size_t find_bucket(uint64_t x, uint64_t last) {\n    return x == last ? 0 :\
    \ 64 - __builtin_clzll(x ^ last);\n  }\n};\ntemplate <typename T>\ninline constexpr\
    \ size_t find_bucket(T x, T last) {\n  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x,\
    \ last);\n}\ntemplate <typename key_t, bool IsSigned>\nclass encoder_impl_integer;\n\
    template <typename key_t>\nclass encoder_impl_integer<key_t, false> {\n public:\n\
    \  using ukey_t = key_t;\n  inline static constexpr ukey_t encode(key_t x) { return\
    \ x; }\n  inline static constexpr key_t decode(ukey_t x) { return x; }\n};\ntemplate\
    \ <typename key_t>\nclass encoder_impl_integer<key_t, true> {\n public:\n  typedef\
    \ typename make_unsigned<key_t>::type ukey_t;\n  inline static constexpr ukey_t\
    \ encode(key_t x) {\n    return static_cast<ukey_t>(x)\n           ^ (ukey_t(1)\
    \ << ukey_t(numeric_limits<ukey_t>::digits - 1));\n  }\n  inline static constexpr\
    \ key_t decode(ukey_t x) {\n    return static_cast<key_t>(\n        x ^ (ukey_t(1)\
    \ << (numeric_limits<ukey_t>::digits - 1)));\n  }\n};\ntemplate <typename key_t,\
    \ typename ukey_t>\nclass encoder_impl_decimal {\n public:\n  inline static constexpr\
    \ ukey_t encode(key_t x) {\n    return raw_cast<key_t, ukey_t>(x)\n          \
    \ ^ ((-(raw_cast<key_t, ukey_t>(x)\n                 >> (numeric_limits<ukey_t>::digits\
    \ - 1)))\n              | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));\n\
    \  }\n  inline static constexpr key_t decode(ukey_t x) {\n    return raw_cast<ukey_t,\
    \ key_t>(\n        x\n        ^ (((x >> (numeric_limits<ukey_t>::digits - 1))\
    \ - 1)\n           | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1))));\n\
    \  }\n\n private:\n  template <typename T, typename U>\n  union raw_cast {\n \
    \  public:\n    constexpr raw_cast(T t) : t_(t) {}\n    operator U() const { return\
    \ u_; }\n\n   private:\n    T t_;\n    U u_;\n  };\n};\ntemplate <typename key_t>\n\
    class encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value> {};\n\
    template <>\nclass encoder<float> : public encoder_impl_decimal<float, uint32_t>\
    \ {};\ntemplate <>\nclass encoder<double> : public encoder_impl_decimal<double,\
    \ uint64_t> {};\n}  // namespace internal\n\ntemplate <typename key_t, typename\
    \ val_t,\n          typename encoder_t = internal::encoder<key_t>>\nclass RadixHeap\
    \ {\n public:\n  typedef typename encoder_t::ukey_t ukey_t;\n\n  RadixHeap() :\
    \ size_(0), last_(), buckets_() {\n    buckets_min_.fill(numeric_limits<ukey_t>::max());\n\
    \  }\n\n  void push(key_t key, val_t value) {\n    const ukey_t x = encoder_t::encode(key);\n\
    \    assert(last_ <= x);\n    ++size_;\n    const size_t k = internal::find_bucket(x,\
    \ last_);\n    buckets_[k].emplace_back(x, value);\n    buckets_min_[k] = min(buckets_min_[k],\
    \ x);\n  }\n  void emplace(key_t key, val_t value) { push(key, value); }\n  pair<key_t,\
    \ val_t> top() {\n    pull();\n    return make_pair(encoder_t::decode(last_),\
    \ buckets_[0].back().second);\n  }\n  pair<key_t, val_t> pop() {\n    pull();\n\
    \    --size_;\n    auto ret = make_pair(encoder_t::decode(last_), buckets_[0].back().second);\n\
    \    buckets_[0].pop_back();\n    return ret;\n  }\n  size_t size() const { return\
    \ size_; }\n  bool empty() const { return size_ == 0; }\n\n private:\n  size_t\
    \ size_;\n  ukey_t last_;\n  array<vector<pair<ukey_t, val_t>>, numeric_limits<ukey_t>::digits\
    \ + 1>\n      buckets_;\n  array<ukey_t, numeric_limits<ukey_t>::digits + 1> buckets_min_;\n\
    \n  void pull() {\n    assert(size_ > 0);\n    if (!buckets_[0].empty()) return;\n\
    \    size_t i = 1;\n    while (buckets_[i].empty()) ++i;\n    last_ = buckets_min_[i];\n\
    \    for (size_t j = 0; j < buckets_[i].size(); ++j) {\n      const ukey_t x =\
    \ buckets_[i][j].first;\n      const size_t k = internal::find_bucket(x, last_);\n\
    \      buckets_[k].emplace_back(move(buckets_[i][j]));\n      buckets_min_[k]\
    \ = min(buckets_min_[k], x);\n    }\n    buckets_[i].clear();\n    buckets_min_[i]\
    \ = numeric_limits<ukey_t>::max();\n  }\n};\n"
  code: "/**\n * @title Radix-Heap\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n\
    \ * @brief dijkstra\u306E\u9AD8\u901F\u5316\u306B\u4F7F\u7528\n * @brief \u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u3082\u4F7F\u3048\u308B\n * @brief \u5C0F\u3055\
    \u3044\u9806\n * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n\n// verify\u7528:\n// https://codeforces.com/contest/316/problem/C2\n\
    // (Radix-Heap\u3067\u306A\u3044\u3068TLE\u3057\u305F -> \u5BB9\u91CF\u30B9\u30B1\
    \u30FC\u30EA\u30F3\u30B0\u306A\u3089TLE\u3057\u306A\u3044)\n\nnamespace internal\
    \ {\ntemplate <bool Is64bit>\nclass find_bucket_impl;\ntemplate <>\nclass find_bucket_impl<false>\
    \ {\n public:\n  static inline constexpr size_t find_bucket(uint32_t x, uint32_t\
    \ last) {\n    return x == last ? 0 : 32 - __builtin_clz(x ^ last);\n  }\n};\n\
    template <>\nclass find_bucket_impl<true> {\n public:\n  static inline constexpr\
    \ size_t find_bucket(uint64_t x, uint64_t last) {\n    return x == last ? 0 :\
    \ 64 - __builtin_clzll(x ^ last);\n  }\n};\ntemplate <typename T>\ninline constexpr\
    \ size_t find_bucket(T x, T last) {\n  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x,\
    \ last);\n}\ntemplate <typename key_t, bool IsSigned>\nclass encoder_impl_integer;\n\
    template <typename key_t>\nclass encoder_impl_integer<key_t, false> {\n public:\n\
    \  using ukey_t = key_t;\n  inline static constexpr ukey_t encode(key_t x) { return\
    \ x; }\n  inline static constexpr key_t decode(ukey_t x) { return x; }\n};\ntemplate\
    \ <typename key_t>\nclass encoder_impl_integer<key_t, true> {\n public:\n  typedef\
    \ typename make_unsigned<key_t>::type ukey_t;\n  inline static constexpr ukey_t\
    \ encode(key_t x) {\n    return static_cast<ukey_t>(x)\n           ^ (ukey_t(1)\
    \ << ukey_t(numeric_limits<ukey_t>::digits - 1));\n  }\n  inline static constexpr\
    \ key_t decode(ukey_t x) {\n    return static_cast<key_t>(\n        x ^ (ukey_t(1)\
    \ << (numeric_limits<ukey_t>::digits - 1)));\n  }\n};\ntemplate <typename key_t,\
    \ typename ukey_t>\nclass encoder_impl_decimal {\n public:\n  inline static constexpr\
    \ ukey_t encode(key_t x) {\n    return raw_cast<key_t, ukey_t>(x)\n          \
    \ ^ ((-(raw_cast<key_t, ukey_t>(x)\n                 >> (numeric_limits<ukey_t>::digits\
    \ - 1)))\n              | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));\n\
    \  }\n  inline static constexpr key_t decode(ukey_t x) {\n    return raw_cast<ukey_t,\
    \ key_t>(\n        x\n        ^ (((x >> (numeric_limits<ukey_t>::digits - 1))\
    \ - 1)\n           | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1))));\n\
    \  }\n\n private:\n  template <typename T, typename U>\n  union raw_cast {\n \
    \  public:\n    constexpr raw_cast(T t) : t_(t) {}\n    operator U() const { return\
    \ u_; }\n\n   private:\n    T t_;\n    U u_;\n  };\n};\ntemplate <typename key_t>\n\
    class encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value> {};\n\
    template <>\nclass encoder<float> : public encoder_impl_decimal<float, uint32_t>\
    \ {};\ntemplate <>\nclass encoder<double> : public encoder_impl_decimal<double,\
    \ uint64_t> {};\n}  // namespace internal\n\ntemplate <typename key_t, typename\
    \ val_t,\n          typename encoder_t = internal::encoder<key_t>>\nclass RadixHeap\
    \ {\n public:\n  typedef typename encoder_t::ukey_t ukey_t;\n\n  RadixHeap() :\
    \ size_(0), last_(), buckets_() {\n    buckets_min_.fill(numeric_limits<ukey_t>::max());\n\
    \  }\n\n  void push(key_t key, val_t value) {\n    const ukey_t x = encoder_t::encode(key);\n\
    \    assert(last_ <= x);\n    ++size_;\n    const size_t k = internal::find_bucket(x,\
    \ last_);\n    buckets_[k].emplace_back(x, value);\n    buckets_min_[k] = min(buckets_min_[k],\
    \ x);\n  }\n  void emplace(key_t key, val_t value) { push(key, value); }\n  pair<key_t,\
    \ val_t> top() {\n    pull();\n    return make_pair(encoder_t::decode(last_),\
    \ buckets_[0].back().second);\n  }\n  pair<key_t, val_t> pop() {\n    pull();\n\
    \    --size_;\n    auto ret = make_pair(encoder_t::decode(last_), buckets_[0].back().second);\n\
    \    buckets_[0].pop_back();\n    return ret;\n  }\n  size_t size() const { return\
    \ size_; }\n  bool empty() const { return size_ == 0; }\n\n private:\n  size_t\
    \ size_;\n  ukey_t last_;\n  array<vector<pair<ukey_t, val_t>>, numeric_limits<ukey_t>::digits\
    \ + 1>\n      buckets_;\n  array<ukey_t, numeric_limits<ukey_t>::digits + 1> buckets_min_;\n\
    \n  void pull() {\n    assert(size_ > 0);\n    if (!buckets_[0].empty()) return;\n\
    \    size_t i = 1;\n    while (buckets_[i].empty()) ++i;\n    last_ = buckets_min_[i];\n\
    \    for (size_t j = 0; j < buckets_[i].size(); ++j) {\n      const ukey_t x =\
    \ buckets_[i][j].first;\n      const size_t k = internal::find_bucket(x, last_);\n\
    \      buckets_[k].emplace_back(move(buckets_[i][j]));\n      buckets_min_[k]\
    \ = min(buckets_min_[k], x);\n    }\n    buckets_[i].clear();\n    buckets_min_[i]\
    \ = numeric_limits<ukey_t>::max();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/RadixHeap.hpp
  requiredBy: []
  timestamp: '2020-08-11 16:57:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.RadixHeap.test.cpp
documentation_of: src/DataStructure/RadixHeap.hpp
layout: document
redirect_from:
- /library/src/DataStructure/RadixHeap.hpp
- /library/src/DataStructure/RadixHeap.hpp.html
title: Radix-Heap
---