---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\
      \u9593"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/SubproductTree.hpp: line 12: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "/**\n * @title \u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\
    \u88DC\u9593\n * @category \u6570\u5B66\n *  \u3069\u3061\u3089\u3082O(N log^2\
    \ N)\n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"src/Math/ModInt.hpp\"\n#include \"\
    src/Math/FormalPowerSeries.hpp\"\n#undef call_from_test\n#endif\n\ntemplate <typename\
    \ Modint>\nstruct SubproductTree {\n  using FPS = FormalPowerSeries<Modint>;\n\
    \  int n;\n  vector<Modint> xs;\n  vector<FPS> buf;\n  SubproductTree() {}\n \
    \ SubproductTree(const vector<Modint> &_xs)\n      : n(_xs.size()), xs(_xs), buf(4\
    \ * n) {\n    pre(0, n, 1);\n  }\n  void pre(int l, int r, int k) {\n    if (r\
    \ - l == 1) {\n      buf[k] = {-xs[l], 1};\n      return;\n    }\n    int m =\
    \ (l + r) >> 1;\n    pre(l, m, k * 2), pre(m, r, k * 2 + 1);\n    buf[k] = buf[k\
    \ * 2] * buf[k * 2 + 1];\n  }\n  vector<Modint> multi_eval(const FPS &f) {\n \
    \   vector<Modint> res(n);\n    function<void(FPS, int, int, int)> dfs = [&](FPS\
    \ g, int l, int r, int k) {\n      g %= buf[k];\n      if (r - l <= 128) {\n \
    \       for (int i = l; i < r; i++) res[i] = g.eval(xs[i]);\n        return;\n\
    \      }\n      int m = (l + r) >> 1;\n      dfs(g, l, m, k * 2), dfs(g, m, r,\
    \ k * 2 + 1);\n    };\n    dfs(f, 0, n, 1);\n    return res;\n  }\n  FPS interpolate(const\
    \ vector<Modint> &ys) {\n    FPS w = buf[1].diff();\n    vector<Modint> vs = multi_eval(w);\n\
    \    function<FPS(int, int, int)> dfs = [&](int l, int r, int k) {\n      if (r\
    \ - l == 1) return FPS({ys[l] / vs[l]});\n      int m = (l + r) >> 1;\n      return\
    \ buf[k * 2 + 1] * dfs(l, m, k * 2)\n             + buf[k * 2] * dfs(m, r, k *\
    \ 2 + 1);\n    };\n    FPS res = dfs(0, n, 1);\n    res.resize(n);\n    return\
    \ res;\n  }\n};\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/SubproductTree.hpp
  requiredBy: []
  timestamp: '2020-10-20 16:49:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
documentation_of: src/Math/SubproductTree.hpp
layout: document
redirect_from:
- /library/src/Math/SubproductTree.hpp
- /library/src/Math/SubproductTree.hpp.html
title: "\u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\u9593"
---
