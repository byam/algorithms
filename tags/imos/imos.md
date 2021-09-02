# Imos method

- [Imos method](#imos-method)
  - [Point](#point)
  - [ref](#ref)
  - [アルゴリズム](#アルゴリズム)
    - [1次元](#1次元)
    - [2次元](#2次元)
  - [座標圧縮](#座標圧縮)
  - [Problems](#problems)

## Point

- それぞれが、区間や範囲がある集合の重なり値（or 最大値）を高速に求めるアルゴリズム
- 計算量：
  - 1次元：`O(N + T)` (ナイーブ：`O(N * T)`)。
    - T: 幅
  - 2次元：`O(N + W * H)` (ナイーブ：`O(N * W * N)`)
    - W: 横幅
    - H: 縦幅
## ref
- https://imoz.jp/algorithms/imos_method.html

## アルゴリズム

### 1次元

```cpp
// 初期化
vector<int> table(T, 0);

// カウント行う
for (int i = 0; i < N; i++) {
  table[L[i]]++;  // 入店処理: カウントを 1 増やす
  table[R[i]]--;  // 出店処理: カウントを 1 減らす
}

// シミュレート：合計する
for (int i = 0; i < T; i++) {
  if (0 < i) table[i] += table[i - 1];
}

// 最大値を調べる
M = 0;
for (int i = 0; i < T; i++) {
  if (M < table[i]) M = table[i];
}
```

### 2次元

TBD: https://imoz.jp/algorithms/imos_method.html


## 座標圧縮

```cpp
map<int, int> zip;
map<int, int> unzip;

int compress(vector<ll>& x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}
```

## Problems

- [Atcoder: C - Lamps](https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c)
