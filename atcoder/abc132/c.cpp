#include <bits/stdc++.h>
using namespace std;

long long N, d[10000009];

int main() {

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
    }

    // sort
    sort(d, d + N);

    // out
    cout << d[N/2] - d[N/2 - 1] << endl;

    return 0;
}
