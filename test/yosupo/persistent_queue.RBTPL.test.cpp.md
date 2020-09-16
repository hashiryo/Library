---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/RedBlackTree_Lazy.hpp
    title: "\u8D64\u9ED2\u6728(\u9045\u5EF6\u4F1D\u642C)"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/RedBlackTree_PersistentLazy.hpp
    title: "\u8D64\u9ED2\u6728(\u6C38\u7D9A\u9045\u5EF6\u4F1D\u642C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/DataStructure/RedBlackTree_PersistentLazy.hpp: line 13: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    // \u6C38\u7D9A\u6027\u306Everify\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"src/DataStructure/RedBlackTree_Lazy.hpp\"\
    \n#include \"src/DataStructure/RedBlackTree_PersistentLazy.hpp\"\n#undef call_from_test\n\
    \nstruct Monoid {\n  using T = int;\n  using E = int;\n  static T ti() { return\
    \ 0; }\n  static T f(const T &l, const T &r) { return l; }\n  static E ei() {\
    \ return 0; }\n  static T g(const T &l, const E &r) { return l; }\n  static E\
    \ h(const E &l, const E &r) { return l; }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  using RBTPL = RedBlackTree_PersistentLazy<Monoid,\
    \ 1 << 25>;\n  int Q;\n  cin >> Q;\n  vector<RBTPL> S(Q + 1);\n  for (int i =\
    \ 1; i <= Q; i++) {\n    int op, t;\n    cin >> op >> t;\n    S[i] = S[++t];\n\
    \    if (op) {\n      cout << S[i].pop_front() << endl;\n    } else {\n      int\
    \ x;\n      cin >> x;\n      S[i].push_back(x);\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/RedBlackTree_Lazy.hpp
  - src/DataStructure/RedBlackTree_PersistentLazy.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_queue.RBTPL.test.cpp
  requiredBy: []
  timestamp: '2020-08-13 01:05:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_queue.RBTPL.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_queue.RBTPL.test.cpp
- /verify/test/yosupo/persistent_queue.RBTPL.test.cpp.html
title: test/yosupo/persistent_queue.RBTPL.test.cpp
---
