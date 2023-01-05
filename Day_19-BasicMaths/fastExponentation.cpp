#include<iostream>
using namespace std;

int fast(int x, int n){
    int res = 1;
    while(n > 0){
        if(n & 1){
            //odd
            res = res * x;
        }
        x = x * x;
        n = n >> 1; //sme as -> n = n/2
    }
    return res;
}

int main(){
    int ans = 1;
    int a = 2;
    int b = 4;
    cout <<fast(a, b );
}

/*

Brute force       a^b

ans = 1;
for(int i = 0; i< b; i++){
    ans = ans * a;
}

*/