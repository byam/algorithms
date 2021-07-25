#include <bits/stdc++.h>
using namespace std;

int main() {

    // 例 1: A or B を計算します。なお、A と B は string 型で 2 進数で与えられます。
    string A; cin >> A;
    string B; cin >> B;

    bitset<2000> A1(A);
    bitset<2000> B1(B);
    bitset<2000> ans = (A1 | B1);

    bool flag = false;
    for (int i = 1999; i >= 0; i--) {
        if (ans[i] == 1) flag = true;
        if (flag == true) cout << ans[i];
    }
    cout << endl;
    return 0;
}
