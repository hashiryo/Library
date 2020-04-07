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


# :heavy_check_mark: test/aoj/ALDS1_14_B.KMP.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_B.KMP.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 17:39:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/String/KnuthMorrisPratt.hpp.html">KnuthMorrisPratt</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "String/KnuthMorrisPratt.hpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string T, P;
    cin >> T >> P;
    KnuthMorrisPratt KMP(P);
    auto ans = KMP.pattern_match(T);
    for(auto a : ans) {
        cout << a << "\n";
    }
    cout << flush;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_B.KMP.test.cpp"
#define PROBLEM                                                                \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "String/KnuthMorrisPratt.hpp"
/**
 * @title KnuthMorrisPratt
 * @category 文字列
 * @brief テーブル構築 O(|S|)
 * @brief pattern_match(T) Tの中からSと一致する部分を検索 O(|T|)
 * @brief period(i) verified :ARC060_F
 */

#ifndef call_from_test
#line 11 "String/KnuthMorrisPratt.hpp"
using namespace std;
#endif
struct KnuthMorrisPratt {
  vector<int> KMP;
  const string s;
  int n;
  KnuthMorrisPratt(const string &str) : s(str), n(s.length()) {
    KMP.resize(n + 1, -1);
    vector<int> knuth(n + 1, -1);
    for (int i = 0, j = -1; i < n; i++) {
      while (~j && s[i] != s[j]) j = knuth[j];
      knuth[i + 1] = KMP[i + 1] = ++j;
      if (i + 1 < n && s[i + 1] == s[j]) knuth[i + 1] = knuth[j];
    }
  }

  // the period of S[0:i]
  int period(int i) { return i - KMP[i]; }

  // positions for T that match s
  // O(|T|)
  vector<int> pattern_match(string T) {
    int m = T.length();
    vector<int> occur;
    for (int i = 0, k = 0; i < m; ++i) {
      while (k >= 0 && T[i] != s[k]) k = KMP[k];
      if (++k == n) {
        /* match at T[i-n+1 ... i] */
        occur.push_back(i - n + 1);
      }
    }
    return occur;
  }
};
#line 9 "test/aoj/ALDS1_14_B.KMP.test.cpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string T, P;
    cin >> T >> P;
    KnuthMorrisPratt KMP(P);
    auto ans = KMP.pattern_match(T);
    for(auto a : ans) {
        cout << a << "\n";
    }
    cout << flush;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

