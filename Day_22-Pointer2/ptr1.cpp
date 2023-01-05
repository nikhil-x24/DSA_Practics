#include<iostream>
using namespace std;
int main(){
    int a = 5;
    int *p = &a;
    int **q = &p;

    cout << &a <<endl;          //address of a
    cout << a <<endl <<endl;    //value of a
    //cout << *a;               // error kyu ki a ek variable hai pointer nhi

    cout << &p <<endl;          //address of p
    cout << p <<endl;           //address of a
    cout << *p <<endl <<endl;   //value of store pointer by p

    cout << &q <<endl;          //address of q
    cout << q <<endl;           //address of p
    cout << *q <<endl;          //address of store pointer by q
    cout << **q <<endl <<endl;  //value of store pointer by **q -> a
}