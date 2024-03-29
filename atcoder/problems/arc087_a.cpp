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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N;
    cin >> N;

    map<ll, ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;

        A[a]++;
    }

    int ans = 0;
    for (auto it = A.begin(); it != A.end(); ++it) {
        ll n = it->first;
        ll n_cnt = it->second;

        if (n == n_cnt) continue;
        if (n < n_cnt)
            ans += n_cnt - n;
        else
            ans += n_cnt;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
