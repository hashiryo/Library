---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2614.rollinghash.test.cpp
    title: test/aoj/2614.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.rollinghash.test.cpp
    title: test/aoj/2711.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
    title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/z_algorithm.rollinghash.test.cpp
    title: test/yosupo/z_algorithm.rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/String/RollingHash.hpp\"\n#include <vector>\n#include\
    \ <random>\n#include <string>\ntemplate <class K> class RollingHash {\n static\
    \ inline std::vector<K> pw;\n static inline K base;\n static inline void set_pw(int\
    \ n) {\n  if (int m= pw.size(); m < n)\n   for (pw.resize(n); m < n; m++) pw[m]=\
    \ pw[m - 1] * base;\n }\n std::vector<K> hash;\npublic:\n class SubString {\n\
    \  const RollingHash *instance;\n  const int bg, ed;\n public:\n  SubString(const\
    \ RollingHash &rh): instance(&rh), bg(0), ed(rh.hash.size()) {}\n  SubString(const\
    \ RollingHash *i, int b, int e): instance(i), bg(b), ed(e) {}\n  inline K get_hash(int\
    \ l= 0, int r= -1) const { return instance->get_hash(bg + l, (r == -1 ? ed : bg\
    \ + r)); }\n  friend int lcp(const SubString &l, const SubString &r) {\n   int\
    \ ok= 0, ng= std::min(l.ed - l.bg, r.ed - r.bg) + 1;\n   for (int x; ng - ok >\
    \ 1;) x= (ok + ng) / 2, (l.get_hash(0, x) == r.get_hash(0, x) ? ok : ng)= x;\n\
    \   return ok;\n  }\n };\n static void set_base(K b) { base= b, pw.assign(1, 1);\
    \ }\n static K base_pow(int i) { return pw[i]; }\n RollingHash()= default;\n template\
    \ <class T> RollingHash(const std::vector<T> &v): hash(v.size() + 1, 0) {\n  set_pw(hash.size());\n\
    \  for (int i= 0, ed= v.size(); i < ed; i++) hash[i + 1]= hash[i] * base + v[i];\n\
    \ }\n RollingHash(const std::string &s): RollingHash(std::vector<char>(s.begin(),\
    \ s.end())) {}\n inline K get_hash(int l= 0, int r= -1) const {\n  if (r < 0)\
    \ r= hash.size() - 1;\n  return hash[r] - hash[l] * pw[r - l];\n }\n SubString\
    \ sub(int l, int r) const { return SubString{this, l, r}; }\n};\nstd::uint64_t\
    \ get_rand(std::uint64_t l, std::uint64_t r) {\n static std::mt19937_64 gen(std::random_device{}());\n\
    \ return std::uniform_int_distribution<std::uint64_t>(l, r)(gen);\n}\n"
  code: "#pragma once\n#include <vector>\n#include <random>\n#include <string>\ntemplate\
    \ <class K> class RollingHash {\n static inline std::vector<K> pw;\n static inline\
    \ K base;\n static inline void set_pw(int n) {\n  if (int m= pw.size(); m < n)\n\
    \   for (pw.resize(n); m < n; m++) pw[m]= pw[m - 1] * base;\n }\n std::vector<K>\
    \ hash;\npublic:\n class SubString {\n  const RollingHash *instance;\n  const\
    \ int bg, ed;\n public:\n  SubString(const RollingHash &rh): instance(&rh), bg(0),\
    \ ed(rh.hash.size()) {}\n  SubString(const RollingHash *i, int b, int e): instance(i),\
    \ bg(b), ed(e) {}\n  inline K get_hash(int l= 0, int r= -1) const { return instance->get_hash(bg\
    \ + l, (r == -1 ? ed : bg + r)); }\n  friend int lcp(const SubString &l, const\
    \ SubString &r) {\n   int ok= 0, ng= std::min(l.ed - l.bg, r.ed - r.bg) + 1;\n\
    \   for (int x; ng - ok > 1;) x= (ok + ng) / 2, (l.get_hash(0, x) == r.get_hash(0,\
    \ x) ? ok : ng)= x;\n   return ok;\n  }\n };\n static void set_base(K b) { base=\
    \ b, pw.assign(1, 1); }\n static K base_pow(int i) { return pw[i]; }\n RollingHash()=\
    \ default;\n template <class T> RollingHash(const std::vector<T> &v): hash(v.size()\
    \ + 1, 0) {\n  set_pw(hash.size());\n  for (int i= 0, ed= v.size(); i < ed; i++)\
    \ hash[i + 1]= hash[i] * base + v[i];\n }\n RollingHash(const std::string &s):\
    \ RollingHash(std::vector<char>(s.begin(), s.end())) {}\n inline K get_hash(int\
    \ l= 0, int r= -1) const {\n  if (r < 0) r= hash.size() - 1;\n  return hash[r]\
    \ - hash[l] * pw[r - l];\n }\n SubString sub(int l, int r) const { return SubString{this,\
    \ l, r}; }\n};\nstd::uint64_t get_rand(std::uint64_t l, std::uint64_t r) {\n static\
    \ std::mt19937_64 gen(std::random_device{}());\n return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/String/RollingHash.hpp
  requiredBy: []
  timestamp: '2023-01-21 20:06:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2711.rollinghash.test.cpp
  - test/aoj/2614.rollinghash.test.cpp
  - test/aoj/ALDS1_14_B.rollinghash.test.cpp
  - test/yosupo/z_algorithm.rollinghash.test.cpp
documentation_of: src/String/RollingHash.hpp
layout: document
title: Rolling-Hash
---
`+ - *` が定義されているクラスでhashを計算
## 問題例
[AtCoder Beginner Contest 274 Ex - XOR Sum of Arrays](https://atcoder.jp/contests/abc274/tasks/abc274_h) (標数2の体 e.g. Nimber)