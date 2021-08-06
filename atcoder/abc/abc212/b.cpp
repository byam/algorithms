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
    string s;
    cin >> s;

    bool same = true;
    bool step = true;

    rep(i, 3) {
        if (s[i] != s[i + 1]) same = false;
        int a = s[i] - '0';
        int b = s[i + 1] - '0';
        if ((a + 1) % 10 != b) step = false;
    }

    if (same or step)
        cout << "Weak" << endl;
    else
        cout << "Strong" << endl;
}

int main() {
    solve();
    return 0;
}
