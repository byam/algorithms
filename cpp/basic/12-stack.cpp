#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: a に色々な操作を行う（x1 = 156, x2 = 202, x3 = 117, x4 = 3, x5 = 0 となります）
    stack<int> a;
    a.push(179); // その時点で下から順に {179}
    a.push(173); // その時点で下から順に {179, 173}
    a.push(156); // その時点で下から順に {179, 173, 156}
    int x1 = a.top();

    a.pop(); // その時点で下から順に {179, 173}
    a.push(117); // その時点で下から順に {179, 173, 117}
    a.push(202); // その時点で下から順に {179, 173, 117, 202}
    int x2 = a.top();

    a.pop(); // その時点で下から順に {179, 173, 117}
    int x3 = a.top();
    int x4 = a.size();

    int x5 = 0; if (a.empty()) x5 = 10000;

    cout << x1 << " " << x2 << " "<< x3 << " " << x4 << " " << x5 << endl;

    return 0;
}
