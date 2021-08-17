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
#define srtv(v) sort((v).begin(), (v).end())

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

// Driver function to sort the vector elements
// by second element of pairs
bool sort_by_fir_desc(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second > b.second);
}
bool sort_by_sec_asc(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second < b.second);
}
bool sort_by_sec_desc(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second > b.second);
}

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int> pqi;                              // greater
typedef priority_queue<int, vector<int>, greater<int>> pqli;  // less
typedef priority_queue<long long, vector<long long>, greater<long long>> pqlll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    int N, Q;
    cin >> N >> Q;

    // multset
    map<ll, multiset<ll>> M;
    map<ll, pll> C;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        M[b].insert(a);

        C[i + 1] = make_pair(a, b);
    }

    // show all maxs
    map<ll, ll> BMAX;
    ll ans = INF_9;
    for (auto [b, s] : M) {
        if (s.size()) {
            BMAX[b] = *(--s.end());
            chmin(ans, BMAX[b]);
        }
    }

    // query
    for (int i = 0; i < Q; i++) {
        int c, next_b;
        cin >> c >> next_b;

        // find c's B
        ll pre_r = C[c].first;
        ll pre_b = C[c].second;
        C[c].second = next_b;

        // erase pre_r from pre_b
        auto it = M[pre_b].find(pre_r);
        if (it != M[pre_b].end()) M[pre_b].erase(it);

        // update pre_r to next_b
        M[next_b].insert(pre_r);

        // cout << ma << endl;
    }
}

int main() {
    solve();
    return 0;
}
