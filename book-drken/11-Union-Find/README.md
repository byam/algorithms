## ポイント

- グループ分けを効率的に管理するデータ構造
  - 根付き木の構造を用いる
- 機能
  - issame(x, y)：同じグループに属するかどうかを調べる
  - unite(x, y)：グループを合併する
  - root(x)：グループの根を返す
- 工夫
  - union by size：サイズが小さい方のデーア構造を大きい方に合併する
  - 経路圧縮：根に到着するまでの経路中の各頂点 v に対しても、par[v] = r 格納される

```cpp
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) { return -par[root(x)]; }
};
```

## Weighted Union-Find

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind<int> uf(N);
    for (int i = 0; i < M; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (uf.issame(l, r)) {
            int diff = uf.diff(l, r);
            if (diff != d) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);
        }
    }
    cout << "Yes" << endl;
}
```

## Ref
- [Union find (素集合データ構造) - SlideShare](https://www.slideshare.net/chokudai/union-find-49066733)
- [重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
