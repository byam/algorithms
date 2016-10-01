#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// Iterative: binary search
int binary_search_it(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size();

  while (left <= right) {
      size_t mid = left + (right - left) / 2;
      if (a[mid] == x) {
          return mid;
      }
      else if(a[mid] < x){
          left = mid + 1;
      }
      else {
          right = mid - 1;
      }
  }

  return -1;
}

// Recursive: binary search
int binary_search(const vector<int> &a, int left, int right, int key){
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    if (a[mid] == key) {
        return mid;
    }

    if (a[mid] > key) {
        return binary_search(a, left, mid - 1, key);
    }
    else{
        return binary_search(a, mid + 1, right, key);
    }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, 0, a.size(), b[i]) << ' ';
  }
}
