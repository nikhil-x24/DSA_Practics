#include<iostream>
using namespace std;

void print(int arr[], int s,int e){
    //cout << "Size of array is " << n <<endl;

    for(int i = s; i <= e; i++){
        cout << arr[i] << " " ;
    }
    cout <<endl;
}

bool binary(int arr[], int s, int e, int k){

    //print
    print(arr, s, e);

    int mid = s + (e-s) /2;
    cout << "Value of mid is " << arr[mid] <<endl;
    //base case

    //element not found
    if(s > e)
        return false;
    //element found
    if(arr[mid] == k)
        return true;
    
    //RR
    if(arr[mid] < k){
        return binary(arr, mid+1, e, k);
    }
    else{
        return binary(arr, s, mid-1, k);
    }
}

int main(){
    int arr[] = {5,6,7,6,42};
    int size = 5;
    int k = 42;
    bool ans = binary(arr, 0, 4, k);

    if(ans){
        cout << "Present " <<endl;
    }
    else{
        cout << "Absent " <<endl;
    }
}