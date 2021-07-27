#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i< (n); i++)

int main() {
    int m, f, r;
    for (int i = 0; ; i++)
    {
        cin >> m >> f >> r;
        // printf("\n%d %d %d\n", m, f, r);
        // end
        if (m == -1 && f == -1 && r == -1) break;

        // F
        if (m == -1 || f == -1 ) {
            cout << "F" << endl;
            continue;
        }

        // A -> D
        int sum = m + f;
        if (sum >= 80)  cout << "A" << endl;
        else if (sum >= 65)  cout << "B" << endl;
        else if (sum >= 50) cout << "C" << endl;
        else if (sum >= 30) {
            if (r >= 50) cout << "C" << endl;
            else {
                cout << "D" << endl;
                }
        }
        else cout << "F" << endl;
    }

    return 0;
}
