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


# :heavy_check_mark: test/yosupo/z_algorithm.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/z_algorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 01:08:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/String/z_algorithm.hpp.html">最長共通接頭辞(Z-Algorithm)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "String/z_algorithm.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  vector<int> ans = z_algorithm(s);
  for (int i = 0; i < s.size(); i++) {
    cout << (i ? " " : "") << ans[i];
  }
  cout << endl;
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/z_algorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "String/z_algorithm.hpp"
/**
 * @title 最長共通接頭辞(Z-Algorithm)
 * @category 文字列
 * @brief $prefix_i$ は、$S$ と $S.substr(i)$ の LCP(longest common prefix)
 * @brief O(|S|)
 */

#ifndef call_from_test
#line 10 "String/z_algorithm.hpp"
using namespace std;
#endif

vector<int> z_algorithm(const string &s) {
  vector<int> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++) {
    if (i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}
#line 8 "test/yosupo/z_algorithm.test.cpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  vector<int> ans = z_algorithm(s);
  for (int i = 0; i < s.size(); i++) {
    cout << (i ? " " : "") << ans[i];
  }
  cout << endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

