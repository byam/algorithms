#undef NDEBUG
#ifdef SU1
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<li, li> pt;

template <typename X>
inline X abs(const X& a) {
    return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
    return a * a;
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

pt c[2];
li r[2];

inline bool read() {
    forn(i, 2) assert(cin >> c[i].x >> c[i].y >> r[i]);
    return true;
}

li sqd;

inline ld calc(int a, int b) {
    ld cosa = ld(sqr(r[b]) + sqd - sqr(r[a])) / (ld(2) * r[b] * sqrtl(sqd));
    cosa = max(ld(-1), min(ld(1), cosa));
    ld sina = sqrt(max(ld(0), 1 - sqr(cosa)));
    ld alpha = acosl(cosa);
    ld segment = alpha * sqr(r[b]);
    ld triang = sqr(r[b]) * sina * cosa;
    cerr << "alpha=" << 2 * alpha << endl;
    cerr << "triang=" << triang << endl;
    return segment - triang;
}

inline void solve() {
    if (r[0] > r[1]) swap(c[0], c[1]), swap(r[0], r[1]);

    sqd = sqr(c[0].x - c[1].x) + sqr(c[0].y - c[1].y);

    if (sqd > sqr(r[0] + r[1])) {
        cerr << "Not intersecting" << endl;
        cout << ld(0) << endl;
        return;
    }

    if (sqd <= sqr(r[1] - r[0])) {
        cerr << "Fully in" << endl;
        cout << PI * sqr(ld(r[0])) << endl;
        return;
    }

    ld ans = 0;
    ans += calc(0, 1);
    ans += calc(1, 0);
    cout << ans << endl;
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
        solve();
        break;
    }

    return 0;
}
