#include<iostream>
using namespace std;

int find(int num){
    int mask = 0;
    while(mask < num){
        //left Shift or + (add) 1
        mask = (mask << 1) | 1;
    }
    int ans = (~num) & mask;
    return ans;
}

int main(){
    int n = 10;
    cout << endl;
    cout << "Complement Of " <<n <<" is : "<<find(n);
}