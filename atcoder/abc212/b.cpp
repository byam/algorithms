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
    // in
    string s;
    cin >> s;

    int x[4];
    for (int i = 0; i < s.length(); i++) {
        x[i] = s[i] + '0' - 96;
    }
    // printv(x);

    bool weak = true;

    if (x[0] == x[1] and x[1] == x[2] and x[2] == x[3]) {
        weak = true;
    } else {
        for (int i = 0; i <= 2; i++) {
            if (x[i + 1] != (x[i] + 1) % 10) {
                // cout << i << endl;
                // cout << "Weak" << endl;
                weak = false;
            }
        }
    }

    if (weak)
        cout << "Weak" << endl;
    else
        cout << "Strong" << endl;
}

int main() {
    solve();
    return 0;
}
