#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
const int inf = INT_MAX / 2;

bool isSquare(ll n) {
    ll d = (ll)sqrt(n) - 1;
    while (d * d < n) ++d;
    return d * d == n;
}

int N, D;
int X[10][10];

int main() {
    cin >> N >> D;
    rep(i, N) rep(j, D) cin >> X[i][j];
    int cnt = 0;
    rep(i, N) {
        for (int j = i + 1; j < N; j++) {
            int sum = 0;
            rep(d, D) sum += (X[i][d] - X[j][d]) * (X[i][d] - X[j][d]);
            if (isSquare(sum)) cnt++;
        }
    }
    cout << cnt << endl;
}