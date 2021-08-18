#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a) for (auto& i : a)
#define all(x) (x).begin(), (x).end()

using namespace std;
void _main();
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------------------------------
#define def inf
template <class V, int NV>
struct SegTree {  //[l,r)
    V comp(V& l, V& r) { return min(l, r); };

    vector<V> val;
    SegTree() { val = vector<V>(NV * 2, def); }
    V get(int x, int y, int l = 0, int r = NV, int k = 1) {
        if (r <= x || y <= l) return def;
        if (x <= l && r <= y) return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2);
        auto b = get(x, y, (l + r) / 2, r, k * 2 + 1);
        return comp(a, b);
    }
    void update(int i, V v) {
        i += NV;
        val[i] = v;
        while (i > 1) i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]);
    }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};
//---------------------------------------------------------------------------------------------------

int N, Q, A[201010], B[201010];
SegTree<int, 1 << 18> st;
multiset<int> rates[201010];
int cnt[201010];
void add(int child, int to) {
    cnt[to]++;
    rates[to].insert(A[child]);
    st.update(to, *rates[to].rbegin());
}
void erase(int child, int from) {
    cnt[from]--;
    auto ite = rates[from].find(A[child]);
    rates[from].erase(ite);

    if (cnt[from] == 0)
        st.update(from, inf);
    else
        st.update(from, *rates[from].rbegin());
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Q;
    rep(i, 1, N + 1) {
        cin >> A[i] >> B[i];
        add(i, B[i]);
    }

    rep(_, 0, Q) {
        int C, D;
        cin >> C >> D;
        erase(C, B[C]);
        B[C] = D;
        add(C, B[C]);

        int ans = st.get(0, 201010);
        printf("%d\n", ans);
    }
}



