/**
 * @title 最長共通接頭辞(Z-Algorithm)
 * @category 文字列
 *  $prefix_i$ は、$S$ と $S.substr(i)$ の LCP(longest common prefix)
 *  O(|S|)
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

vector<int> z_algorithm(const string &s) {
  vector<int> prefix(s.size());
  for (int i = 1, j = 0; i < s.size(); i++) {
    if (i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while (i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int)s.size();
  return prefix;
}