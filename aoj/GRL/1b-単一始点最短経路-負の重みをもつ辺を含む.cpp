#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const long long INF = 1LL << 60;

// 辺を表す型
struct Edge {
    ll to, cost;  // 辺の接続先頂点, 辺の重み
    Edge(ll to, ll cost) : to(to), cost(cost) {}  // コンストラクタ
};

typedef vector<vector<Edge>> GraphEdge;

/*
    単一始点最短経路（負の重みをもつ辺を含む）

    計算量：O(E * V)
    利点：負の辺があっても正しく動作し、負の閉路を検出することができる。
         戻り値がtrueなら負の閉路を含む
 */
bool bellman_ford(GraphEdge& graph, int s, vector<ll>& dist) {
    int n = graph.size();
    dist = vector<ll>(n, INF);
    dist[s] = 0;  // 開始点の距離は0
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int k = 0; k < graph[v].size(); k++) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i == n - 1)
                        return true;  // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}

int main() {
    // 入力
    int V, E, r;
    cin >> V >> E >> r;

    GraphEdge G(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(Edge(t, d));
    }

    // 計算
    vector<ll> dist;
    bool neg_cycle = bellman_ford(G, r, dist);
    if (neg_cycle) {
        printf("NEGATIVE CYCLE\n");
        return 0;
    }

    // 出力
    for (auto x : dist) {
        if (x == INF)
            printf("INF\n");
        else
            printf("%d\n", x);
    }
    return 0;
}
