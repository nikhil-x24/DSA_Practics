#include<iostream>
using namespace std;

int pivotelement(int arr[], int n){
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

int binSer(int arr[], int st, int en, int k){
    int s = st;
    int e = en;
    int mid = s+(e-s)/2;        //int range 2^31 - 1
    while(s <= e){
    
        if(arr[mid] == k)
            return mid;
        
        if(arr[mid] > k)
            e = mid - 1;
        
        else if(arr[mid] < k)
            s = mid + 1;
        
        mid = s+(e-s)/2;
    }
    // mid iss liye update kiya gya hai kyu ki
    // jb start AUR end update kiya hai to mid ko update krna hoga na......
    return -1;
}

int findPostion(int arr[], int n, int k){
    int pivot = pivotelement(arr, n);

    //BS in secind part
    if(k >= arr[pivot] && k <= arr[n-1]){
        return binSer(arr, pivot, n-1, k);
    }
    //BS in first part
    else{
        return binSer(arr, 0, pivot -1, k);
    }
}

int main(){
    int arr[] = {8, 10, 17, 1, 3};
    int n = 5;
    int k = 17;
    cout << findPostion(arr, n, k);
    
}