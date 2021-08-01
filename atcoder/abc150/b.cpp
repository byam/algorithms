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
using Graph = vector<vector<int>>;  // グラフ型

void solve() {
    // in
    int N;
    string S;
    string match = "ABC";

    cin >> N >> S;

    int cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        if (S.substr(i, 3) == match) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
