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


# :heavy_check_mark: test/aoj/ALDS1_14_B.rollinghash.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_B.rollinghash.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 17:25:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/src/String/RollingHash.hpp.html">Rolling-Hash</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/String/RollingHash.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string T, P;
  cin >> T >> P;
  using RH1 = RollingHash<2020031611>;
  using RH2 = RollingHash<19990929>;
  RH1 rt1(T), rp1(P);
  RH2 rt2(T), rp2(P);
  int N = P.length();
  for (int i = 0; i + N <= T.length(); i++) {
    if (rt1.get_hash(i, i + N) == rp1.get_hash(0, N)
        && rt2.get_hash(i, i + N) == rp2.get_hash(0, N))
      cout << i << "\n";
  }
  cout << flush;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_B.rollinghash.test.cpp"
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/String/RollingHash.hpp"
/**
 * @title Rolling-Hash
 * @category 文字列
 * @brief Mod は　2^61-1 で固定
 */

#ifndef call_from_test
#line 9 "src/String/RollingHash.hpp"
using namespace std;
#endif

template <unsigned long long B>
struct RollingHash {
 private:
  const uint64_t MASK30 = (1UL << 30) - 1;
  const uint64_t MASK31 = (1UL << 31) - 1;
  const uint64_t MOD = (1UL << 61) - 1;
  const uint64_t MASK61 = MOD;
  vector<uint64_t> hash, po;

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
      hash[i + 1] = calcmod(mul(hash[i], B) + vs[i]);
      po[i + 1] = calcmod(mul(po[i], B));
    }
  }
  // S[l, r)
  uint64_t get_hash(int l, int r) {
    uint64_t res = hash[r] + MOD * 3 - mul(hash[l], po[r - l]);
    return calcmod(res);
  }

 private:
  uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t au = a >> 31;
    uint64_t ad = a & MASK31;
    uint64_t bu = b >> 31;
    uint64_t bd = b & MASK31;
    uint64_t mid = ad * bu + au * bd;
    uint64_t midu = mid >> 30;
    uint64_t midd = mid & MASK30;
    return au * bu * 2 + midu + (midd << 31) + ad * bd;
  }

  uint64_t calcmod(uint64_t x) {
    uint64_t xu = x >> 61;
    uint64_t xd = x & MASK61;
    uint64_t res = xu + xd;
    return res >= MOD ? res - MOD : res;
  }
};
#line 9 "test/aoj/ALDS1_14_B.rollinghash.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string T, P;
  cin >> T >> P;
  using RH1 = RollingHash<2020031611>;
  using RH2 = RollingHash<19990929>;
  RH1 rt1(T), rp1(P);
  RH2 rt2(T), rp2(P);
  int N = P.length();
  for (int i = 0; i + N <= T.length(); i++) {
    if (rt1.get_hash(i, i + N) == rp1.get_hash(0, N)
        && rt2.get_hash(i, i + N) == rp2.get_hash(0, N))
      cout << i << "\n";
  }
  cout << flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

