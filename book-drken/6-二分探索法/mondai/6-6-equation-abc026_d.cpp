#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// 円周率 PI
const double PI = acos(-1.0);

// https://atcoder.jp/contests/abc026/tasks/abc026_d
// https://drken1215.hatenablog.com/entry/2021/07/03/173400
int main() {
    // 入力
    int A, B, C;
    cin >> A >> B >> C;

    // 関数 f
    auto func = [&](double t) -> double { return A * t + B * sin(C * PI * t); };

    // 二分探索
    double alpha = 0, beta = 200;
    for (int iter = 0; iter < 100; ++iter) {
        double gamma = (alpha + beta) / 2;
        if (func(gamma) <= 100)
            alpha = gamma;
        else
            beta = gamma;
    }

    // 小数点第 15 位まで出力 (ヘッダ <iomanip> が必要)
    cout << fixed << setprecision(15) << alpha << endl;
}
