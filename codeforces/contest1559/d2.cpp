#include <bits/stdc++.h>
using namespace std;

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

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) { return -par[root(x)]; }
};

void solve() {
    // in
    int N, M1, M2;
    cin >> N >> M1 >> M2;

    UnionFind M(N);
    UnionFind D(N);

    for (int i = 0; i < M1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        M.merge(u, v);
    }
    for (int i = 0; i < M2; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        D.merge(u, v);
    }

    vector<pii> pos;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (M.issame(i, j)) continue;
            pos.push_back(make_pair(i, j));
        }
    }

    vector<pii> ans;
    for (auto [a, b] : pos) {
        if (D.issame(a, b) or M.issame(a, b)) continue;
        ans.push_back(make_pair(a, b));
        D.merge(a, b);
        M.merge(a, b);
    }

    cout << ans.size() << endl;
    if (ans.size()) {
        for (auto [a, b] : ans) {
            cout << a + 1 << " " << b + 1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
