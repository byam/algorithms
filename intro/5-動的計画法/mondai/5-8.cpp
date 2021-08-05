#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

const long long INF = 1LL << 60;
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 区間 [j, i) の平均値を前処理で求める
    vector<vector<double>> f(N + 1, vector<double>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            double sum = 0;
            for (int k = j; k < i; ++k) sum += a[k];
            f[j][i] = sum / (i - j);
        }
    }

    // DP
    vector<vector<double>> dp(N + 1, vector<double>(M + 1, -INF));
    dp[0][0] = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 1; k <= M; ++k) {
                chmax(dp[i][k], dp[j][k - 1] + f[j][i]);
            }
        }
    }
    double res = -INF;
    for (int m = 0; m <= M; ++m) chmax(res, dp[N][m]);
    cout << fixed << setprecision(10) << res << endl;
}
