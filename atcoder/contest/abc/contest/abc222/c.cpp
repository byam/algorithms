#include <bits/stdc++.h>

//#include <atcoder/all>
// using namespace atcoder;
using namespace std;

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

// out -> print
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

template <class T>
void out(vector<pair<T, T>> p) {
    for (auto [f, s] : p) {
        cout << f << " " << s << endl;
    }
}

template <class T>
void out(map<T, T> m) {
    for (auto [k, v] : m) {
        cout << k << ": " << v << endl;
    }
}

template <class T>
void out(set<T> s) {
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;
}

// パラメータパックが空になったら終了
void outt() { cout << endl; }

// ひとつ以上のパラメータを受け取るようにし、
// 可変引数を先頭とそれ以外に分割する
template <class Head, class... Tail>
void outt(Head&& head, Tail&&... tail) {
    std::cout << head << " ";

    // パラメータパックtailをさらにheadとtailに分割する
    outt(std::forward<Tail>(tail)...);
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

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first > b.first) return true;
    if (a.first < b.first) return false;
    if (a.second < b.second) return true;
    return false;
}

void solve() {
    // in
    int n, m;
    read(n, m);
    vector A(2 * n, vector<char>(m));
    read(A);
    // for (auto x : A) out(x);

    // points
    vpii p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        p[i] = {0, i};
    }

    for (int i = 0; i < m; i++) {
        vpii r;

        for (int j = 0; j < 2 * n; j += 2) {
            pii p1 = p[j];
            pii p2 = p[j + 1];

            int po1 = p1.first;
            int po2 = p2.first;

            int n1 = p1.second;
            int n2 = p2.second;

            char c1 = A[n1][i];
            char c2 = A[n2][i];

            // draw
            if (c1 == c2) {
                r.push_back({po1, n1});
                r.push_back({po2, n2});
            }
            // c1 wins
            else if (c1 == 'G' and c2 == 'C') {
                r.push_back({2 + po1, n1});
                r.push_back({0 + po2, n2});

            } else if (c1 == 'C' and c2 == 'P') {
                r.push_back({2 + po1, n1});
                r.push_back({0 + po2, n2});
            } else if (c1 == 'P' and c2 == 'G') {
                r.push_back({2 + po1, n1});
                r.push_back({0 + po2, n2});
            }
            // c2 wins
            else if (c2 == 'G' and c1 == 'C') {
                r.push_back({0 + po1, n1});
                r.push_back({2 + po2, n2});
            } else if (c2 == 'C' and c1 == 'P') {
                r.push_back({0 + po1, n1});
                r.push_back({2 + po2, n2});
            } else if (c2 == 'P' and c1 == 'G') {
                r.push_back({0 + po1, n1});
                r.push_back({2 + po2, n2});
            }
        }

        sort(r.begin(), r.end(), comp);
        // out(r);
        p = r;
    }
    for (auto [f, s] : p) out(s + 1);
    // sort(point.begin(), point.end(), comp);
    // for (auto [f, s] : point) out(s + 1);
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
