#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int l[100009];

    // input
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> l[i];
    }

    // descent sort
    sort(l, l + N, greater<int>());

    int sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += l[i];
    }

    // output
    cout << sum << endl;

    return 0;
}
