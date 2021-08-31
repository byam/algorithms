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

void solve(int t) {
    // in
    int n;
    int N_MAX = 10000;
    cin >> n;
    vvi field(n, vi(n, 0));
    vi row(n, 0);
    vi col(n, 0);
    rep(i, n) {
        rep(j, n) {
            char c;
            cin >> c;
            int k;
            if (c == 'X') k = 1;
            if (c == 'O') k = (-1) * N_MAX;
            if (c == '.') k = 0;
            field[i][j] = k;
            row[i] += k;
            col[j] += k;
        }
    }

    int ans = N_MAX;
    rep(i, n) {
        if (row[i] >= 0 and row[i] < n) {
            chmin(ans, n - row[i]);
        }
        if (col[i] >= 0 and col[i] < n) {
            chmin(ans, n - col[i]);
        }
    }

    int cnt = 0;
    rep(i, n) {
        if (row[i] >= 0 and row[i] == n - ans) cnt++;
        if (col[i] >= 0 and col[i] == n - ans) cnt++;
    }

    rep(i, n) {
        rep(j, n) {
            if (field[i][j] != 0) continue;
            if (ans == 1 and row[i] == n - ans and col[j] == n - ans) cnt--;
        }
    }

    if (cnt == 0 or ans == N_MAX)
        printf("Case #%d: Impossible\n", t);
    else
        printf("Case #%d: %d %d\n", t, ans, cnt);
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
        solve(cnt);
        cnt++;
    }
    return 0;
}
