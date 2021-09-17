#include <bits/stdc++.h>
using namespace std;

long long N, a[1000009];

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // sort
    sort(a, a + N, greater<int>());
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if ( i % 2 == 0) sum += a[i];
        else sum -= a[i];
    }

    cout << sum << endl;

    return 0;
}
