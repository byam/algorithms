#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long long, long long>;
int main() {
    int N;
    long long M;
    cin >> N >> M;
    vector<pll> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    long long res = 0;
    for (int i = 0; i < N && M > 0; ++i) {
        res += v[i].first * min(M, v[i].second);
        M -= min(M, v[i].second);
    }
    cout << res << endl;
}
