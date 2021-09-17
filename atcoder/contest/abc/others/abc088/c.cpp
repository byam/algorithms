#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int c[3][3] = {{0}};
    string ans = "No";

    // int
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    for (int a1 = 0; a1 <= 100; a1++) {
        for (int a2 = 0; a2 <= 100; a2++) {
            for (int a3 = 0; a3 <= 100; a3++) {
                int cnt = 0;
                for (int i = 0; i < 3; i++) {
                    // b
                    int x = c[0][i] - a1;
                    int y = c[1][i] - a2;
                    int z = c[2][i] - a3;
                    if (x == y && x == z) cnt++;
                }
                if (cnt == 3) ans = "Yes";
            }
        }
    }

    // out
    cout << ans << endl;
    return 0;
}
