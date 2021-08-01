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
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll cost = INT_MAX;
    for (ll c_cnt = 0; c_cnt <= 2 * max(X, Y); c_cnt++) {
        ll cost_i = c_cnt * C;
        if (c_cnt / 2 < X) cost_i += A * abs(X - c_cnt / 2);
        if (c_cnt / 2 < Y) cost_i += B * abs(Y - c_cnt / 2);

        ckmin(cost, cost_i);
    }

    cout << cost << endl;
}

int main() {
    solve();
    return 0;
}
