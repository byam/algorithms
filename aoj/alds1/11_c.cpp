#include <bits/stdc++.h>
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define print2d(v, n, m)                \
    for (int i = 0; i < (n); i++) {     \
        for (int j = 0; j < (m); j++) { \
            cout << v[i][j] << " ";     \
        }                               \
        cout << endl;                   \
    }

// func
#define rep(i, first, last) for (int i = (first); i < (last); i++)
#define fore(x, v) for (auto x : v)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define fill2d(arr2d, val) memset(&arr2d, val, sizeof arr2d)

// type
#define ll long long

int N;
vector<vector<int> > G(100);
vector<int> dist(100, -1);

void solve() {
    // in
    cin >> N;

    rep(i, 0, N) {
        int u, k;
        cin >> u >> k;
        rep(j, 0, k) {
            int v;
            cin >> v;
            G[u - 1].push_back(v - 1);
        }
    }

    queue<int> queue;
    queue.push(0);
    dist[0] = 0;

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            queue.push(nv);
        }
    }

    rep(i, 0, N) { cout << i + 1 << " " << dist[i] << endl; }
}

int main() {
    solve();
    return 0;
}
