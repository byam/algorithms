# Range Queries

Goal
- Efficiently processing (logarithmic time) **range queries on arrays**.
  - ex: range sum queries (RSQ) and range minimun queries (RMQ)

Points
- Array values are not modified between queries
  - preprocess array -> any possible query
    - **Prefix Sum Array** for RSQ. Can be generalized to higher dimension.
    - **Sparse Table** for RMQ. Can be maximum query too.
- Process queries and update array values efficiently
  - **Binary Indexed Tree** (Fenwick Tree) for sum queries: dynamic version of of **Prefix Sum Array**.
  - **Segment Tree** supports RSQ, RMQ and several other queries

- [Range Queries](#range-queries)
  - [Prefix Sum Array (RSQ)](#prefix-sum-array-rsq)
    - [Code](#code)
  - [Sparse Table Algorithm (RMQ)](#sparse-table-algorithm-rmq)

## Prefix Sum Array (RSQ)

Point
- Each value in array: `k = sum(0, k)`
- `sum(a, b) = sum(0, b)-sum(0, a-1)`
- Constructed: `O(n)`
- Query: `O(1)`
- High Dimension (2D):
  - `S(lower right) - S(lower left) - S(upper right) + S(upper left)`

### Code
```cpp
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
```

## Sparse Table Algorithm (RMQ)

Point
- Query: `O(1)`, Preprocess: `O(n log n)`
- Precalculate all values of `min(a, b)`
  - `b - a + 1 = power of two (2, 4, 8 ...)`
  - Range lengths: `O(log n)`
