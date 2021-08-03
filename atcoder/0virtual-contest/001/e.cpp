#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f[214514];

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n + m + 1);
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            ll x;
            cin >> x;
            v[n + x].push_back(i);
            v[i].push_back(n + x);
        }
    }
    queue<ll> que;
    que.push(1);
    f[1] = 1;
    ll cnt = 1;
    while (!que.empty()) {
        ll x = que.front();
        que.pop();
        for (ll p : v[x]) {
            if (f[p]) continue;
            f[p] = 1;
            if (p <= n) cnt++;
            if (cnt == n) {
                cout << "YES\n";
                return 0;
            }
            que.push(p);
        }
    }
    cout << "NO\n";
    return 0;
}
