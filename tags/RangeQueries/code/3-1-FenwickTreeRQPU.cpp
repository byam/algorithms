#include <bits/stdc++.h>

using namespace std;

template <class T>
struct FenwickTreeRQPU {
    vector<T> bit;  // binary indexed tree
    int n;

    FenwickTreeRQPU(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);  // one base indexing
    }

    FenwickTreeRQPU(vector<T> a) : FenwickTreeRQPU(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }

    T sum(int idx) {
        T ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }

    // RQ: Range Query
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    // PU: Point Update
    void add(int idx, T delta) {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    FenwickTreeRQPU<int> bit(a);
    cout << bit.sum(0, 4) << endl;
    cout << bit.sum(4, 7) << endl;
    cout << bit.sum(7, 8) << endl;

    bit.add(7, 1);
    cout << bit.sum(4, 7) << endl;
    cout << bit.sum(7, 8) << endl;

    return 0;
}
