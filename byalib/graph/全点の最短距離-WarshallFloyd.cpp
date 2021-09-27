#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Graph;
const int INF = 1000000009;

/*
    グラフの全ての頂点の間の最短路を求める

    計算量：O(V^3)

    G: グラフの距離を格納した2次元配列（隣接行列）
       辺が存在しない場合はINF、ただしG[i][i]=0

    負の辺に対応できる。負の閉路があると、d[i][i]が負となる
 */
void warshall_floyd(Graph& d) {  // nは頂点数
    int n = d.size();
    for (int i = 0; i < n; i++)          // 経由する頂点
        for (int j = 0; j < n; j++)      // 開始頂点
            for (int k = 0; k < n; k++)  // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
    int n, m;
    cin >> n;

    Graph d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;

    cin >> m;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        d[from][to] = cost;
    }

    warshall_floyd(d);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && d[i][j] != INF)
                cout << i << "から" << j << "へのコスト: " << d[i][j] << endl;
        }
    }

    return 0;
}
