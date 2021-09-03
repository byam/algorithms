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
        if (arr[r] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    // End Condition: left > right
    return -1;
}

void solve() {
    // in
    vector<int> arr({4, 5, 6, 7, 0, 1, 2});

    cout << binarySearch(arr, 0) << endl;
    cout << binarySearch(arr, 3) << endl;
}

int main() {
    solve();
    return 0;
}
