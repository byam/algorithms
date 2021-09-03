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
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

int n, m, k;
vector<vector<char>> field;
vector<vector<bool>> seen;
vector<vector<int>> ans;
vpii path;

int dfs(int x, int y) {
    seen[x][y] = true;
    path.push_back(make_pair(x, y));
    int w_cnt = 0;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = dx + x;
            int ny = dy + y;

            if ((dx * dy == 0) && 0 <= nx && nx < n && 0 <= ny && ny < m &&
                field[nx][ny] == '*') {
                w_cnt++;
                seen[nx][ny] = true;
            }

            if ((dx * dy == 0) && 0 <= nx && nx < n && 0 <= ny && ny < m &&
                !seen[nx][ny]) {
                w_cnt += dfs(nx, ny);
            }
        }
    }
    return w_cnt;
}

void solve() {
    int x, y;
    cin >> x >> y;
    --x;
    --y;

    if (ans[x][y] == -1) {
        path.clear();
        int cnt = dfs(x, y);
        for (auto [a, b] : path) {
            ans[a][b] = cnt;
        }
    }
    cout << ans[x][y] << endl;
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    field.resize(n);
    seen.resize(n, vector<bool>(m, false));
    ans.resize(n, vector<int>(m, -1));

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        field[i].resize(m);
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            field[i][j] = c;
            if (c == '.') cnt++;
        }
    }

    for (int i = 0; i < k; i++) solve();

    return 0;
}
