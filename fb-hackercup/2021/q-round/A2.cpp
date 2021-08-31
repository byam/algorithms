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

/*-----------------------------------
        Coding Starts Here
------------------------------------*/
void bfs(int s, const vvi& field, vi& dist) {
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (auto nx : field[x]) {
            if (dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            Q.emplace(nx);
        }
    }

    // printv(dist);
}

int solve() {
    // in
    int n = 26;
    string S;
    cin >> S;
    int k;
    cin >> k;

    vvi field(n);
    vector<vector<int>> dist(n, vector<int>(n, -1));

    // graph
    for (size_t i = 0; i < k; i++) {
        char l, r;
        cin >> l >> r;
        int s = (int)l - 65;
        int t = (int)r - 65;
        field[s].push_back(t);
    }

    int ans = INT32_MAX;
    bool found = false;

    // all path dist
    rep(i, n) bfs(i, field, dist[i]);

    // all char dist
    rep(i, n) {
        int move = 0;
        for (auto s : S) {
            int j = (int)s - 65;
            if (dist[j][i] == -1) {
                move = -1;
                break;
            }
            move += dist[j][i];
        }
        if (move == -1) continue;
        chmin(ans, move);
        found = true;
    }

    return found ? ans : -1;
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
