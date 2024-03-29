---
title: 木
documentation_of: ../../src/old/Tree.hpp
---
HL分解＋オイラーツアーで頂点集合を数列に \
非連結(森)でも動くはず

## テンプレート `Tree<Cost=void, weight=false>`

`Cost`: 辺に乗せる情報の型. デフォルト (void) の時は何も乗らない. \
`weight`: true なら重みつき (型 は `Cost`) 辺の距離等を扱える (この場合`Cost`は int などの +, - が定義された型でないといけない). デフォルトは false. 

## メンバ関数
**※`add_edge` (とコンストラクタと`build`) 以外の関数は `build` 関数が実行済みであることを前提とする**

| 名前                                             | 概要                                                                                                              | 備考                          |
| ------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------- | ----------------------------- |
| `Tree(n)`                                        | コンストラクタ. 頂点数 n を渡す                                                                                   |                               |
| `add_edge(u,v)`                                  | 無向辺 (u, v) を追加                                                                                              | 重みなし(Cost=void)の場合のみ |
| 1. `add_edge(u,v,c) `<br> 2. `add_edge(u,v,c,d)` | 1.  無向辺 (u, v) を重み c で追加 <br> 2.  有向辺 (u, v) を重み c で、 有向辺 (v, u) を重み d で追加              | 重みあり(Cost≠void)の場合のみ |
| `build(root=0)`                                  | 頂点 root を根としてHL分解を実行. 辺をセットし終えたらとにかく最初に実行.                                         |                               |
| `size()`                                         | 頂点数を返す.                                                                                                     |                               |
| `operator[](v)`                                  | 頂点 v から隣接する辺集合                                                                                         |                               |
| `path<edge=0>(u,v)`                              | 頂点 u から頂点 v へのパスを表す"**閉**"区間列を返す. <br> `edge`フラグが true なら lca を含めないような区間列を返す. |                               |
| `subtree(v)`                                     | 頂点 v を根とする部分木を表す"**半開**"区間を返す.                                                                      |                               |
| `depth(v)`                                       | 頂点 v の深さを返す.                                                                                               |                               |
|`depth_w(v)`|頂点 v の重みつき深さを返す.  | `weight` = true の時のみ|
| `to_seq(v)`                                      | 頂点 v がオイラーツアー列で何番目に対応するかを返す                                                               |                               |
| `to_node(i)`                                     | オイラーツアー列で i 番目が指す頂点を返す                                                                         |                               |
| `parent(v)`                                      | 頂点 v の親を返す. v が根なら -1                                                                                  |                               |
| `head(v)`                                      | HL分解における頂点 v の head を返す.  |                               |
| `root(v)`                                        | 頂点 v が属する木の根を返す                                                                                       |                               |
| `lca(u,v)`                                       | 頂点 u と 頂点 v の最小共通祖先を返す. u と v が非連結の場合は未定義.                                             |                               |  |
| `la(v,k)`                                        | 頂点 v から距離 k の祖先頂点を返す. k が頂点 v の深さより大きいと assert で落ちる.                             |                               |
| `la_w(v,w)`                                        | 頂点 v から重みつき距離 w 以内の最も祖先の頂点を返す.                           |           `weight` = true の時のみ     |
| `jump(u,v,k)`                                    | 頂点 u から 頂点 v へ向けて 長さ k 移動した先の頂点を返す.  存在しないなら -1                                     |                               |
| `jump_w(u,v,w)`                                    | 頂点 u から 頂点 v までのパスのうち u からの重みつき距離 w 以内で最も v に近い頂点を返す.        |  `weight` = true の時のみ    |
| `dist(u,v)`                                      | 頂点 u から 頂点 v までの辺の数を返す. u と v が非連結の場合は未定義.                                             |                               |
| `connected(u,v)`                                 | 頂点 u と 頂点 v が連結なら true, 非連結なら false                                                                |                               |
| `in_subtree(u,v)`                                | 頂点 u が 頂点 v を根とする部分木に属するなら true, そうでないなら false.                                         |                               |
| `subtree_size(v)`                                | 頂点 v を根とする部分木の頂点数を返す.                                                                            |                               |

使用例 \
クエリ
```c++
while(Q--){
 int t;cin>>t;
 if(t==1){
  // path query
  int u,v;cin>>u>>v;
  int ans=0;
  for(auto [a,b]: tree.path(u,v)) ans += a<b? seg1.fold(a,b+1) : seg2.fold(b,a+1);
  cout<<ans<<'\n';
 }else if(t==2){
  // subtree query
  int v;cin>>v;
  auto [l,r] = tree.subtree(v);
  cout << seg3.fold(l,r)<<'\n';
 }
}
```