#include<iostream>
using namespace std;

int optimalGame(int arr[], int i, int j){
    if(i > j)
        return 0;
    
    int choice1 = arr[i] + min(optimalGame(arr, i+2, j), 
                               optimalGame(arr, i+1, j-1));
                               
    int choice2 = arr[j] + min(optimalGame(arr, i+1, j-1), 
                               optimalGame(arr, i, j-2));

    int ans = max(choice1, choice2);
    return ans;
}

int main(){
    int arr[] = {20, 30, 2, 2, 2, 10};
    int s = 0;
    int e = 5;
    cout << "Ans is : " <<optimalGame(arr, s, e);
}