#include<iostream>
#include<vector>
using namespace std;

int soe(int n){
    int cnt = 0;

    //sare no. of intially prime make
    vector<bool>prime(n + 1, true);

    //0 and 1 ko non prime
    prime[0] = prime[1] = false;

    //table via non prime mark
    for(int i = 2; i <n; i++){  
        if(prime[i])
            cnt++;
        
        //table wise marking
        for(int j = 2*i; j<n; j=j+i){
            prime[j] = 0;     //false mark
        }
    }
    cout <<"Count of prime no is : ";
    return cnt;
}

int main(){
    int n;
    cout << "Enter no. ";
    cin>> n;
    cout << soe(n);
}