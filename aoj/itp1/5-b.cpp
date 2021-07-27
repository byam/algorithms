#include <bits/stdc++.h>
using namespace std;

void print_frame(int h, int w) {
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(i == 0 || j == 0 || i == h - 1 || j == w - 1) printf("#");
            else printf(".");
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
        print_frame(h, w);
        printf("\n");
    }

    return 0;
}
