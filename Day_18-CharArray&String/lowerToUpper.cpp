#include<iostream>
using namespace std;

char toLowerCase(int ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main(){
    cout << toLowerCase('B') <<endl;;
    cout << toLowerCase('b');
}