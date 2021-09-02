#include <bits/stdc++.h>

using namespace std;

template <class T>
struct FenwickTreeRQPU {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeRQPU(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);  // one base indexing
    }

    FenwickTreeRQPU(vector<int> a) : FenwickTreeRQPU(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }

    void add(int idx, T val) {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += val;
    }

    // Range Update
    void range_add(int l, int r, T val) {
        add(l, val);
        add(r + 1, -val);
    }

    // Point Query
    T point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
        return ret;
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    FenwickTreeRQPU<int> bit(a);
    cout << bit.point_query(4) << endl;
    cout << bit.point_query(7) << endl;
    cout << bit.point_query(8) << endl;

    bit.range_add(0, 4, 1);
    cout << bit.point_query(4) << endl;

    return 0;
}
