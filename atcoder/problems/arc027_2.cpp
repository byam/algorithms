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

void solve() {
    // in
    ll N;
    string A, B;
    cin >> N >> A >> B;

    map<char, bool> M;
    for (ll i = 0; i < N; i++) {
        if (isalpha(A[i]) and isdigit(B[i])) {
            M[A[i]] = true;
            A[i] = B[i];
        }
        if (isalpha(B[i]) and isdigit(A[i])) {
            M[B[i]] = true;
            B[i] = A[i];
        }
    }

    long long ans = 1LL;

    for (ll i = 0; i < N; i++) {
        if (M[A[i]] or M[B[i]] or isdigit(A[i]) or isdigit(B[i])) {
            M[A[i]] = true;
            M[B[i]] = true;
            continue;
        }

        if (i == 0)
            ans *= 9LL;
        else
            ans *= 10LL;

        M[A[i]] = true;
        M[B[i]] = true;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
