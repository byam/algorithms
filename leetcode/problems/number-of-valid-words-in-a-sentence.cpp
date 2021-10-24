#include <bits/stdc++.h>

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

bool checkWord(string word, bool digit, int hypen, int punc) {
    int n = word.length();

    if (word == "") return false;
    if (digit) return false;

    if (hypen > 1) return false;
    if (hypen == 1) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] == '-') x = i;
        }

        if (x < 1 or x > n - 2) return false;

        if (!isalpha(word[x - 1]) or !isalpha(word[x + 1])) return false;
    }

    if (punc > 1) return false;
    if (punc == 1 and !ispunct(word[n - 1])) return false;

    // out(word);
    return true;
}

int countValidWords(string sentence) {
    int ans = 0;
    string word = "";
    bool digit = false;
    int hypen = 0;
    int punc = 0;
    for (auto x : sentence) {
        if (x == ' ') {
            // check is valid word
            if (checkWord(word, digit, hypen, punc)) ans++;

            digit = false;
            hypen = 0;
            punc = 0;
            word = "";
        } else {
            word += x;
            if (isdigit(x)) digit = true;
            if (x == '-') hypen++;
            if (ispunct(x) and x != '-') punc++;
        }
    }

    // check is valid word
    if (checkWord(word, digit, hypen, punc)) ans++;

    return ans;
}

void solve() {
    // in

    out(countValidWords(
        " 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 "
        "nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 "
        ".y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u "
        "n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 "
        "8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk "
        "i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  "
        "h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  "
        "u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  "
        "kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  "
        "agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e "
        "9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   "
        "j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif "));
    // out(countValidWords("cat and  dog"));
    // out(countValidWords("!this  1-s b8d!"));
    // out(countValidWords("alice and  bob are playing stone-game10"));
    // out(countValidWords(
    //     "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."));
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
