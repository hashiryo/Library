---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Game/PartisanGame.hpp
    title: "\u975E\u4E0D\u504F\u30B2\u30FC\u30E0 (Conway\u306E\u69CB\u6210)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc229/tasks/abc229_h
    links:
    - https://atcoder.jp/contests/abc229/tasks/abc229_h
  bundledCode: "#line 1 \"test/atcoder/abc229_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc229/tasks/abc229_h\"\
    \n\n#include <bits/stdc++.h>\n#line 3 \"src/Game/PartisanGame.hpp\"\nclass DyadicRational\
    \ {\n static constexpr char FracLen= std::numeric_limits<std::uint64_t>::digits\
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
    \  return mp[g]= DyadicRational(L, R);\n }\n};\n#line 5 \"test/atcoder/abc229_h.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N;\n  cin >> N;\n  using Game = vector<int>;\n  auto f = [&](const Game\
    \ &g) {\n    vector<Game> gs[2];\n    for (int b = 0; b < 2; b++)\n      for (int\
    \ i = 0; i < N; i++)\n        if (g[i] == !b) {\n          gs[b].emplace_back(g),\
    \ gs[b].back()[i] = 2;\n        } else if (g[i] == b && i > 0 && g[i - 1] == 2)\
    \ {\n          gs[b].emplace_back(g), gs[b].back()[i - 1] = b, gs[b].back()[i]\
    \ = 2;\n        }\n    return make_pair(gs[0], gs[1]);\n  };\n  PartisanGame<Game,\
    \ decltype(f)> pg(f);\n  string S[N];\n  for (int i = 0; i < N; i++) cin >> S[i];\n\
    \  DyadicRational sum(0);\n  for (int j = 0; j < N; j++) {\n    Game g(N);\n \
    \   for (int i = 0; i < N; i++) g[i] = S[i][j] == '.' ? 2 : (S[i][j] == 'B');\n\
    \    sum += pg.eval(g);\n  }\n  cout << (sum > 0 ? \"Takahashi\" : \"Snuke\")\
    \ << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc229/tasks/abc229_h\"\n\n\
    #include <bits/stdc++.h>\n#include \"src/Game/PartisanGame.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int N;\n\
    \  cin >> N;\n  using Game = vector<int>;\n  auto f = [&](const Game &g) {\n \
    \   vector<Game> gs[2];\n    for (int b = 0; b < 2; b++)\n      for (int i = 0;\
    \ i < N; i++)\n        if (g[i] == !b) {\n          gs[b].emplace_back(g), gs[b].back()[i]\
    \ = 2;\n        } else if (g[i] == b && i > 0 && g[i - 1] == 2) {\n          gs[b].emplace_back(g),\
    \ gs[b].back()[i - 1] = b, gs[b].back()[i] = 2;\n        }\n    return make_pair(gs[0],\
    \ gs[1]);\n  };\n  PartisanGame<Game, decltype(f)> pg(f);\n  string S[N];\n  for\
    \ (int i = 0; i < N; i++) cin >> S[i];\n  DyadicRational sum(0);\n  for (int j\
    \ = 0; j < N; j++) {\n    Game g(N);\n    for (int i = 0; i < N; i++) g[i] = S[i][j]\
    \ == '.' ? 2 : (S[i][j] == 'B');\n    sum += pg.eval(g);\n  }\n  cout << (sum\
    \ > 0 ? \"Takahashi\" : \"Snuke\") << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Game/PartisanGame.hpp
  isVerificationFile: true
  path: test/atcoder/abc229_h.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 22:09:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc229_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc229_h.test.cpp
- /verify/test/atcoder/abc229_h.test.cpp.html
title: test/atcoder/abc229_h.test.cpp
---
