#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;

        // in
        cin >> n >> k;
        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // logic
        long long ans = -1e12;
        int l = max(1, n - 2 * k);
        for (int i = l; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
            }
        }

        // out
        cout << ans << endl;
    }

    return 0;
}
