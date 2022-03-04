#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int n;
vector<vector<char>> field;
vector<vector<int>> memo;

int dp(int i, int j) {
    if (i < 0 or j < 0) return 0;
    if (i == 0 and j == 0) return 1;

    if (memo[i][j] == -1) {
        if (field[i][j] == '*')
            memo[i][j] = 0;
        else
            (memo[i][j] = dp(i - 1, j) + dp(i, j - 1)) %= mod;
    }
    return memo[i][j];
}

void solve() {
    // in
    cin >> n;
    field.resize(n, vector<char>(n));
    memo.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
        }
    }

    // edge case
    if (field[0][0] == '*' or field[n - 1][n - 1] == '*') {
        cout << 0 << endl;
        return;
    }

    // dp: top-down
    cout << dp(n - 1, n - 1) << endl;
}

int main() {
    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
