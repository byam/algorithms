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
#define vi vector<int>
#define ll long long
#define Graph vector<vector<int>>

void solve() {
    // in
    int N;
    cin >> N;

    vi P(N), Q(N), O(N);
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, N) cin >> Q[i];

    rep(i, 0, N) O[i] = i + 1;

    int p, q;

    int cnt = 0;
    do {
        cnt++;

        bool ok = true;
        rep(i, 0, N) if (O[i] != P[i]) ok = false;
        if (ok) p = cnt;

        ok = true;
        rep(i, 0, N) if (O[i] != Q[i]) ok = false;
        if (ok) q = cnt;

    } while (next_permutation(O.begin(), O.end()));

    cout << abs(p - q) << endl;
}

int main() {
    solve();
    return 0;
}
