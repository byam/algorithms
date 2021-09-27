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
    vpii A(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        read(x, y);
        A[i] = {x, y};
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {
        // pick B
        pii b = A[i];

        // b based angle
        vector<double> T;
        for (auto x : A) {
            if (b == x) continue;
            double py = x.second - b.second;
            double px = x.first - b.first;
            double angle = atan2(py, px) * 180 / M_PI;
            if (py < 0)
                T.push_back(360 + angle);
            else
                T.push_back(angle);
        }

        sort(all(T));
        // out(T);

        for (int j = 0; j < n - 1; j++) {
            // pick a
            double a = T[j];

            // optimal c
            double co = a + 180;
            if (co > 360) co -= 360;
            int idc = lower_bound(T.begin(), T.end(), co) - T.begin();
            if (idc < n - 1) {
                double diff = min(abs(a - T[idc]), abs(360 - abs(a - T[idc])));
                chmax(ans, diff);
            }
            if (idc > 0) {
                double diff =
                    min(abs(a - T[idc - 1]), abs(360 - abs(a - T[idc - 1])));
                chmax(ans, diff);
            }
        }
    }
    printf("%.7f\n", ans);
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
