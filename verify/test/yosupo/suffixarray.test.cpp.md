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


# :heavy_check_mark: test/yosupo/suffixarray.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/suffixarray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-28 22:59:45+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/String/SuffixArray.hpp.html">SuffixArray</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "String/SuffixArray.hpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string S;
    cin >> S;
    SuffixArray SA(S);
    for(int i = 0; i < S.length(); i++) {
        if(i)
            cout << " ";
        cout << SA[i];
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
#line 1 "String/SuffixArray.hpp"
/**
 * @title SuffixArray
 * @brief 構築 O(|S| log |S|)
 */

#ifndef call_from_test
#line 8 "String/SuffixArray.hpp"
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
        for(int len = 1; len < s.size(); len <<= 1) {
            for(int i = 0; i < s.size(); i++) {
                if(i > 0 && c[SA[i - 1]] == c[SA[i]]
                   && SA[i - 1] + len < s.size()
                   && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
                    classes[SA[i]] = classes[SA[i - 1]];
                } else {
                    classes[SA[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(SA), end(SA), begin(c));
            for(int i = 0; i < s.size(); i++) {
                int s1 = c[i] - len;
                if(s1 >= 0)
                    SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }
    int operator[](int k) const { return (SA[k]); }
};
#line 8 "test/yosupo/suffixarray.test.cpp"
#undef call_from_test

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string S;
    cin >> S;
    SuffixArray SA(S);
    for(int i = 0; i < S.length(); i++) {
        if(i)
            cout << " ";
        cout << SA[i];
    }
    cout << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

