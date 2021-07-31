#include <iostream>
#include <vector>

using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

int N, M;
char field[102][102];

void dfs(int x, int y) {
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = dx + x;
            int ny = dy + y;
            if (0 <= nx && nx < N && 0 <= ny && ny < M &&
                field[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
}

void solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
        }
    }
    solve();
    return 0;
}
