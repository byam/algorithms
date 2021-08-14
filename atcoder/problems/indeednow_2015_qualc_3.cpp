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
typedef priority_queue<int, vector<int>, greater<int>> pqmin;
typedef priority_queue<int, vector<int>, less<int>> pqmax;
typedef vector<vector<int>> vvi;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

vvi G;
vb seen;
pqmin que;

void solve() {
    // in
    int N;
    cin >> N;

    G.resize(N + 1);
    seen.resize(N, false);

    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    que.push(1);

    string ans = "";

    while (que.size()) {
        int v = que.top();
        que.pop();
        seen[v] = true;

        if (ans.length() > 0) ans += " ";
        ans += to_string(v);

        for (auto n_v : G[v])
            if (!seen[n_v]) que.push(n_v);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
