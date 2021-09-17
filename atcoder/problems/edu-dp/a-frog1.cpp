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

const int INF = 1 << 29;

void solve() {
    // in
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];

    // dp table
    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        if (i > 0) chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

int main() {
    solve();
    return 0;
}
