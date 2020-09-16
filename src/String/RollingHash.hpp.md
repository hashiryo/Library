---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Rolling-Hash
    links:
    - https://atcoder.jp/contests/arc050/tasks/arc050_d
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "#line 1 \"src/String/RollingHash.hpp\"\n/**\n * @title Rolling-Hash\n\
    \ * @category \u6587\u5B57\u5217\n *  Mod \u306F\u30002^61-1 \u3067\u56FA\u5B9A\
    \n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n */\n\n// lcp\
    \ verify https://atcoder.jp/contests/arc050/tasks/arc050_d\n\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#endif\n\nstruct RollingHash {\n\
    \ private:\n  static constexpr uint64_t mod = (1ull << 61ull) - 1;\n  vector<uint64_t>\
    \ hash, pw;\n  uint64_t base;\n\n private:\n  static inline uint64_t add(uint64_t\
    \ a, uint64_t b) {\n    if ((a += b) >= mod) a -= mod;\n    return a;\n  }\n \
    \ static inline uint64_t mul(uint64_t a, uint64_t b) {\n    __uint128_t c = (__uint128_t)a\
    \ * b;\n    return add(c >> 61, c & mod);\n  }\n\n public:\n  static inline uint64_t\
    \ generate_base() {\n    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);\n    return\
    \ rand(mt);\n  }\n\n  RollingHash() = default;\n  RollingHash(const string& s,\
    \ uint64_t base)\n      : RollingHash(vector<char>(s.begin(), s.end()), base)\
    \ {}\n  template <typename T>\n  RollingHash(const vector<T>& s, uint64_t base)\
    \ : base(base) {\n    hash.assign(s.size() + 1, 0);\n    pw.assign(s.size() +\
    \ 1, 0);\n    pw[0] = 1;\n    for (size_t i = 0; i < s.size(); i++) {\n      pw[i\
    \ + 1] = mul(pw[i], base);\n      hash[i + 1] = add(mul(hash[i], base), s[i]);\n\
    \    }\n  }\n  // S[l, r)\n  uint64_t get_hash(int l, int r) const {\n    return\
    \ add(hash[r], mod - mul(hash[l], pw[r - l]));\n  }\n  uint64_t combine_hash(uint64_t\
    \ hash1, uint64_t hash2, int hash2len) {\n    return add(mul(hash1, pw[hash2len]),\
    \ hash2);\n  }\n};\n\ntemplate <size_t SIZE>\nstruct RollingHash_MultiBase {\n\
    \  using Array = array<uint64_t, SIZE>;\n  array<RollingHash, SIZE> rhs;\n  Array\
    \ bases;\n  RollingHash_MultiBase() = default;\n  RollingHash_MultiBase(const\
    \ string& s, Array bs)\n      : RollingHash_MultiBase(vector<char>(s.begin(),\
    \ s.end()), bs) {}\n  template <typename T>\n  RollingHash_MultiBase(const vector<T>&\
    \ s, Array bs) : bases(bs) {\n    for (size_t i = 0; i < SIZE; i++) rhs[i] = RollingHash(s,\
    \ bases[i]);\n  }\n  Array get_hash(int l, int r) const {\n    Array ret;\n  \
    \  for (size_t i = 0; i < SIZE; i++) ret[i] = rhs[i].get_hash(l, r);\n    return\
    \ ret;\n  }\n  bool equal(int l1, int r1, int l2, int r2) const {\n    return\
    \ equal(*this, *this, l1, r1, l2, r2);\n  }\n  int lcp(int l1, int r1, int l2,\
    \ int r2) const {\n    return lcp(*this, *this, l1, r1, l2, r2);\n  }\n  static\
    \ bool equal(const RollingHash_MultiBase& a,\n                    const RollingHash_MultiBase&\
    \ b, int l1, int r1, int l2,\n                    int r2) {\n    for (size_t i\
    \ = 0; i < SIZE; i++)\n      if (a.rhs[i].get_hash(l1, r1) != b.rhs[i].get_hash(l2,\
    \ r2)) return false;\n    return true;\n  }\n  static int lcp(const RollingHash_MultiBase&\
    \ a, const RollingHash_MultiBase& b,\n                 int l1, int r1, int l2,\
    \ int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low = 0, high = len\
    \ + 1;\n    while (high - low > 1) {\n      int mid = (low + high) / 2;\n    \
    \  if (equal(a, b, l1, l1 + mid, l2, l2 + mid))\n        low = mid;\n      else\n\
    \        high = mid;\n    }\n    return low;\n  }\n};\n"
  code: "/**\n * @title Rolling-Hash\n * @category \u6587\u5B57\u5217\n *  Mod \u306F\
    \u30002^61-1 \u3067\u56FA\u5B9A\n * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n\
    \ */\n\n// lcp verify https://atcoder.jp/contests/arc050/tasks/arc050_d\n\n#ifndef\
    \ call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n#endif\n\nstruct\
    \ RollingHash {\n private:\n  static constexpr uint64_t mod = (1ull << 61ull)\
    \ - 1;\n  vector<uint64_t> hash, pw;\n  uint64_t base;\n\n private:\n  static\
    \ inline uint64_t add(uint64_t a, uint64_t b) {\n    if ((a += b) >= mod) a -=\
    \ mod;\n    return a;\n  }\n  static inline uint64_t mul(uint64_t a, uint64_t\
    \ b) {\n    __uint128_t c = (__uint128_t)a * b;\n    return add(c >> 61, c & mod);\n\
    \  }\n\n public:\n  static inline uint64_t generate_base() {\n    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);\n    return\
    \ rand(mt);\n  }\n\n  RollingHash() = default;\n  RollingHash(const string& s,\
    \ uint64_t base)\n      : RollingHash(vector<char>(s.begin(), s.end()), base)\
    \ {}\n  template <typename T>\n  RollingHash(const vector<T>& s, uint64_t base)\
    \ : base(base) {\n    hash.assign(s.size() + 1, 0);\n    pw.assign(s.size() +\
    \ 1, 0);\n    pw[0] = 1;\n    for (size_t i = 0; i < s.size(); i++) {\n      pw[i\
    \ + 1] = mul(pw[i], base);\n      hash[i + 1] = add(mul(hash[i], base), s[i]);\n\
    \    }\n  }\n  // S[l, r)\n  uint64_t get_hash(int l, int r) const {\n    return\
    \ add(hash[r], mod - mul(hash[l], pw[r - l]));\n  }\n  uint64_t combine_hash(uint64_t\
    \ hash1, uint64_t hash2, int hash2len) {\n    return add(mul(hash1, pw[hash2len]),\
    \ hash2);\n  }\n};\n\ntemplate <size_t SIZE>\nstruct RollingHash_MultiBase {\n\
    \  using Array = array<uint64_t, SIZE>;\n  array<RollingHash, SIZE> rhs;\n  Array\
    \ bases;\n  RollingHash_MultiBase() = default;\n  RollingHash_MultiBase(const\
    \ string& s, Array bs)\n      : RollingHash_MultiBase(vector<char>(s.begin(),\
    \ s.end()), bs) {}\n  template <typename T>\n  RollingHash_MultiBase(const vector<T>&\
    \ s, Array bs) : bases(bs) {\n    for (size_t i = 0; i < SIZE; i++) rhs[i] = RollingHash(s,\
    \ bases[i]);\n  }\n  Array get_hash(int l, int r) const {\n    Array ret;\n  \
    \  for (size_t i = 0; i < SIZE; i++) ret[i] = rhs[i].get_hash(l, r);\n    return\
    \ ret;\n  }\n  bool equal(int l1, int r1, int l2, int r2) const {\n    return\
    \ equal(*this, *this, l1, r1, l2, r2);\n  }\n  int lcp(int l1, int r1, int l2,\
    \ int r2) const {\n    return lcp(*this, *this, l1, r1, l2, r2);\n  }\n  static\
    \ bool equal(const RollingHash_MultiBase& a,\n                    const RollingHash_MultiBase&\
    \ b, int l1, int r1, int l2,\n                    int r2) {\n    for (size_t i\
    \ = 0; i < SIZE; i++)\n      if (a.rhs[i].get_hash(l1, r1) != b.rhs[i].get_hash(l2,\
    \ r2)) return false;\n    return true;\n  }\n  static int lcp(const RollingHash_MultiBase&\
    \ a, const RollingHash_MultiBase& b,\n                 int l1, int r1, int l2,\
    \ int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low = 0, high = len\
    \ + 1;\n    while (high - low > 1) {\n      int mid = (low + high) / 2;\n    \
    \  if (equal(a, b, l1, l1 + mid, l2, l2 + mid))\n        low = mid;\n      else\n\
    \        high = mid;\n    }\n    return low;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2020-09-14 13:17:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
documentation_of: src/String/RollingHash.hpp
layout: document
redirect_from:
- /library/src/String/RollingHash.hpp
- /library/src/String/RollingHash.hpp.html
title: Rolling-Hash
---
