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
vb P(1001005, false);

set<int> primes;

void primeFactors(int n) {
    // Print the number of 2s that divide n
    if (n % 2 == 0) primes.insert(2);

    while (n % 2 == 0) {
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            primes.insert(i);
            n = n / i;
        }
    }

    if (n > 2) primes.insert(n);
}

void solve() {
    // in
    int N, M;
    cin >> N >> M;
    vi A(N);
    rep(i, 0, N) cin >> A[i];

    for (int i = 0; i < N; i++) {
        primes.clear();

        primeFactors(A[i]);

        for (auto it = primes.begin(); it != primes.end(); ++it) {
            int p = *it;
            if (P[p]) continue;

            while (p <= M) {
                P[p] = true;
                p += *it;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (P[i]) continue;
        cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= M; i++) {
        if (P[i]) continue;
        cout << i << endl;
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
