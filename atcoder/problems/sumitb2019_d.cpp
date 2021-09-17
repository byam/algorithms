#include <bits/stdc++.h>
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

// func
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)

// type
#define vi vector<int>
#define ll long long
#define Graph vector<vector<int>>

void solve() {
    // in
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;

    // possible ABC
    for (int i = 0; i < 1000; i++) {
        // abc
        int pin[3] = {i / 100, (i % 100) / 10, i % 10};

        int pi = 0;
        for (int si = 0; si < S.length(); si++) {
            if (pi == 3) continue;
            if (S[si] - '0' == pin[pi]) {
                pi++;
            }
        }

        if (pi == 3) {
            ans++;
            // printv(pin);
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
