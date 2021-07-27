#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ma = -1000001, mi = 1000001;
    long sum = 0;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        mi = min(mi, a);
        ma = max(ma, a);
    }

    cout << mi << " " << ma << " " << sum << endl;

    return 0;
}
