#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int a, b;
    vector<string> msg{"VS Code", "and the C++ extension!"};
    for (const string& word : msg) {
        cout << word << " ";
    }
    cin >> a >> b;
    a += b;
    b--;
    cout << endl << a << endl;
}

// run: ctl(cap) + alt(win) + N
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    solve();
}
