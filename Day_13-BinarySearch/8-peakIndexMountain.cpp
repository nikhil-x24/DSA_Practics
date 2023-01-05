//peak index in array

#include<iostream>
using namespace std;

int peak(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s) /2;

    while(s < e){
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid;     //mid -1 nhi kr skte kyu ki wo galt hi jye ga
        }
        mid = s+(e-s) /2;
    }
    return s;
}

int main(){
    int arr[] = {0, 2, 5, 2};
    int n = 4;
    int ans = peak(arr, n);
    cout << "Peak element is: " <<ans;

}