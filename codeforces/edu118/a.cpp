#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

//#include <atcoder/all>
// using namespace atcoder;
using namespace std;

// func
#define rep(i, first, last) for (int i = (first); i < (last); i++)
#define rrep(i, last, first) for (int i = (last); i >= (first); i--)
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
template <class T>
auto& operator<<(ostream& os, vector<T>& xs) {
    int sz = xs.size();
    rep(i, 0, sz) os << xs[i] << " \n"[i + 1 == sz];
    return os;
}
template <class T, class Y>
auto& operator<<(ostream& os, pair<T, Y>& xs) {
    os << "{" << xs.first << ", " << xs.second << "}";
    return os;
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
const ll MOD = 1000000007;
const ll INF = 1e18;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int rd(x1, p1);
    int rd(x2, p2);
    char ans = '=';

    if (x1 == x2) {
        string ans = "=";
        if (p1 > p2) ans = ">";
        if (p1 < p2) ans = "<";
        out(ans);
        return;
    }

    if (x1 > x2) {
        string ans = ">";
        if (p1 < p2) {
            p2 -= p1;
            while (p2 > 0) {
                x2 *= 10;
                if (x2 > x1) {
                    ans = "<";
                    break;
                }
                p2--;
            }

            if (p2 == 0 and x1 == x2) ans = "=";
        }
        out(ans);
        return;
    } else {
        string ans = "<";
        if (p1 > p2) {
            p1 -= p2;
            while (p1 > 0) {
                x1 *= 10;
                if (x1 > x2) {
                    ans = ">";
                    break;
                }
                p1--;
            }

            if (p1 == 0 and x1 == x2) ans = "=";
        }
        out(ans);
        return;
    }
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
