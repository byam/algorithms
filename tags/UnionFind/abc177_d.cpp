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

Pr: https://atcoder.jp/contests/abc177/tasks/abc177_d
Po: Union Find
------------------------------------*/

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    dsu G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (G.same(a, b)) continue;
        G.merge(a, b);
    }

    int ans = 0;
    for (auto g : G.groups()) {
        int sz = g.size();
        chmax(ans, sz);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
