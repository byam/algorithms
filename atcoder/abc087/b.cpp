#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b, c, x;
    int ans = 0;

    // in
    cin >> a >> b >> c >> x;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                if (500 * i + 100 * j + 50 * k == x) ans++;
            }
        }
    }

    // out
    cout << ans << endl;

    return 0;
}
