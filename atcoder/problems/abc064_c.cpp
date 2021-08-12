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

void solve() {
    // in
    int N;
    cin >> N;
    vb A(8, false);
    int over = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        int k = a / 400;

        if (k < 8) {
            A[k] = true;
        } else
            over++;
    }

    for (int i = 0; i < 8; i++) {
        if (A[i]) cnt++;
    }

    int mi = cnt, ma = cnt + over;

    if (mi == 0) mi = 1;

    cout << mi << " " << ma << endl;
}

int main() {
    solve();
    return 0;
}
