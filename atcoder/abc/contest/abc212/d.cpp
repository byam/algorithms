#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

long long Q;

priority_queue<long long, vector<long long>, greater<long long>> pque;

void solve() {
    // in
    cin >> Q;
    long long add = 0;
    for (int i = 0; i < Q; i++) {
        long long p, x;
        cin >> p;

        if (p == 1) {
            cin >> x;
            pque.push(x - add);
        }
        if (p == 2) {
            cin >> x;
            add += x;
        }
        if (p == 3) {
            long long mi = pque.top();
            cout << 1LL * (add + mi) << endl;
            pque.pop();
            if (pque.empty()) add = 0;
        }
    }
}

int main() {
    solve();
    return 0;
}
