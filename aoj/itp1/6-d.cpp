#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i< (n); i++)

int main() {
    int n, m;
    cin >> n >> m;

    int A[100][100] = {{}};
    int b[100] = {};
    int c[100] = {};

    // in
    rep(i, n) {
        rep(j, m) {
            cin >> A[i][j] ;
        }
    }
    rep(i, m) {
        cin >> b[i];
    }

    // Ab = c
    rep(i, n) {
        int sum = 0;
        rep(j, m) {
            sum += A[i][j] * b[j];
        }
        c[i] = sum;
    }

    // out
    rep(i, n) cout << c[i] << endl;

    return 0;
}
