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

int N;
vector<vector<int>> G;
vector<bool> seen;
vector<int> ans;

void dfs(int v) {
    seen[v] = true;
    ans.push_back(v + 1);

    for (auto n_v : G[v]) {
        if (seen[n_v]) continue;
        dfs(n_v);
        ans.push_back(v + 1);
    }
}

void solve() {
    // in
    cin >> N;

    G.resize(N);
    seen.assign(N, false);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    dfs(0);

    printv(ans);
}

int main() {
    solve();
    return 0;
}
