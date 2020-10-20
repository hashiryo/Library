---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/!geometry_temp.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/circle_functions.hpp
    title: "\u5186\u306E\u3042\u308C\u3053\u308C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Geometry/circle_functions.hpp: line 11: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C\"\
    \n\n#define ERROR \"0.00000001\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"src/Geometry/!geometry_temp.hpp\"\
    \n#include \"src/Geometry/circle_functions.hpp\"\n#undef call_from_test\n\nsigned\
    \ main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  using namespace geometry;\n\
    \  Point A, B, C;\n  cin >> A >> B >> C;\n  Circle c = circumscribed_circle(A,\
    \ B, C);\n  cout << fixed << setprecision(12) << c.o << \" \" << c.r << endl;\n\
    \  return 0;\n}"
  dependsOn:
  - src/Geometry/!geometry_temp.hpp
  - src/Geometry/circle_functions.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-06 22:06:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_C.test.cpp
- /verify/test/aoj/CGL_7_C.test.cpp.html
title: test/aoj/CGL_7_C.test.cpp
---
