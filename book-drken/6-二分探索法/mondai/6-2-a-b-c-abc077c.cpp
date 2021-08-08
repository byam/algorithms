#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/abc077/tasks/arc084_a
int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];
    for (int i = 0; i < N; ++i) cin >> c[i];

    // ソートする
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    // b[j] を固定して考える
    long long res = 0;
    for (int j = 0; j < N; ++j) {
        long long Aj = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
        long long Cj = N - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());
        res += Aj * Cj;
    }
    cout << res << endl;
}
