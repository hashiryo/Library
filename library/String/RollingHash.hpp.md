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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: RollingHash

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a973a7fd4d27ccdfce027f329015f5da">文字列</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/RollingHash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-08 12:57:42+09:00




## Verified with

* :x: <a href="../../verify/test/aoj/ALDS1_14_B.rollinghash.test.cpp.html">test/aoj/ALDS1_14_B.rollinghash.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title RollingHash
 * @category 文字列
 * @brief Mod は　2^61-1 で固定
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <unsigned long long B>
struct RollingHash {
  using ull = unsigned long long;

 private:
  const ull MASK30 = (1UL << 30) - 1;
  const ull MASK31 = (1UL << 31) - 1;
  const ull MOD = (1UL << 61) - 1;
  const ull MASK61 = MOD;
  vector<ull> hash, po;

 public:
  RollingHash() {}
  RollingHash(vector<long long> vs) { init(vs); }
  RollingHash(string &s) {
    vector<long long> vs;
    for (char c : s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<long long> vs) {
    int n = vs.size();
    hash.assign(n + 1, 0);
    po.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
      hash[i + 1] = CalcMod(Mul(hash[i], B) + vs[i]);
      po[i + 1] = CalcMod(Mul(po[i], B));
    }
  }
  // S[l, r)
  ull get(int l, int r) {
    ull res = hash[r] + MOD * 3 - Mul(hash[l], po[r - l]);
    return CalcMod(res);
  }

 private:
  // a*b mod 2^61-1を返す関数(最後にModを取る)
  ull Mul(ull a, ull b) {
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return au * bu * 2 + midu + (midd << 31) + ad * bd;
  }

  // mod 2^61-1を計算する関数
  ull CalcMod(ull x) {
    ull xu = x >> 61;
    ull xd = x & MASK61;
    ull res = xu + xd;
    return res >= MOD ? res - MOD : res;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/RollingHash.hpp"
/**
 * @title RollingHash
 * @category 文字列
 * @brief Mod は　2^61-1 で固定
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <unsigned long long B>
struct RollingHash {
  using ull = unsigned long long;

 private:
  const ull MASK30 = (1UL << 30) - 1;
  const ull MASK31 = (1UL << 31) - 1;
  const ull MOD = (1UL << 61) - 1;
  const ull MASK61 = MOD;
  vector<ull> hash, po;

 public:
  RollingHash() {}
  RollingHash(vector<long long> vs) { init(vs); }
  RollingHash(string &s) {
    vector<long long> vs;
    for (char c : s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<long long> vs) {
    int n = vs.size();
    hash.assign(n + 1, 0);
    po.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
      hash[i + 1] = CalcMod(Mul(hash[i], B) + vs[i]);
      po[i + 1] = CalcMod(Mul(po[i], B));
    }
  }
  // S[l, r)
  ull get(int l, int r) {
    ull res = hash[r] + MOD * 3 - Mul(hash[l], po[r - l]);
    return CalcMod(res);
  }

 private:
  // a*b mod 2^61-1を返す関数(最後にModを取る)
  ull Mul(ull a, ull b) {
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return au * bu * 2 + midu + (midd << 31) + ad * bd;
  }

  // mod 2^61-1を計算する関数
  ull CalcMod(ull x) {
    ull xu = x >> 61;
    ull xd = x & MASK61;
    ull res = xu + xd;
    return res >= MOD ? res - MOD : res;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

