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

bool sort_by_fasa(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second < b.second);
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

const long long INFL = 1LL << 60;

// 最長増加部分列の長さを求める
int LIS(const vector<long long>& a) {
    int N = (int)a.size();
    vector<long long> dp(N, INFL);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
    }

    // dp[k] < INFL となる最大の k に対して k+1 が答え
    // それは dp[k] >= INFL となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), INFL) - dp.begin();
}

void solve() {
    // in
    int n, m;
    read(n, m);
    vpii E(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        read(a, b);
        a--;
        b--;
        E[i] = {a, b};
    }

    // sorting
    sort(E.begin(), E.end(), [](auto x, auto y) {
        if (x.first < y.first) return true;
        if (x.first > y.first) return false;
        return x.second > y.second;
    });

    // LIS for second vector
    vll b;
    for (auto [f, s] : E) {
        b.push_back(s);
    }
    out(LIS(b));
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
