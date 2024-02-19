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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: src/Graph/Tree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"src/Graph/Tree.hpp\"\nclass BiConnectedComponents\
    \ {\n const size_t n;\n std::vector<std::pair<int, int>> E;\npublic:\n BiConnectedComponents(int\
    \ n): n(n) {}\n void add_edge(int u, int v) { E.emplace_back(u, v); }\n Tree<void>\
    \ block_cut_tree() const {\n  std::vector<int> pos(n + 1), g(E.size() * 2);\n\
    \  for (auto [u, v]: E) ++pos[u], ++pos[v];\n  std::partial_sum(pos.begin(), pos.end(),\
    \ pos.begin());\n  for (auto [u, v]: E) g[--pos[u]]= v, g[--pos[v]]= u;\n  std::vector<int>\
    \ ord(n), par(n, -2), dat(pos.begin(), pos.begin() + n);\n  int k= 0;\n  for (int\
    \ s= 0, p; s < n; ++s)\n   if (par[s] == -2)\n    for (par[p= s]= -1; p >= 0;)\
    \ {\n     if (dat[p] == pos[p]) ord[k++]= p;\n     if (dat[p] == pos[p + 1]) {\n\
    \      p= par[p];\n      continue;\n     }\n     if (int q= g[dat[p]++]; par[q]\
    \ == -2) par[q]= p, p= q;\n    }\n  for (int i= n; i--;) dat[ord[i]]= i;\n  auto\
    \ low= dat;\n  for (int v= n; v--;)\n   for (int j= pos[v]; j < pos[v + 1]; ++j)\
    \ low[v]= std::min(low[v], dat[g[j]]);\n  for (int i= n; i--;)\n   if (int p=\
    \ ord[i], pp= par[p]; pp >= 0) low[pp]= std::min(low[pp], low[p]);\n  std::vector<std::pair<int,\
    \ int>> es;\n  for (int p: ord)\n   if (par[p] >= 0) {\n    if (int pp= par[p];\
    \ low[p] < dat[pp]) es.emplace_back(low[p]= low[pp], p);\n    else es.emplace_back(k,\
    \ pp), es.emplace_back(k, p), low[p]= k++;\n   }\n  for (int s= n; s--;)\n   if\
    \ (pos[s] == pos[s + 1]) es.emplace_back(k++, s);\n  Tree ret(k);\n  for (auto\
    \ [u, v]: es) ret.add_edge(u, v);\n  return ret.build(), ret;\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/old/BiConnectedComponents.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/BiConnectedComponents.hpp
layout: document
title: "2\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

![bct.svg](https://github.com/hashiryo/Library/blob/master/img/bct.svg?raw=true)

[0, n)：もとの頂点 \
[n, n + n_block)：block\
$\mathrm{deg} > 1 $ $\rightarrow$ 関節点


非再帰 [参考](https://nachiavivias.github.io/cp-library/column/2022/01.html)
## 問題例
[AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)
## 参考
[https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg](https://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg)