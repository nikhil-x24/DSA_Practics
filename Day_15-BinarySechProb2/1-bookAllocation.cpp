#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid){
    int stdcount = 1;
    int pageSum = 0;

    for(int i = 0; i< n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            stdcount++;
            if(stdcount > m || arr[i] > mid){
                return false;
            }
           // pageSum = 0;
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m){
    int s = 0;

    int sum = 0;
    //sum kro lo
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    // s -> e  (e = sum of all element)

    int mid = s +(e-s) /2;

    while(s <= e){
        if(isPossible(arr, n, m , mid)){
            ans = mid;
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
        mid = s +(e-s) /2;
    }
    return ans;
}

int main(){
    int arr[] = {10, 20 ,30, 40};
    int n = 4;
    int m = 2;
    cout << allocateBooks(arr, n, m);
}