---
title: 最長増加部分列 (LIS)
documentation_of: ../../src/Misc/longest_increasing_subsequence.hpp
---

## 概要

配列 `a` の最長増加部分列 (Longest Increasing Subsequence, LIS) を求める。
LIS の長さだけでなく、LIS を構成する要素の候補も同時に計算する。

---

## `longest_increasing_subsequence`

### 形式
```cpp
template <class T>
std::pair<std::vector<int>, std::vector<std::vector<int>>>
longest_increasing_subsequence(const std::vector<T> &a, bool strict = true);
```

### 引数
- `const std::vector<T> &a`: 対象となる配列。
- `bool strict`:
  - `true` (デフォルト): 狭義の単調増加 (`<`) で LIS を求める。
  - `false`: 広義の単調増加 (`<=`) で LIS を求める。

### 返り値
`std::pair<std::vector<int>, std::vector<std::vector<int>>>` 型のペア `(idx, cand)` を返す。

- `cand`:
  - `cand.size()` が LIS の長さを表す。
  - `cand[j]` は、LIS の `j` 番目 (0-indexed) の要素として使用可能な、元の配列 `a` における添字 `i` のリスト (昇順)。
- `idx`:
  - `idx[i]` は、`a[i]` が LIS の要素として使われる場合、その位置が `idx[i]` 番目であることを示す。
  - どの LIS にも含まれない要素 `a[i]` については `idx[i] = -1` となる。

### 計算量
$O(N \log N)$、ただし $N$ は配列 `a` のサイズ。

### 使用例
LIS の長さと、その一例（辞書順最小のもの）を復元する。

```cpp
#include <iostream>
#include <vector>
#include "src/Misc/longest_increasing_subsequence.hpp"

int main() {
    std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
    
    auto [idx, cand] = longest_increasing_subsequence(a);

    // LIS の長さを出力
    int lis_length = cand.size();
    std::cout << "LIS length: " << lis_length << std::endl; // LIS length: 4

    // LIS の一例（添字）を復元して出力
    if (lis_length > 0) {
        std::vector<int> lis_indices;
        for (int i = 0; i < lis_length; ++i) {
            lis_indices.push_back(cand[i].front());
        }
        
        std::cout << "LIS indices: ";
        for (int i = 0; i < lis_length; ++i) {
            std::cout << lis_indices[i] << (i == lis_length - 1 ? "" : " ");
        }
        std::cout << std::endl; // LIS indices: 1 6 7
        // ↑間違い。正しくは 1 2 4 7 or 1 2 5 7
        // cand[i].front() だと辞書順最小にはならない。
        // cand[i] のうち、後続につながるものを選択する必要がある。
        // テストコードの復元方法は辞書順最小のLISを復元するわけではない。
        // LISの一例（添字が最小のもの）を出力する、というほうが正確。

        // LIS の一例（値）を出力
        std::cout << "LIS values: ";
        for (int i = 0; i < lis_length; ++i) {
            std::cout << a[lis_indices[i]] << (i == lis_length - 1 ? "" : " ");
        }
        std::cout << std::endl; // LIS values: 1 2 6
    }
    
    return 0;
}
```

(コード例のコメントをセルフ訂正)
yosupo の問題では `cand[i].front()` で復元したものを提出して AC しているので、それで復元できる「LIS の一例」が得られる。辞書順最小ではない。
「LIS の一例（各位置で最も添字が小さい要素を選んだもの）」と書くのが正確か。

よし、ドキュメントを修正しよう。使用例のコメントが間違っていた。
復元されるものは「LIS の一例」であり、「各位置において、条件を満たすものの中で最も添字が小さい要素を選択して構築した LIS」である。辞書順最小ではない。

```cpp
#include <iostream>
#include <vector>
#include "src/Misc/longest_increasing_subsequence.hpp"

int main() {
    std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
    
    auto [_, cand] = longest_increasing_subsequence(a);

    // LIS の長さを出力
    int lis_length = cand.size();
    std::cout << "LIS length: " << lis_length << std::endl; // LIS length: 4

    // LIS の一例を復元して出力
    // (各位置で条件を満たす要素のうち、最も添字が小さいものを選択)
    if (lis_length > 0) {
        std::vector<int> lis_indices;
        for (int i = 0; i < lis_length; ++i) {
            lis_indices.push_back(cand[i].front());
        }
        
        std::cout << "An example of LIS (indices): ";
        for (int i = 0; i < lis_length; ++i) {
            std::cout << lis_indices[i] << (i == lis_length - 1 ? "" : " ");
        }
        std::cout << std::endl; // An example of LIS (indices): 1 2 4 7

        std::cout << "An example of LIS (values): ";
        for (int i = 0; i < lis_length; ++i) {
            std::cout << a[lis_indices[i]] << (i == lis_length - 1 ? "" : " ");
        }
        std::cout << std::endl; // An example of LIS (values): 1 4 5 6
    }
    
    return 0;
}
```
上のコードで手元でトレースしてみる。

a = {3, 1, 4, 1, 5, 9, 2, 6}
n = 8

strict=true
i=0, a[0]=3: dp[0]=3, idx[0]=0, len=1
i=1, a[1]=1: dp[0]=1, idx[1]=0, len=1
i=2, a[2]=4: dp[1]=4, idx[2]=1, len=2
i=3, a[3]=1: dp[0]=1, idx[3]=0, len=2 (dp[0]が1で不変)
i=4, a[4]=5: dp[2]=5, idx[4]=2, len=3
i=5, a[5]=9: dp[3]=9, idx[5]=3, len=4
i=6, a[6]=2: dp[1]=2, idx[6]=1, len=4
i=7, a[7]=6: dp[3]=6, idx[7]=3, len=4

最終的な len=4, dp={1, 2, 5, 6}
idx = {0, 0, 1, 0, 2, 3, 1, 3}

cand の構築 (i=n-1 ... 0)
len = 4
cand(4)

i=7, a[7]=6, idx[7]=3. idx[7]==len-1. cand[3].push(7).
cand[3] = {7}

i=6, a[6]=2, idx[6]=1. cand[2]は空. a[6]=2, a[cand[2].back()]... ではなくて `cand[idx[6]+1]` を見る。
`cand[1+1] = cand[2]` は空。なので-1に更新。idx[6]=-1.

i=5, a[5]=9, idx[5]=3. idx[5]==len-1. cand[3].push(5).
cand[3] = {7, 5}

i=4, a[4]=5, idx[4]=2. cand[3]は{7, 5}. `cand[3].back()`は5. a[5]=9. a[4]=5 < a[5]=9. cand[2].push(4).
cand[2] = {4}

i=3, a[3]=1, idx[3]=0. cand[1]は空. idx[3]=-1.

i=2, a[2]=4, idx[2]=1. cand[2]は{4}. `cand[2].back()`は4. a[4]=5. a[2]=4 < a[4]=5. cand[1].push(2).
cand[1] = {2}

i=1, a[1]=1, idx[1]=0. cand[1]は{2}. `cand[1].back()`は2. a[2]=4. a[1]=1 < a[2]=4. cand[0].push(1).
cand[0] = {1}

i=0, a[0]=3, idx[0]=0. cand[1]は{2}. `cand[1].back()`は2. a[2]=4. a[0]=3 < a[2]=4. cand[0].push(0).
cand[0] = {1, 0}

最終的な cand (reverse前):
cand[0] = {1, 0}
cand[1] = {2}
cand[2] = {4}
cand[3] = {7, 5}

reverse後:
cand[0] = {0, 1}
cand[1] = {2}
cand[2] = {4}
cand[3] = {5, 7}

`cand[i].front()` をつなげると
`cand[0].front()` = 0
`cand[1].front()` = 2
`cand[2].front()` = 4
`cand[3].front()` = 5
indices: 0, 2, 4, 5
values: a[0]=3, a[2]=4, a[4]=5, a[5]=9.
これは正しいLIS。

コード例のコメントは間違っていた。トレース結果で修正する。
`1 2 4 7` -> `0 2 4 5`
`1 4 5 6` -> `3 4 5 9`

OK、この内容でファイルを書き換える。