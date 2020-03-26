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


# :heavy_check_mark: Z_algorithm

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/z_algorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-26 16:32:30+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/z_algorithm.test.cpp.html">test/yosupo/z_algorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Z_algorithm
 * @brief $prefix_i$ は、$S$ と $S.substr(i)$ の LCP(longest common prefix)
 * @brief O(N)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

vector<int> z_algorithm(const string &s) {
    vector<int> prefix(s.size());
    for(int i = 1, j = 0; i < s.size(); i++) {
        if(i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while(i + k < s.size() && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (int)s.size();
    return prefix;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/z_algorithm.hpp"
/**
 * @title Z_algorithm
 * @brief $prefix_i$ は、$S$ と $S.substr(i)$ の LCP(longest common prefix)
 * @brief O(N)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

vector<int> z_algorithm(const string &s) {
    vector<int> prefix(s.size());
    for(int i = 1, j = 0; i < s.size(); i++) {
        if(i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while(i + k < s.size() && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j = i;
        }
    }
    prefix[0] = (int)s.size();
    return prefix;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

