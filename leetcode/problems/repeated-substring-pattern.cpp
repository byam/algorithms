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
template <class T>
auto& operator<<(ostream& os, vector<T>& xs) {
    int sz = xs.size();
    rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
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
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

class Solution {
   public:
    /**************************************
     KMP法：文字列探索
         - 計算量：O(n)
         - ずらし表(部分マッチ用 / Prefix Table) を利用し比較位置を決める
         - LPS("Longest proper Prefix which is also Suffix")
         - パターン自体の部分マッチの位置を事前に用意する
     ref:
         - https://algoful.com/Archive/Algorithm/KMPSearch
         -
 http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html
         - https://www.codespeedy.com/knuth-morris-pratt-kmp-algorithm-in-c/
 ***************************************/

    vector<int> initPrefixTable(string txt) {
        vector<int> lps(txt.length());
        int len = 0;
        int i = 1;
        while (i < txt.length()) {
            if (txt[i] == txt[len]) {
                len++;
                lps[i] = len;
                i++;
                continue;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                    continue;
                } else {
                    len = lps[len - 1];
                    continue;
                }
            }
        }
        return lps;
    }

    // found: return index of the text
    // not found: -1
    int KMP(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();

        // This function constructs the Lps array.
        vector<int> Lps = initPrefixTable(pattern);

        int i = 0, j = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            // If there is a match continue.
            if (j == m) {
                // if j==m it is confirmed that we have found
                return i - m;
                j = Lps[j - 1];
            }
            // If there is a mismatch
            else if (i < n && pattern[j] != text[i]) {
                // if j becomes 0 then simply increment the index i
                if (j == 0) i++;

                // Update j as Lps of last matched character
                else
                    j = Lps[j - 1];
            }
        }

        // not found
        return -1;
    }

    bool repeatedSubstringPattern(string s) {
        string text = (s + s).substr(1, 2 * s.length() - 2);
        string pattern = s;

        return KMP(text, pattern) != -1;
    }
};

int main() {
    out(Solution().repeatedSubstringPattern("abab"));
    out(Solution().repeatedSubstringPattern("aba"));
    out(Solution().repeatedSubstringPattern("abcabcabcabc"));
    return 0;
}
