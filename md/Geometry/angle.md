---
title: 角度・回転関連
documentation_of: ../../src/Geometry/angle.hpp
---

## 関数

|名前|概要|
|---|---|
|`radian_to_degree(r)`|ラジアンの値を度数に変換したものを返す。|
|`degree_to_radian(d)`|度数の値からラジアンに変換したものを返す。|
|`normalize_radian(r)`|`long double` 型のラジアンの値 `r` を $(-\pi,\pi\rbrack$ の区間に正規化して返す。|
|`angle(p)`|ベクトル $\boldsymbol{p}$ の偏角を `long double` 型のラジアンで返す。返り値の範囲は $(-\pi,\pi\rbrack$。|
|`angle(p,q)`|ベクトル $\boldsymbol{p}$ からベクトル $\boldsymbol{q}$ への符号付きの角度を `long double` 型のラジアンで返す。返り値の範囲は $(-\pi,\pi\rbrack$。反時計回りが正。|
|`rotate(theta)`| 原点を中心に角度 $\theta$ だけ回転する変換を返す。 <br>返り値の型は `Affine<K>`。|
|`rotate(p, theta)`| 点 $\boldsymbol{p}$ を中心に角度 $\theta$ だけ回転する変換を返す。 <br>返り値の型は `Affine<K>`。|
|`rotate90(p)`| 点 $\boldsymbol{p}$ を中心に $\pi/2$ だけ回転する変換を返す。 <br>返り値の型は `Affine<K>`。|

## `AngleComp<K>` クラス

`Point<K>` を偏角の大小で比較するための関数オブジェクト。
主に、点を中心点の周りに反時計回り（counter-clockwise）にソートする（偏角ソート）ために用いる。
比較は、偏角を $(-\pi, \pi\rbrack$ の範囲に正規化して行う。すなわち、x軸の正の向きを基準（角度0）として、反時計回りに比較する。
ゼロベクトル $\boldsymbol{p}=(0,0)$ は、x軸の正の向きにある点と同様に扱われる。
`K` が整数型の場合でも正しく動作する。