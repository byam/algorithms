#include <bits/stdc++.h>
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

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef priority_queue<long long, vector<long long>, greater<long long>> pqll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

bool check(string t, string s, string order) {
    string res = "";

    for (auto c : order) {
        res += s;
        // cout << res << " " << s << endl;
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
    }

    return t == res;
}

void solve() {
    // in
    int t;
    cin >> t;

    while (t--) {
        string S;
        cin >> S;
        int N = S.length();

        // find order string
        string order = "";
        map<char, int> M;
        int rank = 1;

        for (int i = N - 1; i >= 0; i--) {
            char c = S[i];
            if (!M[c]) {
                M[c] = rank;
                rank++;
                order += c;
            }
        }

        reverse(order.begin(), order.end());
        // cout << order << endl;

        // first letter's last index
        int idx;
        for (int i = N - 1; i >= 0; i--) {
            char c = S[i];
            if (c == order[0]) {
                idx = i;
                break;
            }
        }
        // cout << idx << endl;

        // check first string
        bool ok = false;
        int ansx;
        string left = "";
        set<char> diff_left;

        for (int i = 0; i < N; i++) {
            if (order[0] != S[i]) {
                left += S[i];
                diff_left.insert(S[i]);
            }

            if (i >= idx) {
                string right = S.substr(i + 1, left.size());
                cout << diff_left.size() << ": " << left << " " << right
                     << endl;
                if (left == right and diff_left.size() == order.size() - 1) {
                    ok = true;
                    ansx = i;
                    break;
                }
            }
        }

        string ans = S.substr(0, ansx + 1);

        ok = check(S, ans, order);

        if (!ok)
            cout << -1 << endl;
        else
            cout << ans << " " << order << endl;
    }
}

int main() {
    solve();
    return 0;
}
