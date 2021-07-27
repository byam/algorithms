#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int r, c;
    int table[101][101] = {{}};

    cin >> r >> c;

    rep(i, r) {
        rep(j, c) {
            cin >> table[i][j];
            table[i][c] += table[i][j];
            table[r][j] += table[i][j];
            table[r][c] += table[i][j];
        }
    }

    rep(i, r+1) {
        rep(j, c+1) {
            cout << table[i][j];
            if (j != c) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
