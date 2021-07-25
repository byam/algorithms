#include <bits/stdc++.h>
using namespace std;

int main() {

    // 例 1: a に色々な操作を行う（x1 = 179, x2 = 173, x3 = 156, x4 = 3, x5 = 0 となります）
    queue<int> a;
    a.push(179); // その時点で前から順に {179}
    a.push(173); // その時点で前から順に {179, 173}
    a.push(156); // その時点で前から順に {179, 173, 156}
    int x1 = a.front();
    a.pop(); // その時点で前から順に {173, 156}
    a.push(117); // その時点で前から順に {173, 156, 117}
    a.push(202); // その時点で前から順に {173, 156, 117, 202}
    int x2 = a.front();
    a.pop(); // その時点で前から順に {156, 117, 202}
    int x3 = a.front();
    int x4 = a.size();
    int x5 = 0; if (a.empty()) x5 = 10000;

    cout << x1 << " " << x2 << " "<< x3 << " " << x4 << " " << x5 << endl;

    return 0;
}
