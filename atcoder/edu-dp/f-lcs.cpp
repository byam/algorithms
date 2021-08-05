#include <iostream>
#include <string>
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
typedef long long ll;

int main() {
    // 入力
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();

    // DP テーブル
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    // ループ
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            // S の i 文字目と、T の j 文字目が等しいとき
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1])
                    chmax(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    chmax(dp[i][j], dp[i - 1][j - 1]);
            }

            // S に 1 文字追加
            if (i > 0) {
                chmax(dp[i][j], dp[i - 1][j]);
            }

            // T に 1 文字追加
            if (j > 0) {
                chmax(dp[i][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";

    ll i = S.size();
    ll j = T.size();
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans = S[i - 1] + ans;
            i--;
            j--;
        }
    }
    // LCS
    cout << ans << endl;
}
