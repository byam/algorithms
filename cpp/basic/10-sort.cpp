#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 配列 a の 1～4 番目を大きい順に並び替えます。{8, 7, 4, 3, 1, 6, 2, 5} に変化。
    int a[8] = {8, 3, 7, 1, 4, 6, 2, 5};
    sort(a + 1, a + 4 + 1, greater<int>());
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << endl;
    }

    // 例 2: {b[0], b[1], ..., b[N-1]} を入力し、小さい順に並び替えて出力します。
    int N, b[100009];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(b, b + N);
    for (int i = 0; i < N; i++) cout << b[i] << endl;

    return 0;
}
