#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int N, W;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        W += a[i];
    }

    // DP
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // a[i] を選ばない場合
            if (dp[i][j]) dp[i + 1][j] = true;

            // a[i] を選ぶ場合
            if (j >= a[i] && dp[i][j - a[i]]) dp[i + 1][j] = true;
        }
    }

    // 答え
    int cnt = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[N][j]) {
            cnt++;
            // cout << N << ": " << j << endl;
        }
    }
    cout << cnt << endl;
}
