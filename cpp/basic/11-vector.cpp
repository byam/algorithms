#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: a に色々な操作を行う（x1 = 105, x2 = 2, x3 = 146 となります）
    vector<int> a; // その時点で a は空
    a.push_back(121); // その時点で a = {121}
    a.push_back(105); // その時点で a = {121, 105}
    a.push_back(193); // その時点で a = {121, 105, 193}
    int x1 = a[1];
    a.pop_back(); // その時点で a = {121, 105}
    int x2 = a.size();
    a.push_back(146); // その時点で a = {121, 105, 146}
    int x3 = a[2];
    cout << x1 << " " << x2 << " " << x3 << endl;
    return 0;
}
