#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int threebo(int n) {
    // base case
    if (n == 0 or n == 1) return n;
    if (n == 2) return 1;

    // check memo
    if (dp[n - 1] != -1) return dp[n - 1];

    // recursive
    int ans = threebo(n - 1) + threebo(n - 2) + threebo(n - 3);
    printf("threebo(%d - 1) + threebo(%d - 2) + threebo(%d - 3) = %d\n", n, n,
           n, ans);

    return dp[n - 1] = ans;
}

int main() {
    int N;
    cin >> N;

    dp.assign(N, -1);

    cout << threebo(N) << endl;

    return 0;
}
