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

Problem: https://atcoder.jp/contests/arc106/tasks/arc106_b
Point:
- If yes, Union vertexes must be sum(a) = sum(b)
DS: dsu(disjoin set union)
------------------------------------*/

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    vector<ll> a(N), b(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> b[i];

    dsu G(N);
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        if (G.same(c, d)) continue;
        G.merge(c, d);
    }

    string ans = "Yes";
    for (auto g : G.groups()) {
        ll a_sum = 0;
        ll b_sum = 0;
        for (auto v : g) {
            a_sum += a[v];
            b_sum += b[v];
        }
        if (a_sum != b_sum) ans = "No";
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
