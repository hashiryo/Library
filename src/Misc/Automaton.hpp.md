---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0570.test.cpp
    title: test/aoj/0570.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2587.test.cpp
    title: test/aoj/2587.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc117_d.test.cpp
    title: test/atcoder/abc117_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc121_d.test.cpp
    title: test/atcoder/abc121_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc129_e.test.cpp
    title: test/atcoder/abc129_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc135_d.test.cpp
    title: test/atcoder/abc135_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc138_f.test.cpp
    title: test/atcoder/abc138_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc154_e.test.cpp
    title: test/atcoder/abc154_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc155_e.test.cpp
    title: test/atcoder/abc155_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc208_e.test.cpp
    title: test/atcoder/abc208_e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc235_f.test.cpp
    title: test/atcoder/abc235_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc015_d.test.cpp
    title: test/atcoder/agc015_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/agc021_a.test.cpp
    title: test/atcoder/agc021_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc127_a.test.cpp
    title: test/atcoder/arc127_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1106.test.cpp
    title: test/yukicoder/1106.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1417.test.cpp
    title: test/yukicoder/1417.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1740.test.cpp
    title: test/yukicoder/1740.test.cpp
  - icon: ':x:'
    path: test/yukicoder/315.test.cpp
    title: test/yukicoder/315.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/362.test.cpp
    title: test/yukicoder/362.test.cpp
  - icon: ':x:'
    path: test/yukicoder/685.test.cpp
    title: test/yukicoder/685.test.cpp
  - icon: ':x:'
    path: test/yukicoder/737.test.cpp
    title: test/yukicoder/737.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/911.test.cpp
    title: test/yukicoder/911.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Misc/Automaton.hpp\"\n#include <type_traits>\n#include\
    \ <set>\n#include <map>\n#include <unordered_map>\n#include <vector>\n#include\
    \ <algorithm>\n#include <queue>\n#include <cstdlib>\n#include <cassert>\ntemplate\
    \ <class symbol_t> class Automaton {\n std::vector<int> table;\n std::vector<int8_t>\
    \ info;\n std::vector<symbol_t> alph;\n const int m;\n template <class Map, class\
    \ state_t, class F, class G, class H> void build(const state_t &initial_state,\
    \ const F &transition, const G &is_accept, const H &abs_reject) {\n  static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<G, state_t>>);\n  static_assert(std::is_same_v<bool, std::invoke_result_t<H,\
    \ state_t>>);\n  Map encode;\n  std::vector<state_t> decode;\n  int ts= 0;\n \
    \ decode.push_back(initial_state), encode.emplace(initial_state, ts++);\n  for\
    \ (int i= 0, k= 0; i < ts; ++i) {\n   auto s= decode[i];\n   table.resize(table.size()\
    \ + m);\n   for (int j= 0; j < m; ++j) {\n    if (auto t= transition(s, j); abs_reject(t))\
    \ table[k++]= -1;\n    else if (auto it= encode.find(t); it != encode.end()) table[k++]=\
    \ it->second;\n    else table[k++]= ts, decode.push_back(t), encode.emplace(t,\
    \ ts++);\n   }\n  }\n  info.resize(ts);\n  for (int i= ts; i--;) info[i]= is_accept(decode[i]);\n\
    \ }\n Automaton(const std::vector<symbol_t> &alphabet): alph(alphabet), m(alph.size())\
    \ {}\npublic:\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  std::sort(alph.begin(),\
    \ alph.end());\n  auto tr= [&](const state_t &s, int i) { return transition(s,\
    \ alph[i]); };\n  auto rej= [](const state_t &) { return false; };\n  if constexpr\
    \ (std::is_integral_v<state_t>) build<std::unordered_map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n  else build<std::map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const state_t &abs_rej_state): alph(alphabet), m(alph.size())\
    \ {\n  std::sort(alph.begin(), alph.end());\n  auto tr= [&](const state_t &s,\
    \ int i) { return transition(s, alph[i]); };\n  auto rej= [abs_rej_state](const\
    \ state_t &s) { return s == abs_rej_state; };\n  if constexpr (std::is_integral_v<state_t>)\
    \ build<std::unordered_map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n  else build<std::map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<G, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n\
    \   for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return ret;\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(std::set<state_t>({initial_state}), tr, ac, rej);\n\
    \ }\n template <class state_t, class F, class G, class H, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const H &eps_trans): alph(alphabet), m(alph.size()) {\n\
    \  static_assert(std::is_same_v<bool, std::invoke_result_t<G, state_t>>);\n  static_assert(std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<H, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto eps_closure= [&](std::set<state_t> s) {\n   for (std::set<state_t> t;\
    \ s != t;) {\n    t= s;\n    for (const auto &x: t) {\n     auto ys= eps_trans(x);\n\
    \     s.insert(ys.begin(), ys.end());\n    }\n   }\n   return s;\n  };\n  auto\
    \ tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n  \
    \ for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return eps_closure(ret);\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(eps_closure({initial_state}), tr, ac, rej);\n }\n Automaton\
    \ operator&(const Automaton &r) const {\n  assert(alph == r.alph);\n  const int\
    \ S= info.size();\n  auto tr= [&](int s, int q) {\n   auto [s1, s0]= std::div(s,\
    \ S);\n   int t1= r.table[s1 * m + q], t0= table[s0 * m + q];\n   return t0 ==\
    \ -1 || t1 == -1 ? -1 : t1 * S + t0;\n  };\n  auto ac= [&](int s) {\n   auto [s1,\
    \ s0]= std::div(s, S);\n   return info[s0] == 1 && r.info[s1] == 1;\n  };\n  auto\
    \ rej= [](int s) { return s == -1; };\n  Automaton ret(alph);\n  return ret.build<std::unordered_map<int,\
    \ int>, int>(0, tr, ac, rej), ret;\n }\n template <class T, class A, class F>\
    \ T dp_run(int n, const A &op, const T &ti, const F &f, const T &init) const {\n\
    \  static_assert(std::is_same_v<T, std::invoke_result_t<A, T, T>>);\n  static_assert(std::is_same_v<T,\
    \ std::invoke_result_t<F, T, symbol_t, int>>);\n  const size_t S= info.size();\n\
    \  std::queue<std::pair<int, int>> que;\n  T dp[2][S], ret= ti;\n  bool in[2][S];\n\
    \  for (std::fill_n(dp[0], S, ti), std::fill_n(dp[1], S, ti), std::fill_n(in[0],\
    \ S, 0), std::fill_n(in[1], S, 0), dp[0][0]= init, que.emplace(0, 0), in[0][0]=\
    \ 1; que.size();) {\n   auto [s, i]= que.front();\n   bool b= i & 1;\n   T tmp=\
    \ dp[b][s];\n   if (que.pop(), in[b][s]= 0, dp[b][s]= ti; i == n) {\n    if (info[s]\
    \ == 1) ret= op(ret, tmp);\n    continue;\n   }\n   auto l= table.cbegin() + s\
    \ * m;\n   for (int j= m; j--;)\n    if (int t= l[j]; t != -1)\n     if (dp[!b][t]=\
    \ op(dp[!b][t], f(tmp, alph[j], i)); !in[!b][t]) que.emplace(t, i + 1), in[!b][t]=\
    \ 1;\n  }\n  return ret;\n }\n template <class T> T num(int n) const {\n  return\
    \ dp_run(\n      n, [](const T &l, const T &r) { return l + r; }, T(), [](const\
    \ T &x, const auto &, auto) { return x; }, T(1));\n }\n};\n"
  code: "#pragma once\n#include <type_traits>\n#include <set>\n#include <map>\n#include\
    \ <unordered_map>\n#include <vector>\n#include <algorithm>\n#include <queue>\n\
    #include <cstdlib>\n#include <cassert>\ntemplate <class symbol_t> class Automaton\
    \ {\n std::vector<int> table;\n std::vector<int8_t> info;\n std::vector<symbol_t>\
    \ alph;\n const int m;\n template <class Map, class state_t, class F, class G,\
    \ class H> void build(const state_t &initial_state, const F &transition, const\
    \ G &is_accept, const H &abs_reject) {\n  static_assert(std::is_same_v<bool, std::invoke_result_t<G,\
    \ state_t>>);\n  static_assert(std::is_same_v<bool, std::invoke_result_t<H, state_t>>);\n\
    \  Map encode;\n  std::vector<state_t> decode;\n  int ts= 0;\n  decode.push_back(initial_state),\
    \ encode.emplace(initial_state, ts++);\n  for (int i= 0, k= 0; i < ts; ++i) {\n\
    \   auto s= decode[i];\n   table.resize(table.size() + m);\n   for (int j= 0;\
    \ j < m; ++j) {\n    if (auto t= transition(s, j); abs_reject(t)) table[k++]=\
    \ -1;\n    else if (auto it= encode.find(t); it != encode.end()) table[k++]= it->second;\n\
    \    else table[k++]= ts, decode.push_back(t), encode.emplace(t, ts++);\n   }\n\
    \  }\n  info.resize(ts);\n  for (int i= ts; i--;) info[i]= is_accept(decode[i]);\n\
    \ }\n Automaton(const std::vector<symbol_t> &alphabet): alph(alphabet), m(alph.size())\
    \ {}\npublic:\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  std::sort(alph.begin(),\
    \ alph.end());\n  auto tr= [&](const state_t &s, int i) { return transition(s,\
    \ alph[i]); };\n  auto rej= [](const state_t &) { return false; };\n  if constexpr\
    \ (std::is_integral_v<state_t>) build<std::unordered_map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n  else build<std::map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const state_t &abs_rej_state): alph(alphabet), m(alph.size())\
    \ {\n  std::sort(alph.begin(), alph.end());\n  auto tr= [&](const state_t &s,\
    \ int i) { return transition(s, alph[i]); };\n  auto rej= [abs_rej_state](const\
    \ state_t &s) { return s == abs_rej_state; };\n  if constexpr (std::is_integral_v<state_t>)\
    \ build<std::unordered_map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n  else build<std::map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<G, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n\
    \   for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return ret;\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(std::set<state_t>({initial_state}), tr, ac, rej);\n\
    \ }\n template <class state_t, class F, class G, class H, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const H &eps_trans): alph(alphabet), m(alph.size()) {\n\
    \  static_assert(std::is_same_v<bool, std::invoke_result_t<G, state_t>>);\n  static_assert(std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<H, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto eps_closure= [&](std::set<state_t> s) {\n   for (std::set<state_t> t;\
    \ s != t;) {\n    t= s;\n    for (const auto &x: t) {\n     auto ys= eps_trans(x);\n\
    \     s.insert(ys.begin(), ys.end());\n    }\n   }\n   return s;\n  };\n  auto\
    \ tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n  \
    \ for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return eps_closure(ret);\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(eps_closure({initial_state}), tr, ac, rej);\n }\n Automaton\
    \ operator&(const Automaton &r) const {\n  assert(alph == r.alph);\n  const int\
    \ S= info.size();\n  auto tr= [&](int s, int q) {\n   auto [s1, s0]= std::div(s,\
    \ S);\n   int t1= r.table[s1 * m + q], t0= table[s0 * m + q];\n   return t0 ==\
    \ -1 || t1 == -1 ? -1 : t1 * S + t0;\n  };\n  auto ac= [&](int s) {\n   auto [s1,\
    \ s0]= std::div(s, S);\n   return info[s0] == 1 && r.info[s1] == 1;\n  };\n  auto\
    \ rej= [](int s) { return s == -1; };\n  Automaton ret(alph);\n  return ret.build<std::unordered_map<int,\
    \ int>, int>(0, tr, ac, rej), ret;\n }\n template <class T, class A, class F>\
    \ T dp_run(int n, const A &op, const T &ti, const F &f, const T &init) const {\n\
    \  static_assert(std::is_same_v<T, std::invoke_result_t<A, T, T>>);\n  static_assert(std::is_same_v<T,\
    \ std::invoke_result_t<F, T, symbol_t, int>>);\n  const size_t S= info.size();\n\
    \  std::queue<std::pair<int, int>> que;\n  T dp[2][S], ret= ti;\n  bool in[2][S];\n\
    \  for (std::fill_n(dp[0], S, ti), std::fill_n(dp[1], S, ti), std::fill_n(in[0],\
    \ S, 0), std::fill_n(in[1], S, 0), dp[0][0]= init, que.emplace(0, 0), in[0][0]=\
    \ 1; que.size();) {\n   auto [s, i]= que.front();\n   bool b= i & 1;\n   T tmp=\
    \ dp[b][s];\n   if (que.pop(), in[b][s]= 0, dp[b][s]= ti; i == n) {\n    if (info[s]\
    \ == 1) ret= op(ret, tmp);\n    continue;\n   }\n   auto l= table.cbegin() + s\
    \ * m;\n   for (int j= m; j--;)\n    if (int t= l[j]; t != -1)\n     if (dp[!b][t]=\
    \ op(dp[!b][t], f(tmp, alph[j], i)); !in[!b][t]) que.emplace(t, i + 1), in[!b][t]=\
    \ 1;\n  }\n  return ret;\n }\n template <class T> T num(int n) const {\n  return\
    \ dp_run(\n      n, [](const T &l, const T &r) { return l + r; }, T(), [](const\
    \ T &x, const auto &, auto) { return x; }, T(1));\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Misc/Automaton.hpp
  requiredBy: []
  timestamp: '2023-04-11 14:48:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1106.test.cpp
  - test/yukicoder/1417.test.cpp
  - test/yukicoder/685.test.cpp
  - test/yukicoder/362.test.cpp
  - test/yukicoder/1740.test.cpp
  - test/yukicoder/911.test.cpp
  - test/yukicoder/315.test.cpp
  - test/yukicoder/737.test.cpp
  - test/atcoder/abc117_d.test.cpp
  - test/atcoder/arc127_a.test.cpp
  - test/atcoder/agc015_d.test.cpp
  - test/atcoder/abc138_f.test.cpp
  - test/atcoder/abc121_d.test.cpp
  - test/atcoder/abc135_d.test.cpp
  - test/atcoder/abc129_e.test.cpp
  - test/atcoder/abc155_e.test.cpp
  - test/atcoder/abc154_e.test.cpp
  - test/atcoder/abc235_f.test.cpp
  - test/atcoder/agc021_a.test.cpp
  - test/atcoder/abc208_e.test.cpp
  - test/aoj/0570.test.cpp
  - test/aoj/2587.test.cpp
documentation_of: src/Misc/Automaton.hpp
layout: document
title: "\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
---

桁DPを解く. DPの最終的な答えのみを求める仕様なので、DPテーブルの途中の値は手に入らない.

## メンバ関数

| 名前                                                                                                                                              | 概要                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1. `Automaton(alp,init,tr,ac)` <br> 2. `Automaton(alp,init,tr,ac,rej)` <br> 3. `Automaton(alp,init,tr,ac)`<br> 4. `Automaton(alp,init,tr,ac,eps)` | コンストラクタ. <br>4種類共通: `alp`はアルファベット(std::vector&lt;symbol_t&gt;), `init` は初期状態(state_t), `ac` は受理状態か判定する関数(state_t $\rightarrow$ bool) . <br> 1. `tr` は決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ state_t). <br> 2. `tr` は決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ state_t), `rej` は絶対この先受理状態に行くことのない状態 (state_t). <br> 3. `tr` は非決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ std::set&lt;symbol_t&gt;). <br> 4. `tr` は非決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ std::set&lt;symbol_t&gt;), `eps` はイプシロン遷移を表す関数 (state_t  $\rightarrow$ std::set&lt;symbol_t&gt;). |
| `operator&`                                                                                                                                       | 二項演算. 2つのオートマトンの積を表すオートマトンを返す                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `dp_run<T>(n,op,ti,f,init)`                                                                                                                       | オートマトンが受理する長さ n の文字列に対し、与えた関数に従ってDPを計算させて値を返す. <br> T はモノイドで `op` はその二項演算 (T $\times$ T $\rightarrow$ T), `ti` は単位元 . <br> `init`  は dp[初期状態][0文字目]の値. (※イメージ) <br> `f` は dpの遷移を表す関数 ( T $\times$ symbol_t $\times$ (i文字目) $\rightarrow$ T ).  モノイドに対して分配法則が成り立つ必要あり(遅延セグ木の作用素みたいなこと)                                                                                                                                                                                                                                                                                               |
| `num<T>(n)`                                                                                                                                       | オートマトンが受理する長さ n の文字列の個数を返す.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |

## 参考
[https://kuretchi.github.io/blog/entries/automaton-dp/](https://kuretchi.github.io/blog/entries/automaton-dp/)\
[https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836](https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836)\
[https://qiita.com/ryuhe1/items/185e1a283f13ac638a53](https://qiita.com/ryuhe1/items/185e1a283f13ac638a53)\
[https://blog.knshnb.com/posts/aoj2587/](https://blog.knshnb.com/posts/aoj2587/)
## 問題例
[Educational DP Contest S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)\
[Typical DP Contest E - 数](https://atcoder.jp/contests/tdpc/tasks/tdpc_number) \
[AtCoder Beginner Contest 007 D - 禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4) \
[AtCoder Beginner Contest 029 D - 1](https://atcoder.jp/contests/abc029/tasks/abc029_d) \
[AtCoder Beginner Contest 050 D - Xor Sum](https://atcoder.jp/contests/abc050/tasks/arc066_b) (ナイーブにNFA) \
[Donuts プロコンチャレンジ2014 B - 7th](https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2) \
[CODE FESTIVAL 2014 予選A D - 壊れた電卓](https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d) \
[いろはちゃんコンテスト Day1 H - ちらし寿司](https://atcoder.jp/contests/iroha2019-day1/tasks/iroha2019_day1_h) \
[yukicoder No.1953 ８](https://yukicoder.me/problems/no/1953) (sp judge)
