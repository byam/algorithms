#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: a[i] < x となるような i が何個あるのかを O(log N) で計算する
    int N, a[100009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);

    int x;
    cin >> x;
    cout << lower_bound(a, a + N, x) - a << endl;

    return 0;
}
