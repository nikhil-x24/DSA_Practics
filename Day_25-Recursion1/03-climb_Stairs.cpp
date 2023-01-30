//count ways to reach the N-th stair ->codestudio
#include<iostream>
using namespace std;

int climb(int n){

    //base case
    if(n < 0)                 //n (-ve) me hai to 0 return kro
        return 0;
    if(n == 0)
        return 1;
    
    //RR
    int ans = climb(n-1) + climb(n-2);
    return ans;
}

int main(){
    int n = 3;
    cout << climb(n);
}