#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, sqrt(pow(abs(a[i].first - a[j].first), 2) +
                                pow(abs(a[i].second - a[j].second), 2)));
        }
    }
    printf("%1.3f\n", ans);
    return 0;
}
