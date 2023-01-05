#include<iostream>
#include<string.h>
using namespace std;
int main(){
    
    //creation
    string st;

    //input 
    cout << "Enter String Here: ";
    //cin >> st;                         //space ke bad nhi lega...
    //isko overcome krne ke liye fun
    getline(cin, st);

    //print
    cout << "String are: " <<st;
}