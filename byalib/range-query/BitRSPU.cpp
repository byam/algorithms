#include <bits/stdc++.h>

using namespace std;

template <class T>
struct BitRSPU {
    /*
        Fenwick Binary Indexed Tree

        Operation
            - Range Sum Query
            - Point Add
        Time:
            - Build: O(n)
            - Range Query: O(log n)
            - Point Update: O(log n)
        Memory:
            - O(N)
    */

    vector<T> bit;  // binary indexed tree
    int n;

    BitRSPU(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);  // one base indexing
    }

    BitRSPU(vector<T> a) : BitRSPU(a.size()) {
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
    vector<int> a = {1, 2, 3, 4, 5};
    BitRSPU<int> bit(a);

    // 0 indexed, both inclusive
    cout << bit.sum(0, 2) << endl;  // 6
    cout << bit.sum(0, 4) << endl;  // 15
    cout << bit.sum(1, 3) << endl;  // 9

    bit.add(1, 10);                 // 2 -> 12
    cout << bit.sum(1, 3) << endl;  // 19

    return 0;
}
