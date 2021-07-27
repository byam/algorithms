#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int R, C; // 迷路の大きさ
char c[1009][1009]; // 迷路のマップ、'.' の場合白マス、'#' の場合黒マス
int dist[1009][1009];

int sx, sy, gx, gy;

int main() {

    // 迷路を入力する
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> c[i][j];
    }

    // 距離を初期化する
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) dist[i][j] = -1;
    }

    // 幅優先探索により、最短移動回数を求める
    queue<pair<int, int>> Q;
    Q.push(make_pair(sy, sx));
    dist[sy][sx] = 0;

    while (!Q.empty()) {
        int cx = Q.front().first, cy = Q.front().second;
        Q.pop();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int ex = cx + dx[i], ey = cy + dy[i];
            if (c[ex][ey] != '.' || dist[ex][ey] != -1) continue;
            Q.push(make_pair(ex, ey));
            dist[ex][ey] = dist[cx][cy] + 1;
        }
    }

    // 最短距離を出力する
    // for (int i = 1; i <= R; i++) {
    //     for (int j = 1; j <= C; j++) {
    //         if (j >= 2) cout << " ";
    //         cout << dist[i][j];
    //     }
    //     cout << endl;
    // }

    cout << dist[gy][gx] << endl;

    return 0;
}
