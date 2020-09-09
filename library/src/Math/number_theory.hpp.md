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


# :question: 数論

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/number_theory.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 17:41:10+09:00


* see: <a href="https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5">https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5</a>
* see: <a href="https://en.wikipedia.org/wiki/Dirichlet_convolution">https://en.wikipedia.org/wiki/Dirichlet_convolution</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/sum_of_totient_function.test.cpp.html">test/yosupo/sum_of_totient_function.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/644.test.cpp.html">test/yukicoder/644.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/886.numth.test.cpp.html">test/yukicoder/886.numth.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 数論
 * @category 数学
 *  約数や倍数についてのゼータ変換やメビウス変換
 *  をもとに数論的関数やgcd畳み込みなどを実現
 *  O(N log log N)
 * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
 * @see https://en.wikipedia.org/wiki/Dirichlet_convolution
 */

// verify用:
// https://atcoder.jp/contests/agc038/tasks/agc038_c

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

namespace number_theory {
vector<int> primes;
const int MAX_N = 1 << 24;
int mpf[MAX_N];  // minimum prime factor
void init(int n) {
  primes.push_back(2);
  for (int i = 2; i <= n; i += 2) mpf[i] = 2;
  for (long long p = 3; p <= n; p += 2)
    if (!mpf[p]) {
      mpf[p] = p;
      primes.push_back(p);
      for (long long i = p * p; i <= n; i += 2 * p)
        if (!mpf[i]) mpf[i] = p;
    }
}

vector<pair<int, int>> prime_factorize(int n) {  // O(log n)
  vector<pair<int, int>> res;
  while (n > 1) {
    int p = mpf[n];
    int e = 0;
    while (mpf[n] == p) e++, n /= p;
    res.push_back(make_pair(p, e));
  }
  return res;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/number_theory.hpp"
/**
 * @title 数論
 * @category 数学
 *  約数や倍数についてのゼータ変換やメビウス変換
 *  をもとに数論的関数やgcd畳み込みなどを実現
 *  O(N log log N)
 * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
 * @see https://en.wikipedia.org/wiki/Dirichlet_convolution
 */

// verify用:
// https://atcoder.jp/contests/agc038/tasks/agc038_c

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

namespace number_theory {
vector<int> primes;
const int MAX_N = 1 << 24;
int mpf[MAX_N];  // minimum prime factor
void init(int n) {
  primes.push_back(2);
  for (int i = 2; i <= n; i += 2) mpf[i] = 2;
  for (long long p = 3; p <= n; p += 2)
    if (!mpf[p]) {
      mpf[p] = p;
      primes.push_back(p);
      for (long long i = p * p; i <= n; i += 2 * p)
        if (!mpf[i]) mpf[i] = p;
    }
}

vector<pair<int, int>> prime_factorize(int n) {  // O(log n)
  vector<pair<int, int>> res;
  while (n > 1) {
    int p = mpf[n];
    int e = 0;
    while (mpf[n] == p) e++, n /= p;
    res.push_back(make_pair(p, e));
  }
  return res;
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

