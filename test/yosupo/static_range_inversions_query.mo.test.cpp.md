---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/BinaryIndexedTree.hpp
    title: Binary-Indexed-Tree
  - icon: ':x:'
    path: src/Misc/Mo.hpp
    title: Mo's Algorithm
  - icon: ':question:'
    path: src/Misc/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.mo.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#line 4 \"src/Misc/compress.hpp\"\
    \ntemplate <class T> auto compress(std::vector<T> &v) {\n return std::sort(v.begin(),\
    \ v.end()), v.erase(std::unique(v.begin(), v.end()), v.end()), [&v](T x) { return\
    \ std::lower_bound(v.begin(), v.end(), x) - v.begin(); };\n}\n#line 4 \"src/Misc/Mo.hpp\"\
    \n#include <numeric>\nstruct Mo {\n int n;\n std::vector<int> L, R;\n explicit\
    \ Mo(int n): n(n) {}\n void query(int l, int r) { L.push_back(l), R.push_back(r);\
    \ } /* [l, r) */\n template <typename AL, typename AR, typename EL, typename ER,\
    \ typename O> void run(const AL &add_left, const AR &add_right, const EL &erase_left,\
    \ const ER &erase_right, const O &out) {\n  int q= lr.size(), bs= n / std::min<int>(n,\
    \ std::sqrt(q));\n  std::vector<int> ord(q);\n  std::iota(ord.begin(), ord.end(),\
    \ 0), std::sort(ord.begin(), ord.end(), [&](int a, int b) {\n   int ablk= L[a]\
    \ / bs, bblk= L[b] / bs;\n   return ablk != bblk ? ablk < bblk : (ablk & 1) ?\
    \ R[a] > R[b] : R[a] < R[b];\n  });\n  int l= 0, r= 0;\n  for (auto i: ord) {\n\
    \   while (l > L[i]) add_left(--l);\n   while (r < R[i]) add_right(r++);\n   while\
    \ (l < L[i]) erase_left(l++);\n   while (r > R[i]) erase_right(--r);\n   out(i);\n\
    \  }\n }\n template <typename A, typename E, typename O> void run(const A &add,\
    \ const E &erase, const O &out) { run(add, add, erase, erase, out); }\n};\n#line\
    \ 4 \"src/DataStructure/BinaryIndexedTree.hpp\"\ntemplate <typename T> class BinaryIndexedTree\
    \ {\n std::vector<T> dat;\npublic:\n BinaryIndexedTree(int n): dat(n + 1, T())\
    \ {}\n BinaryIndexedTree(int n, T a): BinaryIndexedTree(std::vector<T>(n, a))\
    \ {}\n BinaryIndexedTree(const std::vector<T>& y): dat(y.size() + 1, 0) {\n  for\
    \ (int i= y.size(); i--;) dat[i + 1]= y[i];\n  for (int i= 1, e= dat.size(), j;\
    \ i < e; ++i)\n   if ((j= i + (i & -i)) < e) dat[j]+= dat[i];\n }\n void add(int\
    \ i, T a= 1) {\n  for (++i; i < (int)dat.size(); i+= i & -i) dat[i]+= a;\n }\n\
    \ T sum(int i) const {  // sum [0,i)\n  T s= 0;\n  for (; i; i&= i - 1) s+= dat[i];\n\
    \  return s;\n }\n T sum(int l, int r) const { return sum(r) - sum(l); }  // sum\
    \ [l,r)\n T operator[](int k) const { return sum(k + 1) - sum(k); }\n int find(T\
    \ k) const {  // min { i : sum(i+1) > k } -> kth element(0-indexed)\n  int i=\
    \ 0;\n  for (int p= 1 << (std::__lg(dat.size() - 1) + 1), e= dat.size(); p; p>>=\
    \ 1)\n   if (i + p < e && dat[i + p] <= k) k-= dat[i+= p];\n  return i + 1 ==\
    \ (int)dat.size() ? -1 : i;  // -1 -> no solutions\n }\n};\n#line 8 \"test/yosupo/static_range_inversions_query.mo.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n int A[N];\n for (int i= 0; i < N; i++) cin >> A[i];\n\
    \ vector<int> v(A, A + N);\n auto id= compress(v);\n for (int i= 0; i < N; i++)\
    \ A[i]= id(A[i]);\n Mo mo(N);\n for (int q= 0; q < Q; q++) {\n  int l, r;\n  cin\
    \ >> l >> r;\n  mo.query(l, r);\n }\n BinaryIndexedTree<long long> bit(N + 1);\n\
    \ long long inv= 0, total= 0;\n auto addl= [&](int i) { inv+= bit.sum(A[i]), bit.add(A[i],\
    \ 1), total++; };\n auto addr= [&](int i) { inv+= total - bit.sum(A[i] + 1), bit.add(A[i],\
    \ 1), total++; };\n auto erasel= [&](int i) { inv-= bit.sum(A[i]), bit.add(A[i],\
    \ -1), total--; };\n auto eraser= [&](int i) { inv-= total - bit.sum(A[i] + 1),\
    \ bit.add(A[i], -1), total--; };\n long long ans[Q];\n auto out= [&](int q) {\
    \ ans[q]= inv; };\n mo.run(addl, addr, erasel, eraser, out);\n for (int q= 0;\
    \ q < Q; q++) cout << ans[q] << \"\\n\";\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include \"src/Misc/compress.hpp\"\
    \n#include \"src/Misc/Mo.hpp\"\n#include \"src/DataStructure/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N, Q;\n cin >> N >> Q;\n int A[N];\n for (int i= 0; i < N; i++) cin >> A[i];\n\
    \ vector<int> v(A, A + N);\n auto id= compress(v);\n for (int i= 0; i < N; i++)\
    \ A[i]= id(A[i]);\n Mo mo(N);\n for (int q= 0; q < Q; q++) {\n  int l, r;\n  cin\
    \ >> l >> r;\n  mo.query(l, r);\n }\n BinaryIndexedTree<long long> bit(N + 1);\n\
    \ long long inv= 0, total= 0;\n auto addl= [&](int i) { inv+= bit.sum(A[i]), bit.add(A[i],\
    \ 1), total++; };\n auto addr= [&](int i) { inv+= total - bit.sum(A[i] + 1), bit.add(A[i],\
    \ 1), total++; };\n auto erasel= [&](int i) { inv-= bit.sum(A[i]), bit.add(A[i],\
    \ -1), total--; };\n auto eraser= [&](int i) { inv-= total - bit.sum(A[i] + 1),\
    \ bit.add(A[i], -1), total--; };\n long long ans[Q];\n auto out= [&](int q) {\
    \ ans[q]= inv; };\n mo.run(addl, addr, erasel, eraser, out);\n for (int q= 0;\
    \ q < Q; q++) cout << ans[q] << \"\\n\";\n return 0;\n}"
  dependsOn:
  - src/Misc/compress.hpp
  - src/Misc/Mo.hpp
  - src/DataStructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.mo.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 16:53:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.mo.test.cpp
- /verify/test/yosupo/static_range_inversions_query.mo.test.cpp.html
title: test/yosupo/static_range_inversions_query.mo.test.cpp
---
