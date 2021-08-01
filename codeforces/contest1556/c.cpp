#include <bits/stdc++.h>
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

// func
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)

// type
#define vi vector<int>
#define ll long long
#define Graph vector<priority_queue<int, vector<int>, greater<int>>>

int ans;

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    vector<bool> seen(N);

    Graph G(N), C(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push(v);
        G[v].push(u);

        C[u].push(v);
        C[v].push(u);
    }

    int Q;
    rep(i, Q) {
        int ans = 0;

        int q;
        cin >> q;

        // add friendship
        if (q == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            // G[u].push(v);
            // G[v].push(u);
        }

        // remove friendship
        if (q == 2) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            // remove friendship
            // G[u].erase(G[u].begin() + v);
            // G[v].erase(G[v].begin() + u);
        }

        // find group
        if (q == 3) {
            // check vul nodes;
            rep(ni, N) {
                if (C[ni].size() > 0 and ni < C[ni].top()) {
                    seen[ni] = true;
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
