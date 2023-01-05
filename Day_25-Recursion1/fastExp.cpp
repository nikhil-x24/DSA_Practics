#include<iostream>
using namespace std;

int exp(int n){
    //base case
    if(n == 0)
        return 1;
    
    int chotiProb = exp(n/2);

    //check odd or even
    if(n & 1)  //odd
        return chotiProb * chotiProb * 2;
    else
        return chotiProb * chotiProb;
}

int main(){
    int n;
    cout << "Enter no. -> ";
    cin >> n;
    cout <<"Ans is : " <<exp(n);
}