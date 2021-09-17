#include <bits/stdc++.h>
using namespace std;
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)
using ll = long long;
using Graph = vector<vector<int>>;  // グラフ型

void solve() {
    // in
    int N;
    cin >> N;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (i * j == N) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    solve();
    return 0;
}
