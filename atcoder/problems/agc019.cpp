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
    map<char, int> m;
    m['O'] = 0;
    m['D'] = 0;
    m['I'] = 1;
    m['Z'] = 2;
    m['S'] = 5;
    m['B'] = 8;

    string S;
    cin >> S;
    int ans = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (m.find(S[i]) != m.end()) {
            // cout << S[i] << " " << m[S[i]] << endl;
            S[i] = m[S[i]] + '0';
        }
    }
    cout << S << endl;
}

int main() {
    solve();
    return 0;
}
