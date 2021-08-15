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

void solve() {
    // in
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<vector<bool>> G;

        G.resize(N + 1, vector<bool>(N + 1, false));

        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;

            if (i < N - 1) G[i][i + 1] = true;

            if (a)
                G[N][i] = true;
            else
                G[i][N] = true;
        }

        vi ans(N + 1);
        // n+1 -> 1
        if (G[N][0]) {
            ans[0] = N + 1;
            for (int i = 1; i <= N; i++) ans[i] = i;
        }
        // n+1 -> 1
        else if (G[N - 1][N]) {
            ans[N] = N + 1;
            for (int i = 0; i < N; i++) ans[i] = i + 1;
        }

        else {
            int idx;
            for (int i = 0; i <= N; i++) {
                if (G[i][N]) {
                    ans[i] = i + 1;
                    continue;
                }

                ans[i] = N + 1;
                idx = i + 1;
                break;
            }

            for (int i = idx; i <= N; i++) {
                ans[i] = i;
            }
        }

        for (int i = 0; i < N + 1; i++) {
            cout << ans[i];
            if (i < N) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
