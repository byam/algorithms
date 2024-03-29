# DFS
- ある状態から、遷移できなくなるまで状態を進めていく。
  - できなくなったら一個前の状態に戻る
- 最初の状態から遷移を繰り返すことで辿り着ける全ての状態を生成（全探索）


- [DFS](#dfs)
  - [問題](#問題)
    - [Lake Counting](#lake-counting)
    - [深さ優先探索で S -> G を判定](#深さ優先探索で-s---g-を判定)


## 問題

### [Lake Counting](http://poj.org/problem?id=2386)

- 8 方向に遷移して、みずみ（クラスター）を探す

```cpp
void dfs(int x, int y) {
    // 到達したところを変える
    field[x][y] = '.';

    // 移動する8方向をループ
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = dx + x;
            int ny = dy + y;
            if (0 <= nx && nx < N && 0 <= ny && ny < M &&
                field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}
```
### [深さ優先探索で S -> G を判定](https://atcoder.jp/contests/atc001/tasks/dfs_a)

- 4 方向に遷移して、スタートからゴールまで行けるかを調べる
- [code](https://atcoder.jp/contests/atc001/submissions/24640179)

```cpp
void dfs(int x, int y) {
    // 範囲以外 or 壁なら何もしない
    if (x < 0 || y < 0 || x >= H || y >= W || field[x][y] == '#') return;

    // すでにみているものなら、何もしない
    if (reached[x][y]) return;

    // 到達したので、変える
    reached[x][y] = true;

    // 4方向を移動する
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
```
