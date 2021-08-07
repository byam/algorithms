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
    string S;
    cin >> S;

    // string to list
    list<char> C;
    for (int i = 0; i < S.size(); i++) {
        C.push_back(S[i]);
    }

    int Q;
    cin >> Q;
    bool is_reverse = false;
    for (int i = 0; i < Q; i++) {
        int t, f;
        char c;
        cin >> t;

        if (t == 1) is_reverse = !is_reverse;

        if (t == 2) {
            cin >> f >> c;
            if (f == 1) {
                if (!is_reverse)
                    C.push_front(c);
                else
                    C.push_back(c);
            }
            if (f == 2) {
                if (is_reverse)
                    C.push_front(c);
                else
                    C.push_back(c);
            }
        }

        // cout << is_reverse << " ";
        // printv(C);
    }

    string ans = "";
    for (auto c : C) ans += c;
    if (is_reverse) reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
