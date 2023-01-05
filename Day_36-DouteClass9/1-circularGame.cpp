#include<iostream>
using namespace std;

int findTheWinner(int n, int k) {
    //base case
    if(n == 1)
        return 1;
        
    return (findTheWinner(n-1, k) + k-1 ) %n + 1;
}

int main(){

    int n = 5;
    int k = 2;
    cout << findTheWinner(n, k);
}