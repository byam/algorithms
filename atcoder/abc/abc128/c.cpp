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
    int N, M;
    cin >> N >> M;

    Graph G(M);
    vi P(M);

    rep(i, M) {
        int k;
        cin >> k;
        G[i].resize(k);

        rep(j, k) {
            int s;
            cin >> G[i][j];
            G[i][j]--;
        }
    }

    rep(i, M) cin >> P[i];

    int ans = 0;

    // bit search: all possible switch outcomes
    for (int mask = 0; mask < (1 << N); mask++) {
        // check on first outcome

        // all bulb
        bool ok = true;
        for (int bi = 0; bi < M; bi++) {
            // cnt on switches
            int switch_cnt = 0;
            for (int s : G[bi]) {
                if (mask & (1 << s)) switch_cnt++;
            }
            switch_cnt %= 2;

            if (switch_cnt != P[bi]) ok = false;
        }

        if (ok) ans++;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
