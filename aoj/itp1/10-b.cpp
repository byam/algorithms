#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    double a, b, C;
    cin >> a >> b >> C;
    double S, L, h;

    // 度数
    C = C / 180.0 * acos(-1);

    S = a * b * sin(C) / 2;
    L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C));
    h = b * sin(C);

    printf("%.5f\n%.5f\n%.5f\n", S, L, h);

    return 0;
}
