#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;


long get_a_target_long() {
    long target;
    cout << "target(0~" << RAND_MAX << "): ";
    cin >> target;
    return target; 
}

string get_a_target_string() {
    long target = 0;
    char buf[10];
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    printf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void *a, const void *b) {
    return ( *(long*)a - *(long*)b);
}

int compareStrings(const void *a, const void *b) {
    if( *(string*)a > *(string*)b) {
        return 1;
    } else if( *(string*)a < *(string*)b) {
        return -1;
    } else {
        return 0;
    }
}

#include<array>
#include<ctime>
#include<cstdlib> // qsort, bsearch, NULL
using std::array;
namespace testArray
{
#define ARRAY_SIZE 50000
void testArray() {
    cout << "testArray()......... \n";
    array<long, ARRAY_SIZE> a;
    clock_t timeStart = clock();
    for(int i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand();
    }
    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "array.size(): " << a.size() << endl; 
    cout << "array.front(): " << a.front() << endl;
    cout << "array.back(): " << a.back() << endl;
    cout << "array.data(): " << a.data() << endl;
    long target = get_a_target_long();
    timeStart = clock();
    qsort(a.data(), ARRAY_SIZE, sizeof(long), compareLongs);
    long* pItem = (long*)bsearch(&target, (a.data()), ARRAY_SIZE, sizeof(long), compareLongs);
    cout << "qsort() + bsearch(), milli-seconds: " << clock() - timeStart << endl;
    if(pItem != nullptr) {
        cout << "found, " << *pItem << endl;
    } else {
        cout << "not found! " << endl;
    }
}

} // namespace testArray

#include<vector>
#include<string>
#include<stdexcept>
#include<cstdlib> // bsearch, NULL
#include<cstdio>
#include<iostream>
#include<ctime>
#include<algorithm>
using std::vector;
using std::exception;
namespace testVector
{
void testVector() {
    cout << "testVector().........." << endl;
    long value = 1000000;
    vector<string> v;
    char buf[10];
    clock_t timeStart = clock();
    for(long i = 0; i < value; i++) {
        try {
            snprintf(buf, 10, "%d", rand());
            v.push_back(string(buf));
        }
        catch(exception& p) {
            cout << "i = " << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << (clock() - timeStart) << endl;
    cout << "vector.size(): " << v.size() << endl; 
    cout << "vector.front(): " << v.front() << endl;
    cout << "vector.back(): " << v.back() << endl;
    cout << "vector.data(): " << v.data() << endl;
    cout << "vector.capacity(): " << v.capacity() << endl; 
    string target = get_a_target_string();
    { // 顺序查找
        timeStart = clock();
        auto pItem = find(v.begin(), v.end(), target);
        cout << "find(), milli-seconds: " << (clock() - timeStart) << endl;
        if(pItem != v.end()) {
            cout << "found, " << *pItem << endl;
        } else {
            cout << "not found! " << endl;
        }
    }
    { // 排序 + 二分查找
        timeStart = clock();
        sort(v.begin(), v.end());
        string *pItem = (string*) bsearch(&target, v.data(), v.size(), sizeof(string), compareStrings);
        cout << "sort() + bsearch(), milli-seconds: " << (clock() - timeStart) << endl;
        if(pItem != nullptr) {
            cout << "found, " << *pItem << endl;
        } else {
            cout << "not found! " << endl;
        }
    }
    
}
} // namespace testVector

int main() {
    // testArray::testArray();
    testVector::testVector();
    return 0;
}