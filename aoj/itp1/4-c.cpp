#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    char op;
    for (int i = 0; ; i++)
    {
        scanf("%d %c %d", &a, &op, &b);
        if (op == '?') break;
        switch (op) {
            case '+':
                cout << a + b;
                break;
            case '-':
                cout << a - b;
                break;
            case '*':
                cout << a * b;
                break;
            case '/':
                cout << a / b;
                break;
        }
        cout << endl;
    }

    return 0;
}
