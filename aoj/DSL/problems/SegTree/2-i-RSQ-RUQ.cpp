#include <bits/stdc++.h>
using namespace std;

/* SegTreeLazyProportional<X,M>(n,fx,fa,fm,fp,ex,em): モノイド(集合X,
   二項演算fx,fa,fm,p 単位元ex,em)についてサイズnで構築 set(int i, X x),
   build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n) update(i,x):
   i 番目の要素を x に更新。O(log(n)) query(a,b):  [a,b)
   全てにfxを作用させた値を取得。O(log(n))


   (ex: 区間加算 Range Add Query(RAQ) 型の RSQ)

    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };
    auto fa = [](X x, M m) -> X { return x + m; };
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };
    auto fp = [](M m, long long n) -> M { return m * n; };
    long long ex = 0;
    long long em = 0;
    SegTreeLazyProportional<X, M> rmq(n, fx, fa, fm, fp, ex, em);
*/
template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazyProportional(int n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_,
                            M em_)
        : n(),
          fx(fx_),
          fa(fa_),
          fm(fm_),
          fp(fp_),
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
    void eval(int k, int len) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        } else if (a < r && l < b) {  // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
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
};

int main() {
    int n, q;
    cin >> n >> q;

    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };
    auto fa = [](X x, M m) -> X { return m; };
    auto fm = [](M m1, M m2) -> M { return m2; };
    auto fp = [](M m, long long n) -> M { return m * n; };
    long long ex = 0;
    long long em = numeric_limits<long long>::max();;
    SegTreeLazyProportional<X, M> rsq(n, fx, fa, fm, fp, ex, em);
    for (int i = 0; i < n; i++) {
        rsq.set(i, 0);
    }
    rsq.build();

    vector<int> ans;

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;

        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            rsq.update(s, t + 1, x);
        } else if (com == 1) {
            int s, t;
            cin >> s >> t;
            ans.push_back(rsq.query(s, t + 1));
        }
    }

    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
