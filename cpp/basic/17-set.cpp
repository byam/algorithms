#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: set に対して色々な操作を行う（1 個目は "End"、2 個目は "46" と出力される）
    set<int> Set;
    Set.insert(37); // その時点での Set の要素は {37}
    Set.insert(15); // その時点での Set の要素は {15, 37}
    Set.insert(37); // その時点での Set の要素は {15, 37}
    auto itr1 = Set.lower_bound(40);
    if (itr1 == Set.end()) cout << "End" << endl;
    else cout << (*itr1) << endl;

    Set.erase(37); // その時点での Set の要素は {15}
    Set.insert(46); // その時点での Set の要素は {15, 46}
    auto itr2 = Set.lower_bound(20);
    if (itr2 == Set.end()) cout << "End" << endl;
    else cout << (*itr2) << endl;

    // 例 2: a[1],a[2],...,a[N] を小さい順に出力する（同じ要素が複数ある場合 1 回だけ出力する）
    set<int> b; int N, a[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) b.insert(a[i]);
    auto itr = b.begin();
    while (itr != b.end()) {
        cout << (*itr) << endl;
        itr++;
    }

    return 0;
}
