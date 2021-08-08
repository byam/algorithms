#include <iostream>
#include <vector>
using namespace std;
template <class T>
void chmax(T& a, T b) {
    if (a < b) a = b;
}
template <class T>
void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<vector<long long>> a(N, vector<long long>(3));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j) cin >> a[i][j];

    // DP テーブル
    vector<vector<long long>> dp(N + 1, vector<long long>(3, 0));

    // i 日目から i+1 日目へ
    for (int i = 0; i < N; ++i) {
        // i 日目の状態は j、i+1 日目の状態は k
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    // 答え
    long long res = 0;
    for (int j = 0; j < 3; ++j) chmax(res, dp[N][j]);
    cout << res << endl;
}
