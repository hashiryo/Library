---
title: Union-Find (undo 可能)
documentation_of: ../../src/DataStructure/UnionFind_Undoable.hpp
---

## `UnionFind_Undoable` クラス
`unite` 操作の取り消し (`undo`, `rollback`) ができる Union-Find．
経路圧縮をしないため，各操作の計算量は $O(\log n)$ となる．

|メンバ関数|概要|計算量|
|---|---|---|
|`UnionFind_Undoable(n)`|コンストラクタ. 要素数 $n$ を渡す.||
|`size(u)`|要素 $u$ の属する集合のサイズを返す.|$O(\log n)$|
|`leader(u)`|要素 $u$ の属する集合の代表元を返す.|$O(\log n)$|
|`connected(u,v)`|要素 $u,v$ が同じ集合に属していれば `true` を返す．|$O(\log n)$|
|`unite(u,v)`|要素 $u,v$ の属する集合を併合する．<br>併合に成功した場合 `true` を，すでに同じ集合に属している場合は `false` を返す．|$O(\log n)$|
|`time()`|現在のタイムスタンプを返す．最初は0で，`unite` を呼ぶたびに1増加する．|$O(1)$|
|`undo()`|直近の `unite` 操作を1回取り消す．|$O(1)$|
|`rollback(t)`| タイムスタンプが $t$ になるまで `unite` 操作を取り消す． |$O(\text{time}() - t)$|
