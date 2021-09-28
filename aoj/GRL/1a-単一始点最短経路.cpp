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

/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
    欠点：負の辺があるときに使用できない（その場合はBellman-Fordを利用）
*/
void dijkstra(const GraphEdge &G, int s, vector<ll> &dis) {
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>>
        pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] >
                dis[v] + e.cost) {  // 最短距離候補なら priority_queue に追加
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
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
    dijkstra(G, r, dist);

    // 出力
    for (auto x : dist) {
        if (x == INF)
            printf("INF\n");
        else
            printf("%d\n", x);
    }
    return 0;
}
