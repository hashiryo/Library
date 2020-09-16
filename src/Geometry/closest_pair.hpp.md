---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/!geometry_temp.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u8FD1\u70B9\u5BFE"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Geometry/closest_pair.hpp: line 11: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u6700\u8FD1\u70B9\u5BFE\n * @category \u5E7E\u4F55\n */\n\
    \n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ call_from_test\n#include \"src/Geometry/!geometry_temp.hpp\"\n#undef call_from_test\n\
    #endif\n\nnamespace geometry {\n\npair<Point, Point> closest_pair(vector<Point>\
    \ ps) {\n  sort(ps.begin(), ps.end(), [](Point p, Point q) { return p.y < q.y;\
    \ });\n  Point u = ps[0], v = ps[1];\n  Real best = norm2(u - v);\n  auto update\
    \ = [&](Point p, Point q) {\n    Real dis = norm2(p - q);\n    if (best > dis)\
    \ best = dis, u = p, v = q;\n  };\n  function<void(int, int)> rec = [&](int l,\
    \ int r) {\n    if (r - l <= 1) {\n      for (int i = l; i < r; ++i)\n       \
    \ for (int j = i + 1; j < r; ++j) update(ps[i], ps[j]);\n      stable_sort(&ps[l],\
    \ &ps[r]);\n    } else {\n      int m = (l + r) / 2;\n      Real y = ps[m].y;\n\
    \      rec(l, m);\n      rec(m, r);\n      inplace_merge(&ps[l], &ps[m], &ps[r]);\n\
    \      vector<Point> qs;\n      for (int i = l; i < r; ++i) {\n        if ((ps[i].y\
    \ - y) * (ps[i].y - y) >= best) continue;\n        for (int j = (int)qs.size()\
    \ - 1; j >= 0; --j) {\n          if ((qs[j].x - ps[i].x) * (qs[j].x - ps[i].x)\
    \ >= best) break;\n          update(qs[j], ps[i]);\n        }\n        qs.push_back(ps[i]);\n\
    \      }\n    }\n  };\n  rec(0, ps.size());\n  return {u, v};\n}\n\npair<Point,\
    \ Point> farthest_pair(vector<Point> ps) {\n  return convex_hull(ps).farthest();\n\
    }\n\n}  // namespace geometry"
  dependsOn:
  - src/Geometry/!geometry_temp.hpp
  isVerificationFile: false
  path: src/Geometry/closest_pair.hpp
  requiredBy: []
  timestamp: '2020-09-06 22:06:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
documentation_of: src/Geometry/closest_pair.hpp
layout: document
redirect_from:
- /library/src/Geometry/closest_pair.hpp
- /library/src/Geometry/closest_pair.hpp.html
title: "\u6700\u8FD1\u70B9\u5BFE"
---
