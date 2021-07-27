#include <bits/stdc++.h>
using namespace std;

void rectangle(int h, int w) {
    for (int i = 0; i < h; i++)
    {
        for (int i = 0; i < w; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int h, w;
    for (int i = 0; ; i++)
    {
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        rectangle(h, w);
        printf("\n");
    }

    return 0;
}
