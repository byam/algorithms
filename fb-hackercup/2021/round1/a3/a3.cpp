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

const long long MOD = 1000000007;

int solve() {
    // in
    int k;
    read(k);
    string u;
    read(u);
    string s = "";
    for (int i = 0; i < k; i++) {
        if (u[i] != '.')
            s.push_back(u[i]);
        else {
            s += s;
        }
    }
    out(s);
    int n = s.length();
    auto w = s;

    // find first X or O
    int first_pos = n;
    char first_hand = 'A';
    for (int i = 0; i < n; i++) {
        if (w[i] == 'F') continue;
        first_pos = i;
        first_hand = w[i];
        break;
    }
    // not found X or O
    if (first_pos == n) return 0;

    // previous opposite position
    vi oppos(n);
    int prev_pos = first_pos;
    char prev_hand = first_hand;
    for (int i = 0; i < n; i++) {
        if (w[i] == 'F') continue;
        // same XO: update pos
        if (w[i] == prev_hand) {
            prev_pos = i;
            continue;
        }
        // opposite hand: update
        oppos[i] = prev_pos;
        prev_hand = w[i];
        prev_pos = i;
    }
    out(oppos);

    // dp
    vll dp(n);
    vll ans(n);
    dp[0] = 0L;
    ans[0] = 0L;
    int ppos = first_pos;
    for (int i = 1; i < n; i++) {
        // same or F
        if (w[i] == 'F' or w[i] == w[ppos]) {
            dp[i] = dp[i - 1];
        }
        // hand switch
        else {
            dp[i] = (dp[oppos[i]] + oppos[i] + 1) % MOD;
            ppos = i;
        }
        ans[i] = ans[i - 1] + dp[i];
    }
    out(dp);
    out(ans);

    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     ans = (ans + dp[i]) % MOD;
    // }

    return ans[n - 1];
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        printf("Case #%d: %d\n", cnt, solve());
        cnt++;
    }
    return 0;
}
