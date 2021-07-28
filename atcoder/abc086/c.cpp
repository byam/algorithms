#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, t, x, y, pt, px, py;
    vector<pair<int, int>> V;
    vector<int> T;
    cin >> N;
    string ans = "Yes";

    pt = px = py = 0;
    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;

        int dt = abs(t - pt);
        int dxy = abs(x - px) + abs(y - py);

        if (dt < dxy || (dt - dxy) % 2 != 0) {
            ans = "No";
        }

        pt = t;
        px = x;
        py = y;
    }

    cout << ans << endl;
    return 0;
}
