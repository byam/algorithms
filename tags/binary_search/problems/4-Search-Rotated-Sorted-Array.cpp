#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& a, int x) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;

        // left sorted
        if (a[l] <= a[m]) {
            if (a[l] <= x and x < a[m])  // x in [l,m]
                r = m - 1;
            else  // x in [m,r]
                l = m + 1;
        }

        // right sorted
        else {
            if (x > a[m] and x <= a[r])  // x in [r,m]
                l = m + 1;
            else  // x in [m,r]
                r = m - 1;
        }
    }
    return -1;
}

void solve() {
    // in
    vector<int> arr({4, 5, 6, 7, 0, 1, 2});
    int target = 0;
    cout << binary_search(arr, target) << endl;

    vector<int> arr2({3, 1});
    int target2 = 1;
    cout << binary_search(arr2, target2) << endl;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// binary search
int main() {
    solve();
    return 0;
}
