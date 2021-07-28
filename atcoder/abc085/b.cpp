#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, d, check[101] = {0}, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d;
        if (check[d] == 0) {
            check[d] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
