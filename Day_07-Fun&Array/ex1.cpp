#include<iostream>
using namespace std;
void r(int n){
    cout <<"Rahul " << n <<endl;
    n++;
    cout << n;
    cout <<endl;
}
int main(){
    int n = 5;
    r(n);
    cout << n;
    return 0;
}