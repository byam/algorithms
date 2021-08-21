#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    string s[3] = {"hello", "world", "!"};

    for (auto x : s) {
        int n = x.length();
        cout << x << ": " << n << endl;
    }

    if ((a * b) % 2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
}
