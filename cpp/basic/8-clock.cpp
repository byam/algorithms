#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 実行にかかる時間を計測する
    int ti = clock();
    for (int i = 0; i < 100000; i++)
    {
        cout << i << endl;
    }

    printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);

    return 0;
}
