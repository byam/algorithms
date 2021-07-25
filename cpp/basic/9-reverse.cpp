#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 配列 a の 2～6 番目の要素を逆順にします。{8, 3, 2, 6, 4, 1, 7, 5} に変化します。
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    reverse(a + 2, a + 7);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i];
    }

    // 例 2: {b[0], b[1], ..., b[N-1]} を入力し、逆順にしたうえで出力します。
    int N, b[1009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> b[i];
    reverse(b, b + N);
    for (int i = 0; i < N; i++) cout << b[i] << endl;

    return 0;
}
