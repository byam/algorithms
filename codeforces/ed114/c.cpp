#include <bits/stdc++.h>

//#include <atcoder/all>
// using namespace atcoder;
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cerr << x << " "; \
    }                     \
    cerr << endl;

#define print2d(v)                              \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
    }

// func
#define rep(i, last) for (int i = 0; i < (last); i++)
#define srtv(v) sort((v).begin(), (v).end())
#define all(v) (v).begin(), (v).end()

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

template <class T>
void out(T x) {
    cout << x << "\n";
}

template <class T>
void out(vector<T> x) {
    int sz = x.size();
    for (int i = 0; i < sz; i++) {
        cout << x[i];
        if (i < sz - 1) cout << " ";
    }

    cout << "\n";
}

// in
#define rd(...)  \
    __VA_ARGS__; \
    read(__VA_ARGS__)
#define rdv(value, ...) \
    value(__VA_ARGS__); \
    cin >> value
template <class T>
auto& operator>>(istream& is, vector<T>& xs) {
    for (auto& x : xs) is >> x;
    return is;
}
template <class T, class Y>
auto& operator>>(istream& is, vector<pair<T, Y>>& xs) {
    for (auto& [x1, x2] : xs) is >> x1 >> x2;
    return is;
}
template <class... Args>
auto& read(Args&... args) {
    return (cin >> ... >> args);
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
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> Graph;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int n;
    read(n);
    vll a(n);
    read(a);
    int m;
    read(m);
    vector<pair<ll, ll>> d(m);
    for (int i = 0; i < m; i++) {
        ll x, y;
        read(x, y);
        d[i] = {x, y};
    }

    srtv(a);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    for (int i = 0; i < m; i++) {
        ll att = d[i].first;
        ll def = d[i].second;

        auto it = lower_bound(a.begin(), a.end(), att);

        ll anspick = 0;
        ll ansnotpick = 0;
        ll hatt;

        int idx = it - a.begin();

        // not found lower bound
        if (*it < att) {
            hatt = a[n - 1];
            if (s - hatt < def) anspick += abs(s - hatt - def);
            anspick += abs(att - hatt);
            out(anspick);
            continue;
        }

        // a[0]
        if (idx == 0) {
            hatt = a[0];
            if (s - hatt < def) anspick += abs(s - hatt - def);
            if (a[idx] < att) anspick += abs(a[idx] - att);
            out(anspick);
            continue;
        }

        // pick it
        if (s - a[idx] < def) anspick += abs(s - a[idx] - def);
        if (a[idx] < att) anspick += abs(a[idx] - att);

        // not pick it
        idx--;
        if (s - a[idx] < def) ansnotpick += abs(s - a[idx] - def);
        if (a[idx] < att) ansnotpick += abs(a[idx] - att);

        if (anspick > ansnotpick)
            out(ansnotpick);
        else
            out(anspick);
    }
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
