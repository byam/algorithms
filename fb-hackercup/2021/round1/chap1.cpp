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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

// Function to check the Vowel
bool isVowel(char ch) {
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

// Returns the maximum repeating character length in a
// given string
int maxRepeating(string str) {
    int n = str.length();
    int count = 0;
    char res = str[0];
    int cur_count = 1;

    // Traverse string except last character
    for (int i = 0; i < n; i++) {
        // If current character matches with next
        if (i < n - 1 && str[i] == str[i + 1]) cur_count++;

        // If doesn't match, update result
        // (if required) and reset count
        else {
            chmax(count, cur_count);
            cur_count = 1;
        }
    }

    return count;
}

int solve() {
    // in
    string S;
    cin >> S;

    // counting
    int vow_cnt = 0;
    int con_cnt = 0;
    string vow = "";
    string con = "";
    srtv(S);
    for (auto s : S) {
        if (isVowel(s)) {
            vow_cnt++;
            vow += s;
        } else {
            con_cnt++;
            con += s;
        }
    }

    printv(S);
    cerr << vow << " " << con << endl;
    cerr << vow_cnt << " " << con_cnt << endl;
    cerr << maxRepeating(vow) << " " << maxRepeating(con) << endl;

    int max_vow = maxRepeating(vow);
    int max_con = maxRepeating(con);

    int res_vow = (vow.length() - max_vow) * 2 + con.length();
    int res_con = (con.length() - max_con) * 2 + vow.length();

    return min(res_vow, res_con);
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    cin >> t;
    int cnt = 1;
    while (t--) {
        printf("Case #%d: %d\n", cnt, solve());
        cnt++;
    }
    return 0;
}
