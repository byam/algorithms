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
    map<string, int> m;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    int vmax = 0;
    for (auto it = m.begin(); it != m.end(); ++it) chmax(vmax, it->second);
    // cout << vmax << endl;

    vector<string> S;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == vmax) S.push_back(it->first);
    }

    sort(S.begin(), S.end());
    for (auto v : S) cout << v << endl;
}

int main() {
    solve();

    // map<string, int> Map;
    // Map["a"]++;
    // Map["a"]++;
    // cout << Map["a"] << endl;
    // cout << Map["b"] << endl;

    return 0;
}
