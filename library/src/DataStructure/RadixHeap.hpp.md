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


# :warning: Radix-Heap

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c1c7278649b583761cecd13e0628181d">データ構造</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/DataStructure/RadixHeap.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 16:57:43+09:00


* see: <a href="https://github.com/iwiwi/radix-heap/blob/master/README_ja.md">https://github.com/iwiwi/radix-heap/blob/master/README_ja.md</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title Radix-Heap
 * @category データ構造
 * @brief dijkstraの高速化に使用
 * @brief 浮動小数点数も使える
 * @brief 小さい順
 * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// verify用:
// https://codeforces.com/contest/316/problem/C2
// (Radix-HeapでないとTLEした -> 容量スケーリングならTLEしない)

namespace internal {
template <bool Is64bit>
class find_bucket_impl;
template <>
class find_bucket_impl<false> {
 public:
  static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
    return x == last ? 0 : 32 - __builtin_clz(x ^ last);
  }
};
template <>
class find_bucket_impl<true> {
 public:
  static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
    return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
  }
};
template <typename T>
inline constexpr size_t find_bucket(T x, T last) {
  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
}
template <typename key_t, bool IsSigned>
class encoder_impl_integer;
template <typename key_t>
class encoder_impl_integer<key_t, false> {
 public:
  using ukey_t = key_t;
  inline static constexpr ukey_t encode(key_t x) { return x; }
  inline static constexpr key_t decode(ukey_t x) { return x; }
};
template <typename key_t>
class encoder_impl_integer<key_t, true> {
 public:
  typedef typename make_unsigned<key_t>::type ukey_t;
  inline static constexpr ukey_t encode(key_t x) {
    return static_cast<ukey_t>(x)
           ^ (ukey_t(1) << ukey_t(numeric_limits<ukey_t>::digits - 1));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return static_cast<key_t>(
        x ^ (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
};
template <typename key_t, typename ukey_t>
class encoder_impl_decimal {
 public:
  inline static constexpr ukey_t encode(key_t x) {
    return raw_cast<key_t, ukey_t>(x)
           ^ ((-(raw_cast<key_t, ukey_t>(x)
                 >> (numeric_limits<ukey_t>::digits - 1)))
              | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return raw_cast<ukey_t, key_t>(
        x
        ^ (((x >> (numeric_limits<ukey_t>::digits - 1)) - 1)
           | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1))));
  }

 private:
  template <typename T, typename U>
  union raw_cast {
   public:
    constexpr raw_cast(T t) : t_(t) {}
    operator U() const { return u_; }

   private:
    T t_;
    U u_;
  };
};
template <typename key_t>
class encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value> {};
template <>
class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
template <>
class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
}  // namespace internal

template <typename key_t, typename val_t,
          typename encoder_t = internal::encoder<key_t>>
class RadixHeap {
 public:
  typedef typename encoder_t::ukey_t ukey_t;

  RadixHeap() : size_(0), last_(), buckets_() {
    buckets_min_.fill(numeric_limits<ukey_t>::max());
  }

  void push(key_t key, val_t value) {
    const ukey_t x = encoder_t::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x, value);
    buckets_min_[k] = min(buckets_min_[k], x);
  }
  void emplace(key_t key, val_t value) { push(key, value); }
  pair<key_t, val_t> top() {
    pull();
    return make_pair(encoder_t::decode(last_), buckets_[0].back().second);
  }
  pair<key_t, val_t> pop() {
    pull();
    --size_;
    auto ret = make_pair(encoder_t::decode(last_), buckets_[0].back().second);
    buckets_[0].pop_back();
    return ret;
  }
  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

 private:
  size_t size_;
  ukey_t last_;
  array<vector<pair<ukey_t, val_t>>, numeric_limits<ukey_t>::digits + 1>
      buckets_;
  array<ukey_t, numeric_limits<ukey_t>::digits + 1> buckets_min_;

  void pull() {
    assert(size_ > 0);
    if (!buckets_[0].empty()) return;
    size_t i = 1;
    while (buckets_[i].empty()) ++i;
    last_ = buckets_min_[i];
    for (size_t j = 0; j < buckets_[i].size(); ++j) {
      const ukey_t x = buckets_[i][j].first;
      const size_t k = internal::find_bucket(x, last_);
      buckets_[k].emplace_back(move(buckets_[i][j]));
      buckets_min_[k] = min(buckets_min_[k], x);
    }
    buckets_[i].clear();
    buckets_min_[i] = numeric_limits<ukey_t>::max();
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/DataStructure/RadixHeap.hpp"
/**
 * @title Radix-Heap
 * @category データ構造
 * @brief dijkstraの高速化に使用
 * @brief 浮動小数点数も使える
 * @brief 小さい順
 * @see https://github.com/iwiwi/radix-heap/blob/master/README_ja.md
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

// verify用:
// https://codeforces.com/contest/316/problem/C2
// (Radix-HeapでないとTLEした -> 容量スケーリングならTLEしない)

namespace internal {
template <bool Is64bit>
class find_bucket_impl;
template <>
class find_bucket_impl<false> {
 public:
  static inline constexpr size_t find_bucket(uint32_t x, uint32_t last) {
    return x == last ? 0 : 32 - __builtin_clz(x ^ last);
  }
};
template <>
class find_bucket_impl<true> {
 public:
  static inline constexpr size_t find_bucket(uint64_t x, uint64_t last) {
    return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
  }
};
template <typename T>
inline constexpr size_t find_bucket(T x, T last) {
  return find_bucket_impl<sizeof(T) == 8>::find_bucket(x, last);
}
template <typename key_t, bool IsSigned>
class encoder_impl_integer;
template <typename key_t>
class encoder_impl_integer<key_t, false> {
 public:
  using ukey_t = key_t;
  inline static constexpr ukey_t encode(key_t x) { return x; }
  inline static constexpr key_t decode(ukey_t x) { return x; }
};
template <typename key_t>
class encoder_impl_integer<key_t, true> {
 public:
  typedef typename make_unsigned<key_t>::type ukey_t;
  inline static constexpr ukey_t encode(key_t x) {
    return static_cast<ukey_t>(x)
           ^ (ukey_t(1) << ukey_t(numeric_limits<ukey_t>::digits - 1));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return static_cast<key_t>(
        x ^ (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
};
template <typename key_t, typename ukey_t>
class encoder_impl_decimal {
 public:
  inline static constexpr ukey_t encode(key_t x) {
    return raw_cast<key_t, ukey_t>(x)
           ^ ((-(raw_cast<key_t, ukey_t>(x)
                 >> (numeric_limits<ukey_t>::digits - 1)))
              | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1)));
  }
  inline static constexpr key_t decode(ukey_t x) {
    return raw_cast<ukey_t, key_t>(
        x
        ^ (((x >> (numeric_limits<ukey_t>::digits - 1)) - 1)
           | (ukey_t(1) << (numeric_limits<ukey_t>::digits - 1))));
  }

 private:
  template <typename T, typename U>
  union raw_cast {
   public:
    constexpr raw_cast(T t) : t_(t) {}
    operator U() const { return u_; }

   private:
    T t_;
    U u_;
  };
};
template <typename key_t>
class encoder : public encoder_impl_integer<key_t, is_signed<key_t>::value> {};
template <>
class encoder<float> : public encoder_impl_decimal<float, uint32_t> {};
template <>
class encoder<double> : public encoder_impl_decimal<double, uint64_t> {};
}  // namespace internal

template <typename key_t, typename val_t,
          typename encoder_t = internal::encoder<key_t>>
class RadixHeap {
 public:
  typedef typename encoder_t::ukey_t ukey_t;

  RadixHeap() : size_(0), last_(), buckets_() {
    buckets_min_.fill(numeric_limits<ukey_t>::max());
  }

  void push(key_t key, val_t value) {
    const ukey_t x = encoder_t::encode(key);
    assert(last_ <= x);
    ++size_;
    const size_t k = internal::find_bucket(x, last_);
    buckets_[k].emplace_back(x, value);
    buckets_min_[k] = min(buckets_min_[k], x);
  }
  void emplace(key_t key, val_t value) { push(key, value); }
  pair<key_t, val_t> top() {
    pull();
    return make_pair(encoder_t::decode(last_), buckets_[0].back().second);
  }
  pair<key_t, val_t> pop() {
    pull();
    --size_;
    auto ret = make_pair(encoder_t::decode(last_), buckets_[0].back().second);
    buckets_[0].pop_back();
    return ret;
  }
  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

 private:
  size_t size_;
  ukey_t last_;
  array<vector<pair<ukey_t, val_t>>, numeric_limits<ukey_t>::digits + 1>
      buckets_;
  array<ukey_t, numeric_limits<ukey_t>::digits + 1> buckets_min_;

  void pull() {
    assert(size_ > 0);
    if (!buckets_[0].empty()) return;
    size_t i = 1;
    while (buckets_[i].empty()) ++i;
    last_ = buckets_min_[i];
    for (size_t j = 0; j < buckets_[i].size(); ++j) {
      const ukey_t x = buckets_[i][j].first;
      const size_t k = internal::find_bucket(x, last_);
      buckets_[k].emplace_back(move(buckets_[i][j]));
      buckets_min_[k] = min(buckets_min_[k], x);
    }
    buckets_[i].clear();
    buckets_min_[i] = numeric_limits<ukey_t>::max();
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

