#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using Graph = vector<vector<int>>;  // グラフ型

Graph G;
vb seen;
int ans = 0;
bool cycle;

void dfs(int v, int prev_v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (next_v == prev_v) continue; // 前の node へ戻らない
        if (seen[next_v]) {
            cycle = true; // 次の行く node が、すでに別のルートで確認ずみということは cycle になる
        } else {
            dfs(next_v, v);
        }
    }
}

void solve() {
    int N, M, u, v;
    cin >> N >> M;

    G.resize(N);

    rep(i, M) {
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }

    // 初期化
    seen.assign(N, false);

    rep(i, N) {
        if (seen[i]) continue;
        cycle = false;
        dfs(i, -1);
        if (cycle == false) ans++;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
