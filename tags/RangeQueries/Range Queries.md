# Range Queries

| RMQ | Sparse Table |
|-|-|

- [Range Queries](#range-queries)
  - [Preview](#preview)
  - [Prefix Sum Array (RSQ)](#prefix-sum-array-rsq)
    - [Implement](#implement)
  - [Sparse Table Algorithm](#sparse-table-algorithm)
    - [Ref](#ref)
    - [Implement](#implement-1)
      - [RMQ](#rmq)
      - [RSQ](#rsq)

## Preview

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

## Prefix Sum Array (RSQ)

Point
- Each value in array: `k = sum(0, k)`
- `sum(a, b) = sum(0, b)-sum(0, a-1)`
- Constructed: `O(n)`
- Query: `O(1)`
- High Dimension (2D):
  - `S(lower right) - S(lower left) - S(upper right) + S(upper left)`

### Implement

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

## Sparse Table Algorithm

Pros
- RMQ: `O(1)`
- Other queries: `O(log n)`
  - ex: sum, gcd, multply etc ...

Cons
- Immutable array

How
- Precalculate all values of `min(a, b)`
  - Preprocess: `O(n log n)`

Idea
- Any non-negative number can be uniquely represented as sum of decreasint power of two.
  - Like binary representation of a number.
  - ex: `13 = (1101) = 8 + 4 + 1`, `log(13) = 3` summands.
- Same reasoning, any interval can be uniquely represented union of intervals with lenghts that are decreasing powers of two.
  - ex: `[2, 14] = [2, 9] + [10, 13] + [14, 14]`
  - ex: (RMQ) Split 2 overlapping range: `[1, 6] = [1, 4] + [3, 6]`


![](.img/../img/sparse-table.png)

### Ref
- https://cp-algorithms.com/data_structures/sparse-table.html
- https://www.youtube.com/watch?v=uUatD9AudXo&ab_channel=WilliamFiset

### Implement

#### RMQ

```cpp
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SparseTableRMQ {
    vector<vector<T>> st;
    vector<int> l2;
    int N;
    int K;

    // construct: O(n log n)
    SparseTableRMQ(vector<T> v) {
        N = v.size();
        K = floor(log2(N));

        st.resize(N, vector<T>(K + 1));
        for (int i = 0; i < N; i++) st[i][0] = v[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                // min
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

        l2.resize(N + 1);
        l2[1] = 0;
        for (int i = 2; i <= N; i++) l2[i] = l2[i / 2] + 1;
    }

    // query: O(1)
    T query(int L, int R) {
        int j = l2[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    SparseTableRMQ<int> rmq(a);
    cout << rmq.query(0, 4) << endl;
    cout << rmq.query(4, 7) << endl;
    cout << rmq.query(7, 8) << endl;

    return 0;
}
```

#### RSQ

```cpp
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SparseTableRSQ {
    vector<vector<T>> st;
    int N;
    int K;

    // construct: O(n log n)
    SparseTableRSQ(vector<T> v) {
        N = v.size();
        K = floor(log2(N));

        st.resize(N, vector<T>(K + 1));
        for (int i = 0; i < N; i++) st[i][0] = v[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                // sum
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
    }

    // query: O(log n)
    T query(int L, int R) {
        T sum = 0;
        for (int j = K; j >= 0; j--) {
            if ((1 << j) <= R - L + 1) {
                sum += st[L][j];
                L += 1 << j;
            }
        }
        return sum;
    }
};

int main() {
    vector<int> a = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    SparseTableRSQ<int> rsq(a);
    cout << rsq.query(0, 4) << endl;
    cout << rsq.query(4, 7) << endl;
    cout << rsq.query(7, 8) << endl;

    return 0;
}
```
