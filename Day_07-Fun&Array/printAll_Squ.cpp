//print square till to n
#include<iostream>
using namespace std;

void print_squ(int n){
    for(int i = 1; i <=n; i++){
        cout << i * i <<endl;
    }
}

int main(){
    int n = 8;
    print_squ(n);
    return 0 ;
}