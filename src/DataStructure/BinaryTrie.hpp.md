---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.BinaryTrie.test.cpp
    title: test/yukicoder/649.BinaryTrie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E8C\u5206Trie"
    links:
    - https://codeforces.com/contest/947/problem/C
    - https://codeforces.com/contest/966/problem/C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/BinaryTrie.hpp: line 16: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u4E8C\u5206Trie\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n *  O(logN)\n *  multiset\u7684\u306A\u4ED5\u69D8(\u5185\u90E8\u306F\u52D5\u7684\
    \u30BB\u30B0\u6728)\n */\n// verify\u7528:\n// https://codeforces.com/contest/947/problem/C\n\
    // https://codeforces.com/contest/966/problem/C\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    src/DataStructure/SegmentTree_Dynamic.hpp\"\n#undef call_from_test\n#endif\n\n\
    struct RsumQ {\n  using T = int;\n  static T ti() { return 0; }\n  static T f(const\
    \ T &vl, const T &vr) { return vl + vr; }\n};\nstruct BinaryTrie : public SegmentTree_Dynamic<RsumQ>\
    \ {\n  using ll = long long;\n  using U = unsigned long long;\n  BinaryTrie(ll\
    \ max_val = INT_MAX) : SegmentTree_Dynamic<RsumQ>(max_val) {}\n  void insert(U\
    \ val) { set_val(val, (*this)[val] + 1); }\n  void erase(U val) { set_val(val,\
    \ (*this)[val] - 1); }\n  ll kth_element(int k, U bias = 0) {\n    auto check\
    \ = [&](int x) { return x > k; };\n    return find_first(check, bias);\n  }\n\
    \  ll min_element(U bias = 0) { return kth_element(0, bias); }\n  ll max_element(U\
    \ bias = 0) { return kth_element(0, ~bias); }\n  int lower_bound(U val) { return\
    \ query(0, val); }\n  int upper_bound(U val) { return query(0, val + 1); }\n \
    \ int count(U val) { return query(val, val + 1); }\n  int size() { return root\
    \ ? root->dat : 0; }\n};"
  dependsOn:
  - src/DataStructure/SegmentTree_Dynamic.hpp
  isVerificationFile: false
  path: src/DataStructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2020-08-27 16:28:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/649.BinaryTrie.test.cpp
  - test/yosupo/set_xor_min.test.cpp
documentation_of: src/DataStructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/src/DataStructure/BinaryTrie.hpp
- /library/src/DataStructure/BinaryTrie.hpp.html
title: "\u4E8C\u5206Trie"
---
