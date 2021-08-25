#include <bits/stdc++.h>

//#include <atcoder/all>
// using namespace atcoder;
using namespace std;

// debug
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

#define print2d(v, n, m)                \
    for (int i = 0; i < (n); i++) {     \
        for (int j = 0; j < (m); j++) { \
            cout << v[i][j] << " ";     \
        }                               \
        cout << endl;                   \
    }

// func
#define rep(i, first, last) for (int i = (first); i < (last); i++)
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

vector<int> IntegerToVector(int bit, int N) {
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
            S.push_back(1);
        } else {
            S.push_back(0);
        }
    }
    return S;
}

int calc(vi& bit, string s) {
    int n = bit.size();
    int ans = n;

    int scoreA = 0;
    int scoreB = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '?' and s[i] - '0' != bit[i]) return n;
    }

    // cout << s << endl;
    // printv(bit);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            scoreA += bit[i] == 1;
        else
            scoreB += bit[i] == 1;

        if (scoreA > scoreB + (n - i) / 2) ans = min(ans, i + 1);
        if (scoreB > scoreA + (n - i - 1) / 2) ans = min(ans, i + 1);
    }

    return ans;
}

void solve() {
    // in
    string s;
    cin >> s;

    int N = 10;
    int ans = N;
    for (int bit = 0; bit < (1 << N); bit++) {
        vector<int> S = IntegerToVector(bit, N);
        chmin(ans, calc(S, s));
    }
    cout << ans << endl;
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
