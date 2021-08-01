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
#define Graph vector<vector<int>>

void solve() {
    // in
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi E(n), G(n);
        string e, g;
        cin >> e >> g;

        rep(i, n) E[i] = e[i] - '0';
        rep(i, n) G[i] = g[i] - '0';

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // no pown
            if (!G[i]) continue;

            // no enemy
            if (E[i] == 0) {
                ans++;
                E[i] = 2;
                continue;
            }

            if (i > 0 and E[i - 1] == 1) {
                E[i - 1] = 2;
                ans++;
                continue;
            }

            if (i < n - 1 and E[i + 1] == 1) {
                E[i + 1] = 2;
                ans++;
                continue;
            }
        }

        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
