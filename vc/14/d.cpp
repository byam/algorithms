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
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

ll sumv(vll& a) {
    ll ans = 0;
    for (auto x : a) ans += x;
    return ans;
}

void solve() {
    // in
    int n, m;
    vll a, b;
    read(n);
    a.resize(n, 0);
    read(a);
    read(m);
    b.resize(m, 0);
    read(b);

    int k = 0;

    // diff table
    vector<vector<ll>> d(n, vll(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = fabs(a[i] - b[j]);
        }
    }

    // first swap
    ll v = labs(sumv(a) - sumv(b));
    if (v == 0) {
        printf("%d\n", v);
        printf("%d\n", k);
        return;
    }

    k += 1;
    int x = 0, y = 0;
    ll diff = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (diff > fabs(ceil(v / 2.0) - d[i][j])) {
                x = i;
                y = j;
                diff = fabs(ceil(v / 2.0) - d[i][j]);
            }
        }
    }

    if (sumv(a) > sumv(b) and a[x] < b[y])
        swap(x, y);
    else if (sumv(a) < sumv(b) and a[x] > b[y])
        swap(x, y);

    swap(a[x], b[y]);

    printv(a);
    printv(b);

    // second swap
    v = labs(sumv(a) - sumv(b));
    cerr << v << endl;

    if (v == 0) {
        printf("%d\n", v);
        printf("%d\n", k);
        printf("%d %d\n", x + 1, y + 1);
        return;
    }

    k += 1;
    ll v1 = v;
    ll x1 = x;
    ll y1 = y;

    x = 0, y = 0;
    diff = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (diff > fabs(ceil(v / 2.0) - d[i][j])) {
                x = i;
                y = j;
                diff = fabs(ceil(v / 2.0) - d[i][j]);
            }
        }
    }
    if (sumv(a) > sumv(b) and a[x] < b[y])
        swap(x, y);
    else if (sumv(a) < sumv(b) and a[x] > b[y])
        swap(x, y);

    swap(a[x], b[y]);

    printv(a);
    printv(b);

    // second swap
    v = labs(sumv(a) - sumv(b));
    cerr << v << endl;

    if (v1 <= v) {
        printf("%d\n", v1);
        printf("%d\n", 1);
        printf("%d %d\n", x1 + 1, y1 + 1);
        return;
    }

    printf("%d\n", v);
    printf("%d\n", 2);
    printf("%d %d\n", x1 + 1, y1 + 1);
    printf("%d %d\n", x + 1, y + 1);
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
