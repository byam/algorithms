#include <bits/stdc++.h>
using namespace std;
const int N = 200050;
int cnt[N], ans;
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%i %i", &u, &v);
        if (u > v) swap(u, v);
        cnt[u]++;
        if (cnt[u] == 1) ans++;
    }
    int q;
    scanf("%i", &q);
    while (q--) {
        int t;
        scanf("%i", &t);
        if (t == 1) {
            int u, v;
            scanf("%i %i", &u, &v);
            if (u > v) swap(u, v);
            cnt[u]++;
            if (cnt[u] == 1) ans++;
        } else if (t == 2) {
            int u, v;
            scanf("%i %i", &u, &v);
            if (u > v) swap(u, v);
            cnt[u]--;
            if (cnt[u] == 0) ans--;
        } else
            printf("%i\n", n - ans);
    }
    return 0;
}
