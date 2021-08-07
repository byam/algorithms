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

/*-----------------------------------
        Coding Starts Here

Problem: https://atcoder.jp/contests/abc212/tasks/abc212_d
Point:
- Priority Que
------------------------------------*/

void solve() {
    int Q;
    cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll s = 0;

    rep(qi, Q) {
        int type;
        cin >> type;

        if (type == 3) {
            ll ans = q.top();
            q.pop();
            ans += s;
            cout << ans << endl;
        } else {
            int x;
            cin >> x;
            if (type == 1)
                q.push(x - s);
            else
                s += x;
        }
    }
}

int main() {
    solve();
    return 0;
}
