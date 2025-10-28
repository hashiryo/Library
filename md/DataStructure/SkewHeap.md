---
title: Skew Heap
documentation_of: ../../src/DataStructure/SkewHeap.hpp
---

## 概要
Skew Heap は、ならし計算量 $O(\log N)$ でマージが可能なヒープである。2つのヒープを高速に結合できるため、優先度付きキューとしてだけでなく、様々な場面で応用できる。

この実装では、遅延伝播による要素の一括更新もサポートしている。

## テンプレートパラメータ

| 名前      | 説明                                                                                                                            | デフォルト        |
| :-------- | :------------------------------------------------------------------------------------------------------------------------------ | :---------------- |
| `T`       | 要素の型                                                                                                                        | -                 |
| `Compare` | 2つの要素を比較するための関数オブジェクト。`Compare()(a, b)` が `true` のとき `a` が `b` より優先度が低い（根から遠ざかる）と判断される。 | `std::less<T>`    |
| `M`       | 遅延伝播で用いる作用素モノイド。`apply` を使用する場合に指定する。                                                                | `void`            |

`Compare` のデフォルトは `std::less<T>` であり、このとき大きい値ほど優先度が高くなる **最大ヒープ (max-heap)** として動作する。最小ヒープとして使いたい場合は `std::greater<T>` を指定する。

## メンバ関数

| 関数名        | 機能                                                              | 計算量 (ならし) |
| :------------ | :---------------------------------------------------------------- | :-------------- |
| `push(key)`   | 要素 `key` を追加する                                             | $O(\log N)$     |
| `pop()`       | 最も優先度が高い要素を削除し、その値を返す                        | $O(\log N)$     |
| `top()`       | 最も優先度が高い要素を返す                                        | $O(1)$          |
| `empty()`     | ヒープが空かどうかを返す                                          | $O(1)$          |
| `merge(other)`| 別のヒープ `other` をマージする (`+=` 演算子も利用可能)           | $O(\log N)$     |
| `apply(v)`    | 全ての要素に作用素 `v` を適用する（`M` が `void` でない場合のみ） | $O(1)$          |

## 使用例

### 基本的な使い方 (最大ヒープ)
```cpp
#include <iostream>
#include "src/DataStructure/SkewHeap.hpp"

int main() {
    SkewHeap<int> max_heap;
    max_heap.push(3);
    max_heap.push(5);
    max_heap.push(2);

    // 5, 3, 2 の順に出力される
    while (!max_heap.empty()) {
        std::cout << max_heap.pop() << std::endl;
    }
    return 0;
}
```

### 最小ヒープ
`Compare` に `std::greater<int>` を指定すると、最小ヒープとして動作する。
```cpp
#include <iostream>
#include <functional>
#include "src/DataStructure/SkewHeap.hpp"

int main() {
    SkewHeap<int, std::greater<int>> min_heap;
    min_heap.push(3);
    min_heap.push(5);
    min_heap.push(2);

    // 2, 3, 5 の順に出力される
    while (!min_heap.empty()) {
        std::cout << min_heap.pop() << std::endl;
    }
    return 0;
}
```

### マージ
`+` または `+=` 演算子で2つのヒープをマージできる。
```cpp
SkewHeap<int> heap1, heap2;
heap1.push(1);
heap1.push(4);
heap2.push(2);
heap2.push(3);

heap1 += heap2; // heap1 に heap2 をマージ

// 4, 3, 2, 1 の順に出力される
while (!heap1.empty()) {
    std::cout << heap1.pop() << std::endl;
}
```

### 遅延伝播 (全体への加算)
作用素モノイドを定義することで、`apply` を使って全要素に一括で値を加算できる。
```cpp
#include <iostream>
#include "src/DataStructure/SkewHeap.hpp"

// 全体への加算を行う作用素モノイド
struct Add {
    using E = int;
    static void mp(int &a, const E &b) { a += b; } // 要素 a に 作用素 b を適用
    static void cp(E &a, const E &b) { a += b; }   // 作用素 a に 作用素 b を合成
};

int main() {
    SkewHeap<int, std::less<int>, Add> heap;
    heap.push(10);
    heap.push(20);
    heap.push(30);

    // 全要素に 5 を加算
    heap.apply(5);

    // 35, 25, 15 の順に出力される
    while (!heap.empty()) {
        std::cout << heap.pop() << std::endl;
    }
    return 0;
}
```
