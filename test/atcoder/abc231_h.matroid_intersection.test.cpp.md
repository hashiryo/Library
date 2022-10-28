---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Optimization/matroid_intersection.hpp
    title: "\u30DE\u30C8\u30ED\u30A4\u30C9\u4EA4\u53C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc231/tasks/abc231_h
    links:
    - https://atcoder.jp/contests/abc231/tasks/abc231_h
  bundledCode: "#line 1 \"test/atcoder/abc231_h.matroid_intersection.test.cpp\"\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc231/tasks/abc231_h\"\n// (\u5206\
    \u5272 + \u5206\u5272)\n#include <bits/stdc++.h>\n#line 3 \"src/Optimization/matroid_intersection.hpp\"\
    \n/**\n * @title \u30DE\u30C8\u30ED\u30A4\u30C9\u4EA4\u53C9\n * @category \u6700\
    \u9069\u5316\u554F\u984C\n *  unweighted: return \u8981\u7D20\u6570\u6700\u5927\
    \u306E\u5171\u901A\u72EC\u7ACB\u96C6\u5408\n *  weighted: return { \u8981\u7D20\
    \u6570 = k \u306E\u5171\u901A\u72EC\u7ACB\u96C6\u5408\u306E\u3046\u3061\u91CD\u307F\
    \u304C\u6700\u5927(\u6700\u5C0F)\u306E\u3082\u306E }\n * @see William H. Cunningham.\
    \ Improved bounds for matroid partition and\n * intersection algorithms. SIAMJournal\
    \ on Computing (SICOMP), 15(4):948\u2013957,\n * 1986.\n */\n// verify\u7528:\n\
    // https://www.beecrowd.com.br/judge/en/problems/view/2128 (\u30B0\u30E9\u30D5\
    +\u5206\u5272)\n\n// BEGIN CUT HERE\ntemplate <typename Matroid1, typename Matroid2>\n\
    std::vector<int> matroid_intersection(int n, Matroid1 M1, Matroid2 M2) {\n  std::vector<bool>\
    \ b(n, false), useless(n);\n  std::vector<int> I[2];\n  for (int e = 0; e < n;\
    \ e++) I[0].push_back(e);\n  M1.build(I[1]), M2.build(I[1]);\n  for (bool converged\
    \ = false; !converged;) {\n    useless.assign(n, false);\n    std::vector L(1,\
    \ std::vector<int>());\n    for (int u : I[0])\n      if (M1.oracle(u)) useless[u]\
    \ = true, L[0].push_back(u);\n    int m = 0;\n    for (; L.back().size(); m +=\
    \ 2) {\n      L.push_back({});\n      for (int e : L[m]) {\n        if (converged\
    \ = M2.oracle(e)) break;\n        for (int f : I[1])\n          if (!useless[f]\
    \ && M2.oracle(f, e))\n            L[m + 1].push_back(f), useless[f] = true;\n\
    \      }\n      if (converged) break;\n      L.push_back({});\n      for (int\
    \ e : L[m + 1])\n        for (int f : I[0])\n          if (!useless[f] && M1.oracle(e,\
    \ f))\n            L[m + 2].push_back(f), useless[f] = true;\n    }\n    if (!converged)\
    \ break;\n    std::vector<std::vector<int>> L2(m + 1);\n    for (int e : L[m])\n\
    \      if (M2.oracle(e)) L2[m].push_back(e);\n    for (int i = m; i; i -= 2) {\n\
    \      for (int e : L[i - 1])\n        for (int f : L2[i])\n          if (M1.oracle(e,\
    \ f)) {\n            L2[i - 1].push_back(e);\n            break;\n          }\n\
    \      for (int e : L[i - 2])\n        for (int f : L2[i - 1])\n          if (M2.oracle(f,\
    \ e)) {\n            L2[i - 2].push_back(e);\n            break;\n          }\n\
    \    }\n    auto dfs = [&](auto self, int e, int i) -> bool {\n      if (useless[e]\
    \ = true; i == m)\n        return M2.oracle(e) ? (b[e] = !b[e], true) : false;\n\
    \      for (int f : L2[i + 1])\n        if (!useless[f] && M2.oracle(f, e)) {\n\
    \          useless[f] = true;\n          for (int g : L2[i + 2])\n           \
    \ if (!useless[g] && M1.oracle(f, g))\n              if (self(self, g, i + 2))\
    \ return b[e] = !b[e], b[f] = !b[f], true;\n        }\n      return false;\n \
    \   };\n    useless.assign(n, false);\n    for (int e : L2[0])\n      if (M1.oracle(e)\
    \ && dfs(dfs, e, 0)) {\n        converged = false, I[0].clear(), I[1].clear();\n\
    \        for (int u = 0; u < n; u++) I[b[u]].push_back(u);\n        M1.build(I[1]),\
    \ M2.build(I[1]);\n      }\n  }\n  return I[1];\n}\n\n// sgn: + -> max, - -> min,\
    \ 0 -> unweighted\ntemplate <std::int_least8_t sgn, class Matroid1, class Matroid2,\
    \ class cost_t>\nstd::vector<std::vector<int>> weighted_matroid_intersection(\n\
    \    int n, Matroid1 M1, Matroid2 M2, std::vector<cost_t> c) {\n  assert(n ==\
    \ (int)c.size());\n  bool b[n];\n  std::fill_n(b, n, false);\n  std::vector<int>\
    \ I[2], p;\n  std::vector<std::vector<int>> ret(1);\n  for (int u = 0; u < n;\
    \ u++) I[0].push_back(u);\n  if constexpr (sgn > 0) {\n    auto cmx = *std::max_element(c.begin(),\
    \ c.end());\n    for (auto &x : c) x -= cmx;\n  } else {\n    auto cmi = *std::min_element(c.begin(),\
    \ c.end());\n    for (auto &x : c) x -= cmi;\n  }\n  for (auto &x : c) x *= sgn\
    \ * (n + 1);\n  for (bool converged = false; !converged;) {\n    converged = true,\
    \ M1.build(I[1]), M2.build(I[1]);\n    std::priority_queue<std::pair<cost_t, int>>\
    \ pq;\n    std::vector<cost_t> dist(n, std::numeric_limits<cost_t>::lowest());\n\
    \    for (int u : I[0])\n      if (M1.oracle(u)) pq.emplace(dist[u] = c[u] - 1,\
    \ u);\n    for (p.assign(n, -1); pq.size();) {\n      auto [d, u] = pq.top();\n\
    \      if (pq.pop(); d != dist[u]) continue;\n      if (b[u]) {\n        for (int\
    \ v : I[0])\n          if (M1.oracle(u, v))\n            if (cost_t cost = d +\
    \ c[v] - 1; dist[v] < cost)\n              pq.emplace(dist[v] = cost, v), p[v]\
    \ = u;\n      } else {\n        if (M2.oracle(u)) {\n          for (int v = u;\
    \ v != -1; v = p[v]) b[v] = !b[v];\n          I[0].clear(), I[1].clear(), converged\
    \ = false;\n          for (int u = 0; u < n; u++) I[b[u]].push_back(u);\n    \
    \      ret.emplace_back(I[1]);\n          break;\n        }\n        for (int\
    \ v : I[1])\n          if (M2.oracle(v, u))\n            if (cost_t cost = d -\
    \ c[v] - 1; dist[v] < cost)\n              pq.emplace(dist[v] = cost, v), p[v]\
    \ = u;\n      }\n    }\n  }\n  return ret;\n}\n\nclass GraphicMatroid {\n  int\
    \ n, t;\n  std::vector<std::array<int, 2>> edges;\n  std::vector<std::vector<int>>\
    \ g;\n  std::vector<int> comp, in, out;\n  void dfs(int u) {\n    in[u] = t++;\n\
    \    for (auto v : g[u])\n      if (in[v] == -1) comp[v] = comp[u], dfs(v);\n\
    \    out[u] = t;\n  }\n  inline bool is_ancestor(int u, int v) const {\n    return\
    \ in[u] <= in[v] && in[v] < out[u];\n  }\n\n public:\n  GraphicMatroid(int n_)\
    \ : n(n_), g(n), comp(n), in(n), out(n) {}\n  void add_edge(int u, int v) { edges.emplace_back(std::array{u,\
    \ v}); }\n  void build(const std::vector<int> &I) {\n    t = 0;\n    for (int\
    \ u = 0; u < n; u++) g[u].clear(), in[u] = -1;\n    for (int e : I) {\n      int\
    \ u = edges[e][0], v = edges[e][1];\n      g[u].push_back(v), g[v].push_back(u);\n\
    \    }\n    for (int u = 0; u < n; u++)\n      if (in[u] == -1) comp[u] = u, dfs(u);\n\
    \  }\n  inline bool oracle(int e) const {\n    return comp[edges[e][0]] != comp[edges[e][1]];\n\
    \  }\n  inline bool oracle(int e, int f) const {\n    if (oracle(f)) return true;\n\
    \    int u = edges[e][in[edges[e][0]] < in[edges[e][1]]];\n    return is_ancestor(u,\
    \ edges[f][0]) != is_ancestor(u, edges[f][1]);\n  }\n};\n\nstruct PartitionMatroid\
    \ {\n  std::vector<int> belong, R, cnt;\n  PartitionMatroid(int m_, const std::vector<std::vector<int>>\
    \ &parts,\n                   const std::vector<int> &R_)\n      : belong(m_,\
    \ -1), R(R_) {\n    assert(parts.size() == R.size());\n    for (int i = parts.size();\
    \ i--;)\n      for (int e : parts[i]) belong[e] = i;\n  }\n  void build(const\
    \ std::vector<int> &I) {\n    cnt = R;\n    for (int e : I)\n      if (belong[e]\
    \ != -1) cnt[belong[e]]--;\n  }\n  inline bool oracle(int e) const {\n    return\
    \ belong[e] == -1 || cnt[belong[e]] > 0;\n  }\n  inline bool oracle(int e, int\
    \ f) const {\n    return oracle(f) || belong[e] == belong[f];\n  }\n};\n#line\
    \ 5 \"test/atcoder/abc231_h.matroid_intersection.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int H, W, N;\n\
    \  cin >> H >> W >> N;\n  vector<long long> C(N);\n  vector<vector<int>> parts1(H),\
    \ parts2(W);\n  vector<int> sz1(H, -1), sz2(W, -1);\n  for (int i = 0; i < N;\
    \ i++) {\n    int A, B;\n    cin >> A >> B >> C[i], A--, B--;\n    parts1[A].push_back(i);\n\
    \    parts2[B].push_back(i);\n    sz1[A]++, sz2[B]++;\n  }\n  PartitionMatroid\
    \ M1(N, parts1, sz1), M2(N, parts2, sz2);\n  auto S = weighted_matroid_intersection<+1>(N,\
    \ M1, M2, C);\n  long long s = 0;\n  for (int i = 1, ed = S.size(); i < ed; i++)\
    \ {\n    long long sum = 0;\n    for (int e : S[i]) sum += C[e];\n    if (s <\
    \ sum) s = sum;\n  }\n  cout << accumulate(C.begin(), C.end(), 0ll) - s << '\\\
    n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc231/tasks/abc231_h\"\n//\
    \ (\u5206\u5272 + \u5206\u5272)\n#include <bits/stdc++.h>\n#include \"src/Optimization/matroid_intersection.hpp\"\
    \nusing namespace std;\n\nint main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int H, W, N;\n  cin >> H >> W >> N;\n  vector<long long> C(N);\n  vector<vector<int>>\
    \ parts1(H), parts2(W);\n  vector<int> sz1(H, -1), sz2(W, -1);\n  for (int i =\
    \ 0; i < N; i++) {\n    int A, B;\n    cin >> A >> B >> C[i], A--, B--;\n    parts1[A].push_back(i);\n\
    \    parts2[B].push_back(i);\n    sz1[A]++, sz2[B]++;\n  }\n  PartitionMatroid\
    \ M1(N, parts1, sz1), M2(N, parts2, sz2);\n  auto S = weighted_matroid_intersection<+1>(N,\
    \ M1, M2, C);\n  long long s = 0;\n  for (int i = 1, ed = S.size(); i < ed; i++)\
    \ {\n    long long sum = 0;\n    for (int e : S[i]) sum += C[e];\n    if (s <\
    \ sum) s = sum;\n  }\n  cout << accumulate(C.begin(), C.end(), 0ll) - s << '\\\
    n';\n  return 0;\n}"
  dependsOn:
  - src/Optimization/matroid_intersection.hpp
  isVerificationFile: true
  path: test/atcoder/abc231_h.matroid_intersection.test.cpp
  requiredBy: []
  timestamp: '2022-10-28 11:51:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc231_h.matroid_intersection.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc231_h.matroid_intersection.test.cpp
- /verify/test/atcoder/abc231_h.matroid_intersection.test.cpp.html
title: test/atcoder/abc231_h.matroid_intersection.test.cpp
---
