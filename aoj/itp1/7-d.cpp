#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m, l;
    int A[100][100] = {{}};
    int B[100][100] = {{}};

    // in
    cin >> n >> m >> l;
    rep(i, n) {
        rep(j, m) { cin >> A[i][j]; }
    }
    rep(i, m) {
        rep(j, l) { cin >> B[j][i]; }
    }

    // calculation
    rep(in, n) {
        rep(il, l) {
            long mul = 0;

            // vector * vector
            rep(im, m) { mul += A[in][im] * B[il][im]; }

            cout << mul;
            if (il < l - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
