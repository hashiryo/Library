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


# :heavy_check_mark: test/yosupo/sum_of_totient_function.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sum_of_totient_function.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-30 18:22:54+09:00


* see: <a href="https://judge.yosupo.jp/problem/sum_of_totient_function">https://judge.yosupo.jp/problem/sum_of_totient_function</a>


## Depends on

* :question: <a href="../../../library/Math/ModInt.hpp.html">ModInt</a>
* :question: <a href="../../../library/Math/dujiao_sieve.hpp.html">杜教筛</a>
* :question: <a href="../../../library/Math/number_theory.hpp.html">数論</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/ModInt.hpp"
#include "Math/dujiao_sieve.hpp"
#include "Math/number_theory.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  using Mint = ModInt<998244353>;
  using namespace number_theory;
  const int M = 1 << (200 / 9);
  init(M);
  auto phi = get_phi<Mint>(M);
  for (int i = 2; i < M; i++) phi[i] += phi[i - 1];
  auto g = [](int64_t N, int64_t dummy) {
    return Mint(N) * Mint(N + 1) / Mint(2);
  };
  auto b = [](int64_t d) { return Mint(d); };
  map<pair<int64_t, int64_t>, Mint> memo;
  for (int i = 1; i < M; i++) memo[make_pair(i, i)] = phi[i];
  int64_t N;
  cin >> N;
  Mint ans = dujiao_sieve<Mint>(N, N, g, b, memo);
  cout << ans << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/sum_of_totient_function.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "Math/ModInt.hpp"
/**
 * @title ModInt
 * @category 数学
 */

#ifndef call_from_test
#line 8 "Math/ModInt.hpp"
using namespace std;
#endif

template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) { return *this *= p.inverse(); }
  ModInt operator-() const { return ModInt() - *this; }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b) t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
    return ModInt(u);
  }
  ModInt pow(int64_t e) const {
    ModInt ret(1);
    for (ModInt b = *this; e; e >>= 1, b *= b)
      if (e & 1) ret *= b;
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int modulo() { return mod; }
};
#line 1 "Math/dujiao_sieve.hpp"
/**
 * @title 杜教筛
 * @category 数学
 * @see https://maspypy.com/yukicoder-no-886-direct
 * @see https://yukicoder.me/problems/no/1019/editorial
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_inversion_formula
 * @see https://yukicoder.me/wiki/sum_totient
 * @see https://oi-wiki.org/math/du/
 * @see https://blog.bill.moe/multiplicative-function-sieves-notes/
 * @brief メモ化再帰で実装(map使ってるのでlogがつく)
 * @brief k==1ならO(N^(3/4)) (g,bの計算量をO(1)として)
 * @brief 前処理でN^(2/3)まで計算できるならO(N^(2/3))
 */

// input H,W,g,b,k
// output f(H,W)
//  s.t. g(x,y) = sum_{d=1,2,...} a(d)f([x/d^k],[y/d^k])
//       b(d) = a(1)+a(2)+...+a(d)

#ifndef call_from_test
#line 22 "Math/dujiao_sieve.hpp"
using namespace std;
#endif

template <typename T, typename G, typename A>
T dujiao_sieve(int64_t H, int64_t W, const G &g, const A &b,
               map<pair<int64_t, int64_t>, T> &memo, int k = 1) {
  if (memo.count(make_pair(H, W))) return memo[make_pair(H, W)];
  T ret = g(H, W);
  int64_t d = 2;
  while (true) {
    int64_t Hd = H / pow(d, k), Wd = W / pow(d, k);
    if (!Hd || !Wd) break;
    int64_t next_d
        = min(pow(1. * H / Hd, 1. / k), pow(1. * W / Wd, 1. / k)) + 1;
    T r = dujiao_sieve<T>(Hd, Wd, g, b, memo, k);
    ret -= r * (b(next_d - 1) - b(d - 1));
    d = next_d;
  }
  return memo[make_pair(H, W)] = ret / b(1);
}
#line 1 "Math/number_theory.hpp"
/**
 * @title 数論
 * @category 数学
 * @brief 約数や倍数についてのゼータ変換やメビウス変換
 * @brief をもとに数論的関数やgcd畳み込みなどを実現
 * @brief O(N log log N)
 * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
 * @see https://en.wikipedia.org/wiki/Dirichlet_convolution
 */

// verify用:
// https://atcoder.jp/contests/agc038/tasks/agc038_c

#ifndef call_from_test
#line 16 "Math/number_theory.hpp"
using namespace std;
#endif

namespace number_theory {
vector<int> primes;
void init(int n) {
  primes.push_back(2);
  bool is_prime[n + 1];
  fill(is_prime, is_prime + n + 1, true);
  for (long long p = 3; p <= n; p += 2)
    if (is_prime[p]) {
      primes.push_back(p);
      for (long long i = p * p; i <= n; i += p) is_prime[i] = false;
    }
}
// f -> g s.t. g(n) = sum_{m|n} f(m)
template <typename T>
void divisor_zeta(vector<T> &f) {
  int n = f.size();
  if (!primes.size()) init(n);
  for (int p : primes) {
    if (p > n) break;
    for (int i = 1; p * i < n; i++) f[p * i] += f[i];
  }
}
// f -> h s.t. f(n) = sum_{m|n} h(m)
template <typename T>
void divisor_mobius(vector<T> &f) {
  int n = f.size();
  if (!primes.size()) init(n);
  for (int p : primes) {
    if (p > n) break;
    for (int i = (n - 1) / p; i > 0; i--) f[p * i] -= f[i];
  }
}
// get table of Mobius function
template <typename T = int>
vector<T> get_mu(int n) {
  vector<T> f(n + 1, T(0));
  f[1] = T(1);
  divisor_mobius(f);
  return f;
}
// get table of Euler's totient function
template <typename T = int>
vector<T> get_phi(int n) {
  vector<T> f(n + 1);
  iota(f.begin(), f.end(), 0);
  divisor_mobius(f);
  return f;
}
// get table of number-of-divisors function
template <typename T = int>
vector<T> get_d(int n) {
  vector<T> f(n + 1, 1);
  divisor_zeta(f);
  return f;
}
// get table of sum-of-divisors function
template <typename T = int>
vector<T> get_sigma(int n) {
  vector<T> f(n + 1);
  iota(f.begin(), f.end(), 0);
  divisor_zeta(f);
  return f;
}
template <typename T>
static vector<T> lcm_convolution(vector<T> a, vector<T> b) {
  int n = max(a.size(), b.size());
  a.resize(n);
  b.resize(n);
  divisor_zeta(a);
  divisor_zeta(b);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  divisor_mobius(a);
  return a;
}
// f -> g s.t. g(n) = sum_{n|m} f(m)
template <typename T>
static void multiple_zeta(vector<T> &f) {
  int n = f.size();
  if (!primes.size()) init(n);
  for (int p : primes) {
    if (p > n) break;
    for (int i = (n - 1) / p; i > 0; i--) f[i] += f[p * i];
  }
}
// f -> h s.t. f(n) = sum_{n|m} h(m)
template <typename T>
static void multiple_mobius(vector<T> &f) {
  int n = f.size();
  if (!primes.size()) init(n);
  for (int p : primes) {
    if (p > n) break;
    for (int i = 1; p * i < n; i++) f[i] -= f[p * i];
  }
}
template <typename T>
static vector<T> gcd_convolution(vector<T> a, vector<T> b) {
  int n = max(a.size(), b.size());
  a.resize(n);
  b.resize(n);
  multiple_zeta(a);
  multiple_zeta(b);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  multiple_mobius(a);
  return a;
}
}  // namespace number_theory
#line 10 "test/yosupo/sum_of_totient_function.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  using Mint = ModInt<998244353>;
  using namespace number_theory;
  const int M = 1 << (200 / 9);
  init(M);
  auto phi = get_phi<Mint>(M);
  for (int i = 2; i < M; i++) phi[i] += phi[i - 1];
  auto g = [](int64_t N, int64_t dummy) {
    return Mint(N) * Mint(N + 1) / Mint(2);
  };
  auto b = [](int64_t d) { return Mint(d); };
  map<pair<int64_t, int64_t>, Mint> memo;
  for (int i = 1; i < M; i++) memo[make_pair(i, i)] = phi[i];
  int64_t N;
  cin >> N;
  Mint ans = dujiao_sieve<Mint>(N, N, g, b, memo);
  cout << ans << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

