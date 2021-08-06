#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define ckmin(x, y) x = min(x, y)

void solve() {
    int A, B;
    cin >> A >> B;
    if (0 < A and B == 0)
        cout << "Gold" << endl;
    else if (A == 0 and B > 0)
        cout << "Silver" << endl;
    else if (A > 0 and B > 0)
        cout << "Alloy" << endl;
}

int main() {
    solve();
    return 0;
}
