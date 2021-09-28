#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
};

typedef long long ll;
typedef vector<vector<Edge>> Graph;
typedef pair<ll, ll> P;

/* 関節点
    Lowlink: グラフの関節点・橋を列挙する構造体
    作成: O(E+V)
    関節点の集合: vector<int> aps
    橋の集合: vector<P> bridges

    グラフ G は連結である
*/
struct LowLink {
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps;  // articulation points
    vector<P> bridges;

    LowLink(const Graph &G_) : G(G_) {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
        sort(aps.begin(), aps.end());          // 必要ならソートする
        sort(bridges.begin(), bridges.end());  // 必要ならソートする
    }

    int dfs(
        int id, int k,
        int par) {  // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0;  // 子の数
        for (auto &e : G[id]) {
            if (!used[e.to]) {
                count++;
                k = dfs(e.to, k, id);
                low[id] = min(low[id], low[e.to]);
                if (par != -1 && ord[id] <= low[e.to])
                    is_aps = true;  // 条件2を満たすので関節点
                if (ord[id] < low[e.to])
                    bridges.emplace_back(min(id, e.to), max(id, e.to));
            } else if (e.to != par) {  // eが後退辺の時
                low[id] = min(low[id], ord[e.to]);
            }
        }
        if (par == -1 && count >= 2) is_aps = true;  // 条件1を満たすので関節点
        if (is_aps) aps.push_back(id);
        return k;
    }
};

int main() {
    // 入力
    int V, E;
    cin >> V >> E;

    Graph G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back({t});
        G[t].push_back({s});
    }

    // 計算
    vector<P> bridges = LowLink(G).bridges;

    // 出力
    for (auto [s, t] : bridges) printf("%d %d\n", s, t);

    return 0;
}
