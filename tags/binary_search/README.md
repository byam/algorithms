# Binary Search

- [Binary Search](#binary-search)
  - [Preview](#preview)
  - [ref](#ref)
  - [Implementation](#implementation)
    - [Template 1](#template-1)
    - [Template 2](#template-2)

## Preview

Pros
- Search element efficiently `O(log n)` in sorted order.

Idea
- Divides search space in 2 after every compares
- Parts
  1. Pre-processing - Sort if collection is unsorted.
  2. Binary Search - Using a loop or recursion to divide search space in half after each comparison.
  3. Post-processing - Determine viable candidates in the remaining space.

## ref
- https://leetcode.com/explore/learn/card/binary-search/

## Implementation

### Template 1

- Only checking current (mid) element.

```cpp
#include <bits/stdc++.h>
using namespace std;

// 目的の値 key の添字を返す (存在しない場合は -1)
template <class T>
int binarySearch(const vector<T>& arr, T target) {
    if (arr.size() == 0) return -1;

    int l = 0, r = arr.size() - 1;  // 配列の左端と右端

    while (r >= l) {
        // prevent overflow
        int mid = l + (r - l) / 2;  // 区間の真ん中
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    // End Condition: left > right
    return -1;
}

void solve() {
    // in
    vector<int> arr({1, 3, 5, 7, 11});

    cout << binarySearch(arr, 3) << endl;
    cout << binarySearch(arr, 8) << endl;
}

int main() {
    solve();
    return 0;
}
```

### Template 2

- Search current index and its left and right index
- Size at least 3
- Post-processing required

```cpp
int binarySearch(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[left] == target) return left;
    if (nums[right] == target) return right;
    return -1;
}
```
