#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 0; i < (n); i++)
#define printv(v)                          \
    for (int i = 0; i < (v.size()); i++) { \
        cout << v[i] << " ";               \
    }                                      \
    cout << endl;
#define ckmin(x, y) x = min(x, y)

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;
        vector<int> up(m), down(m);
        for (int i = 0; i < m; i++) cin >> up[i];
        for (int i = 0; i < m; i++) cin >> down[i];

        // accumulate
        vector<int> accup(m), accdown(m);
        accup[0] = up[0];
        accdown[0] = down[0];
        for (int i = 1; i < m; i++) {
            accdown[i] = accdown[i - 1] + down[i];
            accup[i] = accup[i - 1] + up[i];
        }
        // printv(accup);
        // printv(accdown);

        // find k
        vector<int> score(m);
        int ans = INT_MAX;
        score[0] = accup[m - 1] - accup[0];
        ans = score[0];
        for (int i = 1; i < m; i++) {
            score[i] = max(accup[m - 1] - accup[i], accdown[i - 1]);
            ckmin(ans, score[i]);
        }

        // printv(score);
        if (ans != INT_MAX)
            cout << ans << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
