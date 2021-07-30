#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, 1LL * a[i] * a[i + 1]);
        }
        cout << ans << endl;
    }

    return 0;
}
