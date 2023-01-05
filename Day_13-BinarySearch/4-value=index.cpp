#include<iostream>
using namespace std;

int find(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = (s+e)/2;

    while(s<=e){
        if(arr[mid] == mid){
            return mid;
        }
        if(arr[mid] > mid){
            e = mid -1;
        }
        if(arr[mid] < mid){
            s = mid +1;
        }
        mid = (s+e) /2;
    }
    return -1;
}

int main(){
    cout << endl;
    
    int arr[] = {-10, -5, 0, 2 ,4};
    int n = 4;
    cout << find(arr, n);
}