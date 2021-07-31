# Prefix Sum

- [Prefix Sum](#prefix-sum)
  - [ポイント](#ポイント)
  - [実装](#実装)
  - [Ref](#ref)

## ポイント

- 特定の Index までの sum を O(1) で計算できる
- 特定の範囲の sum も O(1) で計算できる

## 実装
```cpp
    int arr[5] = {10, 20, 30, 40, 50};
    int prefix_sum[5];

    // i までの sum 用意しておく
    prefix_sum[0] = arr[0];
    for (int i = 1; i < 5; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    printv(arr);
    printv(prefix_sum);

    // k 番目までの合計
    int k = 3;
    cout << prefix_sum[k - 1] << endl;

    // [l, r] 間までの合計
    int r = 4, l = 2;
    cout << prefix_sum[r - 1] - prefix_sum[l - 1 - 1] << endl;
```
out:
```
arr:        10 20 30 40 50
prefix_sum: 10 30 60 100 150

最初の3個の sum    : 60
2個目から4個目まで sum : 90
```

## Ref
- https://codechacha.com/ja/java-prefix-sum/
- https://leetcode.com/problems/subarray-sum-equals-k/
