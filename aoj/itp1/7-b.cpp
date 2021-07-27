#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

void combination(int n, int x) {
    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                if (i != j && i != k && j != k) {
                    if (i + j + k == x - 3) {
                        // printf("%d %d %d = %d\n", i, j, k, x - 3);
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans / 6 << endl;
}

int main() {
    int n, x;
    for (int i = 0;; i++) {
        cin >> n >> x;

        // end
        if (n == x && x == 0) break;

        combination(n, x);
    }

    return 0;
}
