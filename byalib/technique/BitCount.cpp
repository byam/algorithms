#include <bits/stdc++.h>
using namespace std;

int main() {
    // 4 bit
    for (int i = 0; i < (1 << 4); i++) {
        // convert to 8 bit
        cout << i << "(" << bitset<8>(i) << ")";
        // count bits
        cout << ": " << __builtin_popcount(i) << " bits." << endl;
    }

    return 0;
}

/*
0(00000000): 0 bits.
1(00000001): 1 bits.
2(00000010): 1 bits.
3(00000011): 2 bits.
4(00000100): 1 bits.
5(00000101): 2 bits.
6(00000110): 2 bits.
7(00000111): 3 bits.
8(00001000): 1 bits.
9(00001001): 2 bits.
10(00001010): 2 bits.
11(00001011): 3 bits.
12(00001100): 2 bits.
13(00001101): 3 bits.
14(00001110): 3 bits.
15(00001111): 4 bits.
*/