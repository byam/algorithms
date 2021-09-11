#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int k = 3;
    int ans = 0;
    int right = 1;
    for (int left = 0; left < n; ++left) {
        int diff = nums[right] - nums[left];

        while (right < n) {
            /* 実際に right を 1 進める */
            // ex: sum += a[right];
            ++right;
        }

        /* break した状態で right は条件を満たす最大なので、何かする */
        // ex: res += (right - left);

        /* left をインクリメントする準備 */
        // ex: if (right == left) ++right;
        // ex: else sum -= a[left];
    }

    return ans;
}

int main() {
    vector<int> nums({2, 4, 6, 8, 10});
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}
