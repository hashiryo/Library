---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/String/SuffixArray.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217(Suffix-Array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_D.test.cpp\"\n#define PROBLEM \\\n  \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line 1 \"\
    src/String/SuffixArray.hpp\"\n/**\n * @title \u63A5\u5C3E\u8F9E\u914D\u5217(Suffix-Array)\n\
    \ * @category \u6587\u5B57\u5217\n *  \u69CB\u7BC9 O(|S| log |S|)\n *  lower_bound(T)\
    \ \u6587\u5B57\u5217T\u3092\u542B\u3080\u63A5\u5C3E\u8F9E\u306Eindex\u306E\u4E0B\
    \u9650 O(|T| log |S|)\n *  LongestCommonPrefix\u914D\u5217\uFF08\u9AD8\u3055\u914D\
    \u5217\uFF09 \u69CB\u7BC9 O(|S|)\n *  '$'\u306F\u5165\u308C\u3066\u306A\u3044\n\
    \ */\n\n#ifndef call_from_test\n#line 12 \"src/String/SuffixArray.hpp\"\nusing\
    \ namespace std;\n#endif\n\nstruct SuffixArray {\n  vector<int> SA;\n  const string\
    \ s;\n  SuffixArray(const string &str) : s(str) {\n    SA.resize(s.size());\n\
    \    iota(begin(SA), end(SA), 0);\n    sort(begin(SA), end(SA),\n         [&](int\
    \ a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n    vector<int>\
    \ classes(s.size()), c(s.begin(), s.end()), cnt(s.size());\n    for (int len =\
    \ 1; len < s.size(); len <<= 1) {\n      for (int i = 0; i < s.size(); i++) {\n\
    \        if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size()\n\
    \            && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {\n          classes[SA[i]]\
    \ = classes[SA[i - 1]];\n        } else {\n          classes[SA[i]] = i;\n   \
    \     }\n      }\n      iota(begin(cnt), end(cnt), 0);\n      copy(begin(SA),\
    \ end(SA), begin(c));\n      for (int i = 0; i < s.size(); i++) {\n        int\
    \ s1 = c[i] - len;\n        if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;\n      }\n\
    \      classes.swap(c);\n    }\n  }\n  int operator[](int k) const { return (SA[k]);\
    \ }\n\n  // O(|T|log|S|)\n  int lower_bound(string &T) {\n    int low = -1, high\
    \ = s.size();\n    while (high - low > 1) {\n      int m = (low + high) >> 1;\n\
    \      if (s.compare(SA[m], T.length(), T) < 0)\n        low = m;\n      else\n\
    \        high = m;\n    }\n    return high;\n  }\n  int upper_bound(string &T)\
    \ {\n    T.back()++;\n    int res = lower_bound(T);\n    T.back()--;\n    return\
    \ res;\n  }\n  // O(|T|log|S|)\n  int count(string &T) { return upper_bound(T)\
    \ - lower_bound(T); }\n\n  // O(|S|)\n  vector<int> get_lcp() {\n    vector<int>\
    \ rank(SA.size()), LCP(SA.size());\n    for (int i = 0; i < SA.size(); i++) rank[SA[i]]\
    \ = i;\n    for (int i = 0, h = 0; i < SA.size(); i++) {\n      if (rank[i] +\
    \ 1 < SA.size()) {\n        int j = SA[rank[i] + 1];\n        while (max(i, j)\
    \ + h < SA.size() && s[i + h] == s[j + h]) ++h;\n        LCP[rank[i] + 1] = h;\n\
    \        if (h > 0) --h;\n      }\n    }\n    return LCP;\n  }\n};\n#line 9 \"\
    test/aoj/ALDS1_14_D.test.cpp\"\n#undef call_from_test\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  string t;\n  cin >> t;\n  SuffixArray sa(t);\n\
    \  int Q;\n  cin >> Q;\n  while (Q--) {\n    string p;\n    cin >> p;\n    cout\
    \ << (sa.count(p) > 0) << \"\\n\";\n  }\n  cout << flush;\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"src/String/SuffixArray.hpp\"\n#undef call_from_test\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  string t;\n  cin >> t;\n  SuffixArray\
    \ sa(t);\n  int Q;\n  cin >> Q;\n  while (Q--) {\n    string p;\n    cin >> p;\n\
    \    cout << (sa.count(p) > 0) << \"\\n\";\n  }\n  cout << flush;\n  return 0;\n\
    }"
  dependsOn:
  - src/String/SuffixArray.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_D.test.cpp
  requiredBy: []
  timestamp: '2020-08-11 20:23:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_D.test.cpp
- /verify/test/aoj/ALDS1_14_D.test.cpp.html
title: test/aoj/ALDS1_14_D.test.cpp
---
