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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    ll A, B, C;
    cin >> A >> B >> C;

    ll cnt = 0;
    while (true) {
        if ((A % 2) or (B % 2) or (C % 2)) break;

        ll a = A, b = B, c = C;
        A = (b + c) / 2;
        B = (a + c) / 2;
        C = (a + b) / 2;

        if (A == a and B == b and C == c) {
            cnt = -1;
            break;
        }
        // cout << A << " " << B << " " << C << endl;

        cnt++;
    }

    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
