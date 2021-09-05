#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

// https://leetcode.com/problems/find-peak-element/
// binary search
int main() {
    vector<int> nums({1, 2, 3, 1});
    cout << binarySearch(nums) << endl;

    vector<int> nums2({1, 2, 1, 3, 5, 6, 4});
    cout << binarySearch(nums2) << endl;

    vector<int> nums3({2, 1});
    cout << binarySearch(nums3) << endl;

    return 0;
}
