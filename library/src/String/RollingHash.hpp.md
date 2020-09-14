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


# :heavy_check_mark: Rolling-Hash

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a973a7fd4d27ccdfce027f329015f5da">文字列</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/String/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 13:17:44+09:00


* see: <a href="https://qiita.com/keymoon/items/11fac5627672a6d6a9f6">https://qiita.com/keymoon/items/11fac5627672a6d6a9f6</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_14_B.rollinghash.test.cpp.html">test/aoj/ALDS1_14_B.rollinghash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Rolling-Hash
 * @category 文字列
 *  Mod は　2^61-1 で固定
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 */

// lcp verify https://atcoder.jp/contests/arc050/tasks/arc050_d

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct RollingHash {
 private:
  static constexpr uint64_t mod = (1ull << 61ull) - 1;
  vector<uint64_t> hash, pw;
  uint64_t base;

 private:
  static inline uint64_t add(uint64_t a, uint64_t b) {
    if ((a += b) >= mod) a -= mod;
    return a;
  }
  static inline uint64_t mul(uint64_t a, uint64_t b) {
    __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & mod);
  }

 public:
  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  RollingHash() = default;
  RollingHash(const string& s, uint64_t base)
      : RollingHash(vector<char>(s.begin(), s.end()), base) {}
  template <typename T>
  RollingHash(const vector<T>& s, uint64_t base) : base(base) {
    hash.assign(s.size() + 1, 0);
    pw.assign(s.size() + 1, 0);
    pw[0] = 1;
    for (size_t i = 0; i < s.size(); i++) {
      pw[i + 1] = mul(pw[i], base);
      hash[i + 1] = add(mul(hash[i], base), s[i]);
    }
  }
  // S[l, r)
  uint64_t get_hash(int l, int r) const {
    return add(hash[r], mod - mul(hash[l], pw[r - l]));
  }
  uint64_t combine_hash(uint64_t hash1, uint64_t hash2, int hash2len) {
    return add(mul(hash1, pw[hash2len]), hash2);
  }
};

template <size_t SIZE>
struct RollingHash_MultiBase {
  using Array = array<uint64_t, SIZE>;
  array<RollingHash, SIZE> rhs;
  Array bases;
  RollingHash_MultiBase() = default;
  RollingHash_MultiBase(const string& s, Array bs)
      : RollingHash_MultiBase(vector<char>(s.begin(), s.end()), bs) {}
  template <typename T>
  RollingHash_MultiBase(const vector<T>& s, Array bs) : bases(bs) {
    for (size_t i = 0; i < SIZE; i++) rhs[i] = RollingHash(s, bases[i]);
  }
  Array get_hash(int l, int r) const {
    Array ret;
    for (size_t i = 0; i < SIZE; i++) ret[i] = rhs[i].get_hash(l, r);
    return ret;
  }
  bool equal(int l1, int r1, int l2, int r2) const {
    return equal(*this, *this, l1, r1, l2, r2);
  }
  int lcp(int l1, int r1, int l2, int r2) const {
    return lcp(*this, *this, l1, r1, l2, r2);
  }
  static bool equal(const RollingHash_MultiBase& a,
                    const RollingHash_MultiBase& b, int l1, int r1, int l2,
                    int r2) {
    for (size_t i = 0; i < SIZE; i++)
      if (a.rhs[i].get_hash(l1, r1) != b.rhs[i].get_hash(l2, r2)) return false;
    return true;
  }
  static int lcp(const RollingHash_MultiBase& a, const RollingHash_MultiBase& b,
                 int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (equal(a, b, l1, l1 + mid, l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/String/RollingHash.hpp"
/**
 * @title Rolling-Hash
 * @category 文字列
 *  Mod は　2^61-1 で固定
 * @see https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
 */

// lcp verify https://atcoder.jp/contests/arc050/tasks/arc050_d

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct RollingHash {
 private:
  static constexpr uint64_t mod = (1ull << 61ull) - 1;
  vector<uint64_t> hash, pw;
  uint64_t base;

 private:
  static inline uint64_t add(uint64_t a, uint64_t b) {
    if ((a += b) >= mod) a -= mod;
    return a;
  }
  static inline uint64_t mul(uint64_t a, uint64_t b) {
    __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & mod);
  }

 public:
  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  RollingHash() = default;
  RollingHash(const string& s, uint64_t base)
      : RollingHash(vector<char>(s.begin(), s.end()), base) {}
  template <typename T>
  RollingHash(const vector<T>& s, uint64_t base) : base(base) {
    hash.assign(s.size() + 1, 0);
    pw.assign(s.size() + 1, 0);
    pw[0] = 1;
    for (size_t i = 0; i < s.size(); i++) {
      pw[i + 1] = mul(pw[i], base);
      hash[i + 1] = add(mul(hash[i], base), s[i]);
    }
  }
  // S[l, r)
  uint64_t get_hash(int l, int r) const {
    return add(hash[r], mod - mul(hash[l], pw[r - l]));
  }
  uint64_t combine_hash(uint64_t hash1, uint64_t hash2, int hash2len) {
    return add(mul(hash1, pw[hash2len]), hash2);
  }
};

template <size_t SIZE>
struct RollingHash_MultiBase {
  using Array = array<uint64_t, SIZE>;
  array<RollingHash, SIZE> rhs;
  Array bases;
  RollingHash_MultiBase() = default;
  RollingHash_MultiBase(const string& s, Array bs)
      : RollingHash_MultiBase(vector<char>(s.begin(), s.end()), bs) {}
  template <typename T>
  RollingHash_MultiBase(const vector<T>& s, Array bs) : bases(bs) {
    for (size_t i = 0; i < SIZE; i++) rhs[i] = RollingHash(s, bases[i]);
  }
  Array get_hash(int l, int r) const {
    Array ret;
    for (size_t i = 0; i < SIZE; i++) ret[i] = rhs[i].get_hash(l, r);
    return ret;
  }
  bool equal(int l1, int r1, int l2, int r2) const {
    return equal(*this, *this, l1, r1, l2, r2);
  }
  int lcp(int l1, int r1, int l2, int r2) const {
    return lcp(*this, *this, l1, r1, l2, r2);
  }
  static bool equal(const RollingHash_MultiBase& a,
                    const RollingHash_MultiBase& b, int l1, int r1, int l2,
                    int r2) {
    for (size_t i = 0; i < SIZE; i++)
      if (a.rhs[i].get_hash(l1, r1) != b.rhs[i].get_hash(l2, r2)) return false;
    return true;
  }
  static int lcp(const RollingHash_MultiBase& a, const RollingHash_MultiBase& b,
                 int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (equal(a, b, l1, l1 + mid, l2, l2 + mid))
        low = mid;
      else
        high = mid;
    }
    return low;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

