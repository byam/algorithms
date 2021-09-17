#include <bits/stdc++.h>
using namespace std;

// template
template <class T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template <class T>
void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

void solve() {
    // in
    int N, W;
    cin >> N >> W;

    vector<long long> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    // dp table
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            // not pick
            chmax(dp[i + 1][j], dp[i][j]);

            // pick
            if (j - w[i] >= 0) chmax(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
        }
    }

    cout << dp[N][W] << endl;
}

int main() {
    solve();
    return 0;
}
