#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    double fb = b;
    printf("%d %d %.5f\n", a / b , a % b, a / fb);
    return 0;
}
