---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/!geometry_temp.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/argsort.test.cpp
    title: test/yosupo/argsort.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u504F\u89D2\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Geometry/arg_sort.hpp: line 11: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "/**\n * @title \u504F\u89D2\u30BD\u30FC\u30C8\n * @category \u5E7E\u4F55\n\
    \ */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"src/Geometry/!geometry_temp.hpp\"\n#undef\
    \ call_from_test\n#endif\n\nnamespace geometry {\n// usage: sort(ps.begin(),ps.end(),\
    \ polar_angle(origin, direction));\n// (-PI,PI]\nstruct polar_angle {\n  const\
    \ Point o;\n  const int s;  // +1 for ccw, -1 for cw\n  polar_angle(Point origin\
    \ = {0, 0}, int dir = +1) : o(origin), s(dir) {}\n  int quad(Point p) const {\n\
    \    for (int i = 0; i < 4; ++i, swap(p.x = -p.x, p.y))\n      if (p.x < 0 &&\
    \ p.y < 0) return 2 * i;\n    for (int i = 0; i < 4; ++i, swap(p.x = -p.x, p.y))\n\
    \      if (p.x == 0 && p.y < 0) return 2 * i + 1;\n    return 3;  // arg(0,0)\
    \ = 0\n  }\n  bool operator()(Point p, Point q) const {\n    p = p - o;\n    q\
    \ = q - o;\n    if (quad(p) != quad(q)) return s * quad(p) < s * quad(q);\n  \
    \  if (cross(p, q)) return s * cross(p, q) > 0;\n    return norm2(p) < norm2(q);\
    \  // closer first\n  }\n};\n}  // namespace geometry"
  dependsOn:
  - src/Geometry/!geometry_temp.hpp
  isVerificationFile: false
  path: src/Geometry/arg_sort.hpp
  requiredBy: []
  timestamp: '2020-09-06 22:06:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/argsort.test.cpp
documentation_of: src/Geometry/arg_sort.hpp
layout: document
redirect_from:
- /library/src/Geometry/arg_sort.hpp
- /library/src/Geometry/arg_sort.hpp.html
title: "\u504F\u89D2\u30BD\u30FC\u30C8"
---
