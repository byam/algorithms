#include <bits/stdc++.h>
using namespace std;

vector<bool> arr;
bool isBadVersion(int x) { return arr[x - 1]; }

int binarySearch(int n) {
    if (n == 1) return n;

    int left = 1, right = n;
    while (left < right) {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (!isBadVersion(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// https://leetcode.com/problems/first-bad-version/
// binary search
int main() {
    arr.assign({false, false, false, true, false});
    cout << binarySearch(5) << endl;

    arr.assign({true, false});
    cout << binarySearch(2) << endl;

    return 0;
}
