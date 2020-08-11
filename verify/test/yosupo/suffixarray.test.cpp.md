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


# :x: test/yosupo/suffixarray.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/suffixarray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 20:23:42+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :question: <a href="../../../library/src/String/SuffixArray.hpp.html">接尾辞配列(Suffix-Array)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "src/String/SuffixArray.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string S;
  cin >> S;
  SuffixArray SA(S);
  for (int i = 0; i < S.length(); i++) {
    cout << (i ? " " : "") << SA[i];
  }
  cout << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/suffixarray.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "src/String/SuffixArray.hpp"
/**
 * @title 接尾辞配列(Suffix-Array)
 * @category 文字列
 *  構築 O(|S| log |S|)
 *  lower_bound(T) 文字列Tを含む接尾辞のindexの下限 O(|T| log |S|)
 *  LongestCommonPrefix配列（高さ配列） 構築 O(|S|)
 *  '$'は入れてない
 */

#ifndef call_from_test
#line 12 "src/String/SuffixArray.hpp"
using namespace std;
#endif

struct SuffixArray {
  vector<int> SA;
  const string s;
  SuffixArray(const string &str) : s(str) {
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA),
         [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
    vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
    for (int len = 1; len < s.size(); len <<= 1) {
      for (int i = 0; i < s.size(); i++) {
        if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size()
            && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
          classes[SA[i]] = classes[SA[i - 1]];
        } else {
          classes[SA[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(SA), end(SA), begin(c));
      for (int i = 0; i < s.size(); i++) {
        int s1 = c[i] - len;
        if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
  }
  int operator[](int k) const { return (SA[k]); }

  // O(|T|log|S|)
  int lower_bound(string &T) {
    int low = -1, high = s.size();
    while (high - low > 1) {
      int m = (low + high) >> 1;
      if (s.compare(SA[m], T.length(), T) < 0)
        low = m;
      else
        high = m;
    }
    return high;
  }
  int upper_bound(string &T) {
    T.back()++;
    int res = lower_bound(T);
    T.back()--;
    return res;
  }
  // O(|T|log|S|)
  int count(string &T) { return upper_bound(T) - lower_bound(T); }

  // O(|S|)
  vector<int> get_lcp() {
    vector<int> rank(SA.size()), LCP(SA.size());
    for (int i = 0; i < SA.size(); i++) rank[SA[i]] = i;
    for (int i = 0, h = 0; i < SA.size(); i++) {
      if (rank[i] + 1 < SA.size()) {
        int j = SA[rank[i] + 1];
        while (max(i, j) + h < SA.size() && s[i + h] == s[j + h]) ++h;
        LCP[rank[i] + 1] = h;
        if (h > 0) --h;
      }
    }
    return LCP;
  }
};
#line 8 "test/yosupo/suffixarray.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string S;
  cin >> S;
  SuffixArray SA(S);
  for (int i = 0; i < S.length(); i++) {
    cout << (i ? " " : "") << SA[i];
  }
  cout << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

