#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

long long n, m, x, ans = INT_MAX;

void solve() {
    // in
    cin >> n >> m;
    vector<long long> va(n), vb(m);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> vb[i];
    }

    // sort
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    // printv(va);
    // printv(vb);

    for (int i = 0; i < n; i++) {
        int lb = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
        if (lb < m && lb > 0) {
            ckmin(ans, min(vb[lb] - va[i], va[i] - vb[lb - 1]));
        }
        if (lb == m) {
            ckmin(ans, va[i] - vb[lb - 1]);
        }
        if (lb == 0) {
            ckmin(ans, vb[lb] - va[i]);
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
