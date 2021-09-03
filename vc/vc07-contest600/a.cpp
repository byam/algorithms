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

void solve() {
    // in
    string s;
    cin >> s;

    vector<string> a;
    vector<string> b;

    int n = s.length();
    int l = 0, r = 0;
    bool isnum = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == ',' or s[i] == ';' or s[i] == ',') {
            // cout << l << " " << r << endl;
            string k = s.substr(l, r - l);
            // cout << k << endl;
            if (l == r)
                b.push_back(k);
            else if (k == "0")
                a.push_back(k);
            else if (isnum) {
                if (s[l] != '0')
                    a.push_back(k);
                else
                    b.push_back(k);
            } else
                b.push_back(k);
            l = r + 1;
            r++;
            isnum = true;
        } else {
            r++;
            if (!isdigit(s[i])) isnum = false;
        }
    }

    string k = s.substr(l, r - l);
    if (l == r)
        b.push_back(k);
    else if (k == "0")
        a.push_back(k);
    else if (isnum) {
        if (s[l] != '0')
            a.push_back(k);
        else
            b.push_back(k);
    } else
        b.push_back(k);

    if (a.size()) {
        cout << "\"";
        for (int i = 0; i < a.size(); i++) {
            cout << a[i];
            if (i < a.size() - 1) cout << ",";
        }
        cout << "\"" << endl;
    } else
        cout << "-" << endl;

    if (b.size()) {
        cout << "\"";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i];
            if (i < b.size() - 1) cout << ",";
        }
        cout << "\"" << endl;
    } else
        cout << "-" << endl;
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
