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
Problem: https://atcoder.jp/contests/abc141/tasks/abc141_d
Point: Priority Que
------------------------------------*/

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    // max pq
    priority_queue<ll, vector<ll>, less<ll>> pq;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        sum += a;
        pq.push(a);
    }

    for (int i = 0; i < M; i++) {
        ll a_max = pq.top();
        pq.pop();

        // use ticket
        ll a_sale = floor(a_max / 2);
        pq.push(a_sale);
        sum -= a_max - a_sale;
    }

    cout << sum << endl;
}

int main() {
    solve();
    return 0;
}
