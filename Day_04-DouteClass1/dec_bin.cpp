#include<iostream>
#include<math.h>
using namespace std;
//Decimal to Binary
int main(){
    int n = 11;
    int i = 0, ans = 0;
    
    while(n != 0){
        int bit = n & 1;   //odd
        //cout << bit <<endl;
        ans = (bit * pow (10,i) + ans);
        n = n>>1; // n = n/2;
        i++;
    }
    cout <<endl;
    cout << "In Binary: " <<ans;
}