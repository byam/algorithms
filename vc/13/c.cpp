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

// const
const long long INF_9 = 1001002009;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/
// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
   public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int>& v) { return v.empty(); }),
                     result.end());
        return result;
    }

   private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

void solve() {
    // in
    int n, m;
    read(n, m);
    dsu d(n * m);
    vi a;
    vvi field(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        // char line[1000];
        // scanf("%s", &line);
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            /* code */
            int k = i * m + j;
            if (line[j] == '*') {
                a.push_back(k);
                field[i][j] = 1;
            }
        }
    }

    // connect existing
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j]) continue;
            int k = i * m + j;
            // top
            if (i > 0 and field[i - 1][j] == field[i][j]) {
                int l = (i - 1) * m + j;
                d.merge(l, k);
            }
            // bottom
            if (i < n - 1 and field[i + 1][j] == field[i][j]) {
                int l = (i + 1) * m + j;
                d.merge(l, k);
            }
            // left
            if (j > 0 and field[i][j - 1] == field[i][j]) {
                int l = i * m + (j - 1);
                d.merge(l, k);
            }
            // right
            if (j < m - 1 and field[i][j + 1] == field[i][j]) {
                int l = i * m + (j + 1);
                d.merge(l, k);
            }
        }
    }

    vvi sizes(n, vi(m, 0));
    for (auto g : d.groups()) {
        int sz = g.size() % 10;
        for (auto k : g) {
            int i = k / m;
            int j = k % m;
            sizes[i][j] = sz;
        }
    }
    // print2d(sizes, n, m);

    for (auto k : a) {
        int i = k / m;
        int j = k % m;
        int ans = 1;

        // top
        if (i > 0 and field[i - 1][j] == 0) {
            ans += sizes[i - 1][j];
        }
        // bottom
        if (i < n - 1 and field[i + 1][j] == 0) {
            ans += sizes[i + 1][j];
            if (i > 0 and d.same((i - 1) * m + j, (i + 1) * m + j))
                ans -= sizes[i + 1][j];
        }
        // left
        if (j > 0 and field[i][j - 1] == 0) {
            ans += sizes[i][j - 1];

            if (i > 0 and d.same((i - 1) * m + j, i * m + j - 1))
                ans -= sizes[i][j - 1];
            else if (i < n - 1 and d.same((i + 1) * m + j, i * m + j - 1))
                ans -= sizes[i][j - 1];
        }
        // right
        if (j < m - 1 and field[i][j + 1] == 0) {
            ans += sizes[i][j + 1];
            if (i > 0 and d.same((i - 1) * m + j, i * m + j + 1))
                ans -= sizes[i][j + 1];
            else if (i < n - 1 and d.same((i + 1) * m + j, i * m + j + 1))
                ans -= sizes[i][j + 1];
            else if (j > 0 and d.same(i * m + j - 1, i * m + j + 1))
                ans -= sizes[i][j + 1];
        }
        sizes[i][j] = ans % 10;
    }
    // print2d(sizes, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 0) {
                printf(".");
            } else
                printf("%d", sizes[i][j]);
        }
        printf("\n");
    }
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
