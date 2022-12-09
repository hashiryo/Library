---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/DirichletConvSumTable.hpp
    title: "\u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
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
    PROBLEM: https://atcoder.jp/contests/arc116/tasks/arc116_c
    links:
    - https://atcoder.jp/contests/arc116/tasks/arc116_c
  bundledCode: "#line 1 \"test/atcoder/arc116_c.dujiao.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc116/tasks/arc116_c\"\n\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\n/**\n * @title \u9006\u5143 ($\\mathbb{Z}/m\\\
    mathbb{Z}$)\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\ntemplate <class\
    \ Int>\nconstexpr inline Int mod_inv(Int a, Int mod) {\n  static_assert(std::is_signed_v<Int>);\n\
    \  Int x = 1, y = 0, b = mod;\n  for (Int q = 0, z = 0, c = 0; b;)\n    z = x,\
    \ c = a, x = y, y = z - y * (q = a / b), a = b, b = c - b * q;\n  return assert(a\
    \ == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line 3 \"src/Math/ModIntPrototype.hpp\"\
    \n/**\n * @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category\
    \ \u6570\u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN\
    \ CUT HERE\nnamespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing u128 = __uint128_t;\nstruct MIntPro_Montg {\n  const\
    \ u64 mod;\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0) {}\n  constexpr\
    \ MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr\
    \ inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define\
    \ BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n  constexpr inline\
    \ u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n  constexpr inline\
    \ u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n  constexpr inline\
    \ u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline u64 get(u64\
    \ n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod & -(ret >>\
    \ 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n - (mod & -(n\
    \ >= mod)); }\n\n private:\n  const u64 iv, r2;\n  constexpr u64 inv(u64 n, int\
    \ e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n\
    \  constexpr inline u64 reduce(const u128 &w) const {\n    return u64(w >> 64)\
    \ + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n};\ntemplate <class Uint>\n\
    class MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint, u32>, u64, u128>;\n\
    \n public:\n  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n  constexpr\
    \ MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r)\
    \ const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m## = mod &\
    \ -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return n; }\n  static\
    \ constexpr inline Uint get(Uint n) { return n; }\n  static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 5 \"src/Math/ModInt.hpp\"\n/**\n\
    \ * @title ModInt\n * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace\
    \ math_internal {\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct run_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_runtimemodint_v = is_base_of_v<run_mint_base,\
    \ mod_t>;\ntemplate <class mod_pro_t, u64 MOD>\nstruct StaticB : sta_mint_base\
    \ {\n protected:\n  static constexpr mod_pro_t md = mod_pro_t(MOD);\n};\ntemplate\
    \ <class mod_pro_t, int id>\nstruct RuntimeB : run_mint_base {\n  static inline\
    \ void set_mod(u64 m) { md = mod_pro_t(m); }\n\n protected:\n  static inline mod_pro_t\
    \ md;\n};\ntemplate <class Int, class U, class B>\nstruct ModInt : public B {\n\
    \  using Uint = U;\n  static constexpr inline auto modulo() { return B::md.mod;\
    \ }\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(const ModInt &r) : x(r.x)\
    \ {}\n  template <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T v) : x(B::md.set(v.val() % B::md.mod)) {}\n  template <class\
    \ T,\n            enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\n\
    \  constexpr ModInt(T n)\n      : x(B::md.set((n %= B::md.mod) < 0 ? n + B::md.mod\
    \ : n)) {}\n  constexpr ModInt operator-() const { return ModInt() - *this; }\n\
    #define FUNC(name, op)          \\\n  constexpr ModInt name const { \\\n    ModInt\
    \ ret;                 \\\n    return ret.x = op, ret;     \\\n  }\n  FUNC(operator+(const\
    \ ModInt &r), B::md.plus(x, r.x))\n  FUNC(operator-(const ModInt &r), B::md.diff(x,\
    \ r.x))\n  FUNC(operator*(const ModInt &r), B::md.mul(x, r.x))\n  FUNC(pow(u64\
    \ k), math_internal::pow(x, k, B::md))\n#undef FUNC\n  constexpr ModInt operator/(const\
    \ ModInt &r) const { return *this * r.inv(); }\n  constexpr ModInt &operator+=(const\
    \ ModInt &r) { return *this = *this + r; }\n  constexpr ModInt &operator-=(const\
    \ ModInt &r) { return *this = *this - r; }\n  constexpr ModInt &operator*=(const\
    \ ModInt &r) { return *this = *this * r; }\n  constexpr ModInt &operator/=(const\
    \ ModInt &r) { return *this = *this / r; }\n  constexpr bool operator==(const\
    \ ModInt &r) const {\n    return B::md.norm(x) == B::md.norm(r.x);\n  }\n  constexpr\
    \ bool operator!=(const ModInt &r) const { return !(*this == r); }\n  constexpr\
    \ bool operator<(const ModInt &r) const {\n    return B::md.norm(x) < B::md.norm(r.x);\n\
    \  }\n  constexpr inline ModInt inv() const { return mod_inv<Int>(val(), B::md.mod);\
    \ }\n  constexpr inline Uint val() const { return B::md.get(x); }\n  friend ostream\
    \ &operator<<(ostream &os, const ModInt &r) {\n    return os << r.val();\n  }\n\
    \  friend istream &operator>>(istream &is, ModInt &r) {\n    long long v;\n  \
    \  return is >> v, r = ModInt(v), is;\n  }\n\n private:\n  Uint x;\n};\ntemplate\
    \ <u64 MOD>\nusing StaticModInt =\n    conditional_t <\n    MOD<INT_MAX, ModInt<int,\
    \ u32, StaticB<MIntPro_Na<u32>, MOD>>,\n        conditional_t<MOD &(MOD < LLONG_MAX),\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Montg, MOD>>,\n\
    \                      ModInt<long long, u64, StaticB<MIntPro_Na<u64>, MOD>>>>;\n\
    class Montgomery {};\ntemplate <class Int, int id = -1>\nusing RuntimeModInt =\
    \ conditional_t<\n    is_same_v<Int, Montgomery>,\n    ModInt<long long, u64,\
    \ RuntimeB<MIntPro_Montg, id>>,\n    conditional_t<disjunction_v<is_same<Int,\
    \ long long>, is_same<Int, u64>>,\n                  ModInt<long long, u64, RuntimeB<MIntPro_Na<u64>,\
    \ id>>,\n                  ModInt<int, u32, RuntimeB<MIntPro_Na<u32>, id>>>>;\n\
    }  // namespace math_internal\nusing math_internal::RuntimeModInt, math_internal::StaticModInt,\n\
    \    math_internal::Montgomery, math_internal::is_runtimemodint_v,\n    math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, std::size_t LIM>\n\
    mod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n  static const auto\
    \ m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static int l = 1;\n  if (l\
    \ == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m % l] * (m - m / l);\n\
    \  return dat[n];\n}\n#line 3 \"src/Math/DirichletConvSumTable.hpp\"\n/**\n *\
    \ @title \u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C\n * @category \u6570\
    \u5B66\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ * O(KlogK + \u221A(NL))\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\
    // https://atcoder.jp/contests/abc239/tasks/abc239_h (semi relaxed)\n\n// BEGIN\
    \ CUT HERE\n\ntemplate <class T>\nstruct DirichletConvSumTable {\n  std::uint64_t\
    \ N;  // <= K * L\n  std::vector<T> x /* (1 <= i <= K) */, X /* \u2211^{N/i} (1\
    \ <= i <= L) */;\n  static DirichletConvSumTable get_epsilon(std::uint64_t N,\
    \ std::size_t K) {\n    std::size_t L = (N - 1 + K) / K;\n    std::vector<T> a(K\
    \ + 1, 0);\n    return a[1] = 1, DirichletConvSumTable(N, a, std::vector<T>(L\
    \ + 1, 1));\n  }\n  DirichletConvSumTable(std::uint64_t n_, const std::vector<T>\
    \ &x_,\n                        const std::vector<T> &X_)\n      : N(n_), x(x_),\
    \ X(X_) {\n    assert(N < std::uint64_t(x.size()) * X.size());\n  }\n  DirichletConvSumTable(std::uint64_t\
    \ n_, std::size_t k_)\n      : N(n_), x(k_ + 1, 0), X((n_ - 1 + k_) / k_ + 1,\
    \ 0) {}\n  template <class F>\n  DirichletConvSumTable(std::uint64_t n_, std::size_t\
    \ k_, const F &sum)\n      : N(n_), x(k_ + 1), X((n_ - 1 + k_) / k_ + 1) {\n \
    \   assert(N < std::uint64_t(x.size()) * X.size());\n    for (std::size_t i =\
    \ x.size(); --i;) x[i] = sum(i);\n    for (std::size_t i = x.size(); --i > 1;)\
    \ x[i] -= x[i - 1];\n    for (std::size_t i = X.size(); --i;) X[i] = sum(N / i);\n\
    \  }\n  DirichletConvSumTable operator*(const DirichletConvSumTable &r) const\
    \ {\n    const std::size_t K = x.size() - 1, L = X.size() - 1;\n    assert(N <=\
    \ std::uint64_t(K) * L), assert(N == r.N);\n    assert(K == r.x.size() - 1), assert(L\
    \ == r.X.size() - 1);\n    std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K + 1,\
    \ 0), B_l(K + 1, 0);\n    for (std::size_t i = 1; i <= K; i++) A_l[i] = A_l[i\
    \ - 1] + x[i];\n    for (std::size_t i = 1; i <= K; i++) B_l[i] = B_l[i - 1] +\
    \ r.x[i];\n    auto A = [&](std::uint64_t n) { return n <= K ? A_l[n] : X[N /\
    \ n]; };\n    auto B = [&](std::uint64_t n) { return n <= K ? B_l[n] : r.X[N /\
    \ n]; };\n    std::uint64_t n;\n    for (std::size_t i = K, j; i; i--)\n     \
    \ for (j = K / i; j; j--) c[i * j] += x[i] * r.x[j];\n    for (std::size_t l =\
    \ L, m, i; l; C[l--] -= A(m) * B(m))\n      for (i = m = std::sqrt(n = N / l);\
    \ i; i--)\n        C[l] += x[i] * B(n / i) + r.x[i] * A(n / i);\n    return DirichletConvSumTable<T>(N,\
    \ c, C);\n  }\n  DirichletConvSumTable &operator*=(const DirichletConvSumTable\
    \ &r) {\n    return *this = *this * r;\n  }\n  DirichletConvSumTable operator/(const\
    \ DirichletConvSumTable &r) const {\n    return DirichletConvSumTable(*this) /=\
    \ r;\n  }\n  DirichletConvSumTable &operator/=(const DirichletConvSumTable &r)\
    \ {\n    const std::size_t K = x.size() - 1, L = X.size() - 1;\n    assert(N <=\
    \ std::uint64_t(K) * L), assert(N == r.N);\n    assert(K == r.x.size() - 1), assert(L\
    \ == r.X.size() - 1);\n    std::vector<T> A_l(K + 1, 0), B_l(K + 1, 0);\n    for\
    \ (std::size_t i = 1, j, ed; i <= K; i++)\n      for (x[i] /= r.x[1], j = 2, ed\
    \ = K / i; j <= ed; j++)\n        x[i * j] -= x[i] * r.x[j];\n    for (std::size_t\
    \ i = 1; i <= K; i++) A_l[i] = A_l[i - 1] + r.x[i];\n    for (std::size_t i =\
    \ 1; i <= K; i++) B_l[i] = B_l[i - 1] + x[i];\n    auto A = [&](std::uint64_t\
    \ n) { return n <= K ? A_l[n] : r.X[N / n]; };\n    auto B = [&](std::uint64_t\
    \ n) { return n <= K ? B_l[n] : X[N / n]; };\n    std::uint64_t n;\n    for (std::size_t\
    \ l = L, m; l; X[l--] /= r.x[1])\n      for (m = std::sqrt(n = N / l), X[l] +=\
    \ A(m) * B(m) - x[1] * A(n); m > 1;)\n        X[l] -= r.x[m] * B(n / m) + x[m]\
    \ * A(n / m), m--;\n    return *this;\n  }\n  DirichletConvSumTable square() const\
    \ {\n    const std::size_t K = x.size() - 1, L = X.size() - 1;\n    assert(N <=\
    \ std::uint64_t(K) * L);\n    std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K +\
    \ 1, 0);\n    for (int i = 1; i <= K; i++) A_l[i] = A_l[i - 1] + x[i];\n    auto\
    \ A = [&](std::uint64_t n) { return n <= K ? A_l[n] : X[N / n]; };\n    std::size_t\
    \ i, j, l = std::sqrt(K);\n    std::uint64_t n;\n    T tmp;\n    for (i = l; i;\
    \ i--)\n      for (j = K / i; j > i; j--) c[i * j] += x[i] * x[j];\n    for (i\
    \ = K; i; i--) c[i] += c[i];\n    for (i = l; i; i--) c[i * i] += x[i] * x[i];\n\
    \    for (l = L; l; C[l] += C[l], C[l--] -= tmp * tmp)\n      for (tmp = A(i =\
    \ std::sqrt(n = N / l)); i; i--) C[l] += x[i] * A(n / i);\n    return DirichletConvSumTable<T>(N,\
    \ c, C);\n  }\n  DirichletConvSumTable pow1(std::uint64_t M) const {\n    for\
    \ (auto ret = get_epsilon(N, x.size() - 1), b = *this;; b = b.square()) {\n  \
    \    if (M & 1) ret *= b;\n      if (!(M >>= 1)) return ret;\n    }\n  }\n  DirichletConvSumTable\
    \ pow2(std::uint64_t M) const {\n    const std::size_t K = x.size() - 1, L = X.size()\
    \ - 1;\n    assert(N <= std::uint64_t(K) * L);\n    if (M == 0) return get_epsilon(N,\
    \ K);\n    if (M == 1) return *this;\n    std::size_t n = 0, m, i, l, p = 2;\n\
    \    std::uint64_t e, j;\n    while (n <= M && (1ULL << n) <= N) n++;\n    DirichletConvSumTable\
    \ ret(N, x.size() - 1);\n    T pw[65] = {1}, b = x[1], tmp;\n    for (e = M -\
    \ n + 1;; b *= b)\n      if (e & 1 ? pw[0] *= b : 0; !(e >>= 1)) break;\n    for\
    \ (m = 1; m < n; m++) pw[m] = pw[m - 1] * x[1];\n    std::vector<T> XX(X), z(K\
    \ + 1, 0), Z(L + 1, 0), A_l(K + 1, 0);\n    for (i = 2; i <= K; i++) A_l[i] =\
    \ A_l[i - 1] + x[i];\n    for (i = L; i; i--) XX[i] -= x[1];\n    auto A = [&](std::uint64_t\
    \ n) { return n <= K ? A_l[n] : XX[N / n]; };\n    std::vector<T> y(x), Y(XX),\
    \ B_l(A_l), c(y), C(Y);\n    auto B = [&](std::uint64_t n) { return n <= K ? B_l[n]\
    \ : Y[N / n]; };\n    for (tmp = pw[n - 2] * M, l = L; l; l--) C[l] *= tmp;\n\
    \    for (i = 2; i <= K; i++) c[i] *= tmp;\n    for (c[1] = pw[n - 1], l = L;\
    \ l; l--) C[l] += c[1];\n    for (m = 1, b = M, l = std::min<std::uint64_t>(L,\
    \ N / p / 2); m + 1 < n;) {\n      b *= M - m, b /= ++m, tmp = b * pw[n - 1 -\
    \ m];\n      for (; l; C[l--] += Z[l] * tmp) {\n        for (i = j = std::sqrt(e\
    \ = N / l); i >= p; i--) Z[l] += y[i] * A(e / i);\n        for (i = std::min(j,\
    \ e / p); i >= 2; i--) Z[l] += x[i] * B(e / i);\n        if (j >= p) Z[l] -= A(j)\
    \ * B(j);\n      }\n      for (i = K; i >= p; i--)\n        for (l = K / i; l\
    \ >= 2; l--) z[i * l] += y[i] * x[l];\n      for (i = p = 1 << m; i <= K; i++)\
    \ c[i] += z[i] * tmp;\n      if (m + 1 == n) break;\n      l = std::min<std::uint64_t>(L,\
    \ N / p / 2);\n      y.swap(z), Y.swap(Z), std::fill_n(Z.begin() + 1, l, 0);\n\
    \      if (p * 2 <= K) std::fill(z.begin() + p * 2, z.end(), 0);\n      if (p\
    \ <= K)\n        for (B_l[p] = y[p], i = p + 1; i <= K; i++) B_l[i] = B_l[i -\
    \ 1] + y[i];\n    }\n    return DirichletConvSumTable<T>(N, c, C);\n  }\n  inline\
    \ T sum() const { return X[1]; }\n};\n\ntemplate <class T>  // zeta(s)\nDirichletConvSumTable<T>\
    \ get_1(std::uint64_t N, std::size_t K) {\n  std::size_t L = (N - 1 + K) / K;\n\
    \  std::vector<T> A(L + 1);\n  for (std::size_t l = L; l; l--) A[l] = N / l;\n\
    \  return DirichletConvSumTable<T>(N, std::vector<T>(K + 1, 1), A);\n}\n\ntemplate\
    \ <class T>  // M\xF6bius, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T> get_mu(std::uint64_t\
    \ N, std::size_t K) {\n  return DirichletConvSumTable<T>::get_epsilon(N, K) /\
    \ get_1<T>(N, K);\n}\n\ntemplate <class T>  // zeta(s-1)\nDirichletConvSumTable<T>\
    \ get_Id(std::uint64_t N, std::size_t K) {\n  std::size_t L = (N - 1 + K) / K;\n\
    \  std::vector<T> a(K + 1), A(L + 1);\n  for (std::size_t l = L; l; l--) A[l]\
    \ = N / l, (A[l] *= A[l] + 1) /= 2;\n  return std::iota(a.begin(), a.end(), 0),\
    \ DirichletConvSumTable<T>(N, a, A);\n}\n\ntemplate <class T>  // Euler's totient,\
    \ O(KlogK + \u221A(NL))\nDirichletConvSumTable<T> get_phi(std::uint64_t N, std::size_t\
    \ K) {\n  return get_Id<T>(N, K) / get_1<T>(N, K);\n}\n\ntemplate <class T>  //\
    \ zeta(2s)\nDirichletConvSumTable<T> get_1sq(std::uint64_t N, std::size_t K) {\n\
    \  std::size_t L = (N - 1 + K) / K;\n  std::vector<T> a(K + 1, 0), A(L + 1);\n\
    \  for (std::size_t i = 1; i * i <= K; i++) a[i * i] = 1;\n  for (std::size_t\
    \ l = L; l; l--) A[l] = sqrt(N / l);\n  return DirichletConvSumTable<T>(N, a,\
    \ A);\n}\n\ntemplate <class T>  // Liouville, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_lambda(std::uint64_t N, std::size_t K) {\n  return get_1sq<T>(N, K) / get_1<T>(N,\
    \ K);\n}\n\ntemplate <class T>  // |\xB5|, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_absmu(std::uint64_t N, std::size_t K) {\n  return get_1<T>(N, K) / get_1sq<T>(N,\
    \ K);\n}\n\ntemplate <class T>  // O(\u221AN)\nT dirichlet_mul_sum(const DirichletConvSumTable<T>\
    \ &a,\n                    const DirichletConvSumTable<T> &b) {\n  const std::size_t\
    \ K = a.x.size() - 1, L = a.X.size() - 1, M = std::min(K, L);\n  assert(a.N ==\
    \ b.N), assert(M <= b.x.size() - 1), assert(M <= b.X.size() - 1);\n  assert(std::uint64_t(M\
    \ + 1) * (M + 1) > a.N);\n  T ret = 0, A = 0, B = 0;\n  for (int i = M; i; i--)\
    \ ret += a.x[i] * b.X[i] + b.x[i] * a.X[i];\n  for (int i = M; i; i--) A += a.x[i],\
    \ B += b.x[i];\n  return ret -= A * B;\n}\n\ntemplate <class mod_t>  // return\
    \ \u2211g s.t. s+t\u2211g = \u2211f*g\nauto SemiRelaxed(const DirichletConvSumTable<mod_t>\
    \ &F, mod_t s, mod_t t) {\n  const std::size_t K = F.x.size() - 1, L = F.X.size()\
    \ - 1;\n  assert(F.N <= std::uint64_t(K) * L), assert(F.x[1] != t);\n  std::vector<mod_t>\
    \ A_l(K + 1, 0), B_l(K + 1, 0), g(K + 1, 0), G(L + 1, 0);\n  g[1] = s;\n  for\
    \ (std::size_t j = 1, i, ed; j <= K; j++)\n    for (g[j] /= F.x[1] - t, i = 2,\
    \ ed = K / j; i <= ed; i++)\n      g[i * j] -= F.x[i] * g[j];\n  for (std::size_t\
    \ i = 1; i <= K; i++) A_l[i] = A_l[i - 1] + F.x[i];\n  for (std::size_t i = 1;\
    \ i <= K; i++) B_l[i] = B_l[i - 1] + g[i];\n  auto A = [&](std::uint64_t n) {\
    \ return n <= K ? A_l[n] : F.X[F.N / n]; };\n  auto B = [&](std::uint64_t n) {\
    \ return n <= K ? B_l[n] : G[F.N / n]; };\n  std::uint64_t n;\n  for (std::size_t\
    \ l = L, m; l; (G[l--] += s) /= F.x[1] - t)\n    for (m = std::sqrt(n = F.N /\
    \ l), G[l] = A(m) * B(m) - g[1] * A(n); m > 1;)\n      G[l] -= F.x[m] * B(n /\
    \ m) + g[m] * A(n / m), m--;\n  return DirichletConvSumTable<mod_t>(F.N, g, G);\n\
    }\n#line 6 \"test/atcoder/arc116_c.dujiao.test.cpp\"\nusing namespace std;\n\n\
    signed main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<998244353>;\n\
    \  long long N, M;\n  cin >> N >> M;\n  auto zeta = get_1<Mint>(M, pow(M, 2. /\
    \ 3));\n  cout << zeta.pow2(N).sum() << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc116/tasks/arc116_c\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/DirichletConvSumTable.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using Mint = StaticModInt<998244353>;\n  long long N, M;\n  cin >> N >> M;\n\
    \  auto zeta = get_1<Mint>(M, pow(M, 2. / 3));\n  cout << zeta.pow2(N).sum() <<\
    \ '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Math/ModIntPrototype.hpp
  - src/Math/DirichletConvSumTable.hpp
  isVerificationFile: true
  path: test/atcoder/arc116_c.dujiao.test.cpp
  requiredBy: []
  timestamp: '2022-12-08 15:47:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc116_c.dujiao.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc116_c.dujiao.test.cpp
- /verify/test/atcoder/arc116_c.dujiao.test.cpp.html
title: test/atcoder/arc116_c.dujiao.test.cpp
---
