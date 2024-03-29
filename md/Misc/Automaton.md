---
title: オートマトン上のDP
documentation_of: ../../src/Misc/Automaton.hpp
---

桁DPを解く. DPの最終的な答えのみを求める仕様なので、DPテーブルの途中の値は手に入らない.

## メンバ関数

| 名前                                                                                                                                              | 概要                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1. `Automaton(alp,init,tr,ac)` <br> 2. `Automaton(alp,init,tr,ac,rej)` <br> 3. `Automaton(alp,init,tr,ac)`<br> 4. `Automaton(alp,init,tr,ac,eps)` | コンストラクタ. <br>4種類共通: `alp`はアルファベット(std::vector&lt;symbol_t&gt;), `init` は初期状態(state_t), `ac` は受理状態か判定する関数(state_t $\rightarrow$ bool) . <br> 1. `tr` は決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ state_t). <br> 2. `tr` は決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ state_t), `rej` は絶対この先受理状態に行くことのない状態 (state_t). <br> 3. `tr` は非決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ std::set&lt;symbol_t&gt;). <br> 4. `tr` は非決定的な遷移関数 (state_t $\times$ symbol_t $\rightarrow$ std::set&lt;symbol_t&gt;), `eps` はイプシロン遷移を表す関数 (state_t  $\rightarrow$ std::set&lt;symbol_t&gt;). |
| `operator&`                                                                                                                                       | 二項演算. 2つのオートマトンの積を表すオートマトンを返す                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `dp_run<T>(n,op,ti,f,init)`                                                                                                                       | オートマトンが受理する長さ n の文字列に対し、与えた関数に従ってDPを計算させて値を返す. <br> T はモノイドで `op` はその二項演算 (T $\times$ T $\rightarrow$ T), `ti` は単位元 . <br> `init`  は dp[初期状態][0文字目]の値. (※イメージ) <br> `f` は dpの遷移を表す関数 ( T $\times$ symbol_t $\times$ (i文字目) $\rightarrow$ T ).  モノイドに対して分配法則が成り立つ必要あり(遅延セグ木の作用素みたいなこと)                                                                                                                                                                                                                                                                                               |
| `num<T>(n)`                                                                                                                                       | オートマトンが受理する長さ n の文字列の個数を返す.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |

## 参考
[https://kuretchi.github.io/blog/entries/automaton-dp/](https://kuretchi.github.io/blog/entries/automaton-dp/)\
[https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836](https://qiita.com/hotman78/items/74c2d5d246ba3b6b3836)\
[https://qiita.com/ryuhe1/items/185e1a283f13ac638a53](https://qiita.com/ryuhe1/items/185e1a283f13ac638a53)\
[https://blog.knshnb.com/posts/aoj2587/](https://blog.knshnb.com/posts/aoj2587/)
## 問題例
[Educational DP Contest S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)\
[Typical DP Contest E - 数](https://atcoder.jp/contests/tdpc/tasks/tdpc_number) \
[AtCoder Beginner Contest 007 D - 禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4) \
[AtCoder Beginner Contest 029 D - 1](https://atcoder.jp/contests/abc029/tasks/abc029_d) \
[AtCoder Beginner Contest 050 D - Xor Sum](https://atcoder.jp/contests/abc050/tasks/arc066_b) (ナイーブにNFA) \
[Donuts プロコンチャレンジ2014 B - 7th](https://atcoder.jp/contests/donuts-live2014/tasks/donuts_live2014_2) \
[CODE FESTIVAL 2014 予選A D - 壊れた電卓](https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_d) \
[いろはちゃんコンテスト Day1 H - ちらし寿司](https://atcoder.jp/contests/iroha2019-day1/tasks/iroha2019_day1_h) \
[yukicoder No.1953 ８](https://yukicoder.me/problems/no/1953) (sp judge)
