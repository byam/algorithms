#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)         \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << endl;
#define ckmin(x, y) x = min(x, y)

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int prefix_sum[5];

    // i までの sum 用意しておく
    prefix_sum[0] = arr[0];
    for (int i = 1; i < 5; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
    printv(arr);
    printv(prefix_sum);

    // k 番目までの合計
    int k = 3;
    cout << prefix_sum[k - 1] << endl;

    // [l, r] 間までの合計
    int r = 4, l = 2;
    cout << prefix_sum[r - 1] - prefix_sum[l - 1 - 1] << endl;

    return 0;
}
