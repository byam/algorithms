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

bool isPrime(int n) {
    // Corner case
    if (n <= 1) return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0) return false;

    return true;
}

void solve() {
    // in
    ll k;
    ll n;
    string S_ORG;
    cin >> k >> S_ORG;

    auto S = S_ORG;
    sort(S.begin(), S.end());
    // printv(S);

    char comp_digit[] = {'1', '4', '6', '8', '9'};

    // one digit
    for (auto c : comp_digit) {
        for (auto s : S) {
            if (c == s) {
                cout << 1 << endl;
                cout << c << endl;
                return;
            }
        }
    }

    if (S.size() == 1) {
        cout << 1 << endl;
        cout << S[0] << endl;
        return;
    }

    // two digits: has same digit
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == S[i + 1]) {
            cout << 2 << endl;
            cout << S.substr(i, 2) << endl;
            return;
        }
    }

    int ans = stoi(S_ORG);
    for (int i1 = 0; i1 < k; i1++) {
        for (int i2 = i1; i2 < k; i2++) {
            for (int i3 = i2; i3 < k; i3++) {
                for (int i4 = i3; i4 < k; i4++) {
                    int a = S_ORG[i4] - '0';
                    if (i3 != i4) a = (S_ORG[i3] - '0') * 10 + a;
                    if (i2 != i3) a = (S_ORG[i2] - '0') * 10 + a;
                    if (i1 != i2) a = (S_ORG[i1] - '0') * 10 + a;

                    if (!isPrime(a)) chmin(ans, a);
                }
            }
        }
    }

    string m = to_string(ans);
    cout << m.length() << endl;
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
