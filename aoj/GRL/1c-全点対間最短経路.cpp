#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Graph;
const ll INF = 1LL << 60;

/*
    全点対間最短経路

    warshall_floyd(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：
    - dis[i][j]にiからjへの最短路のコストを格納
    - prev[i][j]にiからjへの最短路でのjの1つ前の点を格納

    ref: https://algo-logic.info/warshall-floyd/
*/
void warshall_floyd(vector<vector<ll>> &dist, vector<vector<ll>> &prev) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }
}

/* get_path(prev, s, t)
    入力：warshall_floyd で得た prev, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(const vector<vector<ll>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

/* is_negative(dist)
    入力：warshall_floyd で得た dist
    出力：負の有向路を含むかどうか
*/
bool is_negative(const vector<vector<ll>> &dist) {
    int V = dist.size();
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

int main() {
    // 入力
    int V, E;
    cin >> V >> E;

    Graph dist(V, vector<ll>(V, INF));
    Graph prev(V, vector<ll>(V));
    for (int i = 0; i < V; i++) dist[i][i] = 0;

    for (int i = 0; i < E; i++) {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    // 計算
    warshall_floyd(dist, prev);

    // 負の有向路
    if (is_negative(dist)) {
        printf("NEGATIVE CYCLE\n");
        return 0;
    }

    // 出力
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF / 2)
                printf("INF");
            else
                printf("%d", dist[i][j]);

            if (j < V - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
