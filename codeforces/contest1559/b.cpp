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
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef priority_queue<long long, vector<long long>, greater<long long>> pqll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int t;
    cin >> t;

    while (t--) {
        int N;
        string S;
        cin >> N >> S;

        int idx = N;

        for (int i = 0; i < N; i++) {
            if (S[i] != '?') {
                idx = i;
                break;
            }
        }

        if (idx == N) {
            for (int i = 0; i < N; i++) {
                if (i % 2 == 0)
                    S[i] = 'B';
                else
                    S[i] = 'R';
            }
        } else {
            // right
            for (int i = idx + 1; i < N; i++) {
                if (S[i] != '?') continue;

                if (S[i - 1] == 'B') S[i] = 'R';
                if (S[i - 1] == 'R') S[i] = 'B';
            }

            for (int i = idx - 1; i >= 0; i--) {
                if (S[i] != '?') continue;

                if (S[i + 1] == 'B') S[i] = 'R';
                if (S[i + 1] == 'R') S[i] = 'B';
            }
        }

        cout << S << endl;
    }
}

int main() {
    solve();
    return 0;
}
