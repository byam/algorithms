#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, a, b, ans = 0;

    // in
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        int sum = 0, num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (a <= sum && sum <= b) {
            // cout << i << endl;
            ans += i;
        };
    }

    // out
    cout << ans << endl;
    return 0;
}
