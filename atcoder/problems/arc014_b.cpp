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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N;
    cin >> N;

    map<string, bool> M;
    string pre_w = "";

    int who = 0;  // draw:0, win: 1, lose: 2

    bool lose = false;

    for (int i = 0; i < N; i++) {
        string w;
        cin >> w;

        if (lose) continue;

        // lose
        if (M[w]) lose = true;
        if (pre_w.size() and pre_w[pre_w.size() - 1] != w[0]) lose = true;

        // game ends
        if (lose) {
            if (i % 2)
                who = 1;
            else
                who = 2;
        } else {
            M[w] = true;
            pre_w = w;
        }
    }

    if (who == 0) cout << "DRAW" << endl;
    if (who == 1) cout << "WIN" << endl;
    if (who == 2) cout << "LOSE" << endl;
}

int main() {
    solve();
    return 0;
}
