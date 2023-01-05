#include<iostream>
using namespace std;

int power(int a, int b){
    //base case
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    
    //RR
    int ans = power(a, b/2);

    //odd
    if(b & 1){
        return ans * ans * a;
    }
    //even
    else{
        return ans * ans;
    }
}

int main(){
    int a, b;
    cout << "Enter No. and Power ";
    cin >> a >> b;
    int ans = power(a, b);
    cout << "Ans is: " << ans <<endl;
}