#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int d;
    cin >> d;
    vector<string> msg{"Hello", "C++",     "World",
                       "from",  "VS Code", "and the C++ extension!"};

    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << d << endl;
    cout << endl;
}
