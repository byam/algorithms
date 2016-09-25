#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()) // container with member function find
#define cpresent(c,x) (find(all(c),x) != (c).end()) // for vector

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

/* VECTOR */

// PAIRS:
void test_pair() {
    std::vector< std::pair<int, int> > v_pair;
    v_pair.push_back(std::pair<int, int>( 10, 11 ));

    std::cout << v_pair[0].first << std::endl;
    std::cout << v_pair[0].second << std::endl;
}

// COPY:
void test_vector_copy() {
    std::vector<int> v(5, 7);
    print_vector(v);
    std::vector<int> v2(v);
    print_vector(v2);
    std::vector<int> v3(v.begin(), v.end()); // v3 equals to v2
    print_vector(v3);
    std::vector<int> v4(all(v3)); // v3 equals to v2
    print_vector(v4);
    // C-style
    int data[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    std::vector<int> primes(data, data+(sizeof(data) / sizeof(data[0])));
    print_vector(primes);
}

// REVERSE FUNCTION:
void test_vector_reverse() {
    // C-style
    int data[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    reverse(data+2, data+6); // the range { 5, 7, 9, 11 } is now { 11, 9, 7, 5 };
    for (int i = 0; i < 10; i++) {
        std::cout << data[i] << " ";
    }
    // STL-style
    vector<int> v = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    vector<int> v2(v.rbegin()+(v.size()/2), v.rend());
    print_vector(v2);
}

// ITERATOR:
void test_iterator() {
    vector<int> v = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    // Traverse all container, from begin() to end()
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
}

// FIND:
void test_vector_find() {
    //  If the element is found, the iterator pointing to the first occurrence of the element is returned. Otherwise, the return value equals the end of interval.
    vector<int> v;
    for(int i = 1; i < 100; i++) {
        v.push_back(i*i);
    }

     if(find(v.begin(), v.end(), 49) != v.end()) {
        std::cout << *find(v.begin(), v.end(), 49) << std::endl;
        std::cout << *find(v.begin(), v.end(), 48) << std::endl;
     }
}

// INDEX:
void test_vector_index() {
    // To get the index of element found, one should subtract the beginning iterator from the result of find():
    vector<int> v;
    for(int i = 1; i < 100; i++) {
        v.push_back(i*i);
    }
    int i = (find(v.begin(), v.end(), 49) - v.begin());
    if(i < v.size()) {
        std::cout << i << std::endl;
    }
}

// MIN, MAX:
void test_vector_min_max() {
    // The min_element and max_element algorithms return an iterator to the respective element.
    int data[5] = { 1, 5, 2, 4, 3 };
    vector<int> X(data, data+5);
    int v1 = *max_element(X.begin(), X.end()); // Returns value of max element in vector
    int i1 = max_element(X.begin(), X.end()) - X.begin(); // Returns index of min element in vector

    int v2 = *min_element(data, data+5); // Returns value of max element in array
    int i2 = min_element(data, data+5) - data; // Returns index of min element in array
    std::cout << i1 << ": " << v1 << std::endl;
    std::cout << i2 << ": " << v2 << std::endl;
}

// SORT:
void test_vector_sort() {
    int data[5] = { 1, 5, 2, 4, 3 };
    vector<int> X(data, data+5);

    sort(X.begin(), X.end()); // Sort array in ascending order
    print_vector(X);
    sort(all(X)); // Sort array in ascending order, use our #define
    print_vector(X);
    sort(X.rbegin(), X.rend()); // Sort array in descending order using with reverse iterators
    print_vector(X);
}

// INSERT:
void test_vector_insert() {
    vector<int> v;
    for(int i = 1; i < 10; i++) {
        v.push_back(i*i);
    }
    print_vector(v);
    v.insert(v.begin(), 42); // Insert value 42 after the first
    print_vector(v);

    vector<int> v1 = {1, 1, 1};
    vector<int> v2 = {2, 2, 2};

    // Shift all elements from second to last to the appropriate number of elements.
    // Then copy the contents of v2 into v.
    v1.insert(v1.begin(), all(v2));
    print_vector(v1);
}

// ERASE:
void test_vector_erase() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    v.erase(v.begin() + 1);
    print_vector(v);
    v.erase(v.begin(), v.end() - 3);
    print_vector(v);
}

// STRING:
void test_string() {
    string s = "hello";
    string s1 = s.substr(0, 3); // "hel"
    string s2 = s.substr(1, 3); // "ell"
    string s3 = s.substr(0, s.length()-1); // "hell"
    string s4 = s.substr(1); // "ello"
    std::cout << s4 << "\n";
}



/* SET */
    // - add an element, but do not allow duples [duplicates?]
    // - remove elements
    // - get count of elements (distinct elements) ➡︎ O(1)
    // - check whether elements are present in set ➡︎ O(log n)

// INSERT and ERASE
void test_set_insert_erase() {
    set<int> s;

    for(int i = 1; i <= 100; i++) {
        s.insert(i); // Insert 100 elements, [1..100]
    }

    s.insert(42); // does nothing, 42 already exists in set

    for(int i = 2; i <= 100; i += 2) {
        s.erase(i); // Erase even values
    }

    int n = int(s.size()); // n will be 50
}

// ITERATE and SUM
void test_set_sum() {
    set<int> s;
    for(int i = 1; i <= 10; i++) {
        s.insert(i); // Insert 10 elements, [1..10]
    }

    // normal iterate
    int sum = 0;
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        sum += *it;
    }
    std::cout << sum << "\n";
}

// SET::FIND
void test_set_find() {
    set<int> s;
    for(int i = 1; i <= 10; i++) {
        s.insert(i*i); // Insert 10 elements, [1..10]
    }

    // ordinary
    if(s.find(42) != s.end()) {
      // 42 presents in set
      std::cout << "42 is found" << "\n";
    }
    else {
      // 42 not presents in set
      std::cout << "42 is not found" << "\n";
    }

    // using macros
    if(present(s, 49)) {
      // 42 presents in set
      std::cout << "49 is found" << "\n";
    }
    else {
      // 42 not presents in set
      std::cout << "49 is not found" << "\n";
    }

}

// SET interval constucter
void test_set_interval_constuctor() {
    int data[5] = { 5, 1, 4, 2, 3 };
    set<int> S(data, data+5);
    print_set(S);

    // It gives us a simple way to get rid of duplicates in vector, and sort it:
    vector<int> v = {8, 8, 1, 3, 2, 9, 9};
    set<int> s(all(v));
    print_set(s);
    vector<int> v2(all(s));
    print_vector(v2);
}


/* MAP */
// SAMPLE
void test_map_sample() {
    map<string, int> M;
    M["Top"] = 1;
    M["Coder"] = 2;
    M["SRM"] = 10;

    print_map(M);

    int x = M["Top"] + M["Coder"];

    if(M.find("SRM") != M.end()) {
        M.erase(M.find("SRM")); // or even M.erase("SRM")
    }
}

// TRAVERSE
void test_map_iterate() {
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

// FIND
void test_map_find() {
     // Error! Cannot use [] on const map objects!
    // if(M["the meaning"] == 42) {
    // }
    map<string, int>M;
    M["the meaning"] = 42;
    if(M.find("the meaning") != M.end() && M.find("the meaning")->second == 42) { // Correct
        cout << "Don't Panic!" << endl;
    }
}


int main() {
    test_map_iterate();
    return 0;
}
