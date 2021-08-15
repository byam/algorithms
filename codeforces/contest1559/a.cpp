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
        vll A(N);

        bool even = false;
        bool odd = false;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i] % 2 == 0) even = true;
            if (A[i] % 2 == 1) odd = true;
        }

        sort(A.begin(), A.end());

        ll ans = A[0];
        if (even and odd) ans = 0;

        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
