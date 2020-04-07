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
    - Last commit date: 2020-04-07 17:39:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/String/RollingHash.hpp.html">RollingHash</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "String/RollingHash.hpp"
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
    for(int i = 0; i + N <= T.length(); i++) {
        if(rt1.find(i, i + N) == rp1.find(0, N)
           && rt2.find(i, i + N) == rp2.find(0, N))
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
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "String/RollingHash.hpp"
/**
 * @title RollingHash
 * @category 文字列
 * @brief Mod は　2^61-1 で固定
 */

#ifndef call_from_test
#line 9 "String/RollingHash.hpp"
using namespace std;
#endif

template <unsigned long long B>
struct RollingHash {
  using ull = unsigned long long;
  const ull MASK30 = (1UL << 30) - 1;
  const ull MASK31 = (1UL << 31) - 1;
  const ull MOD = (1UL << 61) - 1;
  const ull MASK61 = MOD;
  vector<ull> hash, po;
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
  // S[l, r)
  ull find(int l, int r) {
    ull res = hash[r] + MOD * 3 - Mul(hash[l], po[r - l]);
    return CalcMod(res);
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
    for(int i = 0; i + N <= T.length(); i++) {
        if(rt1.find(i, i + N) == rp1.find(0, N)
           && rt2.find(i, i + N) == rp2.find(0, N))
            cout << i << "\n";
    }
    cout << flush;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

