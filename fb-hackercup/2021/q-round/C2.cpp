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
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--)
            dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {  // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    T find_rightest(int a, int b, int x) {
        return find_nearest_sub(a, b, x, 0, 0, n, true);
    }
    T find_leftest(int a, int b, int x) {
        return find_nearest_sub(a, b, x, 0, 0, n, false);
    }
    T find_nearest_sub(int a, int b, int x, int k, int l, int r,
                       bool is_right) {
        eval(k);
        if (dat[k] > x || r <= a ||
            b <= l) {  // 自分の値がxより大きい or
                       // [a,b)が[l,r)の範囲外ならreturn -1
            return -1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            if (is_right) {
                int vr = find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r,
                                          is_right);
                if (vr != -1) {  // 右の部分木を見て-1以外ならreturn
                    return vr;
                } else {  // 左の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2,
                                            is_right);
                }
            } else {
                int vl = find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2,
                                          is_right);
                if (vl != -1) {  // 左の部分木を見て-1以外ならreturn
                    return vl;
                } else {  // 右の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r,
                                            is_right);
                }
            }
        }
    }

    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

void bfs(int s, vector<vb>& field, vll& cost, RMQ<ll>& rmq) {
    int n = field.size();
    vll dist(n, -1);

    queue<int> Q;
    Q.push(s);
    dist[s] = cost[s];

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (auto nx : field[x]) {
            if (dist[nx] != -1) continue;
            dist[nx] = dist[x] + cost[nx];
            Q.emplace(nx);
        }
    }

    printv(dist);
    rep(i, n) rmq.set(i, dist[i]);
    rmq.build();
}

void solve(int t) {
    // in
    int n, k;
    cin >> n >> k;
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

    // k > 2
    vector<RMQ<ll>> rmqs(n, RMQ<ll>(n));

    for (int i = 0; i < n; i++) {
        bfs(i, field, C, rmqs[i]);
    }

    ll ans = 0;
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
