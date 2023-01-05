#include<iostream>
using namespace std;

void print(int n){
    //base case
    if(n == 0)
        return;
    
    int digit = n %10;
    n = n/10;

    //RR
    print(n);

    //Processing
    cout << digit <<" ";
    
    //print(n)
}

int main(){
    int n = 564;
    print(n);
}