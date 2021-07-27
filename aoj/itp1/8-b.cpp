#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string num;
    for (int i = 0;; i++) {
        cin >> num;

        if (num == "0") break;

        int sum = 0;

        for (int j = 0; j < num.size(); j++) {
            sum += num[j] - '0';
        }

        cout << sum << endl;
    }

    return 0;
}
