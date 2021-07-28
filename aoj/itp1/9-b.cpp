#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string str;
    int m;
    int h;

    while (true) {
        cin >> str;
        if (str == "-") break;

        // pos vector
        int len = str.length();
        vector<int> pos;
        rep(i, len) { pos.push_back(i); }

        cin >> m;
        rep(i, m) {
            cin >> h;
            str = str.substr(h) + str.substr(0, h);
        }
        cout << str << endl;
    }

    return 0;
}
