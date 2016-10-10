#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>      // std::accumulate

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end()) // container with member function find
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vector

#define printv(v) for(auto x: v) {cout << x << " ";} cout << "\n"
#define printvv(vv) for (auto v: vv) {printv(v);}

int main() {

    std::vector<char> v = {'a', 'b', 'c'};
    std::vector< std::vector<char> > vv(3, v);

    printvv(vv);

    return 0;
}
