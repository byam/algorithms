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

void bfsPath(int s, const vector<vb>& field, vll& dist, const vll& C, vvi& P) {
    queue<pair<int, vi>> Q;
    Q.push(make_pair(s, vi(1, s)));

    dist[s] = C[s];
    int n = dist.size();

    while (!Q.empty()) {
        int x = Q.front().first;
        vi vx = Q.front().second;
        Q.pop();
        P[x] = vx;

        for (int nx = 0; nx < n; nx++) {
            if (!field[x][nx] or dist[nx] != -1) continue;
            dist[nx] = dist[x] + C[nx];
            auto vnx = vx;
            vnx.push_back(nx);

            Q.emplace(make_pair(nx, vnx));
        }
    }
}

void bfs(int s, const vector<vb>& field, vll& dist, const vll& C, vb& seen) {
    queue<int> Q;
    Q.push(s);

    dist[s] = seen[s] ? 0 : C[s];
    int n = dist.size();

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (int nx = 0; nx < n; nx++) {
            if (!field[x][nx] or dist[nx] != -1) continue;
            dist[nx] = dist[x];
            dist[nx] += seen[nx] ? 0 : C[nx];

            Q.emplace(nx);
        }
    }
}

void solve(int t) {
    // in
    int n;
    cin >> n;
    vll C(n);
    vector<vb> field(n, vb(n, false));
    rep(i, n) cin >> C[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        field[a][b] = field[b][a] = true;
    }

    // Find first path
    vll dist(n, -1);
    vvi P(n);

    bfsPath(0, field, dist, C, P);

    ll first_sum = 0;
    ll first_idx = 0;
    for (int i = 0; i < n; i++) {
        if (first_sum <= dist[i]) {
            first_sum = dist[i];
            first_idx = i;
        }
    }
    // cerr << first_sum << ": " << first_idx << endl;
    // printv(P[first_idx]);

    // disable first path
    int k = P[first_idx].size();
    vb seen(n, false);
    for (int i = 0; i < k - 1; i++) {
        int s = P[first_idx][i];
        int t = P[first_idx][i + 1];
        field[s][t] = false;
        field[t][s] = false;
        seen[s] = true;
        seen[t] = true;
    }
    if (seen.size() == 1) seen[0] = true;

    // find second path
    vvll dist2(n, vll(n, -1));
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        bfs(0, field, dist2[i], C, seen);
        // cerr << i << ": ";
        // printv(dist2[i]);
    }

    ll second_sum = 0;
    ll second_idx = 0;
    for (auto d : dist2) {
        for (int i = 0; i < n; i++) {
            if (second_sum <= d[i]) {
                second_sum = d[i];
                second_idx = i;
            }
        }
    }
    // cerr << second_sum << ": " << second_idx << endl;

    ll ans = first_sum + second_sum;
    printf("Case #%d: %lld\n", t, ans);
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        solve(cnt);
        cnt++;
    }
    return 0;
}
