//find factorial of largest no.
#include<iostream>
using namespace std;

int multiply(int n, int ans[], int ansSize){
    int carry = 0;
    for(int i = 0; i < ansSize; i++){
        int val = n * ans[i] + carry;
        //cout <<" Val  is " <<val <<endl;
        int digit = val % 10;

        ans[i] = digit;
        carry = val/10;
    }
    //cout <<"Outside for loop " <<endl;
    while(carry != 0){
        int digit = carry % 10;
        ans[ansSize] = digit;
        ansSize++;
        carry = carry/10;
    }
    return ansSize;
}

void Factorial(int n){
    int ans[100000] = {1};
    int ansSize = 1;

    for(int i = 1; i <= n; i++){
        ansSize = multiply(i, ans, ansSize);
    }
    cout << "Printing the answer " <<endl;
    //print
    for(int i = ansSize - 1; i >= 0; i--){
        cout << ans[i] ;
    }
    cout <<endl;
}

int main(){
    Factorial(5);
}