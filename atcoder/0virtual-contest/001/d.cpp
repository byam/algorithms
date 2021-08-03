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
#define fore(x, v) for (auto x : v)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define fill2d(arr2d, val) memset(&arr2d, val, sizeof arr2d)

// type
#define vi vector<int>
#define ll long long
#define Graph vector<vector<int>>

const int MAX_N = 100000;

int N, S[MAX_N], T[MAX_N];

pair<int, int> itv[MAX_N];

int tmin = INT_MAX;

void solve() {
    // in
    for (int i = 0; i < N; i++) {
        itv[i].first = T[i];
        itv[i].second = S[i];

        // cout << itv[i].first << " " << itv[i].second << endl;
    }

    sort(itv, itv + N);
    // for (int i = 0; i < N; i++) {
    //     cout << itv[i].first << " " << itv[i].second << endl;
    // }

    int ans = 0, t = -1000000009;

    for (int i = 0; i < N; i++) {
        // cout << "--" << itv[i].first << " " << itv[i].second << endl;

        if (t <= itv[i].second) {
            ans++;
            t = itv[i].first;
            // cout << t << endl;
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, l;
        cin >> x >> l;
        S[i] = x - l;
        T[i] = x + l;

        chmin(tmin, x - l);
    }

    solve();
    return 0;
}
