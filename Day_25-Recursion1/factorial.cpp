#include<iostream>
using namespace std;

int fact(int n){
    
    //base case
    if(n == 1)
        return 1;
        
    //RR
    return n * fact(n-1);
}

int main(){
    int n;
    cout << "Enter Number :";
    cin >> n;
    cout << "Factorial is : " <<fact(n);
}