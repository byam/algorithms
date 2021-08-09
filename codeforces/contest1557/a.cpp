#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll A(n);
        rep(i, 0, n) cin >> A[i];

        sort(A.begin(), A.end());
        ll a = A[n - 1];
        ll sum = 0;
        rep(i, 0, n - 1) sum += A[i];
        double ans = a + (1.0 * sum) / (n - 1);
        printf("%.6f\n", ans);
    }
}

int main() {
    solve();
    return 0;
}
