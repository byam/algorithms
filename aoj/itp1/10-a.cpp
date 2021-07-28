#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    printf("%.5f\n", sqrt(pow(fabs(x1 - x2), 2.0) + pow(fabs(y1 - y2), 2.0)));

    return 0;
}
