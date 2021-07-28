#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, x[100] = {0}, y[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    int p = 1;
    double d1, d2, d3, dinf = 0;
    for (int i = 0; i < n; i++) {
        d1 += pow(abs(x[i] - y[i]), 1);
        d2 += pow(abs(x[i] - y[i]), 2);
        d3 += pow(abs(x[i] - y[i]), 3);
        dinf = fmax(abs(x[i] - y[i]), dinf);
    }
    printf("%.5f\n", pow(d1, 1.0 / 1));
    printf("%.5f\n", pow(d2, 1.0 / 2));
    printf("%.5f\n", pow(d3, 1.0 / 3));
    printf("%.5f\n", dinf);

    return 0;
}
