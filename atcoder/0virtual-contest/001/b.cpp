#include <bits/stdc++.h>
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define print2d(v, n, m)                \
    for (int i = 0; i < (n); i++) {     \
        for (int j = 0; j < (m); j++) { \
            cout << v[i][j] << " ";     \
        }                               \
        cout << endl;                   \
    }

// func
#define rep(i, first, last) for (int i = (first); i < (last); i++)
#define fore(x, v) for (auto x : v)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define fill2d(arr2d, val) memset(&arr2d, val, sizeof arr2d)

// type
#define vi vector<int>
#define ll long long
#define Graph vector<vector<int>>

void solve() {
    // in
    string S, T;
    cin >> S >> T;

    bool ok = true;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    solve();
    return 0;
}
