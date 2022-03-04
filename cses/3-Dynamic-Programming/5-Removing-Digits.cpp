#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

/*
    1. function
        dp[i]: min step of to 0
    2. relation
        dp[i] = min(1 + dp(i - d))
    3. base
        dp[0] = 0
*/

int n;
vi memo;

vi get_digit(int x) {
    vi res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

int dp(int i) {
    if (i == 0) return 0;

    if (memo[i] == -1) {
        vi digits = get_digit(i);
        int res = INT_MAX;
        for (auto d : digits) {
            if (d and i - d >= 0) res = min(res, 1 + dp(i - d));
        }
        memo[i] = res;
    }

    return memo[i];
}

void solve() {
    // in
    cin >> n;
    memo.resize(n + 1, -1);
    cout << dp(n) << endl;
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
