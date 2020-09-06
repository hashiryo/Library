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


# :question: 行列

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e65831863dbf272b7a65cd8df1a440d">数学</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/Math/Matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 22:06:06+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/1328.test.cpp.html">test/aoj/1328.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/linear_equations.test.cpp.html">test/yosupo/linear_equations.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @title 行列
 * @category 数学
 *  Gauss_Jordan(A,B) 拡大係数行列に対するガウスジョルダン法
 *  linear_equations(A,b) 返り値 {解のうちの一つ,解空間の基底ベクトル}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename K>
struct Matrix {
 private:
  vector<vector<K>> a;

 public:
  Matrix() {}
  Matrix(size_t n, size_t m) : a(n, vector<K>(m, 0)) {}
  Matrix(size_t n) : Matrix(n, n) {}
  Matrix(vector<vector<K>> a) : a(a) {}
  size_t height() const { return a.size(); }
  size_t width() const { return a[0].size(); }
  inline const vector<K> &operator[](size_t k) const { return a[k]; }
  inline vector<K> &operator[](size_t k) { return a[k]; }
  static Matrix diag(vector<K> v) {
    Matrix mat(v.size());
    for (size_t i = 0; i < v.size(); i++) mat[i][i] = v[i];
    return mat;
  }
  static Matrix I(size_t n, K e = {1}) { return diag(vector<K>(n, e)); }
  Matrix &operator+=(const Matrix &b) {
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) (*this)[i][j] += b[i][j];
    return (*this);
  }
  Matrix &operator-=(const Matrix &b) {
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) (*this)[i][j] -= b[i][j];
    return (*this);
  }
  Matrix &operator*=(const Matrix &b) {
    size_t n = height(), m = width(), l = b.width();
    assert(m == b.height());
    vector<vector<K>> c(n, vector<K>(l, 0));
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++)
        for (size_t k = 0; k < m; k++) c[i][j] += (*this)[i][k] * b[k][j];
    a.swap(c);
    return (*this);
  }
  Matrix operator+(const Matrix &b) const { return (Matrix(*this) += b); }
  Matrix operator-(const Matrix &b) const { return (Matrix(*this) -= b); }
  Matrix operator*(const Matrix &b) const { return (Matrix(*this) *= b); }
  Matrix pow(uint64_t n, K e = {1}) {
    Matrix ret = I(height(), e);
    for (Matrix base = *this; n; n >>= 1, base *= base)
      if (n & 1) ret *= base;
    return ret;
  }
  vector<K> operator*(const vector<K> &v) {
    size_t n = height(), m = width();
    assert(m == v.size());
    vector<K> ret(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) ret[i] += (*this)[i][j] * v[j];
    return ret;
  }
  bool operator==(const Matrix &b) const { return a == b.a; }
  template <typename T>
  using ET = enable_if<is_floating_point<T>::value>;
  template <typename T>
  using EF = enable_if<!is_floating_point<T>::value>;
  template <typename T, typename ET<T>::type * = nullptr>
  static bool is_zero(T x) {
    return abs(x) < 1e-8;
  }
  template <typename T, typename EF<T>::type * = nullptr>
  static bool is_zero(T x) {
    return x == T(0);
  }
  template <typename T, typename ET<T>::type * = nullptr>
  static bool compare(T x, T y) {
    return abs(x) < abs(y);
  }
  template <typename T, typename EF<T>::type * = nullptr>
  static bool compare(T x, T y) {
    (void)x;
    return y != T(0);
  }
  // O(nm(m+l))
  static pair<Matrix, Matrix> Gauss_Jordan(const Matrix &a, const Matrix &b) {
    size_t n = a.height(), m = a.width(), l = b.width();
    Matrix c(n, m + l);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) c[i][j] = a[i][j];
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++) c[i][j + m] = b[i][j];
    for (size_t j = 0, d = 0; j < m && d < n; j++) {
      int p = d;
      for (size_t i = d + 1; i < n; i++)
        if (compare(c[p][j], c[i][j])) p = i;
      if (is_zero(c[p][j])) continue;
      swap(c[p], c[d]);
      K invc = K(1) / c[d][j];
      for (size_t k = j; k < m + l; k++) c[d][k] *= invc;
      for (size_t i = 0; i < n; i++) {
        if (i == d) continue;
        for (size_t k = m + l - 1; k >= j; k--) c[i][k] -= c[i][j] * c[d][k];
      }
      d++;
    }
    Matrix reta(n, m), retb(n, l);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) reta[i][j] = c[i][j];
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++) retb[i][j] = c[i][j + m];
    return make_pair(reta, retb);
  }
  // O(nm^2)
  static pair<vector<K>, vector<vector<K>>> linear_equations(
      const Matrix &a, const vector<K> &b) {
    size_t n = a.height(), m = a.width();
    Matrix B(n, 1);
    for (size_t i = 0; i < n; i++) B[i][0] = b[i];
    auto p = Gauss_Jordan(a, B);
    vector<int> jdx(n, -1), idx(m, -1);
    for (size_t i = 0, j; i < n; i++) {
      for (j = 0; j < m; j++)
        if (!is_zero(p.first[i][j])) {
          jdx[i] = j, idx[j] = i;
          break;
        }
      if (j == m && !is_zero(p.second[i][0]))
        return make_pair(vector<K>(), vector<vector<K>>());  // no solutions
    }
    vector<K> c(m);
    vector<vector<K>> d;
    for (size_t j = 0; j < m; j++) {
      if (idx[j] != -1)
        c[j] = p.second[idx[j]][0];
      else {
        vector<K> v(m);
        v[j] = 1;
        for (size_t i = 0; i < n; i++)
          if (jdx[i] != -1) v[jdx[i]] = -p.first[i][j];
        d.push_back(v);
      }
    }
    return make_pair(c, d);
  }
  // O(n^3)
  K det() const {
    size_t n = height();
    Matrix A(a);
    K ret(1);
    for (size_t i = 0; i < n; i++) {
      int p = i;
      for (size_t j = i + 1; j < n; j++)
        if (compare(A[p][i], A[j][i])) p = j;
      if (is_zero(A[p][i])) return 0;
      if (p != i) ret = -ret;
      swap(A[p], A[i]);
      ret *= A[i][i];
      K inva = K(1) / A[i][i];
      for (size_t j = i + 1; j < n; j++)
        for (size_t k = n - 1; k >= i; k--) A[j][k] -= inva * A[j][i] * A[i][k];
    }
    return ret;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/Math/Matrix.hpp"
/**
 * @title 行列
 * @category 数学
 *  Gauss_Jordan(A,B) 拡大係数行列に対するガウスジョルダン法
 *  linear_equations(A,b) 返り値 {解のうちの一つ,解空間の基底ベクトル}
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

template <typename K>
struct Matrix {
 private:
  vector<vector<K>> a;

 public:
  Matrix() {}
  Matrix(size_t n, size_t m) : a(n, vector<K>(m, 0)) {}
  Matrix(size_t n) : Matrix(n, n) {}
  Matrix(vector<vector<K>> a) : a(a) {}
  size_t height() const { return a.size(); }
  size_t width() const { return a[0].size(); }
  inline const vector<K> &operator[](size_t k) const { return a[k]; }
  inline vector<K> &operator[](size_t k) { return a[k]; }
  static Matrix diag(vector<K> v) {
    Matrix mat(v.size());
    for (size_t i = 0; i < v.size(); i++) mat[i][i] = v[i];
    return mat;
  }
  static Matrix I(size_t n, K e = {1}) { return diag(vector<K>(n, e)); }
  Matrix &operator+=(const Matrix &b) {
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) (*this)[i][j] += b[i][j];
    return (*this);
  }
  Matrix &operator-=(const Matrix &b) {
    size_t n = height(), m = width();
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) (*this)[i][j] -= b[i][j];
    return (*this);
  }
  Matrix &operator*=(const Matrix &b) {
    size_t n = height(), m = width(), l = b.width();
    assert(m == b.height());
    vector<vector<K>> c(n, vector<K>(l, 0));
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++)
        for (size_t k = 0; k < m; k++) c[i][j] += (*this)[i][k] * b[k][j];
    a.swap(c);
    return (*this);
  }
  Matrix operator+(const Matrix &b) const { return (Matrix(*this) += b); }
  Matrix operator-(const Matrix &b) const { return (Matrix(*this) -= b); }
  Matrix operator*(const Matrix &b) const { return (Matrix(*this) *= b); }
  Matrix pow(uint64_t n, K e = {1}) {
    Matrix ret = I(height(), e);
    for (Matrix base = *this; n; n >>= 1, base *= base)
      if (n & 1) ret *= base;
    return ret;
  }
  vector<K> operator*(const vector<K> &v) {
    size_t n = height(), m = width();
    assert(m == v.size());
    vector<K> ret(n);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) ret[i] += (*this)[i][j] * v[j];
    return ret;
  }
  bool operator==(const Matrix &b) const { return a == b.a; }
  template <typename T>
  using ET = enable_if<is_floating_point<T>::value>;
  template <typename T>
  using EF = enable_if<!is_floating_point<T>::value>;
  template <typename T, typename ET<T>::type * = nullptr>
  static bool is_zero(T x) {
    return abs(x) < 1e-8;
  }
  template <typename T, typename EF<T>::type * = nullptr>
  static bool is_zero(T x) {
    return x == T(0);
  }
  template <typename T, typename ET<T>::type * = nullptr>
  static bool compare(T x, T y) {
    return abs(x) < abs(y);
  }
  template <typename T, typename EF<T>::type * = nullptr>
  static bool compare(T x, T y) {
    (void)x;
    return y != T(0);
  }
  // O(nm(m+l))
  static pair<Matrix, Matrix> Gauss_Jordan(const Matrix &a, const Matrix &b) {
    size_t n = a.height(), m = a.width(), l = b.width();
    Matrix c(n, m + l);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) c[i][j] = a[i][j];
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++) c[i][j + m] = b[i][j];
    for (size_t j = 0, d = 0; j < m && d < n; j++) {
      int p = d;
      for (size_t i = d + 1; i < n; i++)
        if (compare(c[p][j], c[i][j])) p = i;
      if (is_zero(c[p][j])) continue;
      swap(c[p], c[d]);
      K invc = K(1) / c[d][j];
      for (size_t k = j; k < m + l; k++) c[d][k] *= invc;
      for (size_t i = 0; i < n; i++) {
        if (i == d) continue;
        for (size_t k = m + l - 1; k >= j; k--) c[i][k] -= c[i][j] * c[d][k];
      }
      d++;
    }
    Matrix reta(n, m), retb(n, l);
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < m; j++) reta[i][j] = c[i][j];
    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < l; j++) retb[i][j] = c[i][j + m];
    return make_pair(reta, retb);
  }
  // O(nm^2)
  static pair<vector<K>, vector<vector<K>>> linear_equations(
      const Matrix &a, const vector<K> &b) {
    size_t n = a.height(), m = a.width();
    Matrix B(n, 1);
    for (size_t i = 0; i < n; i++) B[i][0] = b[i];
    auto p = Gauss_Jordan(a, B);
    vector<int> jdx(n, -1), idx(m, -1);
    for (size_t i = 0, j; i < n; i++) {
      for (j = 0; j < m; j++)
        if (!is_zero(p.first[i][j])) {
          jdx[i] = j, idx[j] = i;
          break;
        }
      if (j == m && !is_zero(p.second[i][0]))
        return make_pair(vector<K>(), vector<vector<K>>());  // no solutions
    }
    vector<K> c(m);
    vector<vector<K>> d;
    for (size_t j = 0; j < m; j++) {
      if (idx[j] != -1)
        c[j] = p.second[idx[j]][0];
      else {
        vector<K> v(m);
        v[j] = 1;
        for (size_t i = 0; i < n; i++)
          if (jdx[i] != -1) v[jdx[i]] = -p.first[i][j];
        d.push_back(v);
      }
    }
    return make_pair(c, d);
  }
  // O(n^3)
  K det() const {
    size_t n = height();
    Matrix A(a);
    K ret(1);
    for (size_t i = 0; i < n; i++) {
      int p = i;
      for (size_t j = i + 1; j < n; j++)
        if (compare(A[p][i], A[j][i])) p = j;
      if (is_zero(A[p][i])) return 0;
      if (p != i) ret = -ret;
      swap(A[p], A[i]);
      ret *= A[i][i];
      K inva = K(1) / A[i][i];
      for (size_t j = i + 1; j < n; j++)
        for (size_t k = n - 1; k >= i; k--) A[j][k] -= inva * A[j][i] * A[i][k];
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

