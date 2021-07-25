#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> Map;
    Map["qiita"] = 777;
    Map["algorithm"] = 1111;
    Map["competitive_programming"] = 1073741824;

    cout << Map["algorithm"] << endl; // 1111 と出力される
    cout << Map["tourist"] << endl; // まだ何も書き込まれていないので、0 と出力される
    return 0;
}
