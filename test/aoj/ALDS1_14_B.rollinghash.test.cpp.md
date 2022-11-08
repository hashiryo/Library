---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/CartesianProduct.hpp
    title: "\u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\cdots\\\
      times K_n$)"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/String/RollingHash.hpp
    title: Rolling-Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.rollinghash.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n\
    \ * @category \u6570\u5B66\n */\n\n// BEGIN CUT HERE\nnamespace modint_internal\
    \ {\nusing namespace std;\nstruct modint_base {};\nstruct sta_mint_base : modint_base\
    \ {};\nstruct dyn_mint_base : modint_base {};\ntemplate <class mod_t>\nconstexpr\
    \ bool is_modint_v = is_base_of_v<modint_base, mod_t>;\ntemplate <class mod_t>\n\
    constexpr bool is_staticmodint_v = is_base_of_v<sta_mint_base, mod_t>;\ntemplate\
    \ <class mod_t>\nconstexpr bool is_dynamicmodint_v = is_base_of_v<dyn_mint_base,\
    \ mod_t>;\nusing u64 = uint64_t;\nusing u128 = __uint128_t;\ntemplate <class D>\n\
    struct ModIntImpl {\n  static constexpr inline auto modulo() { return D::mod;\
    \ }\n  constexpr D operator-() const { return D() -= (D &)*this; }\n  constexpr\
    \ D &operator/=(const D &r) { return (D &)*this *= r.inv(); }\n  constexpr D operator+(const\
    \ D &r) const { return D((D &)*this) += r; }\n  constexpr D operator-(const D\
    \ &r) const { return D((D &)*this) -= r; }\n  constexpr D operator*(const D &r)\
    \ const { return D((D &)*this) *= r; }\n  constexpr D operator/(const D &r) const\
    \ { return D((D &)*this) /= r; }\n  constexpr bool operator!=(const D &r) const\
    \ { return !((D &)*this == r); }\n  constexpr D pow(u64 k) const {\n    for (D\
    \ ret(1), b((const D &)*this);; b *= b)\n      if (k & 1 ? ret *= b : 0; !(k >>=\
    \ 1)) return ret;\n  }\n  constexpr D inv() const {\n    typename D::Int x = 1,\
    \ y = 0, a = ((D *)this)->val(), b = D::mod;\n    for (typename D::Int q = 0,\
    \ z = 0, c = 0; b;)\n      z = x, c = a, x = y, y = z - y * (q = a / b), a = b,\
    \ b = c - b * q;\n    return assert(a == 1), D(x);\n  }\n  constexpr bool operator<(const\
    \ D &r) const {\n    return ((D *)this)->val() < r.val();\n  }  // for set or\
    \ map\n  friend ostream &operator<<(ostream &os, const D &r) { return os << r.val();\
    \ }\n  friend istream &operator>>(istream &is, D &r) {\n    long long v;\n   \
    \ return is >> v, r = D(v), is;\n  }\n};\ntemplate <class B>\nstruct ModInt_Na\
    \ : public B, public ModIntImpl<ModInt_Na<B>> {\n  using Int = typename B::Int;\n\
    \  using DUint = conditional_t<is_same_v<typename B::Uint, uint32_t>, u64, u128>;\n\
    \  friend ModIntImpl<ModInt_Na<B>>;\n  constexpr ModInt_Na() = default;\n  template\
    \ <class T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T\
    \ n) : ModInt_Na(n.val()) {}\n  template <class T,\n            enable_if_t<is_convertible_v<T,\
    \ __int128_t>, nullptr_t> = nullptr>\n  constexpr ModInt_Na(T n) : x(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod) {}\n#define ASSIGN(m, p) return x m## = B::mod\
    \ & -((x p## = r.x) >= B::mod), *this\n  constexpr ModInt_Na &operator+=(const\
    \ ModInt_Na &r) { ASSIGN(-, +); }\n  constexpr ModInt_Na &operator-=(const ModInt_Na\
    \ &r) { ASSIGN(+, -); }\n#undef ASSIGN\n  constexpr ModInt_Na &operator*=(const\
    \ ModInt_Na &r) {\n    return x = (DUint)(x)*r.x % B::mod, *this;\n  }\n  constexpr\
    \ bool operator==(const ModInt_Na &r) const { return x == r.x; }\n  constexpr\
    \ auto val() const { return x; }\n\n private:\n  typename B::Uint x = 0;\n};\n\
    template <class B>\nstruct ModInt_Mon : public B, public ModIntImpl<ModInt_Mon<B>>\
    \ {\n  using Int = int64_t;\n  using mod_t = ModInt_Mon;\n  friend ModIntImpl<ModInt_Mon<B>>;\n\
    \  constexpr ModInt_Mon() = default;\n  template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n) : ModInt_Mon(n.val()) {}\n\
    \  template <class T,\n            enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr>\n  constexpr ModInt_Mon(T n)\n      : x(mul(n < 0 ? B::mod\
    \ - ((-n) % B::mod) : n % B::mod, B::r2)) {}\n#define ASGN(op, a) return x op##\
    \ = a, x += (B::mod << 1) & -(x >> 63), *this\n  constexpr mod_t &operator+=(const\
    \ mod_t &r) { ASGN(+, r.x - (B::mod << 1)); }\n  constexpr mod_t &operator-=(const\
    \ mod_t &r) { ASGN(-, r.x); }\n#undef ASGN\n  constexpr mod_t &operator*=(const\
    \ mod_t &r) { return x = mul(x, r.x), *this; }\n  constexpr bool operator==(const\
    \ mod_t &r) const { return norm() == r.norm(); }\n  constexpr u64 val() const\
    \ {\n    u64 ret = reduce(x) - B::mod;\n    return ret + (B::mod & -(ret >> 63));\n\
    \  }\n\n private:\n  static constexpr inline u64 reduce(const u128 &w) {\n   \
    \ return u64(w >> 64) + B::mod - ((u128(u64(w) * B::iv) * B::mod) >> 64);\n  }\n\
    \  static constexpr inline u64 mul(u64 l, u64 r) { return reduce(u128(l) * r);\
    \ }\n  u64 x = 0;\n  constexpr inline u64 norm() const { return x - (B::mod &\
    \ -(x >= B::mod)); }\n};\nconstexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n\
    \  return e ? mul_inv(n, e - 1, x * (2 - x * n)) : x;\n}\ntemplate <u64 MOD>\n\
    struct StaticB_Na : sta_mint_base {\n protected:\n  using Int = conditional_t\
    \ < MOD < INT_MAX, int32_t,\n        conditional_t<MOD<LLONG_MAX, int64_t, __int128_t>>;\n\
    \  using Uint = conditional_t < MOD < INT_MAX, uint32_t,\n        conditional_t<MOD<LLONG_MAX,\
    \ u64, u128>>;\n  static constexpr Uint mod = MOD;\n};\ntemplate <u64 MOD>\nstruct\
    \ StaticB_Mon : sta_mint_base {\n protected:\n  static_assert(MOD & 1);\n  static\
    \ constexpr u64 mod = MOD, iv = mul_inv(mod), r2 = -u128(mod) % mod;\n};\ntemplate\
    \ <class I, int id = -1>\nstruct DynamicB_Na : dyn_mint_base {\n  static_assert(is_integral_v<I>);\n\
    \  static inline void set_mod(I m) { mod = m; }\n\n protected:\n  using Int =\
    \ I;\n  using Uint = make_unsigned_t<Int>;\n  static inline Uint mod;\n};\ntemplate\
    \ <int id>\nstruct DynamicB_Mon : dyn_mint_base {\n  static inline void set_mod(u64\
    \ m) {\n    assert(m & 1), iv = mul_inv(mod = m), r2 = -u128(m) % m;\n  }\n\n\
    \ protected:\n  static inline u64 mod, iv, r2;\n};\ntemplate <u64 mod>\nusing\
    \ StaticModInt =\n    conditional_t<mod &(INT_MAX <= mod) & (mod < LLONG_MAX),\n\
    \                  ModInt_Mon<StaticB_Mon<mod>>, ModInt_Na<StaticB_Na<mod>>>;\n\
    struct Montgomery {};\ntemplate <class Int, int id = -1>\nusing DynamicModInt\
    \ =\n    conditional_t<is_same_v<Int, Montgomery>, ModInt_Mon<DynamicB_Mon<id>>,\n\
    \                  ModInt_Na<DynamicB_Na<Int, id>>>;\n}  // namespace modint_internal\n\
    using modint_internal::DynamicModInt, modint_internal::StaticModInt,\n    modint_internal::Montgomery,\
    \ modint_internal::is_dynamicmodint_v,\n    modint_internal::is_modint_v, modint_internal::is_staticmodint_v;\n\
    template <class mod_t, std::size_t LIM>\nmod_t get_inv(int n) {\n  static_assert(is_modint_v<mod_t>);\n\
    \  static const auto m = mod_t::modulo();\n  static mod_t dat[LIM];\n  static\
    \ int l = 1;\n  if (l == 1) dat[l++] = 1;\n  while (l <= n) dat[l++] = dat[m %\
    \ l] * (m - m / l);\n  return dat[n];\n}\n#line 3 \"src/Math/CartesianProduct.hpp\"\
    \n/**\n * @title \u4EE3\u6570\u7CFB\u306E\u76F4\u7A4D ($K_1\\times K_2\\times\\\
    cdots\\times K_n$)\n * @category \u6570\u5B66\n * \u30ED\u30EA\u30CF\u306E\u305F\
    \u3081\u306B\u4F5C\u3063\u305F\n */\n\n// BEGIN CUT HERE\n\ntemplate <class...\
    \ Ks>\nstruct CartesianProduct : std::tuple<Ks...> {\n  static constexpr int N\
    \ = sizeof...(Ks);\n  using Self = CartesianProduct;\n  using std::tuple<Ks...>::tuple;\n\
    \  template <class T>\n  CartesianProduct(const T &v) {\n    fill(v, std::make_index_sequence<N>());\n\
    \  }\n  template <class T, std::size_t... I>\n  std::array<int, N> fill(const\
    \ T &v, std::index_sequence<I...>) {\n    return {{(void(std::get<I>(*this) =\
    \ v), 0)...}};\n  }\n#define HELPER(name, op)                                \
    \               \\\n  template <std::size_t... I>                            \
    \              \\\n  std::array<int, N> name(const Self &y, std::index_sequence<I...>)\
    \ {  \\\n    return {{(void(std::get<I>(*this) op## = std::get<I>(y)), 0)...}};\
    \ \\\n  }                                                                    \\\
    \n  Self &operator op##=(const Self &r) {                                \\\n\
    \    return name(r, std::make_index_sequence<N>()), *this;              \\\n \
    \ }\n  HELPER(add_assign, +)\n  HELPER(dif_assign, -)\n  HELPER(mul_assign, *)\n\
    \  HELPER(div_assign, /)\n#undef HELPER\n  Self operator+(const Self &r) const\
    \ { return Self(*this) += r; }\n  Self operator-(const Self &r) const { return\
    \ Self(*this) -= r; }\n  Self operator*(const Self &r) const { return Self(*this)\
    \ *= r; }\n  Self operator/(const Self &r) const { return Self(*this) /= r; }\n\
    };\n#line 3 \"src/String/RollingHash.hpp\"\n/**\n * @title Rolling-Hash\n * @category\
    \ \u6587\u5B57\u5217\n *  + - * \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\
    \u30AF\u30E9\u30B9\u3067hash\u3092\u8A08\u7B97\n */\n\n// verify\u7528:\n// https://atcoder.jp/contests/abc274/tasks/abc274_h\
    \ (\u6A19\u65702\u306E\u4F53 e.g. Nimber)\n\n// BEGIN CUT HERE\n\ntemplate <class\
    \ K>\nclass RollingHash {\n  static inline std::vector<K> pw;\n  static inline\
    \ K base;\n  static inline void set_pw(int n) {\n    if (int m = pw.size(); m\
    \ < n)\n      for (pw.resize(n); m < n; m++) pw[m] = pw[m - 1] * base;\n  }\n\
    \  std::vector<K> hash;\n\n public:\n  class SubString {\n    const RollingHash\
    \ *instance;\n    const int bg, ed;\n\n   public:\n    SubString(const RollingHash\
    \ &rh)\n        : instance(&rh), bg(0), ed(rh.hash.size()) {}\n    SubString(const\
    \ RollingHash *i, int b, int e) : instance(i), bg(b), ed(e) {}\n    inline K get_hash(int\
    \ l = 0, int r = -1) const {\n      return instance->get_hash(bg + l, (r == -1\
    \ ? ed : bg + r));\n    }\n    friend int lcp(const SubString &l, const SubString\
    \ &r) {\n      int ok = 0, ng = std::min(l.ed - l.bg, r.ed - r.bg) + 1;\n    \
    \  for (int x; ng - ok > 1;)\n        x = (ok + ng) / 2, (l.get_hash(0, x) ==\
    \ r.get_hash(0, x) ? ok : ng) = x;\n      return ok;\n    }\n  };\n  static void\
    \ set_base(K b) { base = b, pw.assign(1, 1); }\n  static K base_pow(int i) { return\
    \ pw[i]; }\n  RollingHash() = default;\n  template <class T>\n  RollingHash(const\
    \ std::vector<T> &v) : hash(v.size() + 1, 0) {\n    set_pw(hash.size());\n   \
    \ for (int i = 0, ed = v.size(); i < ed; i++)\n      hash[i + 1] = hash[i] * base\
    \ + v[i];\n  }\n  RollingHash(const std::string &s)\n      : RollingHash(std::vector<char>(s.begin(),\
    \ s.end())) {}\n  inline K get_hash(int l = 0, int r = -1) const {\n    if (r\
    \ < 0) r = hash.size() - 1;\n    return hash[r] - hash[l] * pw[r - l];\n  }\n\
    \  SubString sub(int l, int r) const { return SubString{this, l, r}; }\n};\n\n\
    std::uint64_t get_rand(std::uint64_t l, std::uint64_t r) {\n  static std::mt19937_64\
    \ gen(std::random_device{}());\n  return std::uniform_int_distribution<std::uint64_t>(l,\
    \ r)(gen);\n}\n#line 7 \"test/aoj/ALDS1_14_B.rollinghash.test.cpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using\
    \ Mint = StaticModInt<(1ll << 61) - 1>;\n  using K = CartesianProduct<Mint, Mint>;\n\
    \  using RH = RollingHash<K>;\n  K base = {get_rand(2, (1ll << 61) - 2), get_rand(2,\
    \ (1ll << 61) - 2)};\n  RH::set_base(base);\n  string T, P;\n  cin >> T >> P;\n\
    \  RH rt(T), rp(P);\n  int N = P.length(), M = T.length();\n  auto hash = rp.get_hash();\n\
    \  for (int i = 0; i + N <= M; i++)\n    if (rt.get_hash(i, i + N) == hash) cout\
    \ << i << \"\\n\";\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/CartesianProduct.hpp\"\
    \n#include \"src/String/RollingHash.hpp\"\nusing namespace std;\n\nsigned main()\
    \ {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  using Mint = StaticModInt<(1ll\
    \ << 61) - 1>;\n  using K = CartesianProduct<Mint, Mint>;\n  using RH = RollingHash<K>;\n\
    \  K base = {get_rand(2, (1ll << 61) - 2), get_rand(2, (1ll << 61) - 2)};\n  RH::set_base(base);\n\
    \  string T, P;\n  cin >> T >> P;\n  RH rt(T), rp(P);\n  int N = P.length(), M\
    \ = T.length();\n  auto hash = rp.get_hash();\n  for (int i = 0; i + N <= M; i++)\n\
    \    if (rt.get_hash(i, i + N) == hash) cout << i << \"\\n\";\n  return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/CartesianProduct.hpp
  - src/String/RollingHash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.rollinghash.test.cpp
  requiredBy: []
  timestamp: '2022-11-08 16:52:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.rollinghash.test.cpp
- /verify/test/aoj/ALDS1_14_B.rollinghash.test.cpp.html
title: test/aoj/ALDS1_14_B.rollinghash.test.cpp
---
