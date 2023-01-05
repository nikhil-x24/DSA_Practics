#include<iostream>
using namespace std;

int minSwap(int arr[], int size, int k){
    int cnt = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] <= k){
            cnt++;
        }
    }

    int bad = 0;
    for(int i = 0; i < cnt; i++){
        if(arr[i] > k){
            bad++;
        }
    }

    //check for remaining window
    int ans = bad;
    for(int i = 0, j = cnt; j < size; i++, j++){
        //check old
        if(arr[i] > k)
            bad--;
        if(arr[j] > k)
            bad++;
        ans = min(ans, bad);
    }
    return ans;
}

int main(){
    int arr[] = {2,1,5,6,3};
    cout <<minSwap(arr, 5, 3);
}