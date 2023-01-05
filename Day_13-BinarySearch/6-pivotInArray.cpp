/*
pivot -> {1,2,3,7,9}; sorted
1- rotate -> {7,9,1,2,3};  => 1 is pivot - > graph me 1 sbse km hai
*/

#include<iostream>
using namespace std;

int pivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s) /2;
    
    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s+(e-s) /2;
    }
    return s;

}

int main(){
    int arr[] = {8, 10, 17, 1, 3};
    int n = 5;
    cout << "Pivot element Index is: " << pivot(arr, n);
}