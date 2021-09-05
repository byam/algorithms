#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;

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
    if (nums[left] >= target) return left;
    if (nums[right] >= target) return right;

    // not found
    return nums.size();
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto a = arr;
    int lb = lowerBound(a, x);

    vector<int> ans;
    int l = k, r = k;
    while (k) {
        if (l < 0) {
            ans.push_back(a[r]);
            r++;
            k--;
            continue;
        }
        if (r >= arr.size()) {
            ans.push_back(a[l]);
            l--;
            k--;
            continue;
        }

        if (abs(x - a[l]) < abs(x - a[r]))
            l--;
        else
            r++;
        k--;
    }
    return ans;
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// binary search
int main() {
    vector<int> nums({1, 2, 3, 4, 5});
    for (auto x : findClosestElements(nums, 4, 3)) cout << x << " ";
    cout << endl;

    return 0;
}
