#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<int>>;  // グラフ型

int N;
int ans;

void solve() {
    // in
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0 and i % 2) {
                cnt++;
            }
        }
        if (cnt == 8) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
