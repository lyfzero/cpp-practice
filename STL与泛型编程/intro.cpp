#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;

int main() {
    int ia[6] = {27, 125, 35, 462, 45, 23};
    vector<int, allocator<int>> vi(ia, ia+6);
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
    return 0;
}