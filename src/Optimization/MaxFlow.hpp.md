---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.Dinic.test.cpp
    title: test/aoj/2313.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.PushRelabel.test.cpp
    title: test/aoj/2313.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2803.Dinic.test.cpp
    title: test/aoj/2803.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2803.PushRelabel.test.cpp
    title: test/aoj/2803.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2835.Dinic.test.cpp
    title: test/aoj/2835.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2835.PushRelabel.test.cpp
    title: test/aoj/2835.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.Dinic.test.cpp
    title: test/aoj/GRL_6_A.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.PushRelabel.test.cpp
    title: test/aoj/GRL_6_A.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.Dinic.test.cpp
    title: test/atcoder/arc107_f.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.PushRelabel.test.cpp
    title: test/atcoder/arc107_f.PushRelabel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.Dinic.test.cpp
    title: test/atcoder/arc129_e.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.PushRelabel.test.cpp
    title: test/atcoder/arc129_e.PushRelabel.test.cpp
  - icon: ':x:'
    path: test/yukicoder/119.Dinic.test.cpp
    title: test/yukicoder/119.Dinic.test.cpp
  - icon: ':x:'
    path: test/yukicoder/119.PushRelabel.test.cpp
    title: test/yukicoder/119.PushRelabel.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "\u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
    links: []
  bundledCode: "#line 2 \"src/Optimization/MaxFlow.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title \u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\
    \n * @category \u6700\u9069\u5316\u554F\u984C\n * \u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0(Dinic\u7B49)\u306Fclass\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3067\u53D7\
    \u3051\u53D6\u308B\n * EdgePtr:\n *  change_cap: \u5BB9\u91CF\u3092\u5909\u66F4\
    , \u305D\u308C\u306B\u4F34\u3046\u30D5\u30ED\u30FC\u306E\u306F\u307F\u51FA\u3057\
    \u3092\u51FA\u529B\n * \u53CC\u65B9\u5411\u8FBA\u3082\u53EF\n */\n\n// BEGIN CUT\
    \ HERE\ntemplate <typename FlowAlgo>\nstruct MaxFlow : public FlowAlgo {\n  using\
    \ FlowAlgo::FlowAlgo;\n  using Edge = typename FlowAlgo::Edge;\n  using flow_t\
    \ = decltype(Edge::cap);\n  int add_vertex() { return this->adj.resize(++this->n),\
    \ this->n - 1; }\n  std::vector<int> add_vertices(const std::size_t size) {\n\
    \    std::vector<int> ret(size);\n    std::iota(ret.begin(), ret.end(), this->n);\n\
    \    return this->adj.resize(this->n += size), ret;\n  }\n  struct EdgePtr {\n\
    \    friend class MaxFlow;\n    MaxFlow *instance;\n    int v, e;\n    bool bidir;\n\
    \    Edge &edge() { return instance->adj[v][e]; }\n    Edge &rev() {\n      Edge\
    \ &e = edge();\n      return instance->adj[e.dst][e.rev];\n    }\n    EdgePtr(MaxFlow\
    \ *instance, int v, int e, bool d)\n        : instance(instance), v(v), e(e),\
    \ bidir(d) {}\n\n   public:\n    EdgePtr() = default;\n    int src() { return\
    \ v; }\n    int dst() { return edge().dst; }\n    bool is_direct() const { return\
    \ !bidir; }\n    flow_t flow() { return cap() - edge().cap; }\n    flow_t cap()\
    \ { return (edge().cap + rev().cap) / (1 + bidir); }\n    flow_t change_cap(flow_t\
    \ new_cap, int s, int t) {\n      assert(0 <= new_cap);\n      Edge &e = edge(),\
    \ &re = rev();\n      flow_t diff = new_cap - cap(), extrusion = std::abs(flow())\
    \ - new_cap;\n      if (extrusion <= 0) return e.cap += diff, re.cap += diff *\
    \ bidir, 0;\n      int sr = src(), ds = dst();\n      if (flow() < 0) std::swap(sr,\
    \ ds);\n      if (bidir) {\n        if (sr == src())\n          re.cap += 2 *\
    \ diff + e.cap, e.cap = 0;\n        else\n          e.cap += 2 * diff + re.cap,\
    \ re.cap = 0;\n      } else\n        re.cap += diff;\n      extrusion -= instance->maxflow(sr,\
    \ ds, extrusion);\n      if (ds != t) instance->maxflow(t, ds, extrusion);\n \
    \     if (sr != s) instance->maxflow(sr, s, extrusion);\n      return extrusion;\n\
    \    }\n  };\n  EdgePtr add_edge(int src, int dst, flow_t cap, bool bidir = false)\
    \ {\n    assert(0 <= src && src < this->n), assert(0 <= dst && dst < this->n);\n\
    \    assert(0 <= cap);\n    int e = this->adj[src].size();\n    int re = src ==\
    \ dst ? e + 1 : this->adj[dst].size();\n    return this->adj[src].push_back(Edge{dst,\
    \ re, cap}),\n           this->adj[dst].push_back(Edge{src, e, cap * bidir}),\
    \ this->m++,\n           EdgePtr{this, src, e, bidir};\n  }\n  flow_t maxflow(int\
    \ s, int t) {\n    return maxflow(s, t, std::numeric_limits<flow_t>::max());\n\
    \  }\n  flow_t maxflow(int s, int t, flow_t flow_lim) {\n    return this->flow(s,\
    \ t, flow_lim);\n  }\n  std::vector<bool> mincut(int s) {\n    std::vector<bool>\
    \ visited(this->n);\n    static std::queue<int> que;\n    for (que.push(s); !que.empty();)\
    \ {\n      s = que.front(), que.pop(), visited[s] = true;\n      for (const auto\
    \ &e : this->adj[s])\n        if (e.cap && !visited[e.dst]) visited[e.dst] = true,\
    \ que.push(e.dst);\n    }\n    return visited;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title \u6700\u5927\u6D41\
    \u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9\n * @category \u6700\u9069\u5316\
    \u554F\u984C\n * \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Dinic\u7B49)\u306Fclass\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u3067\u53D7\u3051\u53D6\u308B\n * EdgePtr:\n *\
    \  change_cap: \u5BB9\u91CF\u3092\u5909\u66F4, \u305D\u308C\u306B\u4F34\u3046\u30D5\
    \u30ED\u30FC\u306E\u306F\u307F\u51FA\u3057\u3092\u51FA\u529B\n * \u53CC\u65B9\u5411\
    \u8FBA\u3082\u53EF\n */\n\n// BEGIN CUT HERE\ntemplate <typename FlowAlgo>\nstruct\
    \ MaxFlow : public FlowAlgo {\n  using FlowAlgo::FlowAlgo;\n  using Edge = typename\
    \ FlowAlgo::Edge;\n  using flow_t = decltype(Edge::cap);\n  int add_vertex() {\
    \ return this->adj.resize(++this->n), this->n - 1; }\n  std::vector<int> add_vertices(const\
    \ std::size_t size) {\n    std::vector<int> ret(size);\n    std::iota(ret.begin(),\
    \ ret.end(), this->n);\n    return this->adj.resize(this->n += size), ret;\n \
    \ }\n  struct EdgePtr {\n    friend class MaxFlow;\n    MaxFlow *instance;\n \
    \   int v, e;\n    bool bidir;\n    Edge &edge() { return instance->adj[v][e];\
    \ }\n    Edge &rev() {\n      Edge &e = edge();\n      return instance->adj[e.dst][e.rev];\n\
    \    }\n    EdgePtr(MaxFlow *instance, int v, int e, bool d)\n        : instance(instance),\
    \ v(v), e(e), bidir(d) {}\n\n   public:\n    EdgePtr() = default;\n    int src()\
    \ { return v; }\n    int dst() { return edge().dst; }\n    bool is_direct() const\
    \ { return !bidir; }\n    flow_t flow() { return cap() - edge().cap; }\n    flow_t\
    \ cap() { return (edge().cap + rev().cap) / (1 + bidir); }\n    flow_t change_cap(flow_t\
    \ new_cap, int s, int t) {\n      assert(0 <= new_cap);\n      Edge &e = edge(),\
    \ &re = rev();\n      flow_t diff = new_cap - cap(), extrusion = std::abs(flow())\
    \ - new_cap;\n      if (extrusion <= 0) return e.cap += diff, re.cap += diff *\
    \ bidir, 0;\n      int sr = src(), ds = dst();\n      if (flow() < 0) std::swap(sr,\
    \ ds);\n      if (bidir) {\n        if (sr == src())\n          re.cap += 2 *\
    \ diff + e.cap, e.cap = 0;\n        else\n          e.cap += 2 * diff + re.cap,\
    \ re.cap = 0;\n      } else\n        re.cap += diff;\n      extrusion -= instance->maxflow(sr,\
    \ ds, extrusion);\n      if (ds != t) instance->maxflow(t, ds, extrusion);\n \
    \     if (sr != s) instance->maxflow(sr, s, extrusion);\n      return extrusion;\n\
    \    }\n  };\n  EdgePtr add_edge(int src, int dst, flow_t cap, bool bidir = false)\
    \ {\n    assert(0 <= src && src < this->n), assert(0 <= dst && dst < this->n);\n\
    \    assert(0 <= cap);\n    int e = this->adj[src].size();\n    int re = src ==\
    \ dst ? e + 1 : this->adj[dst].size();\n    return this->adj[src].push_back(Edge{dst,\
    \ re, cap}),\n           this->adj[dst].push_back(Edge{src, e, cap * bidir}),\
    \ this->m++,\n           EdgePtr{this, src, e, bidir};\n  }\n  flow_t maxflow(int\
    \ s, int t) {\n    return maxflow(s, t, std::numeric_limits<flow_t>::max());\n\
    \  }\n  flow_t maxflow(int s, int t, flow_t flow_lim) {\n    return this->flow(s,\
    \ t, flow_lim);\n  }\n  std::vector<bool> mincut(int s) {\n    std::vector<bool>\
    \ visited(this->n);\n    static std::queue<int> que;\n    for (que.push(s); !que.empty();)\
    \ {\n      s = que.front(), que.pop(), visited[s] = true;\n      for (const auto\
    \ &e : this->adj[s])\n        if (e.cap && !visited[e.dst]) visited[e.dst] = true,\
    \ que.push(e.dst);\n    }\n    return visited;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Optimization/MaxFlow.hpp
  requiredBy: []
  timestamp: '2022-11-18 19:29:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_6_A.Dinic.test.cpp
  - test/aoj/2803.PushRelabel.test.cpp
  - test/aoj/2313.Dinic.test.cpp
  - test/aoj/2835.PushRelabel.test.cpp
  - test/aoj/2803.Dinic.test.cpp
  - test/aoj/2835.Dinic.test.cpp
  - test/aoj/2313.PushRelabel.test.cpp
  - test/aoj/GRL_6_A.PushRelabel.test.cpp
  - test/yukicoder/119.Dinic.test.cpp
  - test/yukicoder/119.PushRelabel.test.cpp
  - test/atcoder/arc107_f.PushRelabel.test.cpp
  - test/atcoder/arc129_e.PushRelabel.test.cpp
  - test/atcoder/arc107_f.Dinic.test.cpp
  - test/atcoder/arc129_e.Dinic.test.cpp
documentation_of: src/Optimization/MaxFlow.hpp
layout: document
redirect_from:
- /library/src/Optimization/MaxFlow.hpp
- /library/src/Optimization/MaxFlow.hpp.html
title: "\u6700\u5927\u6D41\u30A4\u30F3\u30BF\u30FC\u30D5\u30A7\u30FC\u30B9"
---
