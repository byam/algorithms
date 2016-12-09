#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()


/* PRINT */
void print_vector(const std::vector<int>& v) {
    // Traverse all container, from begin() to end()
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void print_set(const set<int>& s){
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void print_map(const map<string, int>& m) {
    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << it->first << "=>" << it->second << " ";
    }
    std::cout << "\n";
}


/* Algorithms */

// MIN MAX SWAP
void test_min_max_swap() {
    int x = 5;
    int y = 3;

    std::cout << min(x, y) << "\n"; // 3
    std::cout << max(x, y) << "\n"; // 5

    swap(x, y);
    std::cout << x << "\n"; // 3
    std::cout << y << "\n"; // 5
}

void test_next_permutation() {
    vector<int> v;

    for(int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    print_vector(v);
    next_permutation(all(v));
    print_vector(v);
    next_permutation(all(v));
    print_vector(v);
    prev_permutation(all(v));
    print_vector(v);

    // do {
    // Solve(..., v);
    // } while(next_permutation(all(v));
}

int main()
{
    test_next_permutation();

    return 0;
}
