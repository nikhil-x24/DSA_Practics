#include<iostream>
using namespace std;
int main(){
    // int b = 10;
    // int *a = &b;
    // cout <<a<<endl;
    char ch = 'a';
    char *ptr = &ch;
    ch++;
    cout <<*ptr;
}
