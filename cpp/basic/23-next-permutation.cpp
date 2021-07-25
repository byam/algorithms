#include <bits/stdc++.h>
using namespace std;

int N, A[12][12], B[12], perm[12], ans = 2000000000;

int main() {
    // N 個の都市があり、都市 i から j まで移動するのにかかる時間は A[i][j] 分
    // 全ての都市を訪れるのに何分かかるか？　ただし、どの都市から出発、どの都市に到着してもよい。
    // A[i][j] = A[j][i], A[i][i] = 0
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> A[i][j];
    }
    for (int i = 0; i < N; i++) B[i] = i + 1;

    do {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += A[B[i]][B[i + 1]];
        }
        ans = min(ans, sum);
    } while(next_permutation(B, B + N));

    cout << ans << endl;
    return 0;
}
