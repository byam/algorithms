#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    double s[1000] = {0}, m, div, sum;
    while (true) {
        cin >> n;
        if (n == 0) break;

        div = sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            sum += s[i];
        }
        m = sum / n;
        for (int i = 0; i < n; i++) {
            div += pow(s[i] - m, 2);
            s[i] = 0;
        }
        // cout << sum << " " << m << " " << div << endl;
        printf("%.5f\n", sqrt(div / n));
    }

    return 0;
}
