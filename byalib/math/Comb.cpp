#include <bits/stdc++.h>

using namespace std;

// start: ModInt --------------------------
template <int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x += MOD - that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const {
        ModInt t;
        t.x = x == 0 ? 0 : Mod - x;
        return t;
    }
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1;
    while (k) {
        if (k & 1) r *= a;
        a *= a;
        k >>= 1;
    }
    return r;
}
// end: ModInt --------------------------

// start: Comb --------------------------
#define rep(i, a, b) for (int i = a; i < b; i++)
template <typename T, int FAC_MAX>
struct Comb {
    vector<T> fac, ifac;
    Comb() {
        fac.resize(FAC_MAX, 1);
        ifac.resize(FAC_MAX, 1);
        rep(i, 1, FAC_MAX) fac[i] = fac[i - 1] * i;
        rep(i, 1, FAC_MAX) ifac[i] = T(1) / fac[i];
    }
    T aPb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1);
        if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
};
// end: Comb --------------------------

typedef ModInt<1000000007> mint;
Comb<mint, 201010> com;

int main() {
    // pick 2 of 5 = 5! / (2! * 3!) = 10
    assert(com.aCb(5, 2).get() == 10);

    // pick 10 of 1000 = 1000! / (10! * 990!) = 302505679
    // do not overflow by MOD
    assert(com.aCb(1000, 10).get() == 302505679);

    return 0;
}
