#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<vector<char>> f;

// flood fill
void dfs(int x, int y, vector<vector<bool>> &check) {
    if (check[x][y]) return;
    check[x][y] = true;
    char c = f[x][y];

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (x + dx < 0 or x + dx >= n) continue;
            if (y + dy < 0 or y + dy >= n) continue;
            if (dx == dy) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (check[nx][ny]) continue;
            if (f[nx][ny] != c) continue;
            dfs(nx, ny, check);
        }
    }
}

bool hasPath(char c) {
    vector<vector<bool>> check(n, vector<bool>(n));

    // Blue
    if (c == 'B') {
        // fill
        for (int i = 0; i < n; i++) {
            if (f[i][0] == c) dfs(i, 0, check);
        }
        // check
        for (int i = 0; i < n; i++) {
            if (check[i][n - 1]) return true;
        }
    }

    // Red
    if (c == 'R') {
        // fill
        for (int i = 0; i < n; i++) {
            if (f[0][i] == c) dfs(0, i, check);
        }
        // check
        for (int i = 0; i < n; i++) {
            if (check[n - 1][i]) return true;
        }
    }

    return false;
}

string solve() {
    // int
    cin >> n;
    f.resize(n);
    int b = 0, r = 0;
    rep(i, n) {
        f[i].resize(n);
        rep(j, n) {
            cin >> f[i][j];
            if (f[i][j] == 'B') b++;
            if (f[i][j] == 'R') r++;
        }
    }

    // solve
    string ans = "Nobody wins";
    if (abs(b - r) > 1) return "Impossible";

    // check blue
    if (hasPath('B')) {
        if (b < r) return "Impossible";

        // change remove one B
        rep(i, n) rep(j, n) if (f[i][j] == 'B') {
            f[i][j] = '.';
            if (!hasPath('B')) return "Blue wins";
            f[i][j] = 'B';
        }
        return "Impossible";
    }

    // check red
    if (hasPath('R')) {
        if (r < b) return "Impossible";

        // change remove one B
        rep(i, n) rep(j, n) if (f[i][j] == 'R') {
            f[i][j] = '.';
            if (!hasPath('R')) return "Red wins";
            f[i][j] = 'R';
        }
        return "Impossible";
    }

    return ans;
}

int main() {
    int t = 1;
    cin >> t;
    int i = 1;
    while (i <= t) {
        cout << "Case #" << i << ": " << solve() << endl;
        i++;
    }
}
