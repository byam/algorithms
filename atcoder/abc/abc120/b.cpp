#include <bits/stdc++.h>
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

// func
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ckmin(x, y) x = min(x, y)

// type
#define vi vector<int>
#define ll long long
#define Graph vector<vector<int>>

void solve() {
    // in
    int A, B, K;
    cin >> A >> B >> K;

    vi div;
    for (int i = 1; i <= A; i++) {
        if (!(A % i) and !(B % i)) div.push_back(i);
    }

    // printv(div);

    cout << div[div.size() - K] << endl;
}

int main() {
    solve();
    return 0;
}
