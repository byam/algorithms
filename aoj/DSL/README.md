# DSL

データセットとクエリに関するテクニックを体得します。
- [データの集合とクエリ処理](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all)

- [DSL](#dsl)
  - [Segment 木](#segment-木)
    - [(RMQ) Range Minimum Query](#rmq-range-minimum-query)
      - [実装](#実装)
    - [(RUQ) Range Update Query](#ruq-range-update-query)
      - [実装](#実装-1)
    - [(RSQ) Range Sum Query](#rsq-range-sum-query)
      - [実装](#実装-2)
    - [(RAQ) Range Add Query](#raq-range-add-query)
      - [実装](#実装-3)
    - [RMQ & RUQ](#rmq--ruq)
      - [実装](#実装-4)
    - [RSQ & RAQ](#rsq--raq)
      - [実装](#実装-5)
    - [RMQ & RAQ](#rmq--raq)
      - [実装](#実装-6)
    - [RSQ & RUQ](#rsq--ruq)
      - [実装](#実装-7)
      - [実装](#実装-8)

## Segment 木

### (RMQ) Range Minimum Query

- 機能
  - `update(i, x)`: `a[i]` を `x` に変更する
  - `find(l,r)`: 区間の最小値

#### 実装

* Using [RMQ](../../ds/RMQ-RUQ.cpp)
```cpp
    // 初期化
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        // 初期値
        rmq.set(i, A[i]);
    }
    rmq.build();

    // update(i, x)
    rmq.update(i, i + 1, x);

    // find(l, r)
    rmq.query(l, r + 1);
```

### (RUQ) Range Update Query

- 機能
  - `update(l,r,x)`: 区間を `x` に更新
  - `find(i)`: `a[i]` の値を出力する

#### 実装

* Using [RMQ](../../ds/RMQ-RUQ.cpp)
```cpp
    // 初期化
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        // 初期値
        rmq.set(i, A[i]);
    }
    rmq.build();

    // update(l, r, x)
    rmq.update(l, r + 1, x);

    // find(i)
    cout << rmq[i] << endl;
```

### (RSQ) Range Sum Query

- 機能
  - `add(i,x)`: `a[i]` に `x` を加算する
  - `getSum(l,r)`: 区間の合計値

#### 実装

* Using [SegTreeLazyProportional](../../ds/SegTreeLazyProportional.cpp)
```cpp
    // 初期化
    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };     // RSQ
    auto fa = [](X x, M m) -> X { return x + m; };         // RSQ
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };     // RSQ
    auto fp = [](M m, long long n) -> M { return m * n; }; // RSQ
    long long ex = 0;                                      // RSQ
    long long em = 0;                                      // RSQ
    SegTreeLazyProportional<X, M> rsq(n, fx, fa, fm, fp, ex, em);
    for (int i = 0; i < n; i++) {
        // 初期値
        rsq.set(i, A[i]);
    }
    rsq.build();

    // add(i, x)
    rsq.update(i, i + 1, x);

    // getSum(l, r)
    rsq.query(l, r + 1)
```




### (RAQ) Range Add Query
- 機能
  - `add(l, r, x)`: 区間に `x` を加算する
  - `get(i)`: `a[i]` の値を出力する

#### 実装

* Using [RMQ & RAQ](../../ds/RMQ-RAQ.cpp)
```cpp
    // 初期化
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        rmq.set(i, A[i]);
    }
    rmq.build();

    // add(l, r, x)
    rmq.add(l, r + 1, x);

    // get(i)
    rmq[i];
```

### RMQ & RUQ

- 機能
  - `update(l,r,x)`: 区間を `x` に更新 (RUQ)
  - `find(l,r)`: 区間の最小値 (RMQ)

#### 実装

* Using [RMQ](../../ds/RMQ-RUQ.cpp)
```cpp
    // 初期化
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        // 初期値
        rmq.set(i, A[i]);
    }
    rmq.build();

    // update(l, r, x)
    rmq.update(l, r + 1, x);

    // find(l, r)
    rmq.query(l, r + 1)
```

* Using [SegTreeLazy](../DSL/problems/2-F-RUQ-SegTreeLazy.cpp)
```cpp
    // 初期化
    using X = int;
    using M = int;
    auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
    auto fa = [](X x, M m) -> X { return m; };
    auto fm = [](M m1, M m2) -> M { return m2; };
    int ex = numeric_limits<int>::max();
    int em = numeric_limits<int>::max();
    SegTreeLazy<X, M> rmq(n, fx, fa, fm, ex, em);

    // update(l, r, x)
    rmq.update(l, r + 1, x);

    // find(l, r)
    rmq.query(l, r + 1)
```

### RSQ & RAQ

- 機能
  - `add(l, r, x)`: 区間に `x` を加算する (RAQ)
  - `getSum(l, r)`: 区間の合計値を出力する (RSQ)

#### 実装

* Using [SegTreeLazyProportional](../../ds/SegTreeLazyProportional.cpp)
```cpp
    // 初期化
    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };
    auto fa = [](X x, M m) -> X { return x + m; };
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };
    auto fp = [](M m, long long n) -> M { return m * n; };
    long long ex = 0;
    long long em = 0;
    SegTreeLazyProportional<X, M> rsq(n, fx, fa, fm, fp, ex, em);
    for (int i = 0; i < n; i++) {
        // 初期値
        rsq.set(i, A[i]);
    }
    rsq.build();

    // add(l, r, x)
    rsq.update(l, r + 1, x);

    // getSum(l, r)
    rsq.query(l, r + 1)
```

### RMQ & RAQ

- 機能
  - `add(l, r, x)`: 区間に `x` を加算する (RAQ)
  - `find(l, r)`: 区間の最小値を出力する (RMQ)

#### 実装

* Using [RMQ & RAQ](../../ds/RMQ-RAQ.cpp)
```cpp
    // 初期化
    RMQ<int> rmq(n);
    for (int i = 0; i < n; i++) {
        rmq.set(i, A[i]);
    }
    rmq.build();

    // add(l, r, x)
    rmq.add(l, r + 1, x);

    // find(l, r)
    rmq.query(l, r + 1)
```

* Using [SegTreeLazy](../../ds/SegTreeLazy.cpp)
```cpp
    // 初期化
    using X = int;
    using M = int;
    auto fx = [](X x1, X x2) -> X { return min(x1, x2); }; // RMQ
    auto fa = [](X x, M m) -> X { return x + m; };         // RAQ
    auto fm = [](M m1, M m2) -> M { return m1 + m2; };     // RAQ
    int ex = numeric_limits<int>::max();                   // RMQ
    int em = 0;                                            // RAQ
    SegTreeLazy<X, M> rmq(n, fx, fa, fm, ex, em);

    for (int i = 0; i < n; i++) {
        rmq.set(i, 0);
    }
    rmq.build();

    // add(l, r, x)
    rmq.add(l, r + 1, x);

    // find(l, r)
    rmq.query(l, r + 1)
```

### RSQ & RUQ

- 機能
  - `update(l, r, x)`: 区間に `x` に変更する (RUQ)
  - `getSum(l, r)`: 区間の合計値を出力する (RSQ)

#### 実装

#### 実装

* Using [SegTreeLazyProportional](../../ds/SegTreeLazyProportional.cpp)
```cpp
    // 初期化
    using X = long long;
    using M = long long;
    auto fx = [](X x1, X x2) -> X { return x1 + x2; };     // RSQ
    auto fa = [](X x, M m) -> X { return m; };             // RUQ
    auto fm = [](M m1, M m2) -> M { return m2; };          // RUQ
    auto fp = [](M m, long long n) -> M { return m * n; }; // RSQ
    long long ex = 0;                                      // RSQ
    long long em = numeric_limits<long long>::max();;      // RUQ
    SegTreeLazyProportional<X, M> rsq(n, fx, fa, fm, fp, ex, em);
    for (int i = 0; i < n; i++) {
        rsq.set(i, 0);
    }
    rsq.build();

    // add(l, r, x)
    rsq.update(l, r + 1, x);

    // getSum(l, r)
    rsq.query(l, r + 1)
```
