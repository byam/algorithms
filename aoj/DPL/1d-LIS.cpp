#include <bits/stdc++.h>
using namespace std;

const long long INFL = 1LL << 60;

// 最長増加部分列の長さを求める
int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INFL);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
    }

    // dp[k] < INFL となる最大の k に対して k+1 が答え
    // それは dp[k] >= INFL となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), INFL) - dp.begin();
}

int main() {
    // 入力
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << LIS(a) << endl;
    return 0;
}
