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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    int cnt = 0;

    if (a[0] == a[1] and a[1] == a[2]) {
        cout << cnt << endl;
        return;
    }

    if (a[0] == a[1]) {
        cnt += (a[2] - a[0]) / 2;
        if ((a[2] - a[0]) % 2) cnt += 1;

        cout << cnt << endl;
        return;
    }

    if (a[1] == a[2]) {
        cnt += (a[2] - a[0]) / 2;
        if ((a[2] - a[0]) % 2) cnt += 2;
        cout << cnt << endl;
        return;
    }

    else {
        cnt += a[2] - a[1];
        a[1] = a[2];
        a[0] += a[2] - a[1];

        cnt += (a[2] - a[0]) / 2;
        if ((a[2] - a[0]) % 2) cnt += 2;
        cout << cnt << endl;
        return;
    }
}

int main() {
    solve();
    return 0;
}
