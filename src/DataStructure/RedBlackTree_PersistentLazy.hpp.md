---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/RedBlackTree_Lazy.hpp
    title: "\u8D64\u9ED2\u6728(\u9045\u5EF6\u4F1D\u642C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.RBTPL.test.cpp
    title: test/yosupo/persistent_queue.RBTPL.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C)"
    links:
    - https://atcoder.jp/contests/arc030/tasks/arc030_4
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/RedBlackTree_PersistentLazy.hpp: line 13: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u8D64\u9ED2\u6728(\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C)\n\
    \ * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief O(logN)\n */\n\n// verify\u7528\
    : https://atcoder.jp/contests/arc030/tasks/arc030_4\n#ifndef call_from_test\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"src/DataStructure/RedBlackTree_Lazy.hpp\"\n#undef call_from_test\n#endif\n\
    \ntemplate <typename M, size_t LIM = 1 << 22, size_t FULL = 1000>\nstruct RedBlackTree_PersistentLazy\
    \ : RedBlackTree_Lazy<M, LIM> {\n  using RBTL = RedBlackTree_Lazy<M, LIM>;\n \
    \ using RBTL::RedBlackTree_Lazy;\n  using Node = typename RBTL::Node;\n  using\
    \ RBTPL = RedBlackTree_PersistentLazy;\n\n private:\n  Node *clone(Node *t) override\
    \ { return &(*RBTL::pool.alloc() = *t); }\n\n public:\n  // merge\n  RBTPL operator+(const\
    \ RBTPL &r) {\n    if (!this->root || !r.root) return this->root ? *this : r;\n\
    \    Node *c = RBTL::submerge(this->root, r.root);\n    c->color = RBTL::BLACK;\n\
    \    return RBTPL(c);\n  }\n  // [0,k) [k,size)\n  pair<RBTPL, RBTPL> split(int\
    \ k) {\n    auto tmp = RBTL::split(this->root, k);\n    return make_pair(RBTPL(tmp.first),\
    \ RBTPL(tmp.second));\n  }\n  // [0,a) [a,b) [b,size)\n  tuple<RBTPL, RBTPL, RBTPL>\
    \ split3(int a, int b) {\n    auto x = RBTL::split(this->root, a);\n    auto y\
    \ = RBTL::split(x.second, b - a);\n    return make_tuple(RBTPL(x.first), RBTPL(y.first),\
    \ RBTPL(y.second));\n  }\n  void rebuild() {\n    auto ret = RBTL::dump();\n \
    \   RBTL::pool.clear();\n    RBTL::build(ret);\n  }\n  static bool almost_full()\
    \ { return RBTL::pool.ptr < FULL; }\n};\n"
  dependsOn:
  - src/DataStructure/RedBlackTree_Lazy.hpp
  isVerificationFile: false
  path: src/DataStructure/RedBlackTree_PersistentLazy.hpp
  requiredBy: []
  timestamp: '2020-08-13 01:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.RBTPL.test.cpp
documentation_of: src/DataStructure/RedBlackTree_PersistentLazy.hpp
layout: document
redirect_from:
- /library/src/DataStructure/RedBlackTree_PersistentLazy.hpp
- /library/src/DataStructure/RedBlackTree_PersistentLazy.hpp.html
title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C)"
---
