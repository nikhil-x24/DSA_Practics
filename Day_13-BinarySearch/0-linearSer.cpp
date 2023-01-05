#include<iostream>
using namespace std;

int linear(int arr[], int n, int k){
    for(int i = 1; i < n; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return n;
}

int main(){
    int arr[] = {1, 45 ,63 ,23 ,88 ,3};
    int n = 6;
    int k = 88;
    cout <<"Index of element is : " <<linear(arr, n, k);

}