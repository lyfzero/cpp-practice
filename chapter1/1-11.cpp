#include<iostream>
using namespace std;
int main() {
    int a, b;
    cout << "input two numbers:" << endl;
    cin >> a >> b;
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    cout << "numbers between " << a << " and " << b << " : " << endl;
    for(int i = a; i <= b; i++) {
        cout << i << endl;
    }
    return 0;
}