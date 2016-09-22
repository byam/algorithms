#include <iostream>

using std::cin;
using std::cout;

long long FibList(int n){
    long long* f = new long long[n];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n-1];

}

int main(){
    int n;
    cin >> n;

    cout << FibList(n) << "\n";
    return 0;
}