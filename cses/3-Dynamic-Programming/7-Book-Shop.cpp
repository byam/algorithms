#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

int n;
int total;
vector<int> prices;
vector<int> pages;
vector<vector<int>> memo;

int dp(int i, int p) {
    // base
    if (i < 0) return 0;

    if (memo[i][p] == -1) {
        memo[i][p] = dp(i - 1, p);
        if (p - prices[i] >= 0)
            memo[i][p] = max(memo[i][p], dp(i - 1, p - prices[i]) + pages[i]);
    }
    return memo[i][p];
}

void solve() {
    // in
    cin >> n >> total;
    prices.resize(n);
    pages.resize(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    memo.resize(n + 1, vector<int>(total + 1, -1));
    cout << dp(n, total) << endl;
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
