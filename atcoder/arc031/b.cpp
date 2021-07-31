#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

char field[11][11];
char island[11][11];
int cnt;
string ans = "NO";

void dfs(int x, int y) {
    island[x][y] = 'x';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = dx + x;
            int ny = dy + y;
            if (0 <= nx && nx < 10 && 0 <= ny && ny < 10 &&
                island[nx][ny] == 'o') {
                dfs(nx, ny);
            }
        }
    }
}

void solve() {
    // in
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> field[i][j];
        }
    }

    // all possible change
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (field[i][j] != 'o') {
                cnt = 0;

                // copy field
                for (int k = 0; k < 10; k++) {
                    for (int m = 0; m < 10; m++) island[k][m] = field[k][m];
                }
                // change
                island[i][j] = 'o';

                // cnt
                for (int k = 0; k < 10; k++) {
                    for (int m = 0; m < 10; m++) {
                        if (island[k][m] == 'o') {
                            dfs(k, m);
                            cnt++;
                        }
                    };
                }

                // only 1
                if (cnt == 1) {
                    ans = "YES";
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
