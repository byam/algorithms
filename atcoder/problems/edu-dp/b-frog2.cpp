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

const int INF = INT_MAX;

void solve() {
    // in
    int N, K;
    cin >> N >> K;
    vector<int> h(101010);
    for (int i = 0; i < N; i++) cin >> h[i];

    // dp table
    vector<int> dp(101010, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= K; k++) {
            chmin(dp[i + k], dp[i] + abs(h[i] - h[i + k]));
        }
    }

    cout << dp[N - 1] << endl;
}

int main() {
    solve();
    return 0;
}
