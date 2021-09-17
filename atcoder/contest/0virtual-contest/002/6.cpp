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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N;
    cin >> N;

    vector<ll> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<ll>());

    ll ans = 1;
    int cnt = 2;
    for (int i = 0; i < N - 1; i++) {
        if (!cnt) break;
        if (A[i] == A[i + 1]) {
            ans *= A[i];
            cnt--;
            i++;
        }
    }

    if (ans == 1)
        cout << 0 << endl;
    else
        cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
