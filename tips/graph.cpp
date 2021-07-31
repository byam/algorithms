#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
using ll = long long;
using Graph = vector<vector<int>>;  // グラフ型

void solve() {
    Graph G;  // グラフ

    // 有効グラフ
    G[0] = {5};
    G[1] = {3, 6};
    G[2] = {5, 7};
    G[3] = {0, 7};
    G[4] = {1, 2, 6};
    G[5] = {};
    G[6] = {7};
    G[7] = {0};
}

int main() {
    solve();
    return 0;
}
