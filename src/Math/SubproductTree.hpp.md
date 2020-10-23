---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\
      \u9593"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/Modint.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/Modint.hpp\"\n\
    #include \"src/Math/FormalPowerSeries.hpp\"\n/**\n * @title \u8907\u6570\u306E\
    \u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\u9593\n * @category \u6570\u5B66\
    \n *  \u3069\u3061\u3089\u3082O(N log^2 N)\n */\n\n// BEGIN CUT HERE\n\ntemplate\
    \ <typename mint>\nstruct SubproductTree {\n  using poly = FormalPowerSeries<mint>;\n\
    \  int n;\n  std::vector<mint> xs;\n  std::vector<poly> buf;\n  SubproductTree()\
    \ {}\n  SubproductTree(const std::vector<mint> &_xs)\n      : n(_xs.size()), xs(_xs),\
    \ buf(4 * n) {\n    pre(0, n, 1);\n  }\n  void pre(int l, int r, int k) {\n  \
    \  if (r - l == 1) {\n      buf[k] = {-xs[l], 1};\n      return;\n    }\n    int\
    \ m = (l + r) >> 1;\n    pre(l, m, k * 2), pre(m, r, k * 2 + 1);\n    buf[k] =\
    \ buf[k * 2] * buf[k * 2 + 1];\n  }\n  std::vector<mint> multi_eval(const poly\
    \ &f) {\n    std::vector<mint> res(n);\n    std::function<void(poly, int, int,\
    \ int)> dfs\n        = [&](poly g, int l, int r, int k) {\n            g %= buf[k];\n\
    \            if (r - l <= 128) {\n              for (int i = l; i < r; i++) res[i]\
    \ = g.eval(xs[i]);\n              return;\n            }\n            int m =\
    \ (l + r) >> 1;\n            dfs(g, l, m, k * 2), dfs(g, m, r, k * 2 + 1);\n \
    \         };\n    dfs(f, 0, n, 1);\n    return res;\n  }\n  poly interpolate(const\
    \ std::vector<mint> &ys) {\n    poly w = buf[1].diff();\n    std::vector<mint>\
    \ vs = multi_eval(w);\n    std::function<poly(int, int, int)> dfs = [&](int l,\
    \ int r, int k) {\n      if (r - l == 1) return poly({ys[l] / vs[l]});\n     \
    \ int m = (l + r) >> 1;\n      return buf[k * 2 + 1] * dfs(l, m, k * 2)\n    \
    \         + buf[k * 2] * dfs(m, r, k * 2 + 1);\n    };\n    poly res = dfs(0,\
    \ n, 1);\n    res.resize(n);\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/SubproductTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/SubproductTree.hpp
layout: document
redirect_from:
- /library/src/Math/SubproductTree.hpp
- /library/src/Math/SubproductTree.hpp.html
title: "\u8907\u6570\u306E\u5024\u4EE3\u5165\u3068\u591A\u9805\u5F0F\u88DC\u9593"
---
