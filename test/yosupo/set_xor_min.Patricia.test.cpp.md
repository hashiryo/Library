---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/SegmentTree_Patricia.hpp
    title: "Segment-Tree(\u30D1\u30C8\u30EA\u30B7\u30A2\u6728)"
  - icon: ':question:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.Patricia.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include <iostream>\n#line\
    \ 2 \"src/DataStructure/SegmentTree_Patricia.hpp\"\n#include <array>\n#include\
    \ <vector>\n#include <string>\n#include <algorithm>\n#include <tuple>\n#include\
    \ <cstddef>\n#include <cstdint>\n#line 2 \"src/Internal/HAS_CHECK.hpp\"\n#include\
    \ <type_traits>\n#define MEMBER_MACRO(member, Dummy, name, type1, type2, last)\
    \ \\\n template <class tClass> struct name##member { \\\n  template <class U,\
    \ Dummy> static type1 check(U *); \\\n  static type2 check(...); \\\n  static\
    \ tClass *mClass; \\\n  last; \\\n }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member,\
    \ Dummy, has_, std::true_type, std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 10 \"src/DataStructure/SegmentTree_Patricia.hpp\"\
    \ntemplate <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Patricia\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_TYPE(T);\n template <class L> static\
    \ constexpr bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n\
    \ using id_t= long long;\n template <class T, class tDerived> struct Node_B {\n\
    \  id_t bits;\n  uint8_t len;\n  T val;\n  tDerived *ch[2]= {nullptr, nullptr};\n\
    \ };\n template <bool mo, typename tEnable= void> struct Node_D: Node_B<M, Node_D<mo,\
    \ tEnable>> {};\n template <bool mo> struct Node_D<mo, typename std::enable_if_t<mo>>:\
    \ Node_B<typename M::T, Node_D<mo>> {};\n using Node= Node_D<monoid_v<M>>;\n using\
    \ T= decltype(Node::val);\n using np= Node *;\n np root;\n static inline constexpr\
    \ T def_val() {\n  if constexpr (monoid_v<M>) return M::ti();\n  else return T();\n\
    \ }\n template <class S> np build(const id_t &n, id_t l, id_t r, const S &bg)\
    \ {\n  if (n <= l) return nullptr;\n  id_t m= (l + r) / 2;\n  while (n <= m) r=\
    \ m, m= (l + r) / 2;\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S,\
    \ T>) return new Node{l, HEIGHT + 1, bg};\n   else return new Node{l, HEIGHT +\
    \ 1, *(bg + l)};\n  }\n  uint8_t h= __builtin_ctzll(r - l);\n  np t= new Node{m\
    \ >> h, uint8_t(HEIGHT + 1 - h), def_val(), {build(n, l, m, bg), build(n, m, r,\
    \ bg)}};\n  if constexpr (monoid_v<M>) t->val= M::op(t->ch[0]->val, t->ch[1]->val);\n\
    \  return t;\n }\n void dump(np t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b, typename std::vector<T>::iterator itr, uint8_t h) {\n  if (r <= b[0] ||\
    \ b[1] <= l) return;\n  if (l <= b[0] && b[1] <= r && !t) {\n   for (id_t i= b[0];\
    \ i < b[1]; i++) *(itr + i)= def_val();\n  } else if (b[1] - b[0] != 1) {\n  \
    \ auto m= (b[0] + b[1]) >> 1;\n   dump(next(t, h, 0), l, r, {b[0], m}, itr, h\
    \ - 1);\n   dump(next(t, h, 1), l, r, {m, b[1]}, itr, h - 1);\n  } else *(itr\
    \ + b[0])= t->val;\n }\n T fold(np &t, const id_t &l, const id_t &r, const id_t\
    \ &bias) {\n  static id_t bits, b[2];\n  if (!t) return def_val();\n  uint8_t\
    \ h= (HEIGHT + 1) - t->len;\n  bits= (bias >> h) ^ t->bits, b[0]= bits << h, b[1]=\
    \ (bits + 1) << h;\n  if (r <= b[0] || b[1] <= l) return def_val();\n  if (l <=\
    \ b[0] && b[1] <= r) return t->val;\n  bool flg= (bias >> (h - 1)) & 1;\n  return\
    \ M::op(fold(t->ch[flg], l, r, bias), fold(t->ch[!flg], l, r, bias));\n }\n void\
    \ set_val(np &t, const id_t &k, const T &val) {\n  if (!t) return t= new Node{k,\
    \ HEIGHT + 1, val}, void();\n  if constexpr (persistent) t= new Node{*t};\n  id_t\
    \ bits= (k >> ((HEIGHT + 1) - t->len));\n  if (bits != t->bits) {\n   uint8_t\
    \ i= 64 - __builtin_clzll(bits ^ t->bits);\n   bool flg= (t->bits >> (i - 1))\
    \ & 1;\n   t->ch[flg]= new Node{*t}, t->ch[!flg]= new Node{k, HEIGHT + 1, val};\n\
    \   t->len-= i, t->bits>>= i;\n  } else if (t->len != HEIGHT + 1) {\n   set_val(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k, val);\n  } else return t->val= val, void();\n\
    \  if constexpr (monoid_v<M>) t->val= M::op(t->ch[0]->val, t->ch[1]->val);\n }\n\
    \ T &at_val(np &t, const id_t &k) {\n  if (!t) return t= new Node{k, HEIGHT +\
    \ 1, def_val()}, t->val;\n  if constexpr (persistent) t= new Node{*t};\n  id_t\
    \ bits= (k >> ((HEIGHT + 1) - t->len));\n  if (bits != t->bits) {\n   uint8_t\
    \ i= 64 - __builtin_clzll(bits ^ t->bits);\n   bool flg= (t->bits >> (i - 1))\
    \ & 1;\n   t->ch[flg]= new Node{*t}, t->ch[!flg]= new Node{k, HEIGHT + 1, def_val()};\n\
    \   t->len-= i, t->bits>>= i;\n   return t->ch[!flg]->val;\n  } else if (t->len\
    \ != HEIGHT + 1) return at_val(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n  return\
    \ t->val;\n }\n bool is_null(np &t, const id_t &k) {\n  if (!t || (k >> ((HEIGHT\
    \ + 1) - t->len)) != t->bits) return true;\n  if (t->len == HEIGHT + 1) return\
    \ false;\n  return is_null(t->ch[(k >> (HEIGHT - t->len)) & 1], k);\n }\n T get_val(np\
    \ &t, const id_t &k) {\n  if (!t || (k >> ((HEIGHT + 1) - t->len)) != t->bits)\
    \ return def_val();\n  if (t->len == HEIGHT + 1) return t->val;\n  return get_val(t->ch[(k\
    \ >> (HEIGHT - t->len)) & 1], k);\n }\n template <bool last> static inline T calc_op(np\
    \ &t, const T &v) {\n  if constexpr (last) return M::op((t ? t->val : def_val()),\
    \ v);\n  else return M::op(v, (t ? t->val : def_val()));\n }\n template <bool\
    \ last> static inline bool is_in(const id_t &m, const id_t &k) {\n  if constexpr\
    \ (last) return k <= m;\n  else return m <= k;\n }\n static inline np next(np\
    \ &t, const uint8_t &h, const bool &f) {\n  if (!t) return nullptr;\n  uint8_t\
    \ len= h + t->len - (HEIGHT + 1);\n  if (!len) return t->ch[f];\n  return (f ==\
    \ ((t->bits >> (len - 1)) & 1)) ? t : nullptr;\n }\n template <bool last, class\
    \ C, std::size_t N> static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias, uint8_t h, const C &check, std::array<np, N> &ts, std::array<T,\
    \ N> &sums) {\n  static_assert(monoid_v<M>, \"\\\"find\\\" is not available\\\
    n\");\n  static std::array<T, N> sums2;\n  if (std::all_of(ts.begin(), ts.end(),\
    \ [](np t) { return !t; })) return -1;\n  if (!h) {\n   for (std::size_t i= N;\
    \ i--;) sums[i]= calc_op<last>(ts[i], sums[i]);\n   return std::apply(check, sums)\
    \ ? std::get<last>(b) : -1;\n  } else if (is_in<last>(k, b[0])) {\n   for (std::size_t\
    \ i= N; i--;) sums2[i]= calc_op<last>(ts[i], sums[i]);\n   if (!std::apply(check,\
    \ sums2)) return sums= std::move(sums2), -1;\n  }\n  std::array<np, N> ss;\n \
    \ id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (h - 1)) & 1;\n  if (!is_in<last>(m,\
    \ k)) {\n   for (std::size_t i= N; i--;) ss[i]= next(ts[i], h, flg);\n   id_t\
    \ ret= find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n   if (ret >=\
    \ 0) return ret;\n  }\n  for (std::size_t i= N; i--;) ss[i]= next(ts[i], h, !flg);\n\
    \  return find<last>(k, {m, b[1]}, bias, h - 1, check, ss, sums);\n }\npublic:\n\
    \ SegmentTree_Patricia(np t= nullptr): root(t) {}\n SegmentTree_Patricia(std::size_t\
    \ n, T val): root(build(n, 0, 1LL << HEIGHT, val)) {}\n SegmentTree_Patricia(T\
    \ *bg, T *ed): root(build(ed - bg, 0, 1LL << HEIGHT, bg)) {}\n SegmentTree_Patricia(const\
    \ std::vector<T> &ar): SegmentTree_Patricia(ar.data(), ar.data() + ar.size())\
    \ {}\n void set(id_t k, T val) { set_val(root, k, val); }\n T get(id_t k) { return\
    \ get_val(root, k); }\n bool is_null(id_t k) { return is_null(root, k); }\n T\
    \ &at(id_t k) {\n  static_assert(!monoid_v<M>, \"\\\"at\\\" is not available\\\
    n\");\n  return at_val(root, k);\n }\n template <class L= M, std::enable_if_t<monoid_v<L>,\
    \ std::nullptr_t> = nullptr> T operator[](id_t k) { return get(k); }\n template\
    \ <class L= M, std::enable_if_t<!monoid_v<L>, std::nullptr_t> = nullptr> T &operator[](id_t\
    \ k) { return at(k); }\n T fold(id_t a, id_t b, id_t bias= 0) {\n  static_assert(monoid_v<M>,\
    \ \"\\\"fold\\\" is not available\\n\");\n  return fold(root, a, b, bias);\n }\n\
    \ // find i s.t.\n //  check(fold(k,i)) == False, check(fold(k,i+1)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_first(id_t a, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n }\n template\
    \ <std::size_t N, class C> static id_t find_first(id_t a, C check, std::array<SegmentTree_Patricia,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, ts, sums);\n }\n\
    \ // find i s.t.\n //  check(fold(i+1,k)) == False, check(fold(i,k)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_last(id_t b, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, t, sum);\n }\n\
    \ template <std::size_t N, class C> static id_t find_last(id_t b, C check, std::array<SegmentTree_Patricia,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, ts, sums);\n }\n\
    \ std::vector<T> dump(id_t bg, id_t ed) {\n  std::vector<T> ret(ed - bg);\n  dump(root,\
    \ bg, ed, {0, 1LL << HEIGHT}, ret.begin(), HEIGHT);\n  return ret;\n }\n static\
    \ std::string which_available() {\n  std::string ret= \"\";\n  if constexpr (monoid_v<M>)\
    \ ret+= \"\\\"fold\\\" \\\"find\\\"\";\n  else ret+= \"\\\"at\\\" \";\n  return\
    \ ret;\n }\n};\n#line 4 \"test/yosupo/set_xor_min.Patricia.test.cpp\"\n\n// find\
    \ + xor \u306E verify\n\nusing namespace std;\nstruct RsumQ {\n using T= int;\n\
    \ static T ti() { return 0; }\n static T op(const T &l, const T &r) { return l\
    \ + r; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n SegmentTree_Patricia<RsumQ>\
    \ S;\n auto check= [&](int x) { return x >= 1; };\n int Q;\n cin >> Q;\n while\
    \ (Q--) {\n  int op, x;\n  cin >> op >> x;\n  if (op == 0) {\n   if (S[x] == 0)\
    \ S.set(x, 1);\n  } else if (op == 1) {\n   if (S[x] == 1) S.set(x, 0);\n  } else\
    \ {\n   cout << S.find_first(0, check, x) << endl;\n  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ <iostream>\n#include \"src/DataStructure/SegmentTree_Patricia.hpp\"\n\n// find\
    \ + xor \u306E verify\n\nusing namespace std;\nstruct RsumQ {\n using T= int;\n\
    \ static T ti() { return 0; }\n static T op(const T &l, const T &r) { return l\
    \ + r; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n SegmentTree_Patricia<RsumQ>\
    \ S;\n auto check= [&](int x) { return x >= 1; };\n int Q;\n cin >> Q;\n while\
    \ (Q--) {\n  int op, x;\n  cin >> op >> x;\n  if (op == 0) {\n   if (S[x] == 0)\
    \ S.set(x, 1);\n  } else if (op == 1) {\n   if (S[x] == 1) S.set(x, 0);\n  } else\
    \ {\n   cout << S.find_first(0, check, x) << endl;\n  }\n }\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Patricia.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.Patricia.test.cpp
  requiredBy: []
  timestamp: '2023-11-02 17:27:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.Patricia.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.Patricia.test.cpp
- /verify/test/yosupo/set_xor_min.Patricia.test.cpp.html
title: test/yosupo/set_xor_min.Patricia.test.cpp
---
