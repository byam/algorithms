#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    vector<int> vi;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vi.push_back(x);
    }

    for (int i = n - 1; i > 0; i--)
    {
        cout << vi[i] << " ";
    }
    cout << vi[0] << endl;

    return 0;
}