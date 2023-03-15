---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':heavy_check_mark:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/WeightedMatching.hpp
    title: "\u91CD\u307F\u4ED8\u304D\u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc080/tasks/arc080_d
  bundledCode: "#line 1 \"test/atcoder/arc080_d.WeightedMatching.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc080/tasks/arc080_d\"\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return\
    \ (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0),\
    \ x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class Uint, class\
    \ MP, u64... args> constexpr bool miller_rabin(Uint n) {\n const MP md(n);\n const\
    \ Uint s= __builtin_ctzll(n - 1), d= n >> s, one= md.set(1), n1= md.norm(md.set(n\
    \ - 1));\n for (auto a: {args...})\n  if (Uint b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b),\
    \ d, md)); p != one)\n    for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n\
    \     if (!(--i)) return 0;\n return 1;\n}\nconstexpr bool is_prime(u64 n) {\n\
    \ if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n if (n < (1 << 30)) return\
    \ miller_rabin<u32, MP_Mo<u32, u64, 32, 31>, 2, 7, 61>(n);\n if (n < (1ull <<\
    \ 62)) return miller_rabin<u64, MP_Mo<u64, u128, 64, 63>, 2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64, MP_D2B1, 2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing math_internal::is_prime;\n\
    #line 2 \"src/Optimization/WeightedMatching.hpp\"\n#include <limits>\n#include\
    \ <iterator>\n#line 5 \"src/Optimization/WeightedMatching.hpp\"\n#include <queue>\n\
    #include <algorithm>\ntemplate <class cost_t, bool min_perfect= false> class WeightedMatching\
    \ {\n static constexpr cost_t INF= std::numeric_limits<cost_t>::max() / 4;\n struct\
    \ E {\n  int16_t u, v;\n  cost_t w;\n };\n template <class T> struct Mat {\n \
    \ int n;\n  std::vector<T> dat;\n  Mat(int n): n(n), dat(n * n){};\n  auto operator[](int\
    \ i) { return std::next(dat.begin(), n * i); }\n  const auto operator[](int i)\
    \ const { return std::next(dat.cbegin(), n * i); }\n };\n cost_t mx;\n Mat<cost_t>\
    \ adj;\n std::vector<int16_t> mt;\n static inline int sgn(cost_t c) {\n  static\
    \ constexpr cost_t EPS= 1e-10;\n  return c < -EPS ? -1 : c > EPS ? 1 : 0;\n }\n\
    public:\n WeightedMatching(int n): mx(0), adj(n), mt(2 * n) {\n  if constexpr\
    \ (min_perfect)\n   for (int i= n; i--;)\n    for (int j= n; j--;) adj[i][j]=\
    \ INF;\n }\n void add_edge(int u, int v, cost_t w) {\n  mx= std::max(mx, w);\n\
    \  if constexpr (min_perfect) {\n   if (adj[u][v] > w) adj[u][v]= adj[v][u]= w;\n\
    \  } else if (adj[u][v] < w) adj[u][v]= adj[v][u]= w;\n }\n void build() {\n \
    \ const int n= mt.size() / 2;\n  int16_t rt[2 * n], used[2 * n], in= 0, m= n,\
    \ q[2 * n], slk[2 * n], par[2 * n], isS[2 * n];\n  Mat<int16_t> blg(2 * n);\n\
    \  std::fill_n(used, 2 * n, 0), std::fill_n(rt + n + 1, n - 1, 0), rt[0]= 0;\n\
    \  std::vector<std::vector<int16_t>> fwr(2 * n);\n  std::queue<int16_t> que;\n\
    \  std::vector<cost_t> dual(2 * n);\n  Mat<E> G(2 * n);\n  for (int16_t i= 0;\
    \ i <= n; ++i) G[i][0]= E{i, int16_t(0), 0};\n  for (int16_t j= 0; j <= n; ++j)\
    \ G[0][j]= E{int16_t(0), j, 0};\n  if constexpr (min_perfect)\n   for (int16_t\
    \ i= 1; i <= n; ++i)\n    for (int16_t j= 1; j <= n; ++j) G[i][j]= E{i, j, adj[i\
    \ - 1][j - 1] == INF ? 0 : (mx - adj[i - 1][j - 1] + 1) * 2};\n  else\n   for\
    \ (int16_t i= 1; i <= n; ++i)\n    for (int16_t j= 1; j <= n; ++j) G[i][j]= E{i,\
    \ j, adj[i - 1][j - 1] * 2};\n  cost_t inf= 0;\n  for (int16_t i= 1; i <= n; ++i)\n\
    \   for (int16_t j= 1; j <= n; ++j) inf= std::max(inf, G[i][j].w);\n  inf+= 1;\n\
    \  for (int i= 1; i <= n; i++) rt[i]= i, blg[i][i]= i, dual[i]= inf;\n  auto dist=\
    \ [&](const E &e) { return dual[e.u] - e.w + dual[e.v]; };\n  auto push= [&](int\
    \ v) {\n   q[0]= v;\n   for (int i= 0, s= 1; i < s; ++i) {\n    if (v= q[i]; v\
    \ > n)\n     for (int u: fwr[v]) q[s++]= u;\n    else que.push(v);\n   }\n  };\n\
    \  auto match= [&](auto self, int u, int v) -> void {\n   if (mt[u]= G[u][v].v;\
    \ u <= n) return;\n   int x= blg[u][G[u][v].u], p= std::find(fwr[u].begin(), fwr[u].end(),\
    \ x) - fwr[u].begin();\n   if (p & 1) std::reverse(fwr[u].begin() + 1, fwr[u].end()),\
    \ p= fwr[u].size() - p;\n   for (int i= 0; i < p; ++i) self(self, fwr[u][i], fwr[u][i\
    \ ^ 1]);\n   self(self, x, v), std::rotate(fwr[u].begin(), fwr[u].begin() + p,\
    \ fwr[u].end());\n  };\n  auto path= [&](const E &e) {\n   if (int u= rt[e.u],\
    \ v= rt[e.v], bu= u, bv= v, x; isS[v] == 1) {\n    for (++in; bu; bu= rt[mt[bu]]\
    \ ? rt[par[rt[mt[bu]]]] : 0) used[bu]= in;\n    for (int id= n + 1; bv; bv= rt[mt[bv]]\
    \ ? rt[par[rt[mt[bv]]]] : 0)\n     if (used[bv] == in) {\n      while (id <= m\
    \ && rt[id]) ++id;\n      for (int i= (m+= (id > m)); i; --i) G[id][i].w= G[i][id].w=\
    \ 0;\n      for (int i= n; --i;) blg[id][i]= 0;\n      mt[id]= mt[bv];\n     \
    \ for (fwr[id].clear(); u != bv; fwr[id].push_back(u), u= rt[par[u]]) fwr[id].push_back(u),\
    \ push(u= rt[mt[u]]);\n      fwr[id].push_back(bv), std::reverse(fwr[id].begin(),\
    \ fwr[id].end());\n      for (; v != bv; fwr[id].push_back(v), v= rt[par[v]])\
    \ fwr[id].push_back(v), push(v= rt[mt[v]]);\n      isS[id]= 1, dual[id]= 0, q[0]=\
    \ id;\n      for (int i= 0, s= 1; i < s; ++i)\n       if (rt[v= q[i]]= id; v >\
    \ n)\n        for (int t: fwr[v]) q[s++]= t;\n      for (int c: fwr[id]) {\n \
    \      for (int i= 1; i <= m; ++i)\n        if (sgn(G[id][i].w) == 0 || sgn(dist(G[c][i])\
    \ - dist(G[id][i])) < 0) G[id][i]= G[c][i], G[i][id]= G[i][c];\n       for (int\
    \ i= 1; i <= n; ++i)\n        if (blg[c][i]) blg[id][i]= c;\n      }\n      for\
    \ (int i= slk[id]= 0; i <= n; ++i)\n       if (sgn(G[i][id].w) != 0 && rt[i] !=\
    \ id && isS[rt[i]] == 1)\n        if (!slk[id] || sgn(dist(G[i][id]) - dist(G[slk[id]][id]))\
    \ < 0) slk[id]= i;\n      return false;\n     }\n    for (bu= u, bv= v;; match(match,\
    \ bv= x, bu= rt[par[x]]))\n     if (x= rt[mt[bu]], match(match, bu, bv); !x)\n\
    \      for (;; match(match, u= x, v= rt[par[x]]))\n       if (x= rt[mt[v]], match(match,\
    \ v, u); !x) return true;\n   } else if (!isS[v]) par[v]= e.u, isS[v]= 2, slk[v]=\
    \ slk[x= rt[mt[v]]]= 0, isS[x]= 1, push(x);\n   return false;\n  };\n LABEL_AUGMENT:\n\
    \  std::fill_n(isS, 2 * n, 0), std::fill_n(slk, 2 * n, 0), std::fill_n(par, 2\
    \ * n, 0), que= std::queue<int16_t>();\n  for (int i= 1; i <= m; i++)\n   if (rt[i]\
    \ == i && !mt[i]) isS[i]= 1, push(i);\n  if (que.empty()) return;\n  for (cost_t\
    \ del= inf;; del= inf) {\n   for (int v, i; !que.empty();)\n    for (v= que.front(),\
    \ que.pop(), i= 1; i <= n; ++i)\n     if (sgn(G[v][i].w) != 0 && rt[i] != rt[v])\
    \ {\n      if (sgn(dist(G[v][i])) == 0) {\n       if (path(G[v][i])) goto LABEL_AUGMENT;\n\
    \      } else if (isS[rt[i]] != 2)\n       if (!slk[rt[i]] || sgn(dist(G[v][rt[i]])\
    \ - dist(G[slk[rt[i]]][rt[i]])) < 0) slk[rt[i]]= v;\n     }\n   for (int i= n\
    \ + 1; i <= m; ++i)\n    if (rt[i] == i && isS[i] == 2 && sgn(del - dual[i] /\
    \ 2) > 0) del= dual[i] / 2;\n   for (int i= 1; i <= m; ++i)\n    if (rt[i] ==\
    \ i && slk[i] && isS[i] != 2)\n     if (cost_t c= dist(G[slk[i]][i]) / (1 + isS[i]);\
    \ sgn(del - c) > 0) del= c;\n   for (int i= 1; i <= n; ++i) {\n    if (isS[rt[i]]\
    \ == 1) {\n     if (sgn(dual[i]-= del) <= 0) return;\n    } else if (isS[rt[i]]\
    \ == 2) dual[i]+= del;\n   }\n   for (int i= n + 1; i <= m; ++i)\n    if (rt[i]\
    \ == i && isS[i]) dual[i]+= isS[i] == 1 ? 2 * del : -2 * del;\n   for (int i=\
    \ 1; i <= m; ++i)\n    if (rt[i] == i && slk[i] && rt[slk[i]] != i && sgn(dist(G[slk[i]][i]))\
    \ == 0)\n     if (path(G[slk[i]][i])) goto LABEL_AUGMENT;\n   for (int b= n +\
    \ 1, x, p, T, S; b <= m; b++)\n    if (rt[b] == b && isS[b] == 2 && sgn(dual[b])\
    \ == 0) {\n     isS[x= blg[b][G[b][par[b]].u]]= 2, par[x]= par[b];\n     for (int\
    \ c: fwr[b]) {\n      q[0]= c;\n      for (int i= 0, s= 1, v; i < s; ++i)\n  \
    \     if (rt[v= q[i]]= c; v > n)\n        for (int u: fwr[v]) q[s++]= u;\n   \
    \  }\n     p= std::find(fwr[b].begin(), fwr[b].end(), x) - fwr[b].begin(), x=\
    \ fwr[b].size();\n     if (p & 1) std::reverse(fwr[b].begin() + 1, fwr[b].end()),\
    \ p= fwr[b].size() - p;\n     for (int i= 0; i < p; i+= 2) isS[S= fwr[b][i + 1]]=\
    \ 1, isS[T= fwr[b][i]]= 2, par[T]= G[S][T].u, slk[S]= slk[T]= 0, push(S);\n  \
    \   for (int i= p + 1, j; i < x; ++i)\n      for (T= fwr[b][i], j= isS[T]= slk[T]=\
    \ 0; j <= n; ++j)\n       if (sgn(G[j][T].w) != 0 && rt[j] != T && isS[rt[j]]\
    \ == 1)\n        if (!slk[T] || sgn(dist(G[j][T]) - dist(G[slk[T]][T])) < 0) slk[T]=\
    \ j;\n     fwr[b].clear(), rt[b]= 0;\n    }\n  }\n  goto LABEL_AUGMENT;\n }\n\
    \ int match(int v) const { return mt[v + 1] - 1; }\n std::vector<E> weight_matching()\
    \ const {\n  const int n= mt.size() / 2;\n  std::vector<E> ret;\n  if constexpr\
    \ (min_perfect) {\n   if (n & 1) return {};  // no solution\n   for (int16_t i=\
    \ 0; i < n; ++i)\n    if (int16_t j= match(i); i < j) ret.push_back(E{i, j, adj[i][j]});\n\
    \   if (2 * int(ret.size()) != n) return {};  // no solution\n  } else\n   for\
    \ (int16_t i= 0; i < n; ++i)\n    if (int16_t j= match(i); i < j) ret.push_back(E{i,\
    \ j, adj[i][j]});\n  return ret;\n }\n};\n#line 6 \"test/atcoder/arc080_d.WeightedMatching.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n int x[N];\n for (int i= 0; i < N; ++i) cin >> x[i];\n vector<int>\
    \ vs= {x[0]};\n for (int i= 1; i < N; ++i)\n  if (x[i] - x[i - 1] > 1) vs.push_back(x[i\
    \ - 1] + 1), vs.push_back(x[i]);\n vs.push_back(x[N - 1] + 1);\n int m= vs.size();\n\
    \ WeightedMatching<long long, true> graph(m);\n for (int i= m; --i;)\n  for (int\
    \ j= i; j--;) {\n   int k= vs[i] - vs[j];\n   graph.add_edge(i, j, k & 1 ? is_prime(k)\
    \ ? 1 : 3 : 2);\n  }\n graph.build();\n long long ans= 0;\n for (auto [u, v, w]:\
    \ graph.weight_matching()) ans+= w;\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc080/tasks/arc080_d\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Math/is_prime.hpp\"\n#include\
    \ \"src/Optimization/WeightedMatching.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n int x[N];\n\
    \ for (int i= 0; i < N; ++i) cin >> x[i];\n vector<int> vs= {x[0]};\n for (int\
    \ i= 1; i < N; ++i)\n  if (x[i] - x[i - 1] > 1) vs.push_back(x[i - 1] + 1), vs.push_back(x[i]);\n\
    \ vs.push_back(x[N - 1] + 1);\n int m= vs.size();\n WeightedMatching<long long,\
    \ true> graph(m);\n for (int i= m; --i;)\n  for (int j= i; j--;) {\n   int k=\
    \ vs[i] - vs[j];\n   graph.add_edge(i, j, k & 1 ? is_prime(k) ? 1 : 3 : 2);\n\
    \  }\n graph.build();\n long long ans= 0;\n for (auto [u, v, w]: graph.weight_matching())\
    \ ans+= w;\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/is_prime.hpp
  - src/Internal/Remainder.hpp
  - src/Optimization/WeightedMatching.hpp
  isVerificationFile: false
  path: test/atcoder/arc080_d.WeightedMatching.cpp
  requiredBy: []
  timestamp: '2023-03-16 02:01:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/arc080_d.WeightedMatching.cpp
layout: document
redirect_from:
- /library/test/atcoder/arc080_d.WeightedMatching.cpp
- /library/test/atcoder/arc080_d.WeightedMatching.cpp.html
title: test/atcoder/arc080_d.WeightedMatching.cpp
---
