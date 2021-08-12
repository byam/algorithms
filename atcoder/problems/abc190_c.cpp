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

int N, M, K;
vector<pair<int, int>> Q, B;

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(1);
        } else {
            S.push_back(0);
        }
    }
    return S;
}

void solve() {
    // in
    cin >> N >> M;
    Q.resize(M + 1);
    rep(i, 1, M + 1) cin >> Q[i].first >> Q[i].second;

    cin >> K;
    B.resize(K + 1);
    rep(i, 1, K + 1) cin >> B[i].first >> B[i].second;

    int ans = 0;
    for (int bitmask = 0; bitmask < (1 << K); bitmask++) {
        vector<int> S = IntegerToVector(bitmask, K);
        // rep(i, 0, S.size()) cout << S[i] << " ";
        // cout << endl;

        vector<bool> seen(N + 1, false);
        for (int i = 0; i < K; i++) {
            if (S[i]) {
                seen[B[i + 1].first] = true;
            } else {
                seen[B[i + 1].second] = true;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= M; i++) {
            if (seen[Q[i].first] and seen[Q[i].second]) cnt++;
        }

        chmax(ans, cnt);
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
