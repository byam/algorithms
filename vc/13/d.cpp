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
const int NMAX = 1e6 + 9;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int n, k;
    read(n, k);
    vi a(n);
    read(a);

    int amax = 0;
    for (auto x : a) chmax(amax, x);

    // cnt n
    vi num(amax + 1, 0);

    int right = 0;
    int diff = 0;
    int ans_sz = 0;
    int ans_l = 0;
    int ans_r = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n) {
            /* 実際に right を 1 進める */

            num[a[right]]++;
            if (num[a[right]] == 1) diff++;

            if (diff > k) {
                diff = k;
                num[a[right]]--;
                break;
            }

            ++right;
        }
        // printv(num);
        // cerr << left << " " << right << endl;
        /* break した状態で right は条件を満たす最大なので、何かする */
        int sz = (right - left);
        if (ans_sz < sz) {
            ans_l = left;
            ans_r = right;
            ans_sz = sz;
        }

        /* left をインクリメントする準備 */
        // ex: if (right == left) ++right;
        // ex: else sum -= a[left];
        if (num[a[left]] == 1) diff--;
        num[a[left]]--;
    }

    printf("%d %d\n", ans_l + 1, ans_r);
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
