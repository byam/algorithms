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
    int N, M, K;
    cin >> N >> M >> K;

    dsu D(N);
    vector<map<int, bool>> F(N), B(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (!D.same(a, b)) D.merge(a, b);

        F[a][b] = true;
        F[b][a] = true;
    }
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;

        B[c][d] = true;
        B[d][c] = true;
    }

    vector<int> ans(N, 0);

    for (auto g : D.groups()) {
        for (auto v : g) {
            ans[v] = g.size() - 1 - F[v].size();
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i] -= F[i].size();
    }

    printv(ans);
}

int main() {
    solve();
    return 0;
}
