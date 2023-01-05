#include<iostream>
using namespace std;
int main(){
    //Swap using +, -
    int a = 5, b = 7;
    cout <<"Before Frist : " << a <<" " << b  <<endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout <<"Frist : " << a <<" " << b <<endl <<endl;

    //Swap using temp Variable
    int c = 10, d = 15;
    cout <<"Before Second : " << c <<" " << d <<endl;
    int temp;
    temp = c;
    c = d;
    d = temp;
    cout << "Second : " << c <<" "<< d <<endl <<endl;

    //Swap using XOR gate
    int e = 101, f = 225;
    cout <<"Before Third : " << e <<" " << f  <<endl;
    e = e ^ f;
    f = e ^ f;
    e = e ^ f;
    cout <<"Third : " << e <<" " << f <<endl <<endl;
}