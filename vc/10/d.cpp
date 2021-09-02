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

int MAX = 1000000000;
/*-----------------------------------
        Coding Starts Here
------------------------------------*/
map<int, int> zip;
map<int, int> unzip;

int compress(vector<ll>& x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}

void solve() {
    // in
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> seg(n);
    vll x;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        seg[i] = make_pair(l, r);
        x.push_back(l);
        x.push_back(r);
    }

    int sz = compress(x);

    // for (auto itr = zip.begin(); itr != zip.end(); ++itr) {
    //     cout << itr->first << '\t' << itr->second << '\n';
    // }
    // cout << endl;
    // for (auto itr = unzip.begin(); itr != unzip.end(); ++itr) {
    //     cout << itr->first << '\t' << itr->second << '\n';
    // }
    // cout << endl;

    // 初期化
    vector<int> table(sz, 0);

    // カウント行う
    for (int i = 0; i < n; i++) {
        table[zip[seg[i].first]]++;  // 入店処理: カウントを 1 増やす
        table[zip[seg[i].second]]--;  // 出店処理: カウントを 1 減らす
    }

    printv(table);
    // シミュレート：合計する
    for (int i = 0; i < sz; i++) {
        if (0 < i) table[i] += table[i - 1];
    }
    printv(table);

    vpii ans;
    for (int i = 0; i < sz; i++) {
        if (table[i] == k) {
            ll l = i;
            ll r = i;
            while (table[r] >= k) {
                r++;
            }
            i = r - 1;
            ans.push_back(make_pair(l, r));
        }
    }

    cout << ans.size() << endl;

    for (auto [l, r] : ans) cout << unzip[l] << " " << unzip[r] << endl;
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
