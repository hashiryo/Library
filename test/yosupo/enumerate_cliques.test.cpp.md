---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/CliqueProblem.hpp
    title: "\u30AF\u30EA\u30FC\u30AF\u554F\u984C"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"test/yosupo/enumerate_cliques.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n#include <iostream>\n\
    #line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n#include <cassert>\n\
    template <class Int> constexpr inline Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n\
    \ Int x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y=\
    \ z - y * (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod\
    \ - (-x) % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE\
    \ constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n\
    \ return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+=\
    \ r; l >= M) l-= M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U\
    \ diff(U l, U r) const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n\
    \ }\n#define SGN(U) \\\n static CE IL U set(U n) { return n; } \\\n static CE\
    \ IL U get(U n) { return n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate\
    \ <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo():\
    \ mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod)\
    \ % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l) * r);\
    \ }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const\
    \ { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n\
    \ }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE\
    \ u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n))\
    \ : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod -\
    \ ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na():\
    \ mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const {\
    \ return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\n\
    struct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n\
    \ CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s) + m\
    \ - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64\
    \ quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const\
    \ { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64\
    \ mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) <<\
    \ 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n\
    \ PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n)\
    \ { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n)\
    \ const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const { return\
    \ (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) *\
    \ mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1(): s(0),\
    \ mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m), d(m\
    \ << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate\
    \ <class mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 2 \"src/Graph/CliqueProblem.hpp\"\n#include <vector>\n\
    #include <algorithm>\nclass CliqueProblem {\n using u128= __uint128_t;\n using\
    \ u64= uint64_t;\n using u16= uint16_t;\n const u16 n, m;\n struct id_num {\n\
    \  u16 id, num;\n };\n std::vector<u128> adj_;\n std::vector<u16> calc(bool complement)\
    \ const {\n  std::vector<u128> buf, adj(adj_);\n  std::vector<u16> deg(n), clique,\
    \ cur;\n  if (complement)\n   for (int u= n; u--;)\n    for (int v= u; v--;) adj[u\
    \ * m + (v >> 7)]^= u128(1) << (v & 127), adj[v * m + (u >> 7)]^= u128(1) << (u\
    \ & 127);\n  auto dfs= [&](auto dfs, std::vector<id_num> &rem) -> void {\n   if\
    \ (clique.size() < cur.size()) clique= cur;\n   std::sort(rem.begin(), rem.end(),\
    \ [&](id_num l, id_num r) { return deg[l.id] > deg[r.id]; }), buf.assign((n +\
    \ 1) * m, 0);\n   for (auto &v: rem) {\n    int b= v.id * m, bb= 0;\n    for (v.num=\
    \ 0;; ++v.num, bb+= m) {\n     bool any= 1;\n     for (u16 i= 0; i < m; ++i) any&=\
    \ !(adj[b + i] & buf[bb + i]);\n     if (any) break;\n    }\n    buf[bb + (v.id\
    \ >> 7)]|= u128(1) << (v.id & 127);\n   }\n   std::sort(rem.begin(), rem.end(),\
    \ [&](id_num l, id_num r) { return l.num < r.num; });\n   std::vector<id_num>\
    \ nrem;\n   for (nrem.reserve(rem.size()); !rem.empty();) {\n    auto p= rem.back();\n\
    \    if (p.num + cur.size() < clique.size()) break;\n    nrem.clear();\n    auto\
    \ a= adj.cbegin() + p.id * m;\n    for (auto u: rem)\n     if ((a[u.id >> 7] >>\
    \ (u.id & 127)) & 1) nrem.emplace_back(u);\n    std::fill_n(buf.begin(), m, 0);\n\
    \    for (auto u: nrem) buf[u.id >> 7]|= u128(1) << (u.id & 127);\n    for (auto\
    \ u: nrem) {\n     int b= u.id * m, i= 0, cnt= 0;\n     for (u128 tmp; i < m;\
    \ ++i) tmp= buf[i] & adj[b + i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \     deg[u.id]= cnt;\n    }\n    cur.push_back(p.id), dfs(dfs, nrem), cur.pop_back(),\
    \ rem.pop_back();\n   }\n  };\n  std::vector<id_num> nrem;\n  for (u16 u= n, cnt;\
    \ u--; nrem.push_back(id_num{u, 0}), deg[u]= cnt) {\n   int b= u * m, i= cnt=\
    \ 0;\n   for (u128 tmp; i < m; ++i) tmp= adj[b + i], cnt+= __builtin_popcountll(tmp\
    \ >> 64) + __builtin_popcountll(u64(tmp));\n  }\n  return dfs(dfs, nrem), clique;\n\
    \ }\npublic:\n CliqueProblem(int n): n(n), m((n + 127) >> 7), adj_(n * m) {}\n\
    \ void add_edge(int u, int v) { adj_[u * m + (v >> 7)]|= u128(1) << (v & 127),\
    \ adj_[v * m + (u >> 7)]|= u128(1) << (u & 127); }\n std::vector<u16> get_max_clique()\
    \ const { return calc(false); }\n std::vector<u16> get_max_independent_set() const\
    \ { return calc(true); }\n std::vector<u16> get_min_vertex_cover() const {\n \
    \ std::vector<u128> buf(m);\n  for (u16 u: calc(true)) buf[u >> 7]|= u128(1) <<\
    \ (u & 127);\n  std::vector<u16> ret;\n  for (u16 i= 0; i < n; ++i)\n   if (!((buf[i\
    \ >> 7] >> (i & 127)) & 1)) ret.push_back(i);\n  return ret;\n }\n template <class\
    \ F> void enumerate_cliques(const F &out) const {\n  std::vector<u128> buf;\n\
    \  std::vector<u16> deg(n), clique, nbd;\n  for (u16 u= n, cnt; u--; deg[u]= cnt)\
    \ {\n   int b= u * m, i= cnt= 0;\n   for (u128 tmp; i < m; ++i) tmp= adj_[b +\
    \ i], cnt+= __builtin_popcountll(tmp >> 64) + __builtin_popcountll(u64(tmp));\n\
    \  }\n  u16 nn;\n  auto dfs= [&](auto dfs, u16 k) -> void {\n   out(clique);\n\
    \   for (u16 i= k; i < nn; ++i) {\n    u16 v= nbd[i];\n    auto b= adj_.cbegin()\
    \ + v * m;\n    bool all= 1;\n    for (u16 j= 0; j < m; ++j) all&= (b[j] & buf[j])\
    \ == buf[j];\n    if (all) clique.push_back(v), buf[v >> 7]|= u128(1) << (v &\
    \ 127), dfs(dfs, i + 1), clique.pop_back(), buf[v >> 7]^= u128(1) << (v & 127);\n\
    \   }\n  };\n  bool unused[n];\n  std::fill_n(unused, n, 1);\n  for (u16 _= n;\
    \ _--;) {\n   u16 v, min_d= n;\n   for (u16 i= n; i--;)\n    if (unused[i] &&\
    \ min_d > deg[i]) v= i, min_d= deg[i];\n   nbd.clear(), clique= {v}, buf.assign(m,\
    \ 0), buf[v >> 7]|= u128(1) << (v & 127);\n   auto a= adj_.cbegin() + v * m;\n\
    \   for (int i= 0; i < n; ++i)\n    if ((a[i >> 7] >> (i & 127)) & unused[i])\
    \ nbd.push_back(i);\n   nn= nbd.size(), dfs(dfs, 0), unused[v]= 0;\n   for (auto\
    \ u: nbd) --deg[u];\n  }\n }\n};\n#line 5 \"test/yosupo/enumerate_cliques.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N, M;\n cin >> N >> M;\n vector<Mint> x(N);\n\
    \ for (int i= 0; i < N; ++i) cin >> x[i];\n CliqueProblem graph(N);\n while (M--)\
    \ {\n  int u, v;\n  cin >> u >> v;\n  graph.add_edge(u, v);\n }\n Mint ans= 0;\n\
    \ graph.enumerate_cliques([&](const auto& clique) {\n  Mint prod= 1;\n  for (auto\
    \ i: clique) prod*= x[i];\n  ans+= prod;\n });\n cout << ans << '\\n';\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n#include\
    \ <iostream>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Graph/CliqueProblem.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N, M;\n cin >> N >> M;\n vector<Mint> x(N);\n\
    \ for (int i= 0; i < N; ++i) cin >> x[i];\n CliqueProblem graph(N);\n while (M--)\
    \ {\n  int u, v;\n  cin >> u >> v;\n  graph.add_edge(u, v);\n }\n Mint ans= 0;\n\
    \ graph.enumerate_cliques([&](const auto& clique) {\n  Mint prod= 1;\n  for (auto\
    \ i: clique) prod*= x[i];\n  ans+= prod;\n });\n cout << ans << '\\n';\n return\
    \ 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/Graph/CliqueProblem.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '2023-08-03 20:58:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_cliques.test.cpp
- /verify/test/yosupo/enumerate_cliques.test.cpp.html
title: test/yosupo/enumerate_cliques.test.cpp
---
