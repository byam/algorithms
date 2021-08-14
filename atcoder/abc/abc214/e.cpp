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
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<pll> B;
        for (int i = 0; i < N; i++) {
            ll l, r;
            cin >> l >> r;
            B.emplace_back(pll(l, r));
        }

        sort(B.begin(), B.end());
        B.emplace_back(INF_9, INF_9);

        bool ans = true;

        pqll R;

        ll idx = 1;
        for (auto [l, r] : B) {
            while (idx < l and R.size()) {
                if (idx > R.top()) {
                    ans = false;
                }

                R.pop();
                idx++;
            }
            idx = l;
            R.push(r);
        }

        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main() {
    solve();
    return 0;
}
