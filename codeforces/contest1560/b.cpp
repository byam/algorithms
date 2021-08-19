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
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans;
        ll n = abs(a - b) * 2;
        ll k = n / 2;

        // c + k
        ans = c + k;
        if (n < a or n < b or n < c)
            cout << -1 << endl;
        else if (ans > n or ans == b or ans == c or ans == a) {
            ans = abs(c - k);
            if (ans > n or ans == 0 or ans == b or ans == c or ans == a) {
                cout << -1 << endl;
            } else
                cout << ans << endl;
        } else {
            cout << ans << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
