---
title: 重軽分解
documentation_of: ../../src/Graph/HeavyLightDecomposition.hpp
---

## 使い方 イメージ

```c++
// Graph g を構築
int n; cin>>n;
Graph g(n,n-1);
for(int i=0;i<n-1;++i)cin>>g[i],--g[i];

// HLD を構築
HeavyLightDecomposition hld(g, 0); // 頂点 0 を根にして構築

// クエリ
// 例えばセグ木, seg1, seg2, seg3 があるとして
int Q;cin>>>Q;
while(Q--){
 int t;cin>>t;
 if(t == 1){ // path query
  int u,v; cin>>u>>v;
  int ans = 0;
  for(auto [a,b]: hld.path(u,v)) ans += a<b? seg1.prod(a,b+1) : seg2.prod(b,a+1);
  cout<< ans <<'\n';
 }else if(t == 2){ // subtree query
  int v; cin>>v;
  auto [l,r] = hld.subtree(v);
  cout << seg3.prod(l,r)<<'\n';
 }
}
```


## `HeavyLightDecomposition` クラス

HL分解＋オイラーツアーで頂点集合を数列に \
非連結(森)でもある程度動くはず

| 名前 | 概要 |
| --- | --- |
| `HeavyLightDecomposition(CSRArray<int> adj, root=0)` <br> `HeavyLightDecomposition(Graph g, root=0)` | コンストラクタ. <br> 引数は頂点 → 頂点の隣接リスト([`CSRArray<int>`クラス](../Internal/ListRange.hpp)) adj または [`Graph` クラス](Graph.hpp) g，と根とする頂点 root を渡す. <br> 親から子へ向かう有向辺さえあれば良い． |
| `size()`| 頂点数を返す.|
| `path<edge=0>(u,v)` | 頂点 u から頂点 v へのパスを表す"**閉**"区間列を返す. <br> `edge`フラグが true なら LCA を含めないような区間列を返す. |
| `subtree(v)` | 頂点 v を根とする部分木を表す"**半開**"区間を返す. |
| `depth(v)`| 頂点 v の深さを返す．|
| `to_seq(v)` | 頂点 v が dfs順 で何番目に対応するかを返す |
| `to_vertex(i)` | dfs順で i 番目が指す頂点を返す． |
| `parent(v)`| 頂点 v の親を返す. v が根なら -1 |
| `head(v)`| HL分解における頂点 v の head を返す.  |
| `root(v)`| 頂点 v が属する木の根を返す．|
| `connected(u,v)`| 頂点 u と 頂点 v が連結なら `true`, 非連結なら `false`|
| `lca(u,v)`| 頂点 u と 頂点 v の最小共通祖先 (Lowest Common Ancestor; LCA) を返す. <br> u と v が非連結の場合は未定義. |
| `la(v,k)`| 頂点 v から距離 k の祖先頂点を返す. <br> k が頂点 v の深さより大きいと assert で落ちる. |
| `jump(u,v,k)`| 頂点 u から 頂点 v へ向けて 長さ k 移動した先の頂点を返す. <br>存在しないなら -1|
| `dist(u,v)`| 頂点 u から 頂点 v までの辺の数を返す. <br> u と v が非連結の場合は未定義.|
| `in_subtree(u,v)`| 頂点 v を根とする部分木に頂点 u が属するなら `true`, そうでないなら `false`.|
| `subtree_size(v)`| 頂点 v を根とした部分木の頂点数を返す.|
