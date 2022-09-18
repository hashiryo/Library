---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Math/DirichletConvSumTable.hpp
    title: "\u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n *\
    \ @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace internal {\ntemplate\
    \ <std::uint64_t mod, std::uint64_t prim_root, class ModInt>\nstruct ModIntImpl\
    \ {\n  static constexpr std::uint64_t modulo() { return mod; }\n  static constexpr\
    \ std::uint64_t pr_rt() { return prim_root; }\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &rhs) {\n    return os << rhs.val();\n  }\n};\n}  // namespace\
    \ internal\ntemplate <std::uint64_t mod, std::uint64_t prim_root = 0>\nclass ModInt\n\
    \    : public internal::ModIntImpl<mod, prim_root, ModInt<mod, prim_root>> {\n\
    \  using u64 = std::uint64_t;\n  static constexpr u64 mul_inv(u64 n, int e = 6,\
    \ u64 x = 1) {\n    return e == 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n\
    \  }\n  static constexpr u64 inv = mul_inv(mod, 6, 1), r2 = -__uint128_t(mod)\
    \ % mod;\n  static constexpr u64 init(u64 w) { return reduce(__uint128_t(w) *\
    \ r2); }\n  static constexpr u64 reduce(const __uint128_t w) {\n    return u64(w\
    \ >> 64) + mod - ((__uint128_t(u64(w) * inv) * mod) >> 64);\n  }\n  u64 x;\n\n\
    \ public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t n)\
    \ : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  static constexpr u64 norm(u64\
    \ w) { return w - (mod & -(w >= mod)); }\n  constexpr ModInt operator-() const\
    \ {\n    ModInt ret;\n    return ret.x = ((mod << 1) & -(x != 0)) - x, ret;\n\
    \  }\n  constexpr ModInt &operator+=(const ModInt &rhs) {\n    return x += rhs.x\
    \ - (mod << 1), x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) {\n    return x -= rhs.x, x += (mod << 1) & -(x\
    \ >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const ModInt &rhs) {\n \
    \   return this->x = reduce(__uint128_t(this->x) * rhs.x), *this;\n  }\n  constexpr\
    \ ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }\n\
    \  constexpr ModInt pow(std::uint64_t k) const {\n    ModInt ret = ModInt(1);\n\
    \    for (ModInt base = *this; k; k >>= 1, base *= base)\n      if (k & 1) ret\
    \ *= base;\n    return ret;\n  }\n  constexpr ModInt inverse() const { return\
    \ pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this == ModInt(0)\
    \ || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return ModInt(0);\
    \  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n    while (w.pow((mod\
    \ - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto mul = [&](std::pair<ModInt,\
    \ ModInt> u, std::pair<ModInt, ModInt> v) {\n      ModInt a = (u.first * v.first\
    \ + u.second * v.second * w);\n      ModInt b = (u.first * v.second + u.second\
    \ * v.first);\n      return std::make_pair(a, b);\n    };\n    std::uint64_t e\
    \ = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n    for (auto\
    \ bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n      if (e & 1)\
    \ ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first : -ret.first;\n\
    \  }\n  constexpr u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return\
    \ ret + (mod & -(ret >> 63));\n  }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n\
    };\ntemplate <std::uint64_t pr_rt>\nstruct ModInt<2, pr_rt> : internal::ModIntImpl<2,\
    \ pr_rt, ModInt<2, pr_rt>> {\n  constexpr ModInt(std::int64_t n = 0) : x(n & 1)\
    \ {}\n  constexpr ModInt operator-() const { return *this; }\n  constexpr ModInt\
    \ &operator+=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator-=(const ModInt &rhs) { return x ^= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator*=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  constexpr ModInt\
    \ &operator/=(const ModInt &rhs) { return x &= rhs.x, *this; }\n  ModInt operator+(const\
    \ ModInt &rhs) const { return ModInt(*this) += rhs; }\n  ModInt operator-(const\
    \ ModInt &rhs) const { return ModInt(*this) -= rhs; }\n  ModInt operator*(const\
    \ ModInt &rhs) const { return ModInt(*this) *= rhs; }\n  ModInt operator/(const\
    \ ModInt &rhs) const { return ModInt(*this) /= rhs; }\n  bool operator==(const\
    \ ModInt &rhs) const { return x == rhs.x; }\n  bool operator!=(const ModInt &rhs)\
    \ const { return !(*this == rhs); }\n  constexpr ModInt pow(std::uint64_t k) const\
    \ { return !k ? ModInt(1) : *this; }\n  constexpr ModInt sqrt() const { return\
    \ *this; }\n  constexpr ModInt inverse() const { return *this; }\n  constexpr\
    \ std::uint64_t val() const { return x; }\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &rhs) {\n    return is >> rhs.x, is;\n  }\n\n private:\n  bool x;\n\
    };\n#line 3 \"src/Math/DirichletConvSumTable.hpp\"\n/**\n * @title \u6570\u8AD6\
    \u95A2\u6570\u306E\u7D2F\u7A4D\u548C\n * @category \u6570\u5B66\n * @see\n * https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C\n\
    \ * O(KlogK + \u221A(NL))\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/xmascon19/tasks/xmascon19_d\n\
    \n// BEGIN CUT HERE\n\ntemplate <class T>\nstruct DirichletConvSumTable {\n  std::uint64_t\
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
    \ 0), B_l(K + 1, 0);\n    for (int i = 1; i <= K; i++) A_l[i] = A_l[i - 1] + x[i];\n\
    \    for (int i = 1; i <= K; i++) B_l[i] = B_l[i - 1] + r.x[i];\n    auto A =\
    \ [&](std::uint64_t n) { return n <= K ? A_l[n] : X[N / n]; };\n    auto B = [&](std::uint64_t\
    \ n) { return n <= K ? B_l[n] : r.X[N / n]; };\n    std::uint64_t n;\n    for\
    \ (std::size_t i = K, j; i; i--)\n      for (j = K / i; j; j--) c[i * j] += x[i]\
    \ * r.x[j];\n    for (std::size_t l = L, m, i; l; C[l--] -= A(m) * B(m))\n   \
    \   for (i = m = std::sqrt(n = N / l); i; i--)\n        C[l] += x[i] * B(n / i)\
    \ + r.x[i] * A(n / i);\n    return DirichletConvSumTable<T>(N, c, C);\n  }\n \
    \ DirichletConvSumTable &operator*=(const DirichletConvSumTable &r) {\n    return\
    \ *this = *this * r;\n  }\n  DirichletConvSumTable operator/(const DirichletConvSumTable\
    \ &r) const {\n    return DirichletConvSumTable(*this) /= r;\n  }\n  DirichletConvSumTable\
    \ &operator/=(const DirichletConvSumTable &r) {\n    const std::size_t K = x.size()\
    \ - 1, L = X.size() - 1;\n    assert(N <= std::uint64_t(K) * L), assert(N == r.N);\n\
    \    assert(K == r.x.size() - 1), assert(L == r.X.size() - 1);\n    std::vector<T>\
    \ A_l(K + 1, 0), B_l(K + 1, 0);\n    for (std::size_t i = 1, j, ed; i <= K; i++)\n\
    \      for (x[i] /= r.x[1], j = 2, ed = K / i; j <= ed; j++)\n        x[i * j]\
    \ -= x[i] * r.x[j];\n    for (std::size_t i = 1; i <= K; i++) A_l[i] = A_l[i -\
    \ 1] + r.x[i];\n    for (std::size_t i = 1; i <= K; i++) B_l[i] = B_l[i - 1] +\
    \ x[i];\n    auto A = [&](std::uint64_t n) { return n <= K ? A_l[n] : r.X[N /\
    \ n]; };\n    auto B = [&](std::uint64_t n) { return n <= K ? B_l[n] : X[N / n];\
    \ };\n    std::uint64_t n;\n    for (std::size_t l = L, m; l; X[l--] /= r.x[1])\n\
    \      for (X[l] += A(m = std::sqrt(n = N / l)) * B(m) - x[1] * A(n); m > 1; m--)\n\
    \        X[l] -= r.x[m] * B(n / m) + x[m] * A(n / m);\n    return *this;\n  }\n\
    \  DirichletConvSumTable square() const {\n    const std::size_t K = x.size()\
    \ - 1, L = X.size() - 1;\n    assert(N <= std::uint64_t(K) * L);\n    std::vector<T>\
    \ c(K + 1, 0), C(L + 1, 0), A_l(K + 1, 0);\n    for (int i = 1; i <= K; i++) A_l[i]\
    \ = A_l[i - 1] + x[i];\n    auto A = [&](std::uint64_t n) { return n <= K ? A_l[n]\
    \ : X[N / n]; };\n    std::size_t i, j, l = std::sqrt(K);\n    std::uint64_t n;\n\
    \    T tmp;\n    for (i = l; i; i--)\n      for (j = K / i; j > i; j--) c[i *\
    \ j] += x[i] * x[j];\n    for (i = K; i; i--) c[i] += c[i];\n    for (i = l; i;\
    \ i--) c[i * i] += x[i] * x[i];\n    for (l = L; l; C[l] += C[l], C[l--] -= tmp\
    \ * tmp)\n      for (tmp = A(i = std::sqrt(n = N / l)); i; i--) C[l] += x[i] *\
    \ A(n / i);\n    return DirichletConvSumTable<T>(N, c, C);\n  }\n  DirichletConvSumTable\
    \ pow1(std::uint64_t M) const {\n    for (auto ret = get_epsilon(N, x.size() -\
    \ 1), b = *this;; b = b.square()) {\n      if (M & 1) ret *= b;\n      if (!(M\
    \ >>= 1)) return ret;\n    }\n  }\n  DirichletConvSumTable pow2(std::uint64_t\
    \ M) const {\n    const std::size_t K = x.size() - 1, L = X.size() - 1;\n    assert(N\
    \ <= std::uint64_t(K) * L);\n    if (M == 0) return get_epsilon(N, K);\n    if\
    \ (M == 1) return *this;\n    std::size_t n = 0, m, i, l, p = 2;\n    std::uint64_t\
    \ e, j;\n    while (n <= M && (1ULL << n) <= N) n++;\n    DirichletConvSumTable\
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
    \ + 1) * (M + 1) > a.N);\n  debug(M);\n  T ret = 0, A = 0, B = 0;\n  for (int\
    \ i = M; i; i--) ret += a.x[i] * b.X[i] + b.x[i] * a.X[i];\n  for (int i = M;\
    \ i; i--) A += a.x[i], B += b.x[i];\n  return ret -= A * B;\n}\n#line 5 \"test/yosupo/sum_of_totient_function.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  long long N;\n  cin >> N;\n  cout << get_phi<Mint>(N,\
    \ int(pow(N, 2. / 3))).sum() << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/DirichletConvSumTable.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  using Mint = ModInt<998244353>;\n  long long N;\n  cin >> N;\n  cout << get_phi<Mint>(N,\
    \ int(pow(N, 2. / 3))).sum() << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/DirichletConvSumTable.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2022-09-19 00:09:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.test.cpp
- /verify/test/yosupo/sum_of_totient_function.test.cpp.html
title: test/yosupo/sum_of_totient_function.test.cpp
---
