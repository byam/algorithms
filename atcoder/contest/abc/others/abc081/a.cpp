#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string str;
    cin >> str;
    int ans = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') ans++;
    }
    cout << ans << endl;

    return 0;
}
