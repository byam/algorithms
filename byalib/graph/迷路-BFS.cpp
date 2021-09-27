#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> field;  // '.': 移動可能

// グリッド上の s(x,y) -> t(x,y) 最短移動距離を求める
// 計算量：O(4 * H * W)
int maze_bfs(int sx, int sy, int tx, int ty) {
    int h = field.size();
    int w = field[0].size();

    // 距離を初期化する
    vector<vector<int>> dist(h, vector<int>(w, -1));

    // 幅優先探索により、最短移動回数を求める
    queue<pair<int, int>> Q;
    Q.push({sy, sx});
    dist[sy][sx] = 0;

    while (!Q.empty()) {
        int cx = Q.front().first, cy = Q.front().second;
        Q.pop();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int ex = cx + dx[i], ey = cy + dy[i];
            if (ex < 0 or ex > h - 1 or ey < 0 or ey > w - 1) continue;
            if (field[ex][ey] != '.' or dist[ex][ey] != -1) continue;
            Q.push({ex, ey});
            dist[ex][ey] = dist[cx][cy] + 1;
        }
    }

    return dist[tx][ty];
}
