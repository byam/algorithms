#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string str;
    int cnt[26] = {};

    while (getline(cin, str)) {
        for (int i = 0; i < (int)str.length(); i++) {
            if ('a' <= str[i] && str[i] <= 'z') cnt[str[i] - 'a']++;
            if ('A' <= str[i] && str[i] <= 'Z') cnt[str[i] - 'A']++;
        }
    }
    rep(i, 26) { cout << (char)(i + 'a') << " : " << cnt[i] << endl; }
    return 0;
}
