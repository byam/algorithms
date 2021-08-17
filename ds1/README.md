# Data Structure Atcoder Problems 1

Atcoder Problems Virtual Contest: [DS-1](https://kenkoooo.com/atcoder/#/contest/show/d39b7676-26a5-41fd-b0a1-d51962723eb9)

- [Data Structure Atcoder Problems 1](#data-structure-atcoder-problems-1)
  - [Prerequisite](#prerequisite)
    - [Union-Find 木](#union-find-木)
    - [Segment 木](#segment-木)
  - [Problems](#problems)
    - [ARC107 C - Shuffle Permutation](#arc107-c---shuffle-permutation)
    - [ARC097 D - Equals](#arc097-d---equals)
    - [ABC137 D - Summer Vacation](#abc137-d---summer-vacation)
    - [ABC126 E - 1 or 2](#abc126-e---1-or-2)

## Prerequisite

ref
- [プログラミングコンテストでのデータ構造](https://www.slideshare.net/iwiwi/ss-3578491)
- [セグメント木を徹底解説！0から遅延評価やモノイドまで](https://algo-logic.info/segment-tree/)

### Union-Find 木
- 機能
  - グループ分けを管理する
  - はじめ、n 個の物は全て別々グループ
  - 2 種類のクエリに対応する
    - 「まとめる」：２つのグループを１つに
    - 「判定」：２つの要素が同じグループに所属するか判定する
- 実装工夫
  - 経路圧縮：root を調べる途中で見たノードにも root 値を設定する
  - ランク：低い方を高い方に繋げる
- 計算量
  - 2つの工夫： `O(alpha(n))` （ほぼ定数）
  - 片方の工夫：`O(log n)`
- 補足
  - Union-Find 木は、グループまとめることができるが、分割することはできない
  - Union-Find 木を改造して機能を付加することが必要になるような問題もある

### Segment 木

- セグメント木
  - 完全二分木（全ての葉の深さが等しい木）
  - 区間を扱うのに適したデータ構造
- 機能(クエリ)
  - 区間上の値を更新する
  - 任意の区間上の最小値や合計値などを取得する
- 計算量
  - `O(log N)`
- 種類
  - 区間上の最小値 Range Minimam Query(RMQ) を扱うセグメント木
  - 区間更新を行う Range Updated Query(RUQ) 遅延評価セグメント木
    - 区間更新：[a, b) の値を x に更新する
    - 区間加算：[a, b) の値に x を加算する
- 様々なバリエーション
  - `update` 方法：一点更新・一点加算・区間更新・区間加算など
  - `query` 内容：区間の最小値・区間の最大値・区間の合計値など

## Problems
### [ARC107 C - Shuffle Permutation](https://atcoder.jp/contests/arc107/tasks/arc107_c)

point
- 行と列を交換しても、互いに影響ないので、それぞれ計算さいて掛け算すると答えになる
- `swap できる行の集合 = 連結木` と考える
- 連結木の中で swap できる頂点の数は、全 permutation は N! となる

solution
- 行だけを計算する
  - swap できる行の番号同士を dsu で merge して行き、連結木たちのそれぞれの size の掛け算
- 列の計算は、列を行に転置して、同じく求める
- [code](https://atcoder.jp/contests/arc107/submissions/25099545)

tags
- dsu (連結木)
- permutation N! (順列)
- matrix transpose (行列転置)

### [ARC097 D - Equals](https://atcoder.jp/contests/arc097/tasks/arc097_b)

point
- 連結成分の中では swap して、どんな順列にでもすることができる

solution
- (x, y) で dsu を作る
- 各連結成分では、頂点の番号集合とpの集合の共通点を数える
  - `std:set_intersection()` で簡単に計算ができる
- 全連結成分の合計が答えとなる
- [code](https://atcoder.jp/contests/arc097/submissions/25100269)

tags
- dsu
- permutation
- set_intersection

### [ABC137 D - Summer Vacation](https://atcoder.jp/contests/abc137/tasks/abc137_d)

point
- 後ろから求めていくタイプな問題。つまり貪欲法
- 最終日から見ていくと、どんどん選択できる候補が増えていく
- priority_que を利用すれば O(log N) 選択できる

solution
- `a = 1` とは最終日にしかできない仕事なので、日ごとにできるバイトのリストを作成
  - `M <= 10^5` なので、全ての人に初期化をする
- 最終日から M 日まで前にをみていく、priority_que で選択していく
- [code](https://atcoder.jp/contests/abc137/submissions/25102171)
- 計算時間：`O(M log N)`

tags
- greedy (貪欲法)
- priority_que (ヒープ)

### [ABC126 E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)

point
- 片方が分かれば、片方がわかる
- 連結成分の中の一個が分かれば、全部わかる

solution
- dsu を利用して、(x, y) を merge していく
- z は無視できる
- 連結成分の個数分魔法使う
- [code](https://atcoder.jp/contests/abc126/submissions/25102803)
- 計算時間：`O(N)`

tags
- dsu
