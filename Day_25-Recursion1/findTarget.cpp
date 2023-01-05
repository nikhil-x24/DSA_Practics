#include<iostream>
using namespace std;

int fun(int arr[], int size, int x){

    int n = size - 1;
    
    if(arr[n] == x)
        return n;
    if(n < 0)
        return -1;

    return fun(arr, n, x);
}

int main(){
    int arr[] = {2, 5, 8, 75, 1};
    int size = 5;
    int x = 5;   //target
    int idx = fun(arr, size, x);

    if(idx != -1){
        cout << "Element " << x  <<" is present at index " << idx;
    }
    else{
        cout << "Element " << x  <<" is not present in array ";
    }
    return 0;
}