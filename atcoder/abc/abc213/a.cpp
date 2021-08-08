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
    int a, b;
    cin >> a >> b;
    bitset<8> abit(a);
    bitset<8> bbit(b);
    bitset<8> c = (abit ^ bbit);

    cout << (int)(c.to_ulong()) << endl;
    // cout << (a | b) << endl;
}

int main() {
    solve();
    return 0;
}
