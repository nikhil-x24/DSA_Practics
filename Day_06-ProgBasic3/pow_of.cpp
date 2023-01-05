#include<iostream>
#include<math.h>
using namespace std;

//1st Approach
bool fun1(int n){
    if(n <= 0)
        return false;
    int count = 0;
    while(n != 0){
        if(n & 1){
            count++;
        }
        n = n >>1;
    }
    if(count == 1)
        return true;
    else    
        return false;
}

//2nd Approach
bool fun2(int n){
    if(n <= 0)
        return false;
    int ans = (n & (n-1));
    if(ans == 0)
        return true;
    else
        return false;
}

int main(){
    cout << fun1(16) <<endl;
    cout << fun2(15) <<endl;
}