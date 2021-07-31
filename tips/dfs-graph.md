# DFS Graph

- [DFS Graph](#dfs-graph)
  - [ポイント](#ポイント)
  - [実装](#実装)
    - [表現](#表現)
    - [グラフの入力受け取り](#グラフの入力受け取り)
    - [重みつきグラフの入力受け取り](#重みつきグラフの入力受け取り)
    - [DFS の再帰関数で検索](#dfs-の再帰関数で検索)
  - [問題](#問題)
    - [s から t へ辿り着けるか](#s-から-t-へ辿り着けるか)
      - [グリッドグラフの場合](#グリッドグラフの場合)
    - [連結成分の個数](#連結成分の個数)
      - [連結成分の個数 (閉路なし)](#連結成分の個数-閉路なし)
  - [Ref](#ref)

## ポイント

- C++ での色々な表現や実装などをまとめる

## 実装

### 表現
```cpp
using Graph = vector<vector<int>>; // グラフ型
Graph G; // グラフ

// 有効グラフ
G[0] = {5}
G[1] = {3, 6}
G[2] = {5, 7}
G[3] = {0, 7}
G[4] = {1, 2, 6}
G[5] = {}
G[6] = {7}
G[7] = {0}
```

### グラフの入力受け取り

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);

        // 無向グラフの場合は以下を追加
        // G[b].push_back(a);
    }
}
```

### 重みつきグラフの入力受け取り

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
    }
}
```

### DFS の再帰関数で検索

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
}
```

## 問題

- グラフ探索はとにかく「習うより慣れろ」の精神が重要なテーマでもあります

### s から t へ辿り着けるか

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数、s と t
    int N, M, s, t; cin >> N >> M >> s >> t;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点 s をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, s);

    // t に辿り着けるかどうか
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
```

#### グリッドグラフの場合

- [AtCoder Typical Contest A - 深さ優先探索](https://atcoder.jp/contests/atc001/tasks/dfs_a)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W;
vector<string> field;

// 探索
bool seen[510][510]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w) {
    seen[h][w] = true;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;

        // 再帰的に探索
        dfs(nh, nw);
    }
}

int main() {
    // 入力受け取り
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; ++h) cin >> field[h];

    // s と g のマスを特定する
    int sh, sw, gh, gw;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 'g') gh = h, gw = w;
        }
    }

    // 探索開始
    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化
    dfs(sh, sw);

    // 結果
    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
```

### 連結成分の個数

- 連結とは限らない無向グラフが与えられたとき、それが何個の連結成分からなるのかを数える問題
- まだ探索済みでない頂点 v を一つ選んで v を始点とした DFS を行う

```cpp
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 全頂点が訪問済みになるまで探索
    int count = 0;
    seen.assign(N, false);
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // v が探索済みだったらスルー
        dfs(G, v); // v が未探索なら v を始点とした DFS を行う
        ++count;
    }
    cout << count << endl;
}
```

#### 連結成分の個数 (閉路なし)

```cpp
...
void dfs(int v, int prev_v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (next_v == prev_v) continue; // 前の node へ戻らない
        if (seen[next_v]) {
            cycle = true; // 次の行く node が、すでに別のルートで確認ずみということは cycle になる
        } else {
            dfs(next_v, v);
        }
    }
}
...
```

## Ref

- [DFS (深さ優先探索) 超入門！ 〜 グラフ・アルゴリズムの世界への入口 〜【前編】](https://qiita.com/drken/items/4a7869c5e304883f539b)
- [DFS (深さ優先探索) 超入門！ 〜 グラフ・アルゴリズムの世界への入口 〜【後編】](https://qiita.com/drken/items/a803d4fc4a727e02f7ba)
