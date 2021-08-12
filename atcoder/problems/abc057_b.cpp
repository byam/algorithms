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

const long long INF = 1001001009;
/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> S(N + 1), P(M + 1);
    for (int i = 1; i <= N; i++) cin >> S[i].first >> S[i].second;
    for (int i = 1; i <= M; i++) cin >> P[i].first >> P[i].second;

    for (int i = 1; i <= N; i++) {
        int ans = N + 1;
        long long manh = INF;
        for (int j = 1; j <= M; j++) {
            long long c_manh =
                abs(S[i].first - P[j].first) + abs(S[i].second - P[j].second);
            if (c_manh < manh) {
                manh = c_manh;
                ans = j;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
