---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/enumerate_quotients.hpp
    title: "$\\lfloor N/i \\rfloor$ \u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/atcoder/abc172_d.enum_quo.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n// O(\u221AN)\n#include\
    \ <iostream>\n#line 2 \"src/Math/enumerate_quotients.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <tuple>\n#include <cmath>\n// (q,l,r) : i in (l,r],\
    \ \u230AN/i\u230B = q\nstd::vector<std::tuple<uint64_t, uint64_t, uint64_t>> enumerate_quotients(uint64_t\
    \ N) {\n uint64_t sq= std::sqrt(N), prev= N, x;\n std::vector<std::tuple<uint64_t,\
    \ uint64_t, uint64_t>> ret;\n for (int q= 1, n= (sq * sq + sq <= N ? sq : sq -\
    \ 1); q <= n; ++q) ret.emplace_back(q, x= double(N) / (q + 1), prev), prev= x;\n\
    \ for (int l= sq; l >= 1; --l) ret.emplace_back(double(N) / l, l - 1, l);\n return\
    \ ret;\n}\n#line 5 \"test/atcoder/abc172_d.enum_quo.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin\
    \ >> N;\n long long ans= 0;\n for (auto [q, l, r]: enumerate_quotients(N)) ans+=\
    \ ((r + 1) * r - (l + 1) * l) / 2 * q * (q + 1) / 2;\n cout << ans << '\\n';\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n//\
    \ O(\u221AN)\n#include <iostream>\n#include \"src/Math/enumerate_quotients.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n long long ans= 0;\n for (auto [q, l, r]: enumerate_quotients(N))\
    \ ans+= ((r + 1) * r - (l + 1) * l) / 2 * q * (q + 1) / 2;\n cout << ans << '\\\
    n';\n return 0;\n}"
  dependsOn:
  - src/Math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/atcoder/abc172_d.enum_quo.test.cpp
  requiredBy: []
  timestamp: '2023-05-13 17:48:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc172_d.enum_quo.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc172_d.enum_quo.test.cpp
- /verify/test/atcoder/abc172_d.enum_quo.test.cpp.html
title: test/atcoder/abc172_d.enum_quo.test.cpp
---
