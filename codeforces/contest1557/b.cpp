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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

// const ll INF = 1 << 60;

void solve() {
    // in
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vll A(n), C(n);
        rep(i, 0, n) cin >> A[i];

        auto B = A;

        sort(B.begin(), B.end());

        int cnt = 1;

        for (int i = 0; i < n - 1; i++) {
            ll cur = A[i];
            ll cur_n = A[i + 1];

            int idx_cur = lower_bound(B.begin(), B.end(), cur) - B.begin();
            int idx_cur_n = lower_bound(B.begin(), B.end(), cur_n) - B.begin();

            if (idx_cur + 1 != idx_cur_n) cnt++;
        }

        // cout << cnt << endl;
        if (n == k)
            cout << "Yes" << endl;
        else if (k < cnt)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

int main() {
    solve();
    return 0;
}
