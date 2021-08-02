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

const int N_MAX = 15;

int N;
vector<int> honests[15];
vector<int> liars[15];

void solve() {
    cin >> N;
    rep(i, 0, N) {
        int A;
        cin >> A;
        rep(j, 0, A) {
            int x, y;
            cin >> x >> y;
            if (y == 0)
                liars[i].push_back(x - 1);
            else
                honests[i].push_back(x - 1);
        }
    }

    int ans = 0;
    rep(msk, 0, 1 << N) {
        bool ok = true;
        int tot = 0;
        rep(i, 0, N) if (msk & (1 << i)) {
            tot++;
            fore(honest, honests[i]) if (!(msk & (1 << honest))) ok = false;
            fore(liar, liars[i]) if (msk & (1 << liar)) ok = false;
        }
        if (ok) chmax(ans, tot);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
