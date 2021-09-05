#include <bits/stdc++.h>
using namespace std;

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
