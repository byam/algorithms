#include <iostream>
#include <vector>
#include <typeinfo>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vi::iterator vi_iterator;
typedef vvi::iterator vvi_iterator;


#define sz(a) int((a).size())
#define pb push_back
#define all(c) c.begin(),c.end()
#define present(c,x) ((c).find(x) != (c).end()) // container with member function find
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vector
#define traverse(c,it) for(auto it = c.begin(); it != c.end(); it++)

int main(int argc, char* argv[])
{
    vi v;
    for (int i = 1; i < 10; ++i)
    {
        v.pb(i*i);
    }

    // size
    std::cout << "size: " << sz(v) << "\n";

    // iterate
    std::cout << "iterate: ";
    traverse(v, i){
        std::cout << *i << " ";
    }
    std::cout << "\n";

    // if value exists in vector
    if(cpresent(v, 25)) {
        std::cout << "found: " << *find(all(v), 25) << std::endl; // print 25
        std::cout << "not found: " << *find(all(v), 48) << std::endl; // print 0
    }

    return 0;
}
