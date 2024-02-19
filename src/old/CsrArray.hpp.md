---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <iterator>\n#include <type_traits>\n#define _LR(name, IT,\
    \ CT) \\\n template <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT;\
    \ \\\n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\ntemplate\
    \ <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int> p;\n size_t\
    \ size() const { return p.size() - 1; }\n ListRange<T> operator[](int i) { return\
    \ {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T> operator[](int\
    \ i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate\
    \ <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/old/CsrArray.hpp\"\ntemplate <class T> class\
    \ CsrArray {\n std::vector<T> csr;\n std::vector<int> pos;\npublic:\n CsrArray()=\
    \ default;\n CsrArray(const std::vector<T> &c, const std::vector<int> &p): csr(c),\
    \ pos(p) {}\n size_t size() const { return pos.size() - 1; }\n const ConstListRange<T>\
    \ operator[](int i) const { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i\
    \ + 1]}; }\n};\n"
  code: "#pragma once\n#include \"src/Internal/ListRange.hpp\"\ntemplate <class T>\
    \ class CsrArray {\n std::vector<T> csr;\n std::vector<int> pos;\npublic:\n CsrArray()=\
    \ default;\n CsrArray(const std::vector<T> &c, const std::vector<int> &p): csr(c),\
    \ pos(p) {}\n size_t size() const { return pos.size() - 1; }\n const ConstListRange<T>\
    \ operator[](int i) const { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i\
    \ + 1]}; }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/old/CsrArray.hpp
  requiredBy: []
  timestamp: '2024-02-20 00:09:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/CsrArray.hpp
layout: document
title: "CSR\u5F62\u5F0F"
---
## 参考
[https://ja.wikipedia.org/wiki/疎行列#圧縮行格納](https://ja.wikipedia.org/wiki/%E7%96%8E%E8%A1%8C%E5%88%97#%E5%9C%A7%E7%B8%AE%E8%A1%8C%E6%A0%BC%E7%B4%8D) \
[https://nachiavivias.github.io/cp-library/column/2022/03.html](https://nachiavivias.github.io/cp-library/column/2022/03.html)
