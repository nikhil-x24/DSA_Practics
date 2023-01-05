#include<iostream>
using namespace std;

void reverse(int n, int& sum){

    //base case
    if(n == 0){
        cout << sum <<endl;
        return;
    }

    //Processing
    int digit = n % 10;
    sum = sum * 10 + digit;
    n = n/10;

    //RR
    reverse(n, sum);
    
}

int main(){
    int sum = 0;
    reverse(1234, sum);
}