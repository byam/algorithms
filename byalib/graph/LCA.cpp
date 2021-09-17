#include <bits/stdc++.h>
using namespace std;

/* LCA(G, root): Lowest Common Ancestor を求める構造体
    - 木 G に対する
    - 根を root とする

    計算時間
    - 前処理：𝑂(𝑁log𝐾) 時間, 𝑂(𝑁log𝐾) 空間
    - クエリ：𝑂(log𝐾)

    I/F
    - int query(int u, int v): LCA を返す
    - get_dist(int u, int v): LCA で 任意の2頂点間の距離が分かる
    - is_on_path(int u, int v, int a): パス上にある頂点があるか分かる

    ref: https://algo-logic.info/lca/
*/
using Graph = vector<vector<int>>;

struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }

    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e != p) dfs(G, e, v, d + 1);
        }
    }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // LCA で 任意の2頂点間の距離が分かる
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    // パス上にある頂点があるか分かる
    bool is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};

int main() {
    // グラフ入力
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // LCA 作成
    LCA lca(g, 0);

    // クエリ
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a, b;
        a--;
        b--;
        // 閉路サイズ
        cout << lca.get_dist(a, b) + 1 << endl;
    }
    return 0;
}
