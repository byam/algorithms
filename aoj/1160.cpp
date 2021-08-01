#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)

int w, h;
int field[51][51] = {{0}};
int cnt = 0;

void dfs(int x, int y) {
    // checked
    field[x][y] = 0;

    // move
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int next_x = dx + x;
            int next_y = dy + y;
            if (0 <= next_x and next_x < h and 0 <= next_y and next_y < w and
                field[next_x][next_y])
                dfs(next_x, next_y);
        }
    }
}

void solve() {
    while (true) {
        // in
        cin >> w >> h;

        // stop
        if (w == 0 and h == 0) return;

        rep(i, h) rep(j, w) cin >> field[i][j];

        cnt = 0;

        // dfs
        rep(i, h) rep(j, w) {
            if (!field[i][j]) continue;
            dfs(i, j);
            cnt++;
        }

        // out
        cout << cnt << endl;
    }
}

int main() {
    solve();
    return 0;
}
