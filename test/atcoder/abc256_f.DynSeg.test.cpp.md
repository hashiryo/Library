---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dynamic.hpp
    title: "Segment-Tree(\u52D5\u7684\u69CB\u7BC9)"
  - icon: ':heavy_check_mark:'
    path: src/Internal/HAS_CHECK.hpp
    title: "\u30E1\u30F3\u30D0\u306E\u6709\u7121\u3092\u5224\u5B9A\u3059\u308B\u30C6\
      \u30F3\u30D7\u30EC\u30FC\u30C8 \u4ED6"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_f
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
  bundledCode: "#line 1 \"test/atcoder/abc256_f.DynSeg.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n// \u53CC\u5BFE \u306E\
    \ verify\n#include <iostream>\n#include <array>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\ntemplate <class mod_t,\
    \ size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n static\
    \ const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n if\
    \ (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 3 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\n#include\
    \ <vector>\n#include <string>\n#include <algorithm>\n#include <tuple>\n#include\
    \ <cstddef>\n#include <cstdint>\n#line 3 \"src/Internal/HAS_CHECK.hpp\"\n#define\
    \ MEMBER_MACRO(member, Dummy, name, type1, type2, last) \\\n template <class tClass>\
    \ struct name##member { \\\n  template <class U, Dummy> static type1 check(U *);\
    \ \\\n  static type2 check(...); \\\n  static tClass *mClass; \\\n  last; \\\n\
    \ }\n#define HAS_CHECK(member, Dummy) MEMBER_MACRO(member, Dummy, has_, std::true_type,\
    \ std::false_type, static const bool value= decltype(check(mClass))::value)\n\
    #define HAS_MEMBER(member) HAS_CHECK(member, int dummy= (&U::member, 0))\n#define\
    \ HAS_TYPE(member) HAS_CHECK(member, class dummy= typename U::member)\n#define\
    \ HOGE_OR(member, name, type2) \\\n MEMBER_MACRO(member, class dummy= typename\
    \ U::member, name, typename U::member, type2, using type= decltype(check(mClass)));\
    \ \\\n template <class tClass> using name##member##_t= typename name##member<tClass>::type\n\
    #define NULLPTR_OR(member) HOGE_OR(member, nullptr_or_, std::nullptr_t)\n#define\
    \ MYSELF_OR(member) HOGE_OR(member, myself_or_, tClass)\n#line 10 \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \ntemplate <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Dynamic\
    \ {\n HAS_MEMBER(op);\n HAS_MEMBER(ti);\n HAS_MEMBER(mp);\n HAS_MEMBER(cp);\n\
    \ HAS_TYPE(T);\n HAS_TYPE(E);\n NULLPTR_OR(E);\n template <class L> static constexpr\
    \ bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;\n template\
    \ <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>, has_E<L>,\
    \ has_mp<L>, has_cp<L>>;\n using id_t= long long;\n template <class T, class tDerived>\
    \ struct Node_B {\n  T val;\n  tDerived *ch[2]= {nullptr, nullptr};\n };\n template\
    \ <bool mo, bool du, typename tEnable= void> struct Node_D: Node_B<M, Node_D<mo,\
    \ du, tEnable>> {};\n template <bool mo, bool du> struct Node_D<mo, du, typename\
    \ std::enable_if_t<mo && !du>>: Node_B<typename M::T, Node_D<mo, du>> {};\n template\
    \ <bool mo, bool du> struct Node_D<mo, du, typename std::enable_if_t<du>>: Node_B<typename\
    \ M::T, Node_D<mo, du>> {\n  typename M::E lazy;\n  bool lazy_flg= false;\n };\n\
    \ using Node= Node_D<monoid_v<M>, dual_v<M>>;\n using T= decltype(Node::val);\n\
    \ using E= nullptr_or_E_t<M>;\n using np= Node *;\n np root;\n static inline constexpr\
    \ T def_val() {\n  if constexpr (monoid_v<M>) return M::ti();\n  else return T();\n\
    \ }\n template <class S> np build(id_t n, id_t l, id_t r, const S &bg) {\n  if\
    \ (n <= l) return nullptr;\n  if (r - l == 1) {\n   if constexpr (std::is_same_v<S,\
    \ T>) return new Node{bg};\n   else return new Node{*(bg + l)};\n  }\n  id_t m=\
    \ (r + l) / 2;\n  np t= new Node{def_val(), {build(n, l, m, bg), build(n, m, r,\
    \ bg)}};\n  if constexpr (monoid_v<M>) update(t);\n  return t;\n }\n void dump(np\
    \ t, const id_t &l, const id_t &r, std::array<id_t, 2> b, typename std::vector<T>::iterator\
    \ itr) {\n  if (r <= b[0] || b[1] <= l) return;\n  if (l <= b[0] && b[1] <= r\
    \ && !t) {\n   for (id_t i= b[0]; i < b[1]; i++) *(itr + i)= def_val();\n  } else\
    \ if (b[1] - b[0] != 1) {\n   if constexpr (dual_v<M>) push(t, b[1] - b[0]);\n\
    \   auto m= (b[0] + b[1]) >> 1;\n   dump(t ? t->ch[0] : nullptr, l, r, {b[0],\
    \ m}, itr);\n   dump(t ? t->ch[1] : nullptr, l, r, {m, b[1]}, itr);\n  } else\
    \ *(itr + b[0])= t->val;\n }\n static inline void update(np &t) {\n  t->val= def_val();\n\
    \  if (t->ch[0]) t->val= M::op(t->ch[0]->val, t->val);\n  if (t->ch[1]) t->val=\
    \ M::op(t->val, t->ch[1]->val);\n }\n static inline T &reflect(np &t) {\n  if\
    \ constexpr (dual_v<M> && !monoid_v<M>)\n   if (t->lazy_flg) M::mp(t->val, t->lazy,\
    \ 1), t->lazy_flg= false;\n  return t->val;\n }\n static inline void propagate(np\
    \ &t, const E &x, const id_t &sz) {\n  t->lazy_flg ? (M::cp(t->lazy, x), x) :\
    \ t->lazy= x;\n  t->lazy_flg= true;\n  if constexpr (monoid_v<M>) M::mp(t->val,\
    \ x, sz);\n }\n static inline void cp_node(np &t) {\n  if (!t) t= new Node{def_val()};\n\
    \  else if constexpr (persistent) t= new Node(*t);\n }\n static inline void push(np\
    \ &t, const id_t &sz) {\n  if (!t->lazy_flg) return;\n  cp_node(t->ch[0]), cp_node(t->ch[1]),\
    \ t->lazy_flg= false;\n  propagate(t->ch[0], t->lazy, sz / 2), propagate(t->ch[1],\
    \ t->lazy, sz / 2);\n }\n T fold(np &t, const id_t &l, const id_t &r, std::array<id_t,\
    \ 2> b, const id_t &bias) {\n  if (!t || r <= b[0] || b[1] <= l) return def_val();\n\
    \  if (l <= b[0] && b[1] <= r) return t->val;\n  if constexpr (dual_v<M>) push(t,\
    \ b[1] - b[0]);\n  id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (__builtin_ctzll(b[1]\
    \ - b[0]) - 1)) & 1;\n  return M::op(fold(t->ch[flg], l, r, {b[0], m}, bias),\
    \ fold(t->ch[!flg], l, r, {m, b[1]}, bias));\n }\n void apply(np &t, const id_t\
    \ &l, const id_t &r, std::array<id_t, 2> b, const E &x) {\n  if (r <= b[0] ||\
    \ b[1] <= l) return;\n  id_t m= (b[0] + b[1]) >> 1;\n  if (cp_node(t); l <= b[0]\
    \ && b[1] <= r) return propagate(t, x, b[1] - b[0]);\n  push(t, b[1] - b[0]);\n\
    \  apply(t->ch[0], l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);\n\
    \  if constexpr (monoid_v<M>) update(t);\n }\n void set_val(np &t, const id_t\
    \ &k, const T &val, uint8_t h) {\n  if (cp_node(t); !h) return reflect(t)= val,\
    \ void();\n  if constexpr (dual_v<M>) push(t, 1LL << h);\n  set_val(t->ch[(k >>\
    \ (h - 1)) & 1], k, val, h - 1);\n  if constexpr (monoid_v<M>) update(t);\n }\n\
    \ T &at_val(np &t, const id_t &k, uint8_t h) {\n  if (cp_node(t); !h) return reflect(t);\n\
    \  if constexpr (dual_v<M>) push(t, 1LL << h);\n  return at_val(t->ch[(k >> (h\
    \ - 1)) & 1], k, h - 1);\n }\n bool is_null(np &t, const id_t &k, uint8_t h) {\n\
    \  if (!t) return true;\n  if (!h) return false;\n  if constexpr (dual_v<M>) push(t,\
    \ 1LL << h);\n  return is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);\n }\n T get_val(np\
    \ &t, const id_t &k, uint8_t h) {\n  if (!t) return def_val();\n  if (!h) return\
    \ reflect(t);\n  if constexpr (dual_v<M>) push(t, 1LL << h);\n  return get_val(t->ch[(k\
    \ >> (h - 1)) & 1], k, h - 1);\n }\n template <bool last> static inline T calc_op(np\
    \ &t, const T &v) {\n  if constexpr (last) return M::op((t ? t->val : def_val()),\
    \ v);\n  else return M::op(v, (t ? t->val : def_val()));\n }\n template <bool\
    \ last> static inline bool is_in(const id_t &m, const id_t &k) {\n  if constexpr\
    \ (last) return k <= m;\n  else return m <= k;\n }\n template <bool last, class\
    \ C, std::size_t N> static id_t find(const id_t &k, std::array<id_t, 2> b, const\
    \ id_t &bias, uint8_t h, const C &check, std::array<np, N> &ts, std::array<T,\
    \ N> &sums) {\n  static_assert(monoid_v<M>, \"\\\"find\\\" is not available\\\
    n\");\n  static std::array<T, N> sums2;\n  if (std::all_of(ts.begin(), ts.end(),\
    \ [](np t) { return !t; })) return -1;\n  if (!h) {\n   for (std::size_t i= N;\
    \ i--;) sums[i]= calc_op<last>(ts[i], sums[i]);\n   return std::apply(check, sums)\
    \ ? std::get<last>(b) : -1;\n  } else if (is_in<last>(k, b[0])) {\n   for (std::size_t\
    \ i= N; i--;) sums2[i]= calc_op<last>(ts[i], sums[i]);\n   if (!std::apply(check,\
    \ sums2)) return sums= std::move(sums2), -1;\n  }\n  if constexpr (dual_v<M>)\n\
    \   for (std::size_t i= N; i--;) push(ts[i], b[1] - b[0]);\n  std::array<np, N>\
    \ ss;\n  id_t m= (b[0] + b[1]) >> 1;\n  bool flg= (bias >> (h - 1)) & 1;\n  if\
    \ (!is_in<last>(m, k)) {\n   for (std::size_t i= N; i--;) ss[i]= ts[i] ? ts[i]->ch[flg]\
    \ : nullptr;\n   id_t ret= find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);\n\
    \   if (ret >= 0) return ret;\n  }\n  for (std::size_t i= N; i--;) ss[i]= ts[i]\
    \ ? ts[i]->ch[!flg] : nullptr;\n  return find<last>(k, {m, b[1]}, bias, h - 1,\
    \ check, ss, sums);\n }\npublic:\n SegmentTree_Dynamic(np t= nullptr): root(t)\
    \ {}\n SegmentTree_Dynamic(std::size_t n, T val): root(build(n, 0, 1LL << HEIGHT,\
    \ val)) {}\n SegmentTree_Dynamic(const T *bg, const T *ed): root(build(ed - bg,\
    \ 0, 1LL << HEIGHT, bg)) {}\n SegmentTree_Dynamic(const std::vector<T> &ar): SegmentTree_Dynamic(ar.data(),\
    \ ar.data() + ar.size()) {}\n void set(id_t k, T val) { set_val(root, k, val,\
    \ HEIGHT); }\n T get(id_t k) { return get_val(root, k, HEIGHT); }\n bool is_null(id_t\
    \ k) { return is_null(root, k, HEIGHT); }\n T &at(id_t k) {\n  static_assert(!monoid_v<M>,\
    \ \"\\\"at\\\" is not available\\n\");\n  return at_val(root, k, HEIGHT);\n }\n\
    \ template <class L= M, std::enable_if_t<monoid_v<L>, std::nullptr_t> = nullptr>\
    \ T operator[](id_t k) { return get(k); }\n template <class L= M, std::enable_if_t<!monoid_v<L>,\
    \ std::nullptr_t> = nullptr> T &operator[](id_t k) { return at(k); }\n T fold(id_t\
    \ a, id_t b, id_t bias= 0) {\n  static_assert(monoid_v<M>, \"\\\"fold\\\" is not\
    \ available\\n\");\n  return fold(root, a, b, {0, 1LL << HEIGHT}, bias);\n }\n\
    \ // find i s.t.\n //  check(fold(a,i)) == False, check(fold(a,i+1)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_first(id_t a, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);\n }\n template\
    \ <std::size_t N, class C> static id_t find_first(id_t a, C check, std::array<SegmentTree_Dynamic,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, ts, sums);\n }\n\
    \ // find i s.t.\n //  check(fold(i+1,b)) == False, check(fold(i,b)) == True\n\
    \ // return -1 if not found\n template <class C> id_t find_last(id_t b, C check,\
    \ id_t bias= 0) {\n  std::array<T, 1> sum{def_val()};\n  std::array<np, 1> t{root};\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, t, sum);\n }\n\
    \ template <std::size_t N, class C> static id_t find_last(id_t b, C check, std::array<SegmentTree_Dynamic,\
    \ N> segs, id_t bias= 0) {\n  std::array<T, N> sums;\n  sums.fill(def_val());\n\
    \  std::array<np, N> ts;\n  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;\n\
    \  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, ts, sums);\n }\n\
    \ void apply(id_t a, id_t b, E x) {\n  static_assert(dual_v<M>, \"\\\"apply\\\"\
    \ is not available\\n\");\n  apply(root, a, b, {0, 1LL << HEIGHT}, x);\n }\n std::vector<T>\
    \ dump(id_t bg, id_t ed) {\n  std::vector<T> ret(ed - bg);\n  return dump(root,\
    \ bg, ed, {0, 1LL << HEIGHT}, ret.begin()), ret;\n }\n static std::string which_available()\
    \ {\n  std::string ret= \"\";\n  if constexpr (monoid_v<M>) ret+= \"\\\"fold\\\
    \" \\\"find\\\" \";\n  else ret+= \"\\\"at\\\" \";\n  if constexpr (dual_v<M>)\
    \ ret+= \"\\\"apply\\\" \";\n  return ret;\n }\n};\n#line 7 \"test/atcoder/abc256_f.DynSeg.test.cpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct Mono {\n struct\
    \ T {\n  Mint val, coef[2];\n  T()= default;\n  T(Mint id, Mint v): val(v), coef{(id\
    \ + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using E= array<Mint, 3>;\n\
    \ static void mp(T &x, const E &mapp, int) { x.val+= mapp[0] * x.coef[0] - mapp[1]\
    \ * x.coef[1] + mapp[2]; }\n static void cp(E &pre, const E &suf) { pre[0]+= suf[0],\
    \ pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, Q;\n cin >> N >> Q;\n Mint A[N], D[N];\n for (int i= 0; i < N; i++) cin\
    \ >> A[i], D[i]= A[i];\n for (int j= 0; j < 3; j++)\n  for (int i= 1; i < N; i++)\
    \ D[i]+= D[i - 1];\n SegmentTree_Dynamic<Mono> seg;\n for (int i= 0; i < N; i++)\
    \ seg.set(i, {i, D[i]});\n while (Q--) {\n  int op, x;\n  cin >> op >> x, x--;\n\
    \  if (op == 1) {\n   Mint v;\n   cin >> v, v-= A[x], A[x]+= v;\n   seg.apply(x,\
    \ N, {v, v * x, v * x * x / 2});\n  } else {\n   cout << seg[x].val << '\\n';\n\
    \  }\n }\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_f\"\n//\
    \ \u53CC\u5BFE \u306E verify\n#include <iostream>\n#include <array>\n#include\
    \ \"src/Math/ModInt.hpp\"\n#include \"src/DataStructure/SegmentTree_Dynamic.hpp\"\
    \nusing namespace std;\n\nusing Mint= ModInt<998244353>;\nstruct Mono {\n struct\
    \ T {\n  Mint val, coef[2];\n  T()= default;\n  T(Mint id, Mint v): val(v), coef{(id\
    \ + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}\n };\n using E= array<Mint, 3>;\n\
    \ static void mp(T &x, const E &mapp, int) { x.val+= mapp[0] * x.coef[0] - mapp[1]\
    \ * x.coef[1] + mapp[2]; }\n static void cp(E &pre, const E &suf) { pre[0]+= suf[0],\
    \ pre[1]+= suf[1], pre[2]+= suf[2]; }\n};\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ int N, Q;\n cin >> N >> Q;\n Mint A[N], D[N];\n for (int i= 0; i < N; i++) cin\
    \ >> A[i], D[i]= A[i];\n for (int j= 0; j < 3; j++)\n  for (int i= 1; i < N; i++)\
    \ D[i]+= D[i - 1];\n SegmentTree_Dynamic<Mono> seg;\n for (int i= 0; i < N; i++)\
    \ seg.set(i, {i, D[i]});\n while (Q--) {\n  int op, x;\n  cin >> op >> x, x--;\n\
    \  if (op == 1) {\n   Mint v;\n   cin >> v, v-= A[x], A[x]+= v;\n   seg.apply(x,\
    \ N, {v, v * x, v * x * x / 2});\n  } else {\n   cout << seg[x].val << '\\n';\n\
    \  }\n }\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/DataStructure/SegmentTree_Dynamic.hpp
  - src/Internal/HAS_CHECK.hpp
  isVerificationFile: true
  path: test/atcoder/abc256_f.DynSeg.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 11:44:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc256_f.DynSeg.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256_f.DynSeg.test.cpp
- /verify/test/atcoder/abc256_f.DynSeg.test.cpp.html
title: test/atcoder/abc256_f.DynSeg.test.cpp
---
