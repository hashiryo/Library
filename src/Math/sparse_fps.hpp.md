---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc222_h.sparse_FPS.test.cpp
    title: test/atcoder/abc222_h.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc276_g.sparse_FPS.test.cpp
    title: test/atcoder/abc276_g.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_sparse_FPS.test.cpp
    title: test/yosupo/exp_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_sparse_FPS.test.cpp
    title: test/yosupo/inv_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_sparse_FPS.test.cpp
    title: test/yosupo/log_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_sparse_FPS.test.cpp
    title: test/yosupo/pow_of_sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.sparse_FPS.test.cpp
    title: test/yukicoder/1080.sparse_FPS.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
    - https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0-%E9%AB%98%E9%80%9F%E3%81%AB%E8%A8%88%E7%AE%97%E3%81%A7%E3%81%8D%E3%82%8B%E3%82%82%E3%81%AE
  bundledCode: "#line 2 \"src/Math/sparse_fps.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class Int>\nconstexpr\
    \ inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 4 \"src/Math/ModInt.hpp\"\
    \n/**\n * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\n\
    namespace modint_internal {\nusing namespace std;\nstruct modint_base {};\nstruct\
    \ sta_mint_base : modint_base {};\nstruct run_mint_base : modint_base {};\ntemplate\
    \ <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base, mod_t>;\n\
    template <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    return mod_inv<typename\
    \ D::Int>(((D *)this)->val(), D::mod);\n  }\n  constexpr D sqrt() const {\n  \
    \  if (((D *)this)->val() <= 1 || D::mod == 2) return *(D *)this;\n    u64 e =\
    \ (D::mod - 1) >> 1;\n    D b = 0, d = -(*this), ret = 1, r2 = 0, b2 = 1;\n  \
    \  if (this->pow(e) != 1) return 0;  // no solution\n    while (d.pow(e) == 1)\
    \ d += b * 2 + 1, b += 1;\n    auto mult = [d](D &u1, D &u2, D v1, D v2) {\n \
    \     D tmp = u1 * v1 + u2 * v2 * d;\n      u2 = u1 * v2 + u2 * v1, u1 = tmp;\n\
    \    };\n    for (++e;; mult(b, b2, b, b2)) {\n      if (e & 1) mult(ret, r2,\
    \ b, b2);\n      if (!(e >>= 1)) return ret.val() <= D::mod / 2 ? ret : -ret;\n\
    \    }\n  }\n  constexpr bool operator<(const D &r) const {\n    return ((D *)this)->val()\
    \ < r.val();\n  }  // for set or map\n  friend ostream &operator<<(ostream &os,\
    \ const D &r) { return os << r.val(); }\n  friend istream &operator>>(istream\
    \ &is, D &r) {\n    long long v;\n    return is >> v, r = D(v), is;\n  }\n};\n\
    template <class B>\nstruct ModInt_Na : public B, public ModIntImpl<ModInt_Na<B>>\
    \ {\n  using Int = typename B::Int;\n  using DUint = conditional_t<is_same_v<typename\
    \ B::Uint, uint32_t>, u64, u128>;\n  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr\
    \ ModInt_Na() = default;\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t>\
    \ = nullptr>\n  constexpr ModInt_Na(T n) : ModInt_Na(n.val()) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod - ((-n) % B::mod) : n % B::mod)\
    \ {}\n#define ASSIGN(m, p) return x m## = B::mod & -((x p## = r.x) >= B::mod),\
    \ *this\n  constexpr ModInt_Na &operator+=(const ModInt_Na &r) { ASSIGN(-, +);\
    \ }\n  constexpr ModInt_Na &operator-=(const ModInt_Na &r) { ASSIGN(+, -); }\n\
    #undef ASSIGN\n  constexpr ModInt_Na &operator*=(const ModInt_Na &r) {\n    return\
    \ x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr bool operator==(const\
    \ ModInt_Na &r) const { return x == r.x; }\n  constexpr auto val() const { return\
    \ x; }\n  constexpr auto norm() const { return x; }\n\n private:\n  typename B::Uint\
    \ x = 0;\n};\ntemplate <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Int = int64_t;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    \  template <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op##\
    \ = a, x += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const\
    \ mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const\
    \ mod_t &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const\
    \ {\n    u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n  constexpr inline u64 norm() const { return x - (B::mod & -(x >= B::mod));\
    \ }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n    return\
    \ u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n  static\
    \ constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r); }\n  u64\
    \ x = 0;\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n  return e\
    \ ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\nstruct StaticB_Na\
    \ : sta_mint_base {\n protected:\n  using Int = conditional_t < MOD < INT_MAX,\
    \ int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n  using\
    \ Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct RuntimeB_Na : run_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct RuntimeB_Mon : run_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<RuntimeB_Mon<id>>,\n\
    \                  ModInt_Na<RuntimeB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::RuntimeModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_runtimemodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 4 \"src/Math/sparse_fps.hpp\"\n\
    /**\n * @title \u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @category\
    \ \u6570\u5B66\n * @see\n * https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0-%E9%AB%98%E9%80%9F%E3%81%AB%E8%A8%88%E7%AE%97%E3%81%A7%E3%81%8D%E3%82%8B%E3%82%82%E3%81%AE\n\
    \ */\n\n// verify\u7528:\n// https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\n\
    \n// BEGIN CUT HERE\ntemplate <class K>\nstd::vector<K> sparse_inv(const std::vector<K>\
    \ &f, int n) {\n  assert(f[0] != K(0));\n  std::vector<std::pair<int, K>> dat;\n\
    \  for (int i = 1, ed = std::min<int>(n, f.size()); i < ed; i++)\n    if (f[i]\
    \ != K(0)) dat.emplace_back(i, f[i]);\n  std::vector<K> ret(n);\n  const K iv\
    \ = ret[0] = K(1) / f[0];\n  for (int i = 1; i < n; ret[i++] *= iv)\n    for (auto\
    \ &&[j, v] : dat) {\n      if (i < j) break;\n      ret[i] -= ret[i - j] * v;\n\
    \    }\n  return ret;\n}\n\ntemplate <class K>\nstd::vector<K> sparse_div(std::vector<K>\
    \ f, const std::vector<K> &g, int n) {\n  assert(g[0] != K(0));\n  std::vector<std::pair<int,\
    \ K>> dat;\n  for (int i = 1, ed = std::min<int>(n, g.size()); i < ed; i++)\n\
    \    if (g[i] != K(0)) dat.emplace_back(i, g[i]);\n  f.resize(n);\n  const K iv\
    \ = K(1) / g[0];\n  for (int i = 0; i < n; f[i++] *= iv)\n    for (auto &&[j,\
    \ v] : dat) {\n      if (i < j) break;\n      f[i] -= f[i - j] * v;\n    }\n \
    \ return f;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\nstd::vector<mod_t>\
    \ sparse_log(const std::vector<mod_t> &f, int n) {\n  assert(f[0] == mod_t(1));\n\
    \  std::vector<mod_t> df(n - 1);\n  for (int i = 1, ed = std::min<int>(n, f.size());\
    \ i < ed; i++)\n    df[i - 1] += f[i] * i;\n  df = sparse_div(df, f, n - 1);\n\
    \  std::vector<mod_t> ret(n);\n  for (int i = 1; i < n; i++) ret[i] = df[i - 1]\
    \ * get_inv<mod_t, _Nm>(i);\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 24>\nstd::vector<mod_t> sparse_exp(const std::vector<mod_t> &f, int\
    \ n) {\n  assert(f[0] == mod_t(0));\n  std::vector<std::pair<int, mod_t>> dat;\n\
    \  for (int i = 1, ed = std::min<int>(n, f.size()); i < ed; i++)\n    if (f[i]\
    \ != mod_t(0)) dat.emplace_back(i - 1, f[i] * i);\n  std::vector<mod_t> ret(n);\n\
    \  ret[0] = 1;\n  for (int i = 1; i < n; ret[i] *= get_inv<mod_t, _Nm>(i), i++)\n\
    \    for (auto &&[j, v] : dat) {\n      if (i <= j) break;\n      ret[i] += ret[i\
    \ - 1 - j] * v;\n    }\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 24>\nstd::vector<mod_t> sparse_pow(const std::vector<mod_t> &f, std::uint64_t\
    \ k,\n                              int n) {\n  std::vector<mod_t> ret(n);\n \
    \ if (k == 0) return ret[0] = 1, ret;\n  int cnt = 0, ed = std::min<int>(n, f.size());\n\
    \  while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n  const __int128_t ofs = (__int128_t)k\
    \ * cnt, sz = n - ofs;\n  if (sz <= 0) return ret;\n  std::vector<std::pair<int,\
    \ mod_t>> dat;\n  for (int i = cnt + 1; i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat.emplace_back(i - cnt, f[i]);\n  mod_t *bf = ret.data() + k * cnt, mk = k,\
    \ iv = mod_t(1) / f[cnt];\n  bf[0] = f[cnt].pow(k);\n  for (int i = 1; i < sz;\
    \ bf[i] *= get_inv<mod_t, _Nm>(i) * iv, i++)\n    for (auto &&[j, v] : dat) {\n\
    \      if (i < j) break;\n      bf[i] += v * (mk * j - (i - j)) * bf[i - j];\n\
    \    }\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\n\
    std::vector<mod_t> sparse_sqrt(const std::vector<mod_t> &f, int n) {\n  std::vector<mod_t>\
    \ ret(n);\n  int cnt = 0, ed = std::min<int>(n, f.size());\n  while (cnt < ed\
    \ && f[cnt] == mod_t(0)) cnt++;\n  if (cnt == ed) return ret;\n  if (cnt & 1)\
    \ return {};  // no solution\n  const int ofs = cnt >> 1, sz = n - ofs;\n  std::vector<std::pair<int,\
    \ mod_t>> dat;\n  for (int i = cnt + 1; i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat.emplace_back(i - cnt, f[i]);\n  mod_t *bf = ret.data() + ofs, mk = mod_t(1)\
    \ / 2, iv = mod_t(1) / f[cnt];\n  bf[0] = f[cnt].sqrt();\n  if (bf[0] * bf[0]\
    \ != f[cnt]) return {};  // no solution\n  for (int i = 1; i < sz; bf[i] *= get_inv<mod_t,\
    \ _Nm>(i) * iv, i++)\n    for (auto &&[j, v] : dat) {\n      if (i < j) break;\n\
    \      bf[i] += v * (mk * j - (i - j)) * bf[i - j];\n    }\n  return ret;\n}\n\
    \n// F'/F = f(x)/g(x), F[0]=1\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\n\
    std::vector<mod_t> sparse_log_differentiation(const std::vector<mod_t> &f,\n \
    \                                             const std::vector<mod_t> &g,\n \
    \                                             int n) {\n  assert(g[0] == mod_t(1));\n\
    \  std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n  for (int i = 0, ed = std::min<int>(f.size(),\
    \ n); i < ed; i++)\n    if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n \
    \ for (int i = 1, ed = std::min<int>(g.size(), n); i < ed; i++)\n    if (g[i]\
    \ != mod_t(0)) dat_g.emplace_back(i, g[i]);\n  std::vector<mod_t> ret(n), d(n\
    \ - 1);\n  ret[0] = 1;\n  for (int i = 0; i < n - 1; i++) {\n    for (auto &&[j,\
    \ v] : dat_g) {\n      if (i < j) break;\n      d[i] -= v * d[i - j];\n    }\n\
    \    for (auto &&[j, v] : dat_f) {\n      if (i < j) break;\n      d[i] += v *\
    \ ret[i - j];\n    }\n    ret[i + 1] = d[i] * get_inv<mod_t, _Nm>(i + 1);\n  }\n\
    \  return ret;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>  // exp(f/g)\n\
    std::vector<mod_t> sparse_exp_of_div(const std::vector<mod_t> &f,\n          \
    \                           const std::vector<mod_t> &g, int n) {\n  assert(f[0]\
    \ == mod_t(0)), assert(g[0] == mod_t(1));\n  std::vector<std::pair<int, mod_t>>\
    \ dat_f, dat_g;\n  for (int i = 1, ed = std::min<int>(f.size(), n); i < ed; i++)\n\
    \    if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n  for (int i = 0, ed\
    \ = std::min<int>(g.size(), n); i < ed; i++)\n    if (g[i] != mod_t(0)) dat_g.emplace_back(i,\
    \ g[i]);\n  std::vector<mod_t> a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n\
    \  for (auto &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) a[i + j - 1] +=\
    \ x * y * (i - j);\n  for (auto &&[i, x] : dat_g)\n    for (auto &&[j, y] : dat_g)\
    \ b[i + j] += x * y;  // a = f'g-fg', b = g^2\n  return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>  // (f/g)^k\n\
    std::vector<mod_t> sparse_pow_of_div(const std::vector<mod_t> &f,\n          \
    \                           const std::vector<mod_t> &g,\n                   \
    \                  std::uint64_t k, int n) {\n  assert(f[0] == mod_t(1)), assert(g[0]\
    \ == mod_t(1));\n  std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n  for (int\
    \ i = 0, ed = std::min<int>(f.size(), n); i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat_f.emplace_back(i, f[i]);\n  for (int i = 0, ed = std::min<int>(g.size(),\
    \ n); i < ed; i++)\n    if (g[i] != mod_t(0)) dat_g.emplace_back(i, g[i]);\n \
    \ std::vector<mod_t> a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n  for (auto\
    \ &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) a[i + j - 1] += x * y * (i\
    \ - j) * k;\n  for (auto &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) b[i\
    \ + j] += x * y;  // a = k(f'g-fg'), b = fg\n  return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n\
    /**\n * @title \u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n * @category\
    \ \u6570\u5B66\n * @see\n * https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0-%E9%AB%98%E9%80%9F%E3%81%AB%E8%A8%88%E7%AE%97%E3%81%A7%E3%81%8D%E3%82%8B%E3%82%82%E3%81%AE\n\
    \ */\n\n// verify\u7528:\n// https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\n\
    \n// BEGIN CUT HERE\ntemplate <class K>\nstd::vector<K> sparse_inv(const std::vector<K>\
    \ &f, int n) {\n  assert(f[0] != K(0));\n  std::vector<std::pair<int, K>> dat;\n\
    \  for (int i = 1, ed = std::min<int>(n, f.size()); i < ed; i++)\n    if (f[i]\
    \ != K(0)) dat.emplace_back(i, f[i]);\n  std::vector<K> ret(n);\n  const K iv\
    \ = ret[0] = K(1) / f[0];\n  for (int i = 1; i < n; ret[i++] *= iv)\n    for (auto\
    \ &&[j, v] : dat) {\n      if (i < j) break;\n      ret[i] -= ret[i - j] * v;\n\
    \    }\n  return ret;\n}\n\ntemplate <class K>\nstd::vector<K> sparse_div(std::vector<K>\
    \ f, const std::vector<K> &g, int n) {\n  assert(g[0] != K(0));\n  std::vector<std::pair<int,\
    \ K>> dat;\n  for (int i = 1, ed = std::min<int>(n, g.size()); i < ed; i++)\n\
    \    if (g[i] != K(0)) dat.emplace_back(i, g[i]);\n  f.resize(n);\n  const K iv\
    \ = K(1) / g[0];\n  for (int i = 0; i < n; f[i++] *= iv)\n    for (auto &&[j,\
    \ v] : dat) {\n      if (i < j) break;\n      f[i] -= f[i - j] * v;\n    }\n \
    \ return f;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\nstd::vector<mod_t>\
    \ sparse_log(const std::vector<mod_t> &f, int n) {\n  assert(f[0] == mod_t(1));\n\
    \  std::vector<mod_t> df(n - 1);\n  for (int i = 1, ed = std::min<int>(n, f.size());\
    \ i < ed; i++)\n    df[i - 1] += f[i] * i;\n  df = sparse_div(df, f, n - 1);\n\
    \  std::vector<mod_t> ret(n);\n  for (int i = 1; i < n; i++) ret[i] = df[i - 1]\
    \ * get_inv<mod_t, _Nm>(i);\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 24>\nstd::vector<mod_t> sparse_exp(const std::vector<mod_t> &f, int\
    \ n) {\n  assert(f[0] == mod_t(0));\n  std::vector<std::pair<int, mod_t>> dat;\n\
    \  for (int i = 1, ed = std::min<int>(n, f.size()); i < ed; i++)\n    if (f[i]\
    \ != mod_t(0)) dat.emplace_back(i - 1, f[i] * i);\n  std::vector<mod_t> ret(n);\n\
    \  ret[0] = 1;\n  for (int i = 1; i < n; ret[i] *= get_inv<mod_t, _Nm>(i), i++)\n\
    \    for (auto &&[j, v] : dat) {\n      if (i <= j) break;\n      ret[i] += ret[i\
    \ - 1 - j] * v;\n    }\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t\
    \ _Nm = 1 << 24>\nstd::vector<mod_t> sparse_pow(const std::vector<mod_t> &f, std::uint64_t\
    \ k,\n                              int n) {\n  std::vector<mod_t> ret(n);\n \
    \ if (k == 0) return ret[0] = 1, ret;\n  int cnt = 0, ed = std::min<int>(n, f.size());\n\
    \  while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n  const __int128_t ofs = (__int128_t)k\
    \ * cnt, sz = n - ofs;\n  if (sz <= 0) return ret;\n  std::vector<std::pair<int,\
    \ mod_t>> dat;\n  for (int i = cnt + 1; i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat.emplace_back(i - cnt, f[i]);\n  mod_t *bf = ret.data() + k * cnt, mk = k,\
    \ iv = mod_t(1) / f[cnt];\n  bf[0] = f[cnt].pow(k);\n  for (int i = 1; i < sz;\
    \ bf[i] *= get_inv<mod_t, _Nm>(i) * iv, i++)\n    for (auto &&[j, v] : dat) {\n\
    \      if (i < j) break;\n      bf[i] += v * (mk * j - (i - j)) * bf[i - j];\n\
    \    }\n  return ret;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\n\
    std::vector<mod_t> sparse_sqrt(const std::vector<mod_t> &f, int n) {\n  std::vector<mod_t>\
    \ ret(n);\n  int cnt = 0, ed = std::min<int>(n, f.size());\n  while (cnt < ed\
    \ && f[cnt] == mod_t(0)) cnt++;\n  if (cnt == ed) return ret;\n  if (cnt & 1)\
    \ return {};  // no solution\n  const int ofs = cnt >> 1, sz = n - ofs;\n  std::vector<std::pair<int,\
    \ mod_t>> dat;\n  for (int i = cnt + 1; i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat.emplace_back(i - cnt, f[i]);\n  mod_t *bf = ret.data() + ofs, mk = mod_t(1)\
    \ / 2, iv = mod_t(1) / f[cnt];\n  bf[0] = f[cnt].sqrt();\n  if (bf[0] * bf[0]\
    \ != f[cnt]) return {};  // no solution\n  for (int i = 1; i < sz; bf[i] *= get_inv<mod_t,\
    \ _Nm>(i) * iv, i++)\n    for (auto &&[j, v] : dat) {\n      if (i < j) break;\n\
    \      bf[i] += v * (mk * j - (i - j)) * bf[i - j];\n    }\n  return ret;\n}\n\
    \n// F'/F = f(x)/g(x), F[0]=1\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>\n\
    std::vector<mod_t> sparse_log_differentiation(const std::vector<mod_t> &f,\n \
    \                                             const std::vector<mod_t> &g,\n \
    \                                             int n) {\n  assert(g[0] == mod_t(1));\n\
    \  std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n  for (int i = 0, ed = std::min<int>(f.size(),\
    \ n); i < ed; i++)\n    if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n \
    \ for (int i = 1, ed = std::min<int>(g.size(), n); i < ed; i++)\n    if (g[i]\
    \ != mod_t(0)) dat_g.emplace_back(i, g[i]);\n  std::vector<mod_t> ret(n), d(n\
    \ - 1);\n  ret[0] = 1;\n  for (int i = 0; i < n - 1; i++) {\n    for (auto &&[j,\
    \ v] : dat_g) {\n      if (i < j) break;\n      d[i] -= v * d[i - j];\n    }\n\
    \    for (auto &&[j, v] : dat_f) {\n      if (i < j) break;\n      d[i] += v *\
    \ ret[i - j];\n    }\n    ret[i + 1] = d[i] * get_inv<mod_t, _Nm>(i + 1);\n  }\n\
    \  return ret;\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>  // exp(f/g)\n\
    std::vector<mod_t> sparse_exp_of_div(const std::vector<mod_t> &f,\n          \
    \                           const std::vector<mod_t> &g, int n) {\n  assert(f[0]\
    \ == mod_t(0)), assert(g[0] == mod_t(1));\n  std::vector<std::pair<int, mod_t>>\
    \ dat_f, dat_g;\n  for (int i = 1, ed = std::min<int>(f.size(), n); i < ed; i++)\n\
    \    if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n  for (int i = 0, ed\
    \ = std::min<int>(g.size(), n); i < ed; i++)\n    if (g[i] != mod_t(0)) dat_g.emplace_back(i,\
    \ g[i]);\n  std::vector<mod_t> a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n\
    \  for (auto &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) a[i + j - 1] +=\
    \ x * y * (i - j);\n  for (auto &&[i, x] : dat_g)\n    for (auto &&[j, y] : dat_g)\
    \ b[i + j] += x * y;  // a = f'g-fg', b = g^2\n  return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}\n\ntemplate <class mod_t, std::size_t _Nm = 1 << 24>  // (f/g)^k\n\
    std::vector<mod_t> sparse_pow_of_div(const std::vector<mod_t> &f,\n          \
    \                           const std::vector<mod_t> &g,\n                   \
    \                  std::uint64_t k, int n) {\n  assert(f[0] == mod_t(1)), assert(g[0]\
    \ == mod_t(1));\n  std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n  for (int\
    \ i = 0, ed = std::min<int>(f.size(), n); i < ed; i++)\n    if (f[i] != mod_t(0))\
    \ dat_f.emplace_back(i, f[i]);\n  for (int i = 0, ed = std::min<int>(g.size(),\
    \ n); i < ed; i++)\n    if (g[i] != mod_t(0)) dat_g.emplace_back(i, g[i]);\n \
    \ std::vector<mod_t> a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n  for (auto\
    \ &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) a[i + j - 1] += x * y * (i\
    \ - j) * k;\n  for (auto &&[i, x] : dat_f)\n    for (auto &&[j, y] : dat_g) b[i\
    \ + j] += x * y;  // a = k(f'g-fg'), b = fg\n  return sparse_log_differentiation<mod_t,\
    \ _Nm>(a, b, n);\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  isVerificationFile: false
  path: src/Math/sparse_fps.hpp
  requiredBy: []
  timestamp: '2022-11-14 09:47:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1533.test.cpp
  - test/yukicoder/1080.sparse_FPS.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/atcoder/abc222_h.sparse_FPS.test.cpp
  - test/atcoder/abc276_g.sparse_FPS.test.cpp
  - test/yosupo/inv_of_sparse_FPS.test.cpp
  - test/yosupo/exp_of_sparse_FPS.test.cpp
  - test/yosupo/log_of_sparse_FPS.test.cpp
  - test/yosupo/pow_of_sparse_FPS.test.cpp
documentation_of: src/Math/sparse_fps.hpp
layout: document
redirect_from:
- /library/src/Math/sparse_fps.hpp
- /library/src/Math/sparse_fps.hpp.html
title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
