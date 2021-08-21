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

const long long INF = 1001001009;
int N;
vll S, T, ans;

void solve() {
    // in
    cin >> N;
    S.resize(N);
    T.resize(N);
    ans.resize(N);

    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) cin >> T[i];

    // find min
    int min_idx = N;

    ll min_val = INF;
    rep(i, 0, N) {
        ans[i] = T[i];
        if (T[i] < min_val) {
            min_idx = i;
            min_val = T[i];
        }
    }

    // cout << min_idx << " " << min_val << endl;

    ans[min_idx] = min_val;
    int idx = min_idx + 1;
    int cnt = N - 1;

    while (cnt--) {
        ll pre_t = ans[idx - 1] + S[idx - 1];
        // cout << pre_t << endl;

        if (idx >= N) idx -= N;

        chmin(ans[idx], pre_t);

        idx++;
    }

    // printv(ans);
    rep(i, 0, N) cout << ans[i] << endl;
}

int main() {
    solve();
    return 0;
}
