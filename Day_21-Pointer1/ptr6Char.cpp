#include<iostream>
using namespace std;
int main(){
    char sen[] = "My Name is Nikhil";
    char *ptr = sen;   //here (*ptr  = &sen) == (*ptr  = sen) becoz &sen = sen = &sen[0]
    cout << ptr <<endl;
    cout << *ptr <<endl; // *(ptr + 0) -> p[i] == i[p]
    cout << &ptr <<endl;
}