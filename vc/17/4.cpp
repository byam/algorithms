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

#define print2d(v)                              \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
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

vector<vector<char>> field;  // '.': 移動可能

// グリッド上の s(x,y) -> t(x,y) 最短移動距離を求める
// 計算量：O(4 * H * W)
int grid_min_st(int sx, int sy, int tx, int ty) {
    int h = field.size();
    int w = field[0].size();

    // 距離を初期化する
    vector<vector<int>> dist(h, vector<int>(w, -1));

    // 幅優先探索により、最短移動回数を求める
    queue<pair<int, int>> Q;
    Q.push({sy, sx});
    dist[sy][sx] = 0;

    while (!Q.empty()) {
        int cx = Q.front().first, cy = Q.front().second;
        Q.pop();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int ex = cx + dx[i], ey = cy + dy[i];
            if (ex < 0 or ex > h - 1 or ey < 0 or ey > w - 1) continue;
            if (field[ex][ey] != '.' or dist[ex][ey] != -1) continue;
            Q.push({ex, ey});
            dist[ex][ey] = dist[cx][cy] + 1;
        }
    }

    return dist[tx][ty];
}

void solve() {
    // in
    int h, w;
    read(h, w);
    field.resize(h);
    int black_cnt = 0;
    for (int i = 0; i < h; i++) {
        field[i].resize(w);
        for (int j = 0; j < w; j++) {
            char c;
            read(c);
            field[i][j] = c;
            if (c == '#') black_cnt++;
        }
    }

    int dist = grid_min_st(0, 0, h - 1, w - 1);
    if (dist == -1) {
        out(-1);
        return;
    }
    out(h * w - dist - 1 - black_cnt);
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
