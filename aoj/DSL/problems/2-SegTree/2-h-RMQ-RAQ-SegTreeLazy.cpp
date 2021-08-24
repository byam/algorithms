/* segment_tree_lazy.cpp
    任意の作用つきモノイドに対して遅延評価セグメント木を構築する。

    モノイドX、作用モノイドMに対するセグメント木を構築するために、
        ・X上の二項演算 fx
        ・XとMの二項演算 fa
        ・M上の二項演算 fm
        ・Xの単位元 ex
        ・Mの単位元 em
    を与える

    RMQ・RUQ：
        using X = int;
        using M = int;
        auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
        auto fa = [](X x, M m) -> X { return m; };
        auto fm = [](M m1, M m2) -> M { return m2; };
        int ex = numeric_limits<int>::max();
        int em = numeric_limits<int>::max();
        SegTreeLazy<X, M> rmq(n, fx, fa, fm, ex, em);

    RMQ・RAQ：
        using X = int;
        using M = int;
        auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
        auto fa = [](X x, M m) -> X { return x + m; };
        auto fm = [](M m1, M m2) -> M { return m1 + m2; };
        int ex = numeric_limits<int>::max();
        int em = 0;
        SegTreeLazy<X, M> rmq(n, fx, fa, fm, ex, em);

    verified: AOJ DSL_2_F RMQ and RUQ
        http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
 */

#include <bits/stdc++.h>
using namespace std;

/* SegTreeLazy<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm,
   単位元ex,em)についてサイズnで構築 set(int i, X x), build():
   i番目の要素をxにセット。まとめてセグ木を構築する。O(n) update(i,x): i
   番目の要素を x に更新。O(log(n)) query(a,b):  [a,b)
   全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X, typename M>
struct SegTreeLazy {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazy(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
        : n(),
          fx(fx_),
          fa(fa_),
          fm(fm_),
          ex(ex_),
          em(em_),
          dat(n_ * 4, ex),
          lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--)
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], lazy[k]);
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k);
        } else if (a < r && l < b) {  // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    /* debug */
    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    using X = int;
    using M = int;
    auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
    auto fa = [](X x, M m) -> X { return x + m; };
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };
    int ex = numeric_limits<int>::max();
    int em = 0;
    SegTreeLazy<X, M> rmq(n, fx, fa, fm, ex, em);

    for (int i = 0; i < n; i++) {
        rmq.set(i, 0);
    }
    rmq.build();

    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            rmq.update(s, t + 1, x);
        } else if (c == 1) {
            int s, t;
            cin >> s >> t;
            ans.push_back(rmq.query(s, t + 1));
        }
    }
    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
