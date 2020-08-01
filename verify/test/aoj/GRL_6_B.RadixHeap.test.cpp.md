---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/aoj/GRL_6_B.RadixHeap.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.RadixHeap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-01 13:12:01+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B</a>


## Depends on

* :x: <a href="../../../library/DataStructure/RadixHeap.hpp.html">Radix-Heap</a>
* :x: <a href="../../../library/Graph/MinCostFlow.hpp.html">最小費用流</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Graph/MinCostFlow.hpp"
#include "DataStructure/RadixHeap.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V, E, F;
  cin >> V >> E >> F;
  MinCostFlow<int, int, RadixHeap<int, int>> graph;
  graph.add_vertices(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph.add_edge(u, v, 0, c, d);
  }
  auto ans = graph.st_flow_run(0, V - 1, F);
  cout << (ans.second ? ans.first : -1) << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_B.RadixHeap.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Graph/MinCostFlow.hpp"
/**
 * @title 最小費用流
 * @category グラフ
 * @brief PrimalDual(容量スケーリング)
 * @brief O(m^2 log U log n)
 * @see https://misawa.github.io/others/flow/library_design.html
 */
// verify用:
// https://codeforces.com/contest/316/problem/C2
// (Radix-HeapでないとTLEした -> 容量スケーリングならTLEしない)
// https://atcoder.jp/contests/geocon2013/tasks/geocon2013_b (コスト実数)

#ifndef call_from_test
#line 15 "Graph/MinCostFlow.hpp"
using namespace std;
#endif

template <class flow_t, class cost_t,
          typename Heap = priority_queue<pair<cost_t, int>,
                                         vector<pair<cost_t, int>>, greater<>>,
          int obj = 1>
class MinCostFlow {
  class Edge {
    friend class MinCostFlow;
    int dst;
    flow_t flow, cap;
    cost_t cost;
    int rev;

   public:
    Edge() = default;
    Edge(const int dst, const flow_t cap, const cost_t cost, const int rev)
        : dst(dst), flow(0), cap(cap), cost(cost), rev(rev) {}
    flow_t residual_cap() const { return cap - flow; }
  };

 public:
  class EdgePtr {
    friend class MinCostFlow;
    const MinCostFlow *instance;
    int v;
    int e;
    EdgePtr(const MinCostFlow *const instance, const int v, const int e)
        : instance(instance), v(v), e(e) {}
    const Edge &edge() const { return instance->adj[v][e]; }
    const Edge &rev() const {
      const Edge &e = edge();
      return instance->adj[e.dst][e.rev];
    }

   public:
    EdgePtr() = default;
    int src() const { return v; }
    int dst() const { return edge().dst; }
    flow_t flow() const { return edge().flow; }
    flow_t lower() const { return -rev().cap; }
    flow_t upper() const { return edge().cap; }
    cost_t cost() const { return edge().cost; }
    cost_t gain() const { return -edge().cost; }
  };

 private:
  int n;
  vector<vector<Edge>> adj;
  vector<flow_t> b;

 public:
  MinCostFlow() : n(0) {}
  int add_vertex() {
    ++n;
    adj.resize(n);
    b.resize(n);
    return n - 1;
  }
  vector<int> add_vertices(const int size) {
    vector<int> ret(size);
    iota(begin(ret), end(ret), n);
    n += size;
    adj.resize(n);
    b.resize(n);
    return ret;
  }
  EdgePtr add_edge(const int src, const int dst, const flow_t lower,
                   const flow_t upper, const cost_t cost) {
    const int e = adj[src].size(), re = src == dst ? e + 1 : adj[dst].size();
    assert(lower <= upper);
    adj[src].emplace_back(Edge{dst, upper, cost * obj, re});
    adj[dst].emplace_back(Edge{src, -lower, -cost * obj, e});
    return EdgePtr{this, src, e};
  }
  void add_supply(const int v, const flow_t amount) { b[v] += amount; }
  void add_demand(const int v, const flow_t amount) { b[v] -= amount; }

 private:
  const cost_t UNREACHABLE = numeric_limits<cost_t>::max();
  const cost_t EPS = 1e-7;
  cost_t farthest;
  vector<cost_t> potential;
  vector<cost_t> dist;
  vector<int> excess_vs, deficit_vs;
  vector<int> prev;
  Heap pq;
  Edge &rev(const Edge &e) { return adj[e.dst][e.rev]; }
  void push(Edge &e, const flow_t amount) {
    e.flow += amount;
    adj[e.dst][e.rev].flow -= amount;
  }
  cost_t residual_cost_t(const int src, const int dst, const Edge &e) {
    return e.cost + potential[src] - potential[dst];
  }
  bool dual(const flow_t delta) {
    dist.assign(n, UNREACHABLE);
    prev.assign(n, -1);
    excess_vs.erase(remove_if(begin(excess_vs), end(excess_vs),
                              [&](const int v) { return b[v] < delta; }),
                    end(excess_vs));
    deficit_vs.erase(remove_if(begin(deficit_vs), end(deficit_vs),
                               [&](const int v) { return b[v] > -delta; }),
                     end(deficit_vs));
    for (const auto v : excess_vs) pq.emplace(dist[v] = 0, v);
    farthest = 0;
    int deficit_count = 0;
    while (!pq.empty()) {
      cost_t d;
      int u;
      tie(d, u) = pq.top();
      pq.pop();
      if (dist[u] - d + EPS < 0) continue;
      farthest = d;
      if (b[u] <= -delta) ++deficit_count;
      if (deficit_count >= deficit_vs.size()) break;
      for (auto &e : adj[u]) {
        if (e.residual_cap() < delta) continue;
        const auto v = e.dst;
        const auto new_dist = d + residual_cost_t(u, v, e);
        if (new_dist - dist[v] + EPS >= 0) continue;
        pq.emplace(dist[v] = new_dist, v);
        prev[v] = e.rev;
      }
    }
    pq = decltype(pq)();
    for (int v = 0; v < n; ++v) potential[v] += min(dist[v], farthest);
    return deficit_count > 0;
  }
  void primal(const flow_t delta) {
    for (const auto t : deficit_vs) {
      if (dist[t] - farthest - EPS > 0) continue;
      flow_t f = -b[t];
      int v;
      for (v = t; prev[v] != -1;) {
        Edge &r = adj[v][prev[v]], &e = adj[r.dst][r.rev];
        f = min(f, e.residual_cap());
        v = r.dst;
      }
      f = min(f, b[v]);
      f -= f % delta;
      if (f <= 0) continue;
      for (v = t; prev[v] != -1;) {
        Edge &r = adj[v][prev[v]], &e = adj[r.dst][r.rev];
        push(e, f);
        if (e.residual_cap() <= 0) prev[v] = -1;
        v = r.dst;
      }
      b[t] += f;
      b[v] -= f;
    }
  }
  void saturate_negative(const flow_t delta) {
    excess_vs.clear();
    deficit_vs.clear();
    for (auto &es : adj)
      for (auto &e : es) {
        flow_t rcap = e.residual_cap();
        rcap -= rcap % delta;
        int src = adj[e.dst][e.rev].dst, dst = e.dst;
        const cost_t rcost_t = residual_cost_t(src, dst, e);
        if (rcost_t + EPS < 0 || rcap < 0) {
          push(e, rcap);
          b[src] -= rcap;
          b[dst] += rcap;
        }
      }
    for (int v = 0; v < n; ++v)
      if (b[v] != 0) (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);
  }

 public:
  pair<bool, cost_t> flow_run() {
    potential.resize(n);
    flow_t inf_flow = 1;
    for (const auto t : b) inf_flow = max({inf_flow, t, -t});
    for (const auto &es : adj)
      for (const auto &e : es)
        inf_flow = max({inf_flow, e.residual_cap(), -e.residual_cap()});
    flow_t delta = 1;
    while (delta < inf_flow) delta *= 2;
    for (; delta; delta /= 2) {
      saturate_negative(delta);
      while (dual(delta)) primal(delta);
    }
    cost_t value = 0;
    for (const auto &es : adj)
      for (const auto &e : es) value += e.flow * e.cost;
    value /= 2;
    if (excess_vs.empty() && deficit_vs.empty()) {
      return {true, value / obj};
    } else {
      return {false, value / obj};
    }
  }
  pair<bool, cost_t> st_flow_run(const int s, const int t, flow_t flow) {
    add_supply(s, flow);
    add_demand(t, flow);
    return flow_run();
  }
  tuple<bool, cost_t, flow_t> max_flow_run(const int s, const int t) {
    assert(s != t);
    flow_t inf_flow = abs(b[s]);
    for (const auto &e : adj[s]) inf_flow += max(e.cap, static_cast<flow_t>(0));
    add_edge(t, s, 0, inf_flow, 0);
    bool status;
    cost_t circulation_value;
    tie(status, circulation_value) = flow_run();
    if (!status) {
      adj[s].pop_back();
      adj[t].pop_back();
      return {status, circulation_value, 0};
    }
    inf_flow = abs(b[s]);
    for (const auto &e : adj[s]) inf_flow += e.residual_cap();
    b[s] += inf_flow;
    b[t] -= inf_flow;
    bool mf_status;
    cost_t mf_value;
    tie(mf_status, mf_value) = flow_run();
    b[s] -= inf_flow;
    b[t] += inf_flow;
    adj[s].pop_back();
    adj[t].pop_back();
    return {true, mf_value, b[t]};
  }
  vector<cost_t> get_potential() {
    fill(begin(potential), end(potential), 0);
    for (int i = 0; i < n; ++i)
      for (const auto &es : adj)
        for (const auto &e : es)
          if (e.residual_cap() > 0)
            potential[e.dst] = min(potential[e.dst],
                                   potential[adj[e.dst][e.rev].dst] + e.cost);
    return potential;
  }
};

template <class flow_t, class cost_t,
          typename Heap = priority_queue<pair<cost_t, int>,
                                         vector<pair<cost_t, int>>, greater<>>>
using MaxGainFlow = MinCostFlow<flow_t, cost_t, Heap, -1>;
#line 1 "DataStructure/RadixHeap.hpp"
/**
 * @title Radix-Heap
 * @category データ構造
 * @brief dijkstraの高速化に使用
 * @brief 浮動小数点数も使える
 * @brief 小さい順
 * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md
 */

#ifndef call_from_test
#line 12 "DataStructure/RadixHeap.hpp"
using namespace std;
#endif

// verify用:
// https://codeforces.com/contest/316/problem/C2
// (Radix-HeapでないとTLEした -> 容量スケーリングならTLEしない)

namespace internal {
template <bool Is64bit>
class find_bucket_impl;
template <>
class find_bucket_impl<false> {
 public:
  static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
    return x == last ? 0 : 32 - __builtin_clz(x ^ last);
  }
};
template <>
class find_bucket_impl<true> {
 public:
  static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
    return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
  }
};
template <typename T>
inline constexpr size_t find_bucket(T x, T last) {
  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
}
template <typename key_t, bool IsSigned>
class encoder_impl_integer;
template <typename key_t>
class encoder_impl_integer<key_t, false> {
 public:
  using ukey_t = key_t;
  inline static constexpr ukey_t encode(key_t x) { return x; }
  inline static constexpr key_t decode(ukey_t x) { return x; }
};
template <typename key_t>
class encoder_impl_integer<key_t, true> {
 public:
  typedef typename make_unsigned<key_t>::type ukey_t;
  inline static constexpr ukey_t encode(key_t x) {
    return static_cast<ukey_t>(x)
           ^ (ukey_t(1) << ukey_t(numeric_limits<ukey_t>::digits - 1));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return static_cast<key_t>(
        x ^ (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
};
template <typename key_t, typename ukey_t>
class encoder_impl_decimal {
 public:
  inline static constexpr ukey_t encode(key_t x) {
    return raw_cast<key_t, ukey_t>(x)
           ^ ((-(raw_cast<key_t, ukey_t>(x)
                 >> (numeric_limits<ukey_t>::digits - 1)))
              | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return raw_cast<ukey_t, key_t>(
        x
        ^ (((x >> (numeric_limits<ukey_t>::digits - 1)) - 1)
           | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1))));
  }

 private:
  template <typename T, typename U>
  union raw_cast {
   public:
    constexpr raw_cast(T t) : t_(t) {}
    operator U() const { return u_; }

   private:
    T t_;
    U u_;
  };
};
template <typename key_t>
class encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value> {};
template <>
class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
template <>
class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
}  // namespace internal

template <typename key_t, typename val_t,
          typename encoder_t = internal::encoder<key_t>>
class RadixHeap {
 public:
  typedef typename encoder_t::ukey_t ukey_t;

  RadixHeap() : size_(0), last_(), buckets_() {
    buckets_min_.fill(numeric_limits<ukey_t>::max());
  }

  void push(key_t key, val_t value) {
    const ukey_t x = encoder_t::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x, value);
    buckets_min_[k] = min(buckets_min_[k], x);
  }
  void emplace(key_t key, val_t value) { push(key, value); }
  pair<key_t, val_t> top() {
    pull();
    return make_pair(encoder_t::decode(last_), buckets_[0].back().second);
  }
  pair<key_t, val_t> pop() {
    pull();
    --size_;
    auto ret = make_pair(encoder_t::decode(last_), buckets_[0].back().second);
    buckets_[0].pop_back();
    return ret;
  }
  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

 private:
  size_t size_;
  ukey_t last_;
  array<vector<pair<ukey_t, val_t>>, numeric_limits<ukey_t>::digits + 1>
      buckets_;
  array<ukey_t, numeric_limits<ukey_t>::digits + 1> buckets_min_;

  void pull() {
    assert(size_ > 0);
    if (!buckets_[0].empty()) return;
    size_t i = 1;
    while (buckets_[i].empty()) ++i;
    last_ = buckets_min_[i];
    for (size_t j = 0; j < buckets_[i].size(); ++j) {
      const ukey_t x = buckets_[i][j].first;
      const size_t k = internal::find_bucket(x, last_);
      buckets_[k].emplace_back(move(buckets_[i][j]));
      buckets_min_[k] = min(buckets_min_[k], x);
    }
    buckets_[i].clear();
    buckets_min_[i] = numeric_limits<ukey_t>::max();
  }
};
#line 10 "test/aoj/GRL_6_B.RadixHeap.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V, E, F;
  cin >> V >> E >> F;
  MinCostFlow<int, int, RadixHeap<int, int>> graph;
  graph.add_vertices(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph.add_edge(u, v, 0, c, d);
  }
  auto ans = graph.st_flow_run(0, V - 1, F);
  cout << (ans.second ? ans.first : -1) << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

