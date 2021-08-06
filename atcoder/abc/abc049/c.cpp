#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S, T, ans = "NO";
    cin >> S;

    string t[4] = {"dreamer", "dream", "eraser", "erase"};

    // reverser
    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; ++i) reverse(t[i].begin(), t[i].end());

    int i = 0;
    while (i < S.length()) {
        int k = i;
        for (int j = 0; j < 4; j++) {
            string str = S.substr(i, t[j].length());
            // cout << str << " " << i << " " << t[j] << endl;
            if (str == t[j]) {
                i += t[j].length();
                // cout << str << " " << i << " " << t[j] << endl;
                break;
            }
        }

        // not changed
        if (i == S.length()) {
            ans = "YES";
        }

        // not changed
        if (k == i) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
