#include <bits/stdc++.h>

#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string str;
    int q;
    cin >> str >> q;
    for (int i = 0; i < q; i++) {
        string cmd, p;
        int x, y;
        cin >> cmd >> x >> y;
        if (cmd == "replace") {
            cin >> p;
            str.replace(x, p.length(), p);
        } else if (cmd == "reverse") {
            reverse(str.begin() + x, str.begin() + y + 1);
        } else if (cmd == "print") {
            cout << str.substr(x, y - x + 1) << endl;
        }
    }

    return 0;
}
