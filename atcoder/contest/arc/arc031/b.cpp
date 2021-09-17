#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)

int w = 10, h = 10;
bool field[11][11] = {{false}};
bool check[11][11] = {{false}};

void dfs(int x, int y) {
    // checked
    check[x][y] = 0;

    // move
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            // 4 directions only
            if (dx * dy) continue;
            int next_x = dx + x;
            int next_y = dy + y;
            if (0 <= next_x and next_x < h and 0 <= next_y and next_y < w and
                check[next_x][next_y])
                dfs(next_x, next_y);
        }
    }
}

void solve() {
    // in
    rep(i, h) rep(j, w) {
        char c;
        cin >> c;
        if (c == 'o') field[i][j] = true;
    }

    // change one grid
    rep(i, h) rep(j, w) {
        if (field[i][j]) continue;

        // change
        field[i][j] = true;

        // copy
        rep(i1, h) rep(j1, w) check[i1][j1] = field[i1][j1];

        // dfs
        int cnt = 0;
        rep(i1, h) rep(j1, w) {
            if (!check[i1][j1]) continue;
            dfs(i1, j1);
            cnt++;
        }

        // found
        if (cnt == 1) {
            cout << "YES" << endl;
            return;
        }

        // revert
        field[i][j] = false;
    }

    cout << "NO" << endl;
}

int main() {
    solve();
    return 0;
}
