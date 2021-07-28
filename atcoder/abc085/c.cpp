#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Y, x, y, z;
    x = y = z = -1;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int k = N - i - j;
            int sum = i * 10000 + j * 5000 + k * 1000;

            if (sum == Y) {
                x = i;
                y = j;
                z = k;
            }
        }
    }

    printf("%d %d %d\n", x, y, z);

    return 0;
}
