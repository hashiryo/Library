#pragma once
#include <bits/stdc++.h>
/**
 * @title 接尾辞配列(Suffix-Array)
 * @category 文字列
 *  構築 O(|S| log |S|)
 *  lower_bound(T) 文字列Tを含む接尾辞のindexの下限 O(|T| log |S|)
 *  LongestCommonPrefix配列（高さ配列） 構築 O(|S|)
 *  '$'は入れてない
 */

// BEGIN CUT HERE

struct SuffixArray {
  std::vector<int> SA;
  const std::string s;
  SuffixArray(const std::string &str) : s(str) {
    SA.resize(s.size());
    std::iota(SA.begin(), SA.end(), 0);
    std::sort(SA.begin(), SA.end(),
              [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
    std::vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
    for (int len = 1; len < (int)s.size(); len <<= 1) {
      for (int i = 0; i < (int)s.size(); i++) {
        if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size()
            && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
          classes[SA[i]] = classes[SA[i - 1]];
        } else {
          classes[SA[i]] = i;
        }
      }
      std::iota(cnt.begin(), cnt.end(), 0);
      std::copy(SA.begin(), SA.end(), c.begin());
      for (int i = 0; i < (int)s.size(); i++) {
        int s1 = c[i] - len;
        if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
  }
  int operator[](int k) const { return (SA[k]); }

  // O(|T|log|S|)
  int lower_bound(std::string &T) {
    int low = -1, high = s.size();
    while (high - low > 1) {
      int m = (low + high) >> 1;
      if (s.compare(SA[m], T.length(), T) < 0)
        low = m;
      else
        high = m;
    }
    return high;
  }
  int upper_bound(std::string &T) {
    T.back()++;
    int res = lower_bound(T);
    T.back()--;
    return res;
  }
  // O(|T|log|S|)
  int count(std::string &T) { return upper_bound(T) - lower_bound(T); }

  // O(|S|)
  std::vector<int> get_lcp() {
    std::vector<int> rank(SA.size()), LCP(SA.size());
    for (int i = 0; i < (int)SA.size(); i++) rank[SA[i]] = i;
    for (int i = 0, h = 0; i < (int)SA.size(); i++) {
      if (rank[i] + 1 < (int)SA.size()) {
        int j = SA[rank[i] + 1];
        while (std::max(i, j) + h < (int)SA.size() && s[i + h] == s[j + h]) ++h;
        LCP[rank[i] + 1] = h;
        if (h > 0) --h;
      }
    }
    return LCP;
  }
};