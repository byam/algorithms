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
    int h, w;
    read(h, w);
    vvi table(h, vi(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            read(c);
            if (c == '.') table[i][j] = 1;
        }
    }

    // L, R
    vvi L(h, vi(w));
    vvi R(h, vi(w));
    for (int i = 0; i < h; i++) {
        // L
        for (int j = 0; j < w; j++) {
            if (table[i][j]) {
                L[i][j] = 1;
                if (j > 0) L[i][j] += L[i][j - 1];
            }
        }
        // R
        for (int j = w - 1; j >= 0; j--) {
            if (table[i][j]) {
                R[i][j] = 1;
                if (j < w - 1) R[i][j] += R[i][j + 1];
            }
        }
    }
    vvi T(h, vi(w));
    vvi D(h, vi(w));
    for (int j = 0; j < w; j++) {
        // T
        for (int i = 0; i < h; i++) {
            if (table[i][j]) {
                T[i][j] = 1;
                if (i > 0) T[i][j] += T[i - 1][j];
            }
        }
        // D
        for (int i = h - 1; i >= 0; i--) {
            if (table[i][j]) {
                D[i][j] = 1;
                if (i < h - 1) D[i][j] += D[i + 1][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int lamp = (L[i][j] + R[i][j] - 1) + (T[i][j] + D[i][j] - 1) - 1;
            chmax(ans, lamp);
        }
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
