---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/FormalPowerSeries.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_Poly.test.cpp
    title: test/yosupo/inv_of_Poly.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
    links:
    - https://loj.ac/article/2773
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/exgcd.hpp: line 13: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "/**\n * @title \u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5\n *\
    \ @category \u6570\u5B66\n *  O(Nlog^2N)\n * @see https://loj.ac/article/2773\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/FormalPowerSeries.hpp\"\
    \n#undef call_from_test\n#endif\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ exgcd(\n    FormalPowerSeries<mint> a, FormalPowerSeries<mint> b,\n    FormalPowerSeries<mint>\
    \ &x,\n    FormalPowerSeries<mint> &y) {  // ax + by = gcd(a, b)\n  using poly\
    \ = FormalPowerSeries<mint>;\n  using pv = array<poly, 2>;\n  using pm = array<pv,\
    \ 2>;\n  assert(a.deg() >= 0);\n  assert(b.deg() >= 0);\n  auto isI = [](const\
    \ pm &m) {\n    static constexpr mint ONE(1);\n    return m[0][1].deg() == -1\
    \ && m[1][0].deg() == -1 && m[0][0].deg() == 0\n           && m[0][0][0] == ONE\
    \ && m[1][1].deg() == 0 && m[1][1][0] == ONE;\n  };\n  auto mulv = [&](const pm\
    \ &lhs, const pv &rhs) {\n    if (isI(lhs)) return rhs;\n    return pv{lhs[0][0]\
    \ * rhs[0] + lhs[0][1] * rhs[1],\n              lhs[1][0] * rhs[0] + lhs[1][1]\
    \ * rhs[1]};\n  };\n  auto mul = [&](const pm &lhs, const pm &rhs) {\n    if (isI(lhs))\
    \ return rhs;\n    if (isI(rhs)) return lhs;\n    return pm{pv{lhs[0][0] * rhs[0][0]\
    \ + lhs[0][1] * rhs[1][0],\n                 lhs[0][0] * rhs[0][1] + lhs[0][1]\
    \ * rhs[1][1]},\n              pv{lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0],\n\
    \                 lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]}};\n  };\n  auto\
    \ mulQ_l = [&](const poly &q, const pm &rhs) {\n    return pm{pv{rhs[1][0], rhs[1][1]},\n\
    \              pv{rhs[0][0] - q * rhs[1][0], rhs[0][1] - q * rhs[1][1]}};\n  };\n\
    \  auto mulQ_r = [&](const pm &lhs, const poly &q) {\n    return pm{pv{lhs[0][1],\
    \ lhs[0][0] - lhs[0][1] * q},\n              pv{lhs[1][1], lhs[1][0] - lhs[1][1]\
    \ * q}};\n  };\n  function<pm(poly, poly)> hgcd = [&](const poly &p0, const poly\
    \ &p1) {\n    assert(p0.deg() > p1.deg());\n    int m = ((p0.deg() - 1) >> 1)\
    \ + 1, n = p1.deg();\n    if (n < m) return pm{pv{poly{1}, poly{}}, pv{poly{},\
    \ poly{1}}};\n    pm R(hgcd(poly(p0.begin() + m, p0.end()), poly(p1.begin() +\
    \ m, p1.end())));\n    pv ab(mulv(R, pv{p0, p1}));\n    if (ab[1].deg() < m) return\
    \ R;\n    pair<poly, poly> qr(ab[0].quorem(ab[1]));\n    int k = 2 * m - ab[1].deg();\n\
    \    if ((int)qr.second.size() <= k) return mulQ_l(qr.first, R);\n    return mul(hgcd(poly(ab[1].begin()\
    \ + k, ab[1].end()),\n                    poly(qr.second.begin() + k, qr.second.end())),\n\
    \               mulQ_l(qr.first, R));\n  };\n  function<pm(poly, poly)> cogcd\
    \ = [&](const poly &p0, const poly &p1) {\n    assert(p0.deg() > p1.deg());\n\
    \    pm M(hgcd(p0, p1));\n    pv p2p3(mulv(M, pv{p0, p1}));\n    if (p2p3[1].deg()\
    \ == -1) return M;\n    pair<poly, poly> qr(p2p3[0].quorem(p2p3[1]));\n    if\
    \ (qr.second.deg() == -1) return mulQ_l(qr.first, M);\n    return mul(cogcd(p2p3[1],\
    \ qr.second), mulQ_l(qr.first, M));\n  };\n  pm c;\n  if (a.norm().deg() > b.norm().deg())\
    \ {\n    c = cogcd(a, b);\n  } else {\n    pair<poly, poly> qr(a.quorem(b));\n\
    \    c = mulQ_r(cogcd(b, qr.second), qr.first);\n  }\n  return a * (x = c[0][0])\
    \ + b * (y = c[0][1]);\n}\n"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/Math/exgcd.hpp
  requiredBy: []
  timestamp: '2020-10-21 15:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/inv_of_Poly.test.cpp
documentation_of: src/Math/exgcd.hpp
layout: document
redirect_from:
- /library/src/Math/exgcd.hpp
- /library/src/Math/exgcd.hpp.html
title: "\u591A\u9805\u5F0F\u306E\u62E1\u5F35\u4E92\u9664\u6CD5"
---
