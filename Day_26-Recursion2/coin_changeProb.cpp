#include<iostream>
using namespace std;

int solve(int coin[], int n, int amount, int currentCoin){

    cout <<"Call recieved for amount " << amount 
         << " And currentCoin is " << currentCoin <<endl;

    //base case
    if(amount == 0){
        cout << "Base case reched -> returning 1 " ;
        return 1;
    }
    if(amount < 0){
        cout << "Base case reched -> returning 0 " <<endl;
        return 0;
    }
    
    int ways = 0;
    //use every coin
    for(int i = currentCoin; i < n; i++){
        //RR
        //niche ke done way to + kr ke upr dedo
        int ans = solve(coin, n, amount - coin[i], i);
        cout <<endl;
        cout << "\nFor i = " <<i << " ans is " << ans << endl;
        ways += ans;
    }
    cout << "Outside for loop, value of ways is " << ways <<endl;

    return ways;
}

int main(){
    int coin[] = {1, 2};
    int amount = 4;
    int size = 2;
    int ans = solve(coin, size, amount, 0);
    cout << ans <<endl;
}