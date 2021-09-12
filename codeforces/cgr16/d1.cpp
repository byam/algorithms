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

#define print2d(v, n, m)                \
    for (int i = 0; i < (n); i++) {     \
        for (int j = 0; j < (m); j++) { \
            cerr << v[i][j] << " ";     \
        }                               \
        cerr << endl;                   \
    }

// func
#define rep(i, last) for (int i = 0; i < (last); i++)
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

bool sort_by_2asc_1desc(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second < b.second)
        return true;
    else if (a.second > b.second)
        return false;
    else {
        if (a.first < b.first)
            return false;
        else
            return true;
    };
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

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

template <class T>
struct FenwickTreeRQPU {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeRQPU(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);  // one base indexing
    }

    FenwickTreeRQPU(vector<int> a) : FenwickTreeRQPU(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }

    T sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }

    // RQ: Range Query
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    // PU: Point Update
    void add(int idx, T delta) {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
};

void solve() {
    // in
    int n, m;
    read(n, m);
    vpii a(m);
    for (int i = 0; i < m; i++) {
        int x;
        read(x);
        a[i] = {i, x};
    }
    sort(a.begin(), a.end(), sort_by_2asc_1desc);
    // for (auto [f, s] : a) {
    //     cout << f << " " << s << endl;
    // }
    vi b(m);
    int r = 0;
    for (auto [f, s] : a) {
        b[f] = r;
        r++;
    }
    // out(b);

    // RSQ
    vi c(m);
    FenwickTreeRQPU<int> bit(m);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += bit.sum(0, b[i]);
        bit.add(b[i], 1);
    }
    out(ans);
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
