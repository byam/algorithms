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
    int N;
    cin >> N;

    vector<vector<int>> h(N, vector<int>(3));

    for (int i = 0; i < N; i++) cin >> h[i][0] >> h[i][1] >> h[i][2];

    // dp table
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmax(dp[i + 1][j], dp[i][k] + h[i][j]);
            }
        }
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
}

int main() {
    solve();
    return 0;
}
