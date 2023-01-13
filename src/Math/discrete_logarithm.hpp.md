---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Math/ModIntPrototype.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/mod_inv.hpp\"\
    \n#include \"src/Math/ModIntPrototype.hpp\"\nint discrete_logarithm(int a, int\
    \ b, int mod) {\n if (a == 0) return b == 0 ? (mod == 1 ? 0 : 1) : (b == 1 ? 0\
    \ : -1);\n using namespace math_internal;\n int cnt= 0;\n for (int g= 0;; ++cnt,\
    \ b/= g, mod/= g, b= u64(b) * mod_inv<int>(a / g, mod) % mod) {\n  if ((b == 1)\
    \ || (mod == 1)) return cnt;\n  if ((g= gcd(a, mod)) == 1) break;\n  if (b % g\
    \ != 0) return -1;  // no solution\n }\n auto mul= [md= MP_Br(mod)](int &x, int\
    \ y) { x= md.mul(x, y); };\n int baby= 1, size= 1 << __lg(int(sqrt(mod)) + 1),\
    \ mask= size - 1, vs[size][2];\n vector<int> os(size + 1);\n for (int i= 0; i\
    \ < size; ++i, mul(baby, a)) ++os[baby & mask];\n for (int i= 1; i < size; ++i)\
    \ os[i]+= os[i - 1];\n os[size]= size, baby= 1;\n for (int i= 0, j= 0; i < size;\
    \ ++i, mul(baby, a)) j= --os[baby & mask], vs[j][0]= baby, vs[j][1]= i;\n for\
    \ (int t= 0, iv= mod_inv<int>(baby, mod); t < mod; t+= size, mul(b, iv))\n  for\
    \ (int m= (b & mask), i= os[m + 1]; i-- > os[m];)\n   if (b == vs[i][0]) return\
    \ cnt + vs[i][1] + t;\n return -1;  // no solution\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/discrete_logarithm.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/discrete_logarithm.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570 ($\\mathbb{Z}/m\\mathbb{Z}$)"
---
## 計算量
$\mathcal{O} (\sqrt{m})$