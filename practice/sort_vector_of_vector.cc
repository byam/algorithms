#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vv(const vector< vector<double> >& grid) {
    for ( std::vector<std::vector<double>>::size_type i = 0; i < grid.size(); i++ ){
        for ( std::vector<double>::size_type j = 0; j < grid[i].size(); j++ ){
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    vector< vector<double> > vv;
    vv.push_back({1.215, 30, 200});
    vv.push_back({1.22, 10, 100});
    vv.push_back({1.21, 20, 300});

    print_vv(vv);

    // sort by first element
    sort(vv.begin(), vv.end(),
        [](const std::vector<double>& a, const std::vector<double>& b) {
      return a[0] < b[0];
    });
    print_vv(vv);

    return 0;
}
