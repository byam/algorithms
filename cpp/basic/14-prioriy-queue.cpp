#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: Q に色々な操作を行う（x1 = 116, x2 = 110, x3 = 122, x4 = 2 となります）
    priority_queue<int, vector<int>, greater<int>> Q;
    Q.push(116); // この時点で、小さい順に {116}
    Q.push(145); // この時点で、小さい順に {116, 145}
    Q.push(122); // この時点で、小さい順に {116, 122, 145}
    int x1 = Q.top();

    Q.push(110); // この時点で、小さい順に {110, 116, 122, 145}
    int x2 = Q.top();

    Q.pop(); // この時点で、小さい順に {116, 122, 145}
    Q.pop(); // この時点で、小さい順に {122, 145}
    int x3 = Q.top();
    int x4 = Q.size();

    cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;

    return 0;
}
