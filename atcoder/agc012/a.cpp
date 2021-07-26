#include <bits/stdc++.h>
using namespace std;

long long N, a[1000009];

int main() {
    // in
    cin >> N;
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> a[i];
    }

    // sort
    sort(a, a + 3 * N, greater<int>());

    long long sum = 0;
    for (int i = 1; i < 2 * N; i+=2)
    {
        sum += a[i];
    }

    cout << sum << endl;

    return 0;
}
