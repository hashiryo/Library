---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/String/z_algorithm.hpp
    title: Z-Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"test/yosupo/runenumerate.zalgo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/runenumerate\"\n#include <iostream>\n#include\
    \ <string>\n#line 2 \"src/String/z_algorithm.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#line 5 \"src/String/z_algorithm.hpp\"\n#include <tuple>\ntemplate\
    \ <class String> std::vector<int> z_algorithm(const String &s) {\n const int n=\
    \ s.size();\n if (n == 0) return {};\n std::vector<int> z(n);\n for (int i= 1,\
    \ j= 0; i < n; ++i) {\n  int &k= z[i];\n  for (k= (j + z[j] <= i) ? 0 : std::min(j\
    \ + z[j] - i, z[i - j]); i + k < n && s[k] == s[i + k];) ++k;\n  if (j + z[j]\
    \ < i + z[i]) j= i;\n }\n return z[0]= n, z;\n}\nstd::vector<int> z_to_kmp(const\
    \ std::vector<int> &z) {\n const int n= z.size();\n std::vector<int> kmp(n + 1);\n\
    \ kmp[0]= -1;\n for (int i= n; --i;) kmp[i + z[i]]= std::max(kmp[i + z[i]], z[i]);\n\
    \ for (int i= n; i--;) kmp[i]= std::max(kmp[i], kmp[i + 1] - 1);\n return kmp;\n\
    }\nnamespace string_internal {\ntemplate <class String> auto run_enumerate_(const\
    \ String &s, typename String::value_type a= 0) {\n using Run= std::tuple<int,\
    \ int, int>;\n std::vector<Run> glb;\n auto rec= [&](auto rec, int l, int r) ->\
    \ std::vector<Run> {\n  if (r - l <= 1) return {};\n  const int m= (l + r) / 2,\
    \ lsz= m - l, rsz= r - m;\n  std::vector<Run> run_l= lsz > 1 ? rec(rec, l, m)\
    \ : std::vector<Run>(), run_r= rsz > 1 ? rec(rec, m, r) : std::vector<Run>();\n\
    \  std::vector<typename String::value_type> rl(r - l + 1, a);\n  std::copy(s.begin()\
    \ + m, s.begin() + r, rl.begin()), std::copy(s.begin() + l, s.begin() + m, rl.begin()\
    \ + rsz + 1);\n  std::vector<int> zrl= z_algorithm(rl);\n  std::reverse(rl.begin(),\
    \ rl.end());\n  std::vector<int> zrl_r= z_algorithm(rl);\n  const int sz= rl.size();\n\
    \  std::vector<Run> ret;\n  auto push= [&](int b, int e, int p) { (b == l || e\
    \ == r ? ret : glb).emplace_back(b, e, p); };\n  std::vector<Run> run_m(rsz /\
    \ 2 + 1);\n  for (auto [b, e, p]: run_r) {\n   if (b != m) ret.emplace_back(b,\
    \ e, p);\n   else run_m[p]= Run{b, e, p};\n  }\n  for (auto [b, e, p]: run_l)\n\
    \   if (e != m) ret.emplace_back(b, e, p);\n   else if (zrl[sz - p] == p) {\n\
    \    if (std::get<2>(run_m[p])) push(b, std::get<1>(run_m[p]), p), run_m[p]= Run{};\n\
    \    else push(b, m + p + zrl[p], p);\n   } else push(b, m + zrl[sz - p], p);\n\
    \  for (auto [b, e, p]: run_m)\n   if (p) {\n    if (zrl[sz - p] != p) push(m\
    \ - zrl_r[sz - p], e, p);\n    else if (2 * p > lsz || zrl[sz - 2 * p] < p) push(m\
    \ - p - zrl_r[p], e, p);\n   }\n  for (int p= 1; p <= lsz; ++p)\n   if (bool skpr=\
    \ 2 * p <= rsz && zrl[p] >= p, skpl= 2 * p <= lsz && zrl[sz - 2 * p] >= p; zrl[sz\
    \ - p] == p) {\n    if (!skpl && !skpr) push(m - p - zrl_r[p], m + p + zrl[p],\
    \ p);\n   } else {\n    if (!skpr)\n     if (int b= m - zrl_r[sz - p], e= m +\
    \ p + zrl[p]; e - b >= 2 * p) push(b, e, p);\n    if (!skpl)\n     if (int b=\
    \ m - p - zrl_r[p], e= m + zrl[sz - p]; e - b >= 2 * p) push(b, e, p);\n   }\n\
    \  return ret;\n };\n std::vector<std::tuple<int, int, int>> runs= rec(rec, 0,\
    \ s.size());\n std::copy(glb.begin(), glb.end(), std::back_inserter(runs)), std::sort(runs.begin(),\
    \ runs.end()), runs.erase(std::unique(runs.begin(), runs.end(), [](auto &r1, auto\
    \ &r2) { return std::get<0>(r1) == std::get<0>(r2) && std::get<1>(r1) == std::get<1>(r2);\
    \ }), runs.end());\n int rn= runs.size(), n= s.size();\n glb.resize(rn);\n std::vector<int>\
    \ pt(n);\n for (auto [l, r, p]: runs) ++pt[p];\n for (int i= 1; i < n; ++i) pt[i]+=\
    \ pt[i - 1];\n for (int i= rn; i--;) glb[--pt[std::get<2>(runs[i])]]= {std::get<2>(runs[i]),\
    \ std::get<0>(runs[i]), std::get<1>(runs[i])};\n return glb;\n}\ntemplate <class\
    \ Int, typename= std::enable_if_t<std::is_integral_v<Int>>> auto run_enumerate(const\
    \ std::vector<Int> &s) { return run_enumerate_(s, *std::max_element(s.begin(),\
    \ s.end()) + 1); }\ntemplate <class String> auto run_enumerate(const String &s)\
    \ {\n auto v= s;\n std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n std::vector<int> t(s.size());\n for (int i= s.size();\
    \ i--;) t[i]= std::lower_bound(v.begin(), v.end(), s[i]) - v.begin();\n return\
    \ run_enumerate_(t, v.size() + 1);\n}\nauto run_enumerate(const std::string &s)\
    \ { return run_enumerate_(s); }\n}\nusing string_internal::run_enumerate;\n#line\
    \ 5 \"test/yosupo/runenumerate.zalgo.test.cpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string S;\n cin >> S;\n\
    \ auto ans= run_enumerate(S);\n cout << ans.size() << '\\n';\n for (auto [t, l,\
    \ r]: ans) cout << t << \" \" << l << \" \" << r << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n#include\
    \ <iostream>\n#include <string>\n#include \"src/String/z_algorithm.hpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n string\
    \ S;\n cin >> S;\n auto ans= run_enumerate(S);\n cout << ans.size() << '\\n';\n\
    \ for (auto [t, l, r]: ans) cout << t << \" \" << l << \" \" << r << '\\n';\n\
    \ return 0;\n}"
  dependsOn:
  - src/String/z_algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/runenumerate.zalgo.test.cpp
  requiredBy: []
  timestamp: '2023-11-21 15:50:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.zalgo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.zalgo.test.cpp
- /verify/test/yosupo/runenumerate.zalgo.test.cpp.html
title: test/yosupo/runenumerate.zalgo.test.cpp
---