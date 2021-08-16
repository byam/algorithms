- [ARC107 C - Shuffle Permutation](#arc107-c---shuffle-permutation)
- [ARC097 D - Equals](#arc097-d---equals)

[DS-1](https://kenkoooo.com/atcoder/#/contest/show/d39b7676-26a5-41fd-b0a1-d51962723eb9)

## [ARC107 C - Shuffle Permutation](https://atcoder.jp/contests/arc107/tasks/arc107_c)

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

## [ARC097 D - Equals](https://atcoder.jp/contests/arc097/tasks/arc097_b)

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
