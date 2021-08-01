#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
#define ckmax(x, y) x = max(x, y)
using ll = long long;
using Graph = vector<vector<int>>;  // グラフ型

void solve() {
    // in
    int N;
    cin >> N;
    int ans = 0;

    int cur = 1;
    bool odd = true;
    int div = 10;

    for (int i = 1; i <= N; i++) {
        if (to_string(i).length() % 2) ans++;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
