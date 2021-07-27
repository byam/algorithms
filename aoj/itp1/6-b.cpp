#include <bits/stdc++.h>
using namespace std;

int main() {
    char suits[4] = {'S', 'H', 'C', 'D'};
    int cards[4][13] = {{}};

    // in
    int n, r;
    char s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> r;
        switch (s)
        {
        case 'S':
            cards[0][r-1] = 1;
            break;
        case 'H':
            cards[1][r-1] = 1;
            break;
        case 'C':
            cards[2][r-1] = 1;
            break;
        case 'D':
            cards[3][r-1] = 1;
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (cards[i][j] == 0) {
                cout << suits[i] << " " << j + 1 << endl;
            }
        }

    }

    return 0;
}
