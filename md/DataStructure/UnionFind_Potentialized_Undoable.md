---
title: Union-Find (ポテンシャル, undo可能)
documentation_of: ../../src/DataStructure/UnionFind_Potentialized_Undoable.hpp
---
 
## `UnionFind_Potentialized_Undoable`　クラス
undo可能な重み(ポテンシャル)付きUnion-Find．\
各要素 $u$ にポテンシャル $p(u)$ ( `weight_t`型 )を持たせ，同じ集合に属する任意の2要素 $u,v$ についてポテンシャルの差分 $p(v)-p(u)$ を計算できるようにする．\
`weight_t`型は `weight_t()`,`operator+(a,b)`,`operator-(a)`,`operator-(a,b)` によって群になれば使える．\
`weight_t=bool` のときは $\mathbb{F}_2$ の意味で使われる．

非可換な群でも動く．その場合計算順序に注意．\
 `unite(u,v,w)`は $p(u) = p(v) + w$ すなわち $-p(v)+p(u)=w$ を満たし，`diff(u,v)` は $-p(v)+p(u)$ を返す．

状態が変化しなくても `unite` を一回呼ぶごとにタイムスタンプが増える．

経路圧縮をしていないため計算量は $\log$ になる．

|メンバ関数|概要|計算量|
|---|---|---|
|`UnionFind(n)`|コンストラクタ. 要素数 $n$ を渡す.||
|`size(u)`|要素 $u$ の属する集合のサイズを返す.||
|`leader(u)`|要素 $u$ の属する集合の代表元を返す.|$O(\log n)$|
|`connected(u,v)`|要素 $u,v$ が同じ集合に属していれば `true` を返す．|$O(\log n)$|
|`unite(u,v,w)`|要素 $u,v$ それぞれが属する集合を併合し，ポテンシャルについては $p(u)=p(v)+w$ を満たすように変更する．<br> 矛盾していたら`false` を返す． |$O(\log n)$|
|`potential(u)`|要素 $u$ のポテンシャル $p(u)$ を返す． |$O(\log n)$|
|`diff(u,v)`| $-p(v)+p(u)$ を返す |$O(\log n)$|
|`time()`|この関数を読んだ時点でのタイムスタンプを返す．最初は0．|$O(1)$|
|`undo()`|直近の `unite` 操作を無かったことにする．|$O(1)$|
|`rollback(t)`| タイムスタンプ $t$ のときに戻す． |最悪`unite`をした回数|

## 問題例
[yukicoder No.1420 国勢調査 (Easy)](https://yukicoder.me/problems/no/1420) (ポテンシャル, xor, sp judge)\
[AtCoder Regular Contest 090 D - People on a Line](https://atcoder.jp/contests/arc090/tasks/arc090_b) (ポテンシャル) \
[AtCoder Regular Contest 099 E - Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c) (2色,連結)\
[第10回 アルゴリズム実技検定 過去問 O - 3-順列](https://atcoder.jp/contests/past202203-open/tasks/past202203_o) (2色,連結)\
[競プロ典型 90 問　068 - Paired Information（★5）](https://atcoder.jp/contests/typical90/tasks/typical90_bp) (affine, 非可換群)