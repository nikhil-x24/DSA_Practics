#include<iostream>
using namespace std;

//F(n) = F(n-1) + F(n-2)

int fib(int n){

    //base case
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    //RR
    int ans = fib(n-1) + fib(n-2);
    return ans;                              //In RR return is mandatory
}

int main(){
    int n = 5;
    cout << fib(n);
}