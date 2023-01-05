#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout << "Size of array is " << n <<endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    cout <<endl;
}

bool linear(int *arr, int n, int k){

    //print
    print(arr, n);

    //base case
    if(n == 0)
        return false;
    if(arr[0] == k)
        return true;
    else{  //RR
        bool rm = linear(arr+1, n-1, k);
        return rm;
    }
}

int main(){
    int arr[] = {5,6,7,6,42};
    int size = 5;
    int k = 1;
    bool ans = linear(arr, size, k);

    if(ans)
        cout << "Present " <<endl;
    
    else
        cout << "Absent " <<endl;
    
}