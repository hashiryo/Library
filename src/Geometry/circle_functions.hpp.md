---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/!geometry_temp.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1132.test.cpp
    title: test/aoj/1132.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2201.test.cpp
    title: test/aoj/2201.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2514.test.cpp
    title: test/aoj/2514.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034.test.cpp
    title: test/aoj/3034.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5186\u306E\u3042\u308C\u3053\u308C"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Geometry/circle_functions.hpp: line 11: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @title \u5186\u306E\u3042\u308C\u3053\u308C\n * @category \u5E7E\u4F55\
    \n */\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define call_from_test\n#include \"src/Geometry/!geometry_temp.hpp\"\n#undef\
    \ call_from_test\n#endif\n\nnamespace geometry {\n\nCircle inscribed_circle(Point\
    \ A, Point B, Point C) {\n  Real a = dist(B, C), b = dist(C, A), c = dist(A, B);\n\
    \  Real s = (a + b + c) / 2;\n  Point o = (a * A + b * B + c * C) / (a + b + c);\n\
    \  Real r = sqrt((s - a) * (s - b) * (s - c) / s);\n  return {o, r};\n}\n\nCircle\
    \ circumscribed_circle(Point A, Point B, Point C) {\n  Point u = orth(B - A),\
    \ v = C - A;\n  Point o = (A + B + u * dot(C - B, v) / dot(u, v)) / 2;\n  return\
    \ {o, dist(A, o)};\n}\n\nvector<Line> common_tangent(Circle c, Circle d) {\n \
    \ Real len = dist(c.o, d.o);\n  if (sgn(len) == 0) return {};  // same origin\n\
    \  Point u = (d.o - c.o) / len, v = orth(u);\n  vector<Line> ls;\n  for (int s\
    \ = +1; s >= -1; s -= 2) {\n    Real h = (c.r + s * d.r) / len;\n    if (sgn(1\
    \ - h * h) == 0) {  // touch inner/outer\n      ls.emplace_back(Line{c.o + h *\
    \ c.r * u, c.o + h * c.r * (u + v)});\n    } else if (sgn(1 - h * h) > 0) {  //\
    \ properly intersect\n      Point uu = h * u, vv = sqrt(1 - h * h) * v;\n    \
    \  ls.emplace_back(Line{c.o + c.r * (uu + vv), d.o - d.r * (uu + vv) * s});\n\
    \      ls.emplace_back(Line{c.o + c.r * (uu - vv), d.o - d.r * (uu - vv) * s});\n\
    \    }\n  }\n  return ls;\n}\n\nReal intersection_area(Circle c, Circle d) {\n\
    \  if (c.r < d.r) swap(c, d);\n  auto A = [&](Real r, Real h) {\n    return r\
    \ * r * acos(h / r) - h * sqrt(r * r - h * h);\n  };\n  Real l = dist(c.o, d.o);\n\
    \  Real a = (l * l + c.r * c.r - d.r * d.r) / (2 * l);\n  if (sgn(l - c.r - d.r)\
    \ >= 0) return 0;  // far away\n  if (sgn(l - c.r + d.r) <= 0) return PI * d.r\
    \ * d.r;\n  if (sgn(l - c.r) >= 0)\n    return A(c.r, a) + A(d.r, l - a);\n  else\n\
    \    return A(c.r, a) + PI * d.r * d.r - A(d.r, a - l);\n}\n\nReal intersection_area(Polygon\
    \ g, Circle c) {\n  auto tri = [&](Point p, Point q) {\n    Point d = q - p;\n\
    \    Real a = dot(d, p) / dot(d, d), b = (dot(p, p) - c.r * c.r) / dot(d, d);\n\
    \    Real det = a * a - b;\n    if (det <= 0) return arg(p, q) * c.r * c.r / 2;\n\
    \    Real s = max((Real)0., -a - sqrt(det)), t = min((Real)1., -a + sqrt(det));\n\
    \    if (t < 0 || 1 <= s) return c.r * c.r * arg(p, q) / 2;\n    Point u = p +\
    \ s * d, v = p + t * d;\n    return arg(p, u) * c.r * c.r / 2 + cross(u, v) /\
    \ 2\n           + arg(v, q) * c.r * c.r / 2;\n  };\n  Real sum = 0.0;\n  for (int\
    \ i = 0; i < (int)g.size(); ++i)\n    sum += tri(g[i] - c.o, g[g.next(i)] - c.o);\n\
    \  return sum;\n}\nReal intersection_area(Circle c, Polygon g) { return intersection_area(g,\
    \ c); }\n\nCircle min_enclosing_circle(vector<Point> ps) {\n  assert(ps.size());\n\
    \  if (ps.size() == 1) return {ps[0], 0.};\n  random_device seed_gen;\n  mt19937\
    \ mt(seed_gen());\n  shuffle(ps.begin(), ps.end(), mt);\n  Circle c = {(ps[0]\
    \ + ps[1]) / 2, dist(ps[0], ps[1]) / 2};\n  for (int i = 2; i < ps.size(); i++)\n\
    \    if (c.where(ps[i]) == OUT) {\n      c = {(ps[0] + ps[i]) / 2, dist(ps[0],\
    \ ps[i]) / 2};\n      for (int j = 1; j < i; j++)\n        if (c.where(ps[j])\
    \ == OUT) {\n          c = {(ps[i] + ps[j]) / 2, dist(ps[i], ps[j]) / 2};\n  \
    \        for (int k = 0; k < j; k++)\n            if (c.where(ps[k]) == OUT)\n\
    \              c = circumscribed_circle(ps[i], ps[j], ps[k]);\n        }\n   \
    \ }\n  return c;\n}\n\npair<int, Point> max_circle_cover(vector<Point> ps, Real\
    \ r) {\n  const Real dx[4] = {1, -1, -1, 1}, dy[4] = {1, 1, -1, -1};\n  Point\
    \ best_p;\n  int best = 0;\n  function<void(Point, Real, vector<Point>)> rec\n\
    \      = [&](Point p, Real w, vector<Point> ps) {\n          w /= 2;\n       \
    \   Point qs[4];\n          vector<Point> pss[4];\n          for (int i = 0; i\
    \ < 4; ++i) {\n            qs[i] = p + w * Point({dx[i], dy[i]});\n          \
    \  int lo = 0;\n            for (Point q : ps) {\n              Real d = dist(qs[i],\
    \ q);\n              if (sgn(d - r) <= 0) ++lo;\n              if (sgn(d - w *\
    \ sqrt(2) - r) <= 0) pss[i].push_back(q);\n            }\n            if (lo >\
    \ best) {\n              best = lo;\n              best_p = qs[i];\n         \
    \   }\n          }\n          for (int i = 0; i < 4; ++i) {\n            for (int\
    \ j = i + 1; j < 4; ++j)\n              if (pss[i].size() < pss[j].size())\n \
    \               swap(pss[i], pss[j]), swap(qs[i], qs[j]);\n            if (pss[i].size()\
    \ <= best) break;\n            rec(qs[i], w, pss[i]);\n          }\n        };\n\
    \  Real w = 0;\n  for (Point p : ps) w = max({w, abs(p.x), abs(p.y)});\n  rec({0,\
    \ 0}, w, ps);\n  return {best, best_p};\n}\n\n}  // namespace geometry\n"
  dependsOn:
  - src/Geometry/!geometry_temp.hpp
  isVerificationFile: false
  path: src/Geometry/circle_functions.hpp
  requiredBy: []
  timestamp: '2020-09-06 22:06:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/3034.test.cpp
  - test/aoj/1132.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/2201.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/2514.test.cpp
documentation_of: src/Geometry/circle_functions.hpp
layout: document
redirect_from:
- /library/src/Geometry/circle_functions.hpp
- /library/src/Geometry/circle_functions.hpp.html
title: "\u5186\u306E\u3042\u308C\u3053\u308C"
---
