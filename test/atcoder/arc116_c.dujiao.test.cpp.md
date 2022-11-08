---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/DirichletConvSumTable.hpp
    title: "\u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
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
    #line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\
    \n */\n\n// BEGIN CUT HERE\nnamespace modint_internal {\nusing namespace std;\n\
    struct modint_base {};\nstruct sta_mint_base : modint_base {};\nstruct dyn_mint_base\
    \ : modint_base {};\ntemplate <class mod_t>\nconstexpr bool is_modint_v = is_base_of_v<modint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base,\
    \ mod_t>;\ntemplate <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
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
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
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
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    #line 3 \"src/Math/DirichletConvSumTable.hpp\"\n/**\n * @title \u6570\u8AD6\u95A2\
    \u6570\u306E\u7D2F\u7A4D\u548C\n * @category \u6570\u5B66\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
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
  - src/Math/DirichletConvSumTable.hpp
  isVerificationFile: true
  path: test/atcoder/arc116_c.dujiao.test.cpp
  requiredBy: []
  timestamp: '2022-10-29 19:15:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc116_c.dujiao.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc116_c.dujiao.test.cpp
- /verify/test/atcoder/arc116_c.dujiao.test.cpp.html
title: test/atcoder/arc116_c.dujiao.test.cpp
---
