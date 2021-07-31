#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

char field[502][502];
bool reached[502][502] = {{false}};
int H, W;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= H || y >= W || field[x][y] == '#') return;
    if (reached[x][y]) return;

    reached[x][y] = true;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

void solve() {
    // in
    cin >> H >> W;
    int sx, sy, gx, gy;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> field[h][w];

            // start x, y
            if (field[h][w] == 's') {
                sx = h;
                sy = w;
            }
            // goal x, y
            if (field[h][w] == 'g') {
                gx = h;
                gy = w;
            }
        }
    }

    dfs(sx, sy);
    if (reached[gx][gy])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    solve();
    return 0;
}
