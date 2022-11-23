---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.Dinic.test.cpp
    title: test/aoj/1615.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.PushRelabel.test.cpp
    title: test/aoj/1615.PushRelabel.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41\
      \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
    links:
    - https://snuke.hatenablog.com/entry/2016/07/10/043918
    - https://yukicoder.me/problems/no/459
  bundledCode: "#line 2 \"src/Optimization/MaxFlowLowerBound.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\n * @category \u6700\u9069\u5316\
    \u554F\u984C\n * \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Dinic\u7B49)\u306Fclass\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u3067\u53D7\u3051\u53D6\u308B\n * @see https://snuke.hatenablog.com/entry/2016/07/10/043918\n\
    \ * \u5BB9\u91CF\u306F\u8CA0\u3082\u53EF (\u9006\u5411\u304D\u306B\u6D41\u308C\
    \u308B\u610F\u5473)\n */\n\n// verify\u7528: https://yukicoder.me/problems/no/459\n\
    \n// BEGIN CUT HERE\ntemplate <typename FlowAlgo>\nclass MaxFlowLowerBound : public\
    \ FlowAlgo {\n  using Edge = typename FlowAlgo::Edge;\n  using flow_t = decltype(Edge::cap);\n\
    \  std::vector<flow_t> in;\n  int add_edge(int src, int dst, flow_t cap) {\n \
    \   int e = this->adj[src].size();\n    int re = src == dst ? e + 1 : this->adj[dst].size();\n\
    \    return this->adj[src].push_back(Edge{dst, re, cap}),\n           this->adj[dst].push_back(Edge{src,\
    \ e, 0}), this->m++, re;\n  }\n\n public:\n  MaxFlowLowerBound(std::size_t n =\
    \ 0) : FlowAlgo(n + 2), in(n) {}\n  int add_vertex() {\n    return this->adj.resize(++this->n),\
    \ in.resize(this->n - 2, 0), this->n - 3;\n  }\n  std::vector<int> add_vertices(const\
    \ std::size_t size) {\n    std::vector<int> ret(size);\n    std::iota(ret.begin(),\
    \ ret.end(), this->n - 2);\n    return this->adj.resize(this->n += size), in.resize(this->n\
    \ - 2, 0), ret;\n  }\n  struct EdgePtr {\n    friend class MaxFlowLowerBound;\n\
    \    MaxFlowLowerBound *instance;\n    int v, e;\n    flow_t u;\n    const Edge\
    \ &edge() { return instance->adj[v][e]; }\n    const Edge &rev() {\n      Edge\
    \ &e = edge();\n      return instance->adj[e.dst][e.rev];\n    }\n    EdgePtr(MaxFlowLowerBound\
    \ *instance, int v, int e, flow_t u)\n        : instance(instance), v(v), e(e),\
    \ u(u) {}\n\n   public:\n    EdgePtr() = default;\n    int src() const { return\
    \ v; }\n    int dst() const { return edge().dst; }\n    flow_t flow() const {\
    \ return u - edge().cap; }\n    flow_t lower() const { return flow() - rev().cap;\
    \ }\n    flow_t upper() const { return u; }\n  };\n  EdgePtr add_edge(int src,\
    \ int dst, flow_t lower, flow_t upper) {\n    assert(lower <= upper), src += 2,\
    \ dst += 2;\n    assert(0 <= src && src < this->n), assert(0 <= dst && dst < this->n);\n\
    \    this->m++;\n    int e = this->adj[src].size(),\n        re = src == dst ?\
    \ e + 1 : this->adj[dst].size();\n    if (lower * upper <= 0) {\n      this->adj[src].push_back(Edge{dst,\
    \ re, upper});\n      this->adj[dst].push_back(Edge{src, e, -lower});\n    } else\
    \ if (lower > 0) {\n      in[src - 2] -= lower, in[dst - 2] += lower;\n      this->adj[src].push_back(Edge{dst,\
    \ re, upper - lower});\n      this->adj[dst].push_back(Edge{src, e, 0});\n   \
    \ } else {\n      in[src - 2] -= upper, in[dst - 2] += upper;\n      this->adj[src].push_back(Edge{dst,\
    \ re, 0});\n      this->adj[dst].push_back(Edge{src, e, upper - lower});\n   \
    \ }\n    return EdgePtr(this, src, e, upper);\n  }\n  flow_t maxflow(int s, int\
    \ t) {\n    static constexpr flow_t INF = std::numeric_limits<flow_t>::max();\n\
    \    flow_t sum = 0;\n    for (int i = this->n - 2; i--;) {\n      if (in[i] >\
    \ 0) add_edge(0, i + 2, in[i]), sum += in[i];\n      if (in[i] < 0) add_edge(i\
    \ + 2, 1, -in[i]);\n    }\n    int re = add_edge(t += 2, s += 2, INF);\n    if\
    \ (this->flow(0, 1, INF) < sum) return -1;  // no solution\n    return this->flow(s,\
    \ t, INF) + this->adj[s][re].cap;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5C0F\u6D41\
    \u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\
    \u30A7\u30FC\u30B9\n * @category \u6700\u9069\u5316\u554F\u984C\n * \u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0(Dinic\u7B49)\u306Fclass\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8\u3067\u53D7\u3051\u53D6\u308B\n * @see https://snuke.hatenablog.com/entry/2016/07/10/043918\n\
    \ * \u5BB9\u91CF\u306F\u8CA0\u3082\u53EF (\u9006\u5411\u304D\u306B\u6D41\u308C\
    \u308B\u610F\u5473)\n */\n\n// verify\u7528: https://yukicoder.me/problems/no/459\n\
    \n// BEGIN CUT HERE\ntemplate <typename FlowAlgo>\nclass MaxFlowLowerBound : public\
    \ FlowAlgo {\n  using Edge = typename FlowAlgo::Edge;\n  using flow_t = decltype(Edge::cap);\n\
    \  std::vector<flow_t> in;\n  int add_edge(int src, int dst, flow_t cap) {\n \
    \   int e = this->adj[src].size();\n    int re = src == dst ? e + 1 : this->adj[dst].size();\n\
    \    return this->adj[src].push_back(Edge{dst, re, cap}),\n           this->adj[dst].push_back(Edge{src,\
    \ e, 0}), this->m++, re;\n  }\n\n public:\n  MaxFlowLowerBound(std::size_t n =\
    \ 0) : FlowAlgo(n + 2), in(n) {}\n  int add_vertex() {\n    return this->adj.resize(++this->n),\
    \ in.resize(this->n - 2, 0), this->n - 3;\n  }\n  std::vector<int> add_vertices(const\
    \ std::size_t size) {\n    std::vector<int> ret(size);\n    std::iota(ret.begin(),\
    \ ret.end(), this->n - 2);\n    return this->adj.resize(this->n += size), in.resize(this->n\
    \ - 2, 0), ret;\n  }\n  struct EdgePtr {\n    friend class MaxFlowLowerBound;\n\
    \    MaxFlowLowerBound *instance;\n    int v, e;\n    flow_t u;\n    const Edge\
    \ &edge() { return instance->adj[v][e]; }\n    const Edge &rev() {\n      Edge\
    \ &e = edge();\n      return instance->adj[e.dst][e.rev];\n    }\n    EdgePtr(MaxFlowLowerBound\
    \ *instance, int v, int e, flow_t u)\n        : instance(instance), v(v), e(e),\
    \ u(u) {}\n\n   public:\n    EdgePtr() = default;\n    int src() const { return\
    \ v; }\n    int dst() const { return edge().dst; }\n    flow_t flow() const {\
    \ return u - edge().cap; }\n    flow_t lower() const { return flow() - rev().cap;\
    \ }\n    flow_t upper() const { return u; }\n  };\n  EdgePtr add_edge(int src,\
    \ int dst, flow_t lower, flow_t upper) {\n    assert(lower <= upper), src += 2,\
    \ dst += 2;\n    assert(0 <= src && src < this->n), assert(0 <= dst && dst < this->n);\n\
    \    this->m++;\n    int e = this->adj[src].size(),\n        re = src == dst ?\
    \ e + 1 : this->adj[dst].size();\n    if (lower * upper <= 0) {\n      this->adj[src].push_back(Edge{dst,\
    \ re, upper});\n      this->adj[dst].push_back(Edge{src, e, -lower});\n    } else\
    \ if (lower > 0) {\n      in[src - 2] -= lower, in[dst - 2] += lower;\n      this->adj[src].push_back(Edge{dst,\
    \ re, upper - lower});\n      this->adj[dst].push_back(Edge{src, e, 0});\n   \
    \ } else {\n      in[src - 2] -= upper, in[dst - 2] += upper;\n      this->adj[src].push_back(Edge{dst,\
    \ re, 0});\n      this->adj[dst].push_back(Edge{src, e, upper - lower});\n   \
    \ }\n    return EdgePtr(this, src, e, upper);\n  }\n  flow_t maxflow(int s, int\
    \ t) {\n    static constexpr flow_t INF = std::numeric_limits<flow_t>::max();\n\
    \    flow_t sum = 0;\n    for (int i = this->n - 2; i--;) {\n      if (in[i] >\
    \ 0) add_edge(0, i + 2, in[i]), sum += in[i];\n      if (in[i] < 0) add_edge(i\
    \ + 2, 1, -in[i]);\n    }\n    int re = add_edge(t += 2, s += 2, INF);\n    if\
    \ (this->flow(0, 1, INF) < sum) return -1;  // no solution\n    return this->flow(s,\
    \ t, INF) + this->adj[s][re].cap;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/MaxFlowLowerBound.hpp
  requiredBy: []
  timestamp: '2022-11-18 14:42:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1615.Dinic.test.cpp
  - test/aoj/1615.PushRelabel.test.cpp
documentation_of: src/Optimization/MaxFlowLowerBound.hpp
layout: document
redirect_from:
- /library/src/Optimization/MaxFlowLowerBound.hpp
- /library/src/Optimization/MaxFlowLowerBound.hpp.html
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u9650\u4ED8\u304D\u6700\u5927\u6D41\u30A4\u30F3\
  \u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
---
