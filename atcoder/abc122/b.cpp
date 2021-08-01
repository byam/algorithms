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
    string S;
    cin >> S;
    string T = "ATCG";
    int ans = 0;

    int now = 0;
    for (int i = 0; i < S.size(); i++) {
        bool isT = false;
        for (int j = 0; j < T.size(); j++) {
            if (S[i] == T[j]) isT = true;
        }
        if (isT) {
            now++;
            ckmax(ans, now);
        } else
            now = 0;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
