//Find Maximum and Minumum Element in array

#include<iostream>
#include<limits.h>
using namespace std;
int getMaximum(int arr[], int n){

    int ans = INT_MIN;   //int ans = arr[0];
    for(int i = 0; i < n; i++){
        ans = max(ans, arr[i]);
    }
    return ans;
}

int getMinumum(int arr[], int n){

    int ans = INT_MAX;   
    for(int i = 0; i < n; i++){
        ans = min(ans, arr[i]);
    }
    return ans;
}
int main(){
    int arr[] = {-3, -12, 75, 18, 17, 16};
    cout <<"Maximum element is : " << getMaximum(arr, 6) <<endl;
    cout <<"Minumum element is : " << getMinumum(arr, 6);
}