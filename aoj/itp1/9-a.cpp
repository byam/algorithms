#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string W, T;
    cin >> W;
    transform(W.begin(), W.end(), W.begin(), ::tolower);

    int cnt = 0;

    while (true) {
        cin >> T;
        if (T == "END_OF_TEXT") break;

        transform(T.begin(), T.end(), T.begin(), ::tolower);

        if (W == T) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
