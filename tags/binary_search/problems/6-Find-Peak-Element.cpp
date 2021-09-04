#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums) {
    int left = 0, right = nums.size();

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

// https://leetcode.com/problems/find-peak-element/
// binary search
int main() {
    vector<int> nums({1, 2, 1, 3, 5, 6, 4});
    cout << binarySearch(nums) << endl;

    return 0;
}
