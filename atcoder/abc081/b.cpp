#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, A[200] = {0}, ans = 1000000009;

    // in
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];

        if (A[i] % 2 != 0) {
            ans = 0;
            break;
        }

        int cnt = 0;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            cnt++;
        }

        ans = min(ans, cnt);
    }

    // out
    cout << ans << endl;

    return 0;
}
