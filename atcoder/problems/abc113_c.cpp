#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n, m;
    cin >> n >> m;
    vector<int> P(m), Y(m);
    for (int i = 0; i < m; ++i) cin >> P[i] >> Y[i], --P[i];

    // vals[v] := P[i] = v であるような i についての Y[i] の値を集めたもの
    vector<vector<int> > vals(n);
    for (int i = 0; i < m; ++i) vals[P[i]].push_back(Y[i]);

    // 各 p の値に対して
    for (int v = 0; v < n; ++v) {
        sort(vals[v].begin(), vals[v].end());

        // 今回は不要だが、通常は数のダブりをなくす
        vals[v].erase(unique(vals[v].begin(), vals[v].end()), vals[v].end());
    }

    // 答え
    for (int i = 0; i < m; ++i) {
        int v = P[i];
        printf("%06d", v + 1);

        // 座標圧縮して導いた答え
        int id =
            lower_bound(vals[v].begin(), vals[v].end(), Y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }
}
