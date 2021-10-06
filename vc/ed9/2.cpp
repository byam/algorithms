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

template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazyProportional(int n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_,
                            M em_)
        : n(),
          fx(fx_),
          fa(fa_),
          fm(fm_),
          fp(fp_),
          ex(ex_),
          em(em_),
          dat(n_ * 4, ex),
          lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--)
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(int k, int len) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        } else if (a < r && l < b) {  // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
};

void solve() {
    // in
    int n;
    read(n);
    vi a(n);
    read(a);
    string s;
    read(s);

    // 初期化
    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };      // RSQ
    auto fa = [](X x, M m) -> X { return x + m; };          // RSQ
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };      // RSQ
    auto fp = [](M m, long long n) -> M { return m * n; };  // RSQ
    long long ex = 0;                                       // RSQ
    long long em = 0;                                       // RSQ

    SegTreeLazyProportional<X, M> rsqA(n, fx, fa, fm, fp, ex, em);
    SegTreeLazyProportional<X, M> rsqB(n, fx, fa, fm, fp, ex, em);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            rsqA.set(i, a[i]);
        else
            rsqA.set(i, 0);
    }
    rsqA.build();

    for (int i = 0; i < n; i++)
        if (s[i] == 'B')
            rsqB.set(i, a[i]);
        else
            rsqB.set(i, 0);

    rsqB.build();

    ll ans = rsqB.query(0, n);
    // prefix
    for (int i = 0; i < n; i++) {
        ll sum = rsqA.query(0, i + 1) + rsqB.query(i + 1, n);
        chmax(ans, sum);
    }
    // suffix
    for (int i = 0; i < n; i++) {
        ll sum = rsqB.query(0, i + 1) + rsqA.query(i + 1, n);
        chmax(ans, sum);
    }
    out(ans);
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
