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
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0;
    map<char, int> RGB;
    for (int i = 0; i < N; i++) {
        RGB[S[i]]++;

        for (int j = i + 1; j < N; j++) {
            int k = j + (j - i);

            if (k < N and S[i] != S[k] and S[j] != S[k] and S[i] != S[j]) {
                cnt++;
            }
        }
    }

    cout << 1LL * RGB['R'] * RGB['G'] * RGB['B'] - cnt << endl;
}

int main() {
    solve();
    return 0;
}
