#include <bits/stdc++.h>
using namespace std;

int threebo(int n) {
    // base case
    if (n == 0 or n == 1) return n;
    if (n == 2) return 1;

    // recursive
    int ans = threebo(n - 1) + threebo(n - 2) + threebo(n - 3);
    printf("threebo(%d - 1) + threebo(%d - 2) + threebo(%d - 3) = %d\n", n, n,
           n, ans);
    return ans;
}

int main() {
    int N;
    cin >> N;
    cout << threebo(N) << endl;
    return 0;
}
