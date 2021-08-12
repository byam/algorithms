#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

// template
template <class T>
void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template <class T>
void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

// Function to return LCM of two numbers
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }

void solve() {
    // in
    int N;
    cin >> N;
    vll T(N);
    rep(i, 0, N) cin >> T[i];

    ll ans = T[0];
    for (int i = 1; i < N; i++) {
        ans = lcm(ans, T[i]);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
