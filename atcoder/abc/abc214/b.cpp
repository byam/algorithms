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

ll ans = 0;

void solve() {
    // in
    int S, T, a, b, c;
    cin >> S >> T;
    for (int i = 0; i <= S; i++) {
        for (int j = 0; j <= S; j++) {
            for (int k = 0; k <= S; k++) {
                if (i + j + k <= S and i * j * k <= T) ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
