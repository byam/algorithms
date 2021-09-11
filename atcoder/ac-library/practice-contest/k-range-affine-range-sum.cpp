#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
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
using mint = modint998244353;

// モノイドの型
struct S {
    mint a;
    int size;
};

// 写像の型
struct F {
    mint a, b;
};

// 二項演算
S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }

// e を返す関数
S e() { return S{0, 0}; }

// f(x) を返す関数
S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }

// f∘g を返す関数
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }

// id を返す関数
F id() { return F{1, 0}; }

// const: lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<T> v);
// set         : seg.set(int p, S x)
// query point : seg.get(int p)
// query range : seg.prod(int l, int r)
// query all   : seg.all_prod()
// update point: seg.apply(int p, F f)
// update range: seg.apply(int l, int r, F f)
// search right: seg.max_right<g>(int l)
// search left : seg.min_left<g>(int r)

void solve() {
    // in
    int n, q;
    read(n, q);
    vector<S> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = S{x, 1};
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    for (int i = 0; i < q; i++) {
        int t;
        read(t);
        if (t == 0) {
            int l, r, b, c;
            read(l, r, b, c);
            // range update
            seg.apply(l, r, F{b, c});
        }
        if (t == 1) {
            int l, r;
            read(l, r);
            // range sum with mod
            int ans = seg.prod(l, r).a.val();
            out(ans);
        }
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
