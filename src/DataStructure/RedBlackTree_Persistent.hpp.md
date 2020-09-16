---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/RedBlackTree.hpp
    title: "\u8D64\u9ED2\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.RBTP.test.cpp
    title: test/yosupo/persistent_queue.RBTP.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A)"
    links:
    - https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/RedBlackTree_Persistent.hpp: line 14: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u8D64\u9ED2\u6728(\u6C38\u7D9A)\n * @category \u30C7\u30FC\
    \u30BF\u69CB\u9020\n * O(logN)\n */\n// verify\u7528:\n// https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ call_from_test\n#include \"src/DataStructure/RedBlackTree.hpp\"\n#undef call_from_test\n\
    #endif\n\ntemplate <typename M, size_t LIM = 1 << 22, size_t FULL = 1000>\nstruct\
    \ RedBlackTree_Persistent : RedBlackTree<M, LIM> {\n  using RBT = RedBlackTree<M,\
    \ LIM>;\n  using RBT::RedBlackTree;\n  using Node = typename RBT::Node;\n  using\
    \ RBTP = RedBlackTree_Persistent;\n\n private:\n  Node *clone(Node *t) override\
    \ { return &(*RBT::pool.alloc() = *t); }\n\n public:\n  // merge\n  RBTP operator+(const\
    \ RBTP &r) {\n    if (!this->root || !r.root) return this->root ? *this : r;\n\
    \    Node *c = RBT::submerge(this->root, r.root);\n    c->color = RBT::BLACK;\n\
    \    return RBTP(c);\n  }\n  // [0,k) [k,size)\n  pair<RBTP, RBTP> split(int k)\
    \ {\n    auto tmp = RBT::split(this->root, k);\n    return make_pair(RBTP(tmp.first),\
    \ RBTP(tmp.second));\n  }\n  // [0,a) [a,b) [b,size)\n  tuple<RBTP, RBTP, RBTP>\
    \ split3(int a, int b) {\n    auto x = RBT::split(this->root, a);\n    auto y\
    \ = RBT::split(x.second, b - a);\n    return make_tuple(RBTP(x.first), RBTP(y.first),\
    \ RBTP(y.second));\n  }\n  void rebuild() {\n    auto ret = RBT::dump();\n   \
    \ RBT::pool.clear();\n    RBT::build(ret);\n  }\n  static bool almost_full() {\
    \ return RBT::pool.ptr < FULL; }\n};\n"
  dependsOn:
  - src/DataStructure/RedBlackTree.hpp
  isVerificationFile: false
  path: src/DataStructure/RedBlackTree_Persistent.hpp
  requiredBy: []
  timestamp: '2020-08-13 01:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.RBTP.test.cpp
documentation_of: src/DataStructure/RedBlackTree_Persistent.hpp
layout: document
redirect_from:
- /library/src/DataStructure/RedBlackTree_Persistent.hpp
- /library/src/DataStructure/RedBlackTree_Persistent.hpp.html
title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A)"
---
