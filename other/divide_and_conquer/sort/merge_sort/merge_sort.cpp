#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


void merge_arrays(vi &v, size_t l, size_t m, size_t r) {
    size_t i = l;
    size_t j = m+1;

    // tmp vector
    vi vc;

    // compare i, j
    while (i <= m && j <= r) {
        if (v[i] > v[j]) {
            vc.push_back(v[j]);
            j++;
        }
        else{
            vc.push_back(v[i]);
            i++;
        }
    }

    // copy all left values
    while (i <= m) {
            vc.push_back(v[i]);
            i++;
    }

    while (j <= r) {
            vc.push_back(v[j]);
            j++;
    }

    // back to real vector
    size_t s = 0;
    for (size_t k = l; k <= r; k++) {
        v[k] = vc[s];
        s++;
    }
}

void merge_sort(vi &v, size_t l, size_t r) {
    if (l >= r) {
        return;
    }

    size_t m = l + (r-l)/2;
    merge_sort(v, l, m);
    merge_sort(v, m+1, r);
    merge_arrays(v, l, m, r);
}

int main() {
    vi v;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        v.push_back(input);
    }

    merge_sort(v, 0, n-1);

    return 0;
}
