#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int W, H, x1, y1, x2, y2, w, h;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;

        int ans = INT_MAX;

        // width
        if (x2 - x1 <= W - w) {
            ans = max(0, w - max(x1, W - x2));
        }
        // height
        if (y2 - y1 <= H - h) {
            ans = min(ans, max(0, h - max(y1, H - y2)));
        }
        if (ans != INT_MAX)
            printf("%.6f\n", 1.0 * ans);
        else
            printf("%d\n", -1);
    }

    return 0;
}
