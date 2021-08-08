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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n), A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        A[i] = a[i];
        B[i] = b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> mpA, mpB;
    int num = 1;
    for (int i = 0; i < n; i++) {
        if (mpA[a[i]] == 0) {
            mpA[a[i]] = num;
            num++;
        }
    }

    num = 1;
    for (int i = 0; i < n; i++) {
        if (mpB[b[i]] == 0) {
            mpB[b[i]] = num;
            num++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mpA[A[i]] << " " << mpB[B[i]] << endl;
    }
}

int main() {
    solve();
    return 0;
}
