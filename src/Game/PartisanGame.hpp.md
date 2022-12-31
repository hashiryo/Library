---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc229_h.test.cpp
    title: test/atcoder/abc229_h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Game/PartisanGame.hpp\"\n#include <bits/stdc++.h>\n\
    class DyadicRational {\n static constexpr char FracLen= std::numeric_limits<std::uint64_t>::digits\
    \ - 1;\n static constexpr std::uint64_t Denom= 1ULL << FracLen;\n int integ;\n\
    \ std::uint64_t frac;\n template <class l_t, class r_t>  // Conway's realization\n\
    \ static DyadicRational reduce(const std::vector<l_t> &L, const std::vector<r_t>\
    \ &R) {\n  if (L.empty() && R.empty()) return DyadicRational();\n  DyadicRational\
    \ sl, sr;\n  if (!L.empty()) sl= *std::max_element(L.begin(), L.end());\n  if\
    \ (!R.empty()) sr= *std::min_element(R.begin(), R.end());\n  if (L.empty()) return\
    \ DyadicRational(sr.integ - !sr.frac);\n  if (R.empty()) return DyadicRational(sl.integ\
    \ + 1);\n  return reduce(sl, sr);\n }\n static DyadicRational reduce(const DyadicRational\
    \ &l, const DyadicRational &r) {\n  assert(l < r);\n  if (r <= 0) return -reduce(-r,\
    \ -l);\n  if (l.integ < 0) return DyadicRational();\n  if (DyadicRational(l.integ\
    \ + 1) < r) return DyadicRational(l.integ + 1);\n  DyadicRational ret;\n  std::uint64_t\
    \ rfrac= r.frac == 0 ? Denom : r.frac;\n  std::uint64_t D= 1ULL << (FracLen -\
    \ __builtin_clzll(l.frac ^ rfrac));\n  std::uint64_t f= (l.frac & (Denom - D))\
    \ | D;\n  if (f < rfrac) return ret.integ= l.integ, ret.frac= f, ret;\n  D= 1ULL\
    \ << (FracLen - __builtin_clzll((l.frac & (D - 1)) ^ (D - 1)));\n  f= (l.frac\
    \ & (Denom - D)) | D;\n  return ret.integ= l.integ, ret.frac= f, ret;\n }\npublic:\n\
    \ DyadicRational(): integ(0), frac(0) {}\n DyadicRational(double x) {\n  double\
    \ i, f= std::modf(x, &i);\n  if (f < 0) f+= 1, i-= 1;\n  integ= i, frac= f * Denom;\n\
    \ }\n template <class l_t= double, class r_t= double> DyadicRational(const std::vector<l_t>\
    \ &L, const std::vector<r_t> &R): DyadicRational(reduce<l_t, r_t>(L, R)) {}\n\
    \ template <class l_t= double, class r_t= double> DyadicRational(const std::initializer_list<l_t>\
    \ &L, const std::initializer_list<r_t> &R): DyadicRational(reduce<l_t, r_t>(L,\
    \ R)) {}\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::vector<l_t> &L, const std::initializer_list<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::initializer_list<l_t> &L, const std::vector<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n double to_double() const { return integ + double(frac) / Denom;\
    \ }\n bool operator==(const DyadicRational &r) const { return integ == r.integ\
    \ && frac == r.frac; }\n bool operator!=(const DyadicRational &r) const { return\
    \ !(*this == r); }\n bool operator<(const DyadicRational &r) const { return integ\
    \ == r.integ ? frac < r.frac : integ < r.integ; }\n bool operator>(const DyadicRational\
    \ &r) const { return r < *this; }\n bool operator<=(const DyadicRational &r) const\
    \ { return !(r < *this); }\n bool operator>=(const DyadicRational &r) const {\
    \ return !(*this < r); }\n DyadicRational &operator+=(const DyadicRational &r)\
    \ {\n  if ((frac+= r.frac) >= Denom) integ++, frac-= Denom;\n  return integ+=\
    \ r.integ, *this;\n }\n DyadicRational &operator-=(const DyadicRational &r) {\n\
    \  frac= frac >= r.frac ? frac - r.frac : (integ--, frac + (Denom - r.frac));\n\
    \  return integ-= r.integ, *this;\n }\n DyadicRational operator-() const { return\
    \ DyadicRational()-= *this; }\n DyadicRational operator+(const DyadicRational\
    \ &r) const { return DyadicRational(*this)+= r; }\n DyadicRational operator-(const\
    \ DyadicRational &r) const { return DyadicRational(*this)-= r; }\n friend std::istream\
    \ &operator>>(std::istream &is, DyadicRational &r) {\n  double x;\n  return is\
    \ >> x, r= DyadicRational(x), is;\n }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const DyadicRational &r) { return os << r.to_double(); }\n};\ntemplate\
    \ <typename Game, typename F> class PartisanGame {\n std::map<Game, DyadicRational>\
    \ mp;\n F f;  // : Game -> (std::vector<Game>, std::vector<Game>)\npublic:\n PartisanGame(const\
    \ F &_f): f(_f) {}\n DyadicRational eval(Game g) {\n  if (mp.count(g)) return\
    \ mp[g];\n  auto [gls, grs]= f(g);\n  std::vector<DyadicRational> L, R;\n  for\
    \ (auto &gl: gls) L.emplace_back(eval(gl));\n  for (auto &gr: grs) R.emplace_back(eval(gr));\n\
    \  return mp[g]= DyadicRational(L, R);\n }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nclass DyadicRational {\n static constexpr\
    \ char FracLen= std::numeric_limits<std::uint64_t>::digits - 1;\n static constexpr\
    \ std::uint64_t Denom= 1ULL << FracLen;\n int integ;\n std::uint64_t frac;\n template\
    \ <class l_t, class r_t>  // Conway's realization\n static DyadicRational reduce(const\
    \ std::vector<l_t> &L, const std::vector<r_t> &R) {\n  if (L.empty() && R.empty())\
    \ return DyadicRational();\n  DyadicRational sl, sr;\n  if (!L.empty()) sl= *std::max_element(L.begin(),\
    \ L.end());\n  if (!R.empty()) sr= *std::min_element(R.begin(), R.end());\n  if\
    \ (L.empty()) return DyadicRational(sr.integ - !sr.frac);\n  if (R.empty()) return\
    \ DyadicRational(sl.integ + 1);\n  return reduce(sl, sr);\n }\n static DyadicRational\
    \ reduce(const DyadicRational &l, const DyadicRational &r) {\n  assert(l < r);\n\
    \  if (r <= 0) return -reduce(-r, -l);\n  if (l.integ < 0) return DyadicRational();\n\
    \  if (DyadicRational(l.integ + 1) < r) return DyadicRational(l.integ + 1);\n\
    \  DyadicRational ret;\n  std::uint64_t rfrac= r.frac == 0 ? Denom : r.frac;\n\
    \  std::uint64_t D= 1ULL << (FracLen - __builtin_clzll(l.frac ^ rfrac));\n  std::uint64_t\
    \ f= (l.frac & (Denom - D)) | D;\n  if (f < rfrac) return ret.integ= l.integ,\
    \ ret.frac= f, ret;\n  D= 1ULL << (FracLen - __builtin_clzll((l.frac & (D - 1))\
    \ ^ (D - 1)));\n  f= (l.frac & (Denom - D)) | D;\n  return ret.integ= l.integ,\
    \ ret.frac= f, ret;\n }\npublic:\n DyadicRational(): integ(0), frac(0) {}\n DyadicRational(double\
    \ x) {\n  double i, f= std::modf(x, &i);\n  if (f < 0) f+= 1, i-= 1;\n  integ=\
    \ i, frac= f * Denom;\n }\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::vector<l_t> &L, const std::vector<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::initializer_list<l_t> &L, const std::initializer_list<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::vector<l_t> &L, const std::initializer_list<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n template <class l_t= double, class r_t= double> DyadicRational(const\
    \ std::initializer_list<l_t> &L, const std::vector<r_t> &R): DyadicRational(reduce<l_t,\
    \ r_t>(L, R)) {}\n double to_double() const { return integ + double(frac) / Denom;\
    \ }\n bool operator==(const DyadicRational &r) const { return integ == r.integ\
    \ && frac == r.frac; }\n bool operator!=(const DyadicRational &r) const { return\
    \ !(*this == r); }\n bool operator<(const DyadicRational &r) const { return integ\
    \ == r.integ ? frac < r.frac : integ < r.integ; }\n bool operator>(const DyadicRational\
    \ &r) const { return r < *this; }\n bool operator<=(const DyadicRational &r) const\
    \ { return !(r < *this); }\n bool operator>=(const DyadicRational &r) const {\
    \ return !(*this < r); }\n DyadicRational &operator+=(const DyadicRational &r)\
    \ {\n  if ((frac+= r.frac) >= Denom) integ++, frac-= Denom;\n  return integ+=\
    \ r.integ, *this;\n }\n DyadicRational &operator-=(const DyadicRational &r) {\n\
    \  frac= frac >= r.frac ? frac - r.frac : (integ--, frac + (Denom - r.frac));\n\
    \  return integ-= r.integ, *this;\n }\n DyadicRational operator-() const { return\
    \ DyadicRational()-= *this; }\n DyadicRational operator+(const DyadicRational\
    \ &r) const { return DyadicRational(*this)+= r; }\n DyadicRational operator-(const\
    \ DyadicRational &r) const { return DyadicRational(*this)-= r; }\n friend std::istream\
    \ &operator>>(std::istream &is, DyadicRational &r) {\n  double x;\n  return is\
    \ >> x, r= DyadicRational(x), is;\n }\n friend std::ostream &operator<<(std::ostream\
    \ &os, const DyadicRational &r) { return os << r.to_double(); }\n};\ntemplate\
    \ <typename Game, typename F> class PartisanGame {\n std::map<Game, DyadicRational>\
    \ mp;\n F f;  // : Game -> (std::vector<Game>, std::vector<Game>)\npublic:\n PartisanGame(const\
    \ F &_f): f(_f) {}\n DyadicRational eval(Game g) {\n  if (mp.count(g)) return\
    \ mp[g];\n  auto [gls, grs]= f(g);\n  std::vector<DyadicRational> L, R;\n  for\
    \ (auto &gl: gls) L.emplace_back(eval(gl));\n  for (auto &gr: grs) R.emplace_back(eval(gr));\n\
    \  return mp[g]= DyadicRational(L, R);\n }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/Game/PartisanGame.hpp
  requiredBy: []
  timestamp: '2022-12-31 22:09:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc229_h.test.cpp
documentation_of: src/Game/PartisanGame.hpp
layout: document
title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0 (Conway\u306E\u69CB\u6210)"
---
メモ化再帰で2進分数を計算
## 参考
http://www.ivis.co.jp/text/20111102.pdf