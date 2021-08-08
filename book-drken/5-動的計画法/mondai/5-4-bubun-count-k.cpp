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

// 無限大を表す値
const int INF = 1 << 29;

int main() {
    // 入力
    int N, K, W;
    cin >> N >> K >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 配列 dp
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));

    // 初期条件
    dp[0][0] = 0;

    // ループ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // a[i] を選ばない場合
            chmin(dp[i + 1][j], dp[i][j]);

            // a[i] を選ぶ場合
            if (j >= a[i]) chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }
    }

    // 最小値が K 以下ならば、Yes
    if (dp[N][W] <= K)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
