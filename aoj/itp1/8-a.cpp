#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string S;
    getline(cin, S);
    rep(i, S.size()) {
        if (isalpha(S[i])) {
            if (islower(S[i]))
                cout << (char)toupper(S[i]);
            else
                cout << (char)tolower(S[i]);
        } else
            cout << S[i];
    }
    cout << endl;
    return 0;
}
