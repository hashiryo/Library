#pragma once
#include <vector>
template <class T, std::size_t M= 8> class PersistentArray {
 struct Node {
  T val;
  Node *ch[M];
 } * root;
 T get(Node *&t, std::size_t k) { return t ? (k ? get(t->ch[(k - 1) % M], (k - 1) / M) : t->val) : T(); }
 bool is_null(Node *&t, std::size_t k) { return t ? (k ? is_null(t->ch[(k - 1) % M], (k - 1) / M) : false) : true; }
 template <bool persistent= true> T &at(Node *&t, std::size_t k) {
  if (!t) t= new Node();
  else if constexpr (persistent) t= new Node(*t);
  return k ? at<persistent>(t->ch[(k - 1) % M], (k - 1) / M) : t->val;
 }
public:
 PersistentArray(): root(nullptr) {}
 PersistentArray(std::size_t n, T v): root(nullptr) {
  for (std::size_t i= n; i--;) at<false>(root, i)= v;
 }
 PersistentArray(T *bg, T *ed): root(nullptr) {
  for (std::size_t i= ed - bg; i--;) at<false>(root, i)= *(bg + i);
 }
 PersistentArray(const std::vector<T> &ar): PersistentArray(ar.data(), ar.data() + ar.size()) {}
 bool is_null(std::size_t k) { return is_null(root, k); }
 T get(std::size_t k) { return get(root, k); }
 T &at(std::size_t k) { return at<true>(root, k); }
 T &operator[](std::size_t k) { return at(k); }
};
