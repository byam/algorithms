#include <bits/stdc++.h>
using namespace std;

template <class T>
void out(T x) {
    cout << x << "\n";
}

template <class T>
void out(vector<T> x) {
    int sz = x.size();
    for (int i = 0; i < sz; i++) {
        cout << x[i];
        if (i < sz - 1) cout << " ";
    }

    cout << "\n";
}

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
    if (nums[left] <= target) return left;
    if (nums[right] >= target) return right;

    // not found
    return nums.size();
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto a = arr;
    int lb = lowerBound(a, x);
    out(lb);
    vector<int> ans;
    int l = lb, r = lb + 1;

    // both side exists
    while (k and l >= 0 and r < a.size()) {
        if (abs(x - a[l]) <= abs(x - a[r])) {
            ans.push_back(a[l]);
            l--;
        } else {
            ans.push_back(a[r]);
            r++;
        }
        k--;
    }

    // left full
    while (l < 0 and k) {
        ans.push_back(a[r]);
        r++;
        k--;
    }

    // right full
    while (r >= a.size() and k) {
        ans.push_back(a[l]);
        l--;
        k--;
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// binary search
int main() {
    vector<int> nums({1, 2, 3, 4, 5});
    out(findClosestElements(nums, 4, 3));

    vector<int> nums2({1, 2, 3, 4, 5});
    out(findClosestElements(nums2, 4, -1));

    vector<int> nums3({0, 0, 1, 2, 3, 3, 4, 7, 7, 8});
    out(findClosestElements(nums3, 3, 5));

    return 0;
}
