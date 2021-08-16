- [ARC107 C - Shuffle Permutation](#arc107-c---shuffle-permutation)

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
