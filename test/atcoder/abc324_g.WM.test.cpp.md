---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/WaveletMatrix.hpp
    title: "Wavelet\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc324/tasks/abc324_g
    links:
    - https://atcoder.jp/contests/abc324/tasks/abc324_g
  bundledCode: "#line 1 \"test/atcoder/abc324_g.WM.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc324/tasks/abc324_g\"\n#include <iostream>\n#include\
    \ <vector>\n#include <array>\n#line 3 \"src/DataStructure/WaveletMatrix.hpp\"\n\
    #include <algorithm>\n#line 5 \"src/DataStructure/WaveletMatrix.hpp\"\n#include\
    \ <cassert>\ntemplate <class T> class WaveletMatrix {\n struct SuccinctIndexableDictionary\
    \ {\n  size_t len, blocks, zeros;\n  std::vector<unsigned> bit, sum;\n  SuccinctIndexableDictionary(size_t\
    \ len): len(len), blocks((len >> 5) + 1), bit(blocks, 0), sum(blocks, 0) {}\n\
    \  void set(int k) { bit[k >> 5]|= 1U << (k & 31); }\n  void build() {\n   for\
    \ (size_t i= 1; i < blocks; ++i) sum[i]= sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\n   zeros= rank0(len);\n  }\n  bool operator[](int k) const { return\
    \ (bit[k >> 5] >> (k & 31)) & 1; }\n  size_t rank(size_t k) const { return (sum[k\
    \ >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1))); }\n  size_t\
    \ rank0(size_t k) const { return k - rank(k); }\n };\n size_t len, lg;\n std::vector<SuccinctIndexableDictionary>\
    \ mat;\n std::vector<T> vec;\npublic:\n WaveletMatrix(const std::vector<T> &v):\
    \ len(v.size()), lg(len ? 32 - __builtin_clz(len) : 1), mat(lg, len), vec(v) {\n\
    \  std::sort(vec.begin(), vec.end()), vec.erase(std::unique(vec.begin(), vec.end()),\
    \ vec.end());\n  std::vector<unsigned> cur(len), nex(len);\n  for (int i= len;\
    \ i--;) cur[i]= std::lower_bound(vec.begin(), vec.end(), v[i]) - vec.begin();\n\
    \  for (auto h= lg; h--; cur.swap(nex)) {\n   for (size_t i= 0; i < len; ++i)\n\
    \    if ((cur[i] >> h) & 1) mat[h].set(i);\n   mat[h].build();\n   std::array\
    \ it{nex.begin(), nex.begin() + mat[h].zeros};\n   for (size_t i= 0; i < len;\
    \ ++i) *it[mat[h][i]]++= cur[i];\n  }\n }\n // k-th(0-indexed) smallest number\
    \ in v[l,r)\n T kth_smallest(int l, int r, int k) const {\n  assert(k < r - l);\n\
    \  size_t ret= 0;\n  for (auto h= lg; h--;)\n   if (auto l0= mat[h].rank0(l),\
    \ r0= mat[h].rank0(r); k >= r0 - l0) k-= r0 - l0, ret|= 1 << h, l+= mat[h].zeros\
    \ - l0, r+= mat[h].zeros - r0;\n   else l= l0, r= r0;\n  return vec[ret];\n }\n\
    \ // k-th(0-indexed) largest number in v[l,r)\n T kth_largest(int l, int r, int\
    \ k) const { return kth_smallest(l, r, r - l - k - 1); }\n // count i s.t. (l\
    \ <= i < r) && (v[i] < ub)\n size_t count(int l, int r, T ub) const {\n  size_t\
    \ x= std::lower_bound(vec.begin(), vec.end(), ub) - vec.begin();\n  if (x >= 1u\
    \ << lg) return r - l;\n  if (x == 0) return 0;\n  size_t ret= 0;\n  for (auto\
    \ h= lg; h--;)\n   if (auto l0= mat[h].rank0(l), r0= mat[h].rank0(r); (x >> h)\
    \ & 1) ret+= r0 - l0, l+= mat[h].zeros - l0, r+= mat[h].zeros - r0;\n   else l=\
    \ l0, r= r0;\n  return ret;\n }\n // count i s.t. (l <= i < r) && (lb <= v[i]\
    \ < ub)\n size_t count(int l, int r, T lb, T ub) const { return count(l, r, ub)\
    \ - count(l, r, lb); }\n};\n#line 6 \"test/atcoder/abc324_g.WM.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int\
    \ N;\n cin >> N;\n vector<int> A(N);\n for (int i= 0; i < N; ++i) cin >> A[i],\
    \ --A[i];\n WaveletMatrix wm(A);\n vector<array<int, 4>> dat;\n dat.push_back({0,\
    \ N, 0, N});\n int Q;\n cin >> Q;\n while (Q--) {\n  int t, s, x;\n  cin >> t\
    \ >> s >> x;\n  auto [l, r, u, d]= dat[s];\n  if (t == 1) {\n   if (wm.count(l,\
    \ r, u, d) < x) dat.push_back({0, 0, 0, 0});\n   else {\n    int ok= r, ng= l\
    \ - 1;\n    while (ok - ng > 1) {\n     int m= (ok + ng) / 2;\n     if (wm.count(l,\
    \ m, u, d) >= x) ok= m;\n     else ng= m;\n    }\n    dat[s]= {l, ok, u, d}, dat.push_back({ok,\
    \ r, u, d});\n   }\n  } else {\n   if (--x; d <= x) dat.push_back({0, 0, 0, 0});\n\
    \   else if (x < u) dat[s]= {0, 0, 0, 0}, dat.push_back({l, r, u, d});\n   else\
    \ dat[s]= {l, r, u, x + 1}, dat.push_back({l, r, x + 1, d});\n  }\n  {\n   auto\
    \ [l, r, u, d]= dat.back();\n   cout << wm.count(l, r, u, d) << '\\n';\n  }\n\
    \ }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc324/tasks/abc324_g\"\n#include\
    \ <iostream>\n#include <vector>\n#include <array>\n#include \"src/DataStructure/WaveletMatrix.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n vector<int> A(N);\n for (int i= 0; i < N; ++i) cin >> A[i],\
    \ --A[i];\n WaveletMatrix wm(A);\n vector<array<int, 4>> dat;\n dat.push_back({0,\
    \ N, 0, N});\n int Q;\n cin >> Q;\n while (Q--) {\n  int t, s, x;\n  cin >> t\
    \ >> s >> x;\n  auto [l, r, u, d]= dat[s];\n  if (t == 1) {\n   if (wm.count(l,\
    \ r, u, d) < x) dat.push_back({0, 0, 0, 0});\n   else {\n    int ok= r, ng= l\
    \ - 1;\n    while (ok - ng > 1) {\n     int m= (ok + ng) / 2;\n     if (wm.count(l,\
    \ m, u, d) >= x) ok= m;\n     else ng= m;\n    }\n    dat[s]= {l, ok, u, d}, dat.push_back({ok,\
    \ r, u, d});\n   }\n  } else {\n   if (--x; d <= x) dat.push_back({0, 0, 0, 0});\n\
    \   else if (x < u) dat[s]= {0, 0, 0, 0}, dat.push_back({l, r, u, d});\n   else\
    \ dat[s]= {l, r, u, x + 1}, dat.push_back({l, r, x + 1, d});\n  }\n  {\n   auto\
    \ [l, r, u, d]= dat.back();\n   cout << wm.count(l, r, u, d) << '\\n';\n  }\n\
    \ }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/WaveletMatrix.hpp
  isVerificationFile: true
  path: test/atcoder/abc324_g.WM.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 23:12:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc324_g.WM.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc324_g.WM.test.cpp
- /verify/test/atcoder/abc324_g.WM.test.cpp.html
title: test/atcoder/abc324_g.WM.test.cpp
---
