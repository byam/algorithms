# 2 pointer approach

- [2 pointer approach](#2-pointer-approach)
  - [ポイント](#ポイント)
  - [実装](#実装)
  - [問題](#問題)
  - [Ref](#ref)

## ポイント

- 数値のリストから、K = a[i] + [j]　となる K を探す
- O(N)

## 実装

- sort して、前と後ろから確認していく

```cpp
// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
bool isPairSum(int A[], int N, int X)
{
    // represents first pointer
    int i = 0;

    // represents second pointer
    int j = N - 1;

    while (i < j) {

        // If we find a pair
        if (A[i] + A[j] == X)
            return true;

        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by doing i++
        else if (A[i] + A[j] < X)
            i++;

        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by doing j--
        else
            j--;
    }
    return false;
}
```

## 問題

- [ABC 212: C - Min Difference](https://atcoder.jp/contests/abc212/tasks/abc212_c)

## Ref

- https://www.geeksforgeeks.org/two-pointers-technique/
- https://algodaily.com/lessons/using-the-two-pointer-technique
