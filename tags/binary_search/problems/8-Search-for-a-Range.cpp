#include <bits/stdc++.h>
using namespace std;

vector<int> binarySearch(vector<int>& nums, int target) {
    if (nums.size() == 0) return vector<int>({-1, -1});

    int first = -1;
    int last = -1;

    // find first
    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[left] == target)
        first = left;
    else if (nums[right] == target)
        first = right;

    // find last
    left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if (nums[right] == target)
        last = right;
    else if (nums[left] == target)
        last = left;

    return vector<int>({first, last});
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// binary search
int main() {
    vector<int> nums({5, 7, 7, 8, 8, 10});
    auto ans = binarySearch(nums, 8);
    cout << ans[0] << " " << ans[1] << endl;

    vector<int> nums2({5, 7, 7, 8, 8, 10});
    auto ans2 = binarySearch(nums2, 6);
    cout << ans2[0] << " " << ans2[1] << endl;

    vector<int> nums3({});
    auto ans3 = binarySearch(nums3, 6);
    cout << ans3[0] << " " << ans3[1] << endl;

    vector<int> nums4({2, 2});
    auto ans4 = binarySearch(nums4, 2);
    cout << ans4[0] << " " << ans4[1] << endl;

    return 0;
}
