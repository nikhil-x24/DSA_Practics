#include<iostream>
using namespace std;
int main(){
    char cha = 'a';
    char *ptr = &cha;
    cout << ptr <<endl;
    cout <<*ptr <<endl <<endl;

    char ch[] = "abcd";
    char *p = ch;
    cout <<p <<endl;
    cout << *p <<endl;
}