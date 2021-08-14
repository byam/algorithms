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
typedef pair<int, int> pii;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N;
    cin >> N;

    vector<pair<ll, pii>> G;
    for (int i = 0; i < N - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G.emplace_back(w, pii(u, v));
    }

    // sort by w
    sort(G.begin(), G.end());

    // union find
    dsu D(N);

    // logic
    ll ans = 0;
    for (auto [w, e] : G) {
        auto [u, v] = e;
        ans += w * D.size(u) * D.size(v);
        D.merge(u, v);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
