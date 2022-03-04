#include <iostream>
#include <vector>
using namespace std;

// func(i, w, a) の答えをメモ化する配列
vector<vector<int>> dp;

// 0：false、1: true
int func(int i, int w, const vector<int> &a) {
    // ベースケース
    if (i == 0) {
        if (w == 0)
            return true;
        else
            return false;
    }

    // メモをチェック (すでに計算済みならば答えをリターンする)
    if (dp[i][w] != -1) return dp[i][w];

    // a[i - 1] を選ばない場合
    if (func(i - 1, w, a)) return dp[i][w] = 1;

    // a[i - 1] を選ぶ場合
    if (func(i - 1, w - a[i - 1], a)) return dp[i][w] = 1;

    // どちらも false の場合は false
    return dp[i][w] = 0;
}

int main() {
    // 入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 再帰的に解く
    dp.assign(N + 1, vector<int>(W + 1, -1));
    if (func(N, W, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
