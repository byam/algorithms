#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: tuple の基本
    tuple<int, int, int> A;
    cin >> get<0>(A) >> get<1>(A) >> get<2>(A);
    cout << get<0>(A) + get<1>(A) + get<2>(A) << endl;

    // 例 2: vector にも tuple を入れられます、この例はソートするプログラムです
    vector<tuple<double, int, int>> B; int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        double p1; int p2, p3;
        cin >> p1 >> p2 >> p3;
        B.push_back(make_tuple(p1, p2, p3));
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) printf("%.5lf %d %d\n", get<0>(B[i]), get<1>(B[i]), get<2>(B[i]));

    return 0;
}
