#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ai = 0, bi = 0;
    int ans = 1001001009;
    while (ai < n && bi < m) {
        ckmin(ans, abs(a[ai] - b[bi]));
        if (a[ai] < b[bi])
            ai++;
        else
            bi++;
    }

    cout << ans << endl;
}

// O(n + m)
int main() {
    solve();
    return 0;
}
