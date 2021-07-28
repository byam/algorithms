#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    string taro, hana;
    int tp = 0, hp = 0;
    for (int i = 0; i < n; i++) {
        cin >> taro >> hana;
        if ( taro == hana) {
            tp++;
            hp++;
        }
        else if (taro > hana) tp += 3;
        else hp += 3;
    }
    cout << tp << " " << hp << endl;
    return 0;
}
