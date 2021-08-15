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
typedef pair<long long, long long> pll;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef priority_queue<long long, vector<long long>, greater<long long>> pqll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/
// https://atcoder.jp/contests/abc075/tasks/abc075_c

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    vector<pii> E(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        E[i] = make_pair(a, b);
    }

    int ans = 0;

    for (auto [a, b] : E) {
        dsu D(N);

        for (auto [c, d] : E) {
            if (a == c and b == d) continue;

            D.merge(c, d);
        }

        if (D.groups().size() > 1) ans++;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
