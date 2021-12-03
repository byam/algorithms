#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int> pqi;                              // greater
typedef priority_queue<int, vector<int>, greater<int>> pqli;  // less
typedef priority_queue<long long, vector<long long>, greater<long long>> pqlll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> Graph;
const ll MOD = 1000000007;
const ll INF = 1e18;

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll powerl(long long x, ll y, ll p) {
    ll res = 1LL;  // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    if (x == 0) return 0;  // In case x is divisible by p;

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;

        // y must be even now
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll subsetXORSum(vector<ll>& a) {
    // return accumulate(begin(n), end(n), 0, bit_or<int>()) << (n.size() - 1);
    ll bits = 0;
    for (auto x : a) {
        bits |= x;
        bits %= MOD;
    }

    ll k = powerl(2, a.size() - 1, MOD);
    ll ans = bits * k;
    ans %= MOD;
    return ans;
}

void solve() {
    // in
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
