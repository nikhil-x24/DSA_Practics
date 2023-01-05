#include <iostream>
using namespace std;

int sum(int a, int b, int c = 0) {   //here,c is the default argument
    return a + b + c;
}

int main() {
    int a = 2, b = 3, c = 4;
    cout << sum(a, b) << endl;    // here c will automatically be taken as 0
    cout << sum(a, b, c) << endl; 
    // as the value of c is provided, the value of c will be 4
    return 0;
}