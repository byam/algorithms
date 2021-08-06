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

ll N;

int countDigit(long long n) {
    if (n / 10 == 0) return 1;
    return 1 + countDigit(n / 10);
}

void solve() {
    // in
    cin >> N;
    ll ans = INT_MAX;

    for (ll a = 1; a <= sqrt(N); a++) {
        if (N % a == 0) {
            ll b;
            b = N / a;

            ll f = max(countDigit(a), countDigit(b));

            // cout << a << " " << b << endl;
            ckmin(ans, f);
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
