#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

// type
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef priority_queue<long long, vector<long long>, greater<long long>> pqll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

void solve() {
    // in
    int N, M;
    cin >> N >> M;

    vi A(N);
    vpii E(M);
    dsu D(N);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        --p;
        A[i] = p;
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        E[i] = make_pair(x, y);
        D.merge(x, y);
    }

    int ans = 0;
    for (auto g : D.groups()) {
        vi value, vertex;
        for (auto v : g) {
            value.push_back(A[v]);
            vertex.push_back(v);
        }
        srtv(value);
        srtv(vertex);

        int cnt = set_intersection(vertex.begin(), vertex.end(), value.begin(),
                                   value.end(), vertex.begin()) -
                  vertex.begin();
        ans += cnt;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
