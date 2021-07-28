#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s, p;
    cin >> s >> p;

    // new string
    s = s + s;

    if (s.find(p) != -1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
