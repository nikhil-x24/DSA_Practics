#include<iostream>
using namespace std;
int main(){
    //int add = 5;
    //cout << &add;     //address in hexadecimal

     
    int a = 5;
    int *p = &a;

    cout << a <<endl;  //value = 5
    //cout << *a <<endl;  // 'a' ek pointer nhi hai 
    cout << &a <<endl; //address (hexDecimal) 
    cout <<endl;

    cout << p <<endl;
    cout << "  " << p+1 <<endl;

    cout << &p <<endl;
    cout << "  " << *p + 10 <<endl;

    cout << *p <<endl; //value = 5
    cout << *p++ <<endl;   //print then inc
    cout << *++p <<endl;   //print 
    cout << *p <<endl <<endl;  //inc. value garbage

    cout << sizeof(a) <<endl; //size of Integer
    cout <<sizeof(p)<<endl;
    cout << sizeof(*p) <<endl; //why? 

}
         
     
 

