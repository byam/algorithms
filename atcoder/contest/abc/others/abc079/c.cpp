#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, i = 8;
    scanf("%1d%1d%1d%1d", &A, &B, &C, &D);
    while (i--)
        if (A + (i & 4 ? -B : B) + (i & 2 ? -C : C) + (i & 1 ? -D : D) == 7) {
            char p[] = {'+', '-'};
            printf("%d%c%d%c%d%c%d=7\n", A, p[i / 4 % 2], B, p[i / 2 % 2], C,
                   p[i % 2], D);
            break;
        }
    return 0;
}
