#include <bits/stdc++.h>
using namespace std;

#define rep(i, last) for (int i = 0; i < (last); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;

/*-----------------------------------
        Coding Starts Here
------------------------------------*/

template <class T>
struct PrefixSumArray {
    vector<T> pre;

    PrefixSumArray(int n) { init(n); }

    void init(int n) { pre.resize(n); }

    void set(int idx, T val) { pre[idx] = val; }

    void build() {
        for (int i = 1; i < pre.size(); i++) {
            pre[i] = pre[i - 1] + pre[i];
        }
    }

    T query(int l, int r) { return pre[r] - pre[l - 1]; }
};

int main() {
    // prepare
    PrefixSumArray<int> psa(10);
    for (int i = 0; i < 10; i++) {
        psa.set(i, i);
    }
    printv(psa.pre);
    psa.build();
    printv(psa.pre);

    // query
    cout << psa.query(0, 9) << endl;
    cout << psa.query(5, 9) << endl;
    cout << psa.query(5, 8) << endl;

    return 0;
}
