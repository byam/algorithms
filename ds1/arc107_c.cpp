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
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef priority_queue<long long, vector<long long>, greater<long long>> pqll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

ll mod = 998244353;

ll fact(int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i % mod;
    }
    return ans;
}

ll calc(const vvi& A, int k) {
    ll ans = 1;
    int n = A.size();

    dsu D(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool ok = true;
            for (int m = 0; m < n; m++)
                if (A[i][m] + A[j][m] > k) ok = false;
            if (ok) D.merge(i, j);
        }
    }

    for (auto g : D.groups()) {
        ans = ans * fact(g.size()) % mod;
    }

    return ans;
}

void solve() {
    // in
    int N, K;
    cin >> N >> K;

    vvi A(N, vi(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            A[i][j] = a;
        }

    // rows
    ll cnt_row = calc(A, K);

    // columns
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) swap(A[i][j], A[j][i]);
    ll cnt_col = calc(A, K);

    cout << cnt_row * cnt_col % mod << endl;
}

int main() {
    solve();
    return 0;
}
