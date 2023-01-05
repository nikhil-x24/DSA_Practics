#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout << "Enter any value ";
    cin >>a >>b;
    char op;
    cout << "enter opertor";
    cin >>op;
    switch(op) {
    case '+' :
        cout << a+b <<endl;
        break;
    case '-' :
        cout << a-b <<endl;
    case '*' :
        cout<< a*b <<endl;
    default:
        cout <<"This is default" <<endl;
    }
}