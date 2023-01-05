#include<iostream>
#include<math.h>
using namespace std;
//Binary to Decimal
int main(){
    int n = 110;
    int i = 0, ans = 0;

    while(n != 0){
        int digit = n % 10;
        if(digit == 1){
            ans = ans + pow(2,i);
        }
        n = n / 10;
        i++;
    }
    cout <<endl;
    cout <<"In Decimal: " <<ans <<endl;
}