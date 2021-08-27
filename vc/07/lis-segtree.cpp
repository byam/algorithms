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

// 抽象化したセグメント木
template <class Monoid>
struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid& unity) : F(f), UNITY(unity) {
        init(n);
    }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* update a, a is 0-indexed */
    void update(int a, const Monoid& v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* get [a, b), a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right;
             left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator[](int a) { return dat[a + SIZE_R]; }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R - 1) cout << ",";
        }
        cout << endl;
    }
};

void solve() {
    // in
    int n;
    cin >> n;
    vi h(n, 0);
    rep(i, n) cin >> h[i];

    // セグメント木 (区間取得を max としたもの)
    SegTree<int> dp(
        n + 1, [](int a, int b) { return max(a, b); }, 0);

    for (int i = 0; i < n; i++) {
        int x = h[i];
        int val = dp.get(0, x);
        dp.update(x, val + 1);
    }

    cout << dp.get(0, n + 1) << endl;
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
