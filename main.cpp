#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef vector<int> vi;

class Solution {
   public:
    vector<int> n;
    vector<int> memo;

    int dp(int i) {
        if (i < 1) return 0;

        if (memo[i] == -1) {
            int diff = n[i] - n[i - 1];
            memo[i] = 0;

            if (n[i] - n[i - 1] == n[i - 1] - n[i - 2]) memo[i] = dp(i - 1) + 1;
        }

        return memo[i];
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        n = nums;

        memo.resize(nums.size(), -1);
        memo[nums.size() - 1] = dp(nums.size() - 1);

        int sum = 0;
        for (auto x : memo)
            if (x > 0) sum += x;

        return sum;
    }
};

void solve() {
    // in
    // vi nums = {1, 2, 3, 4};
    vi nums = {1};
    cout << Solution().numberOfArithmeticSlices(nums) << endl;
}

int main() {
    // make input and output more efficient
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
