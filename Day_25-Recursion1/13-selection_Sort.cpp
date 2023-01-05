#include<iostream>
#include<limits.h>
using namespace std;

void RR_SelectionSort(int arr[], int n){

    if(n == 1)
      return;
       
    int mini = INT_MIN;
    int j;
    
    for(int i = 0; i<n; i++){
        mini = min(mini, arr[i]);
    }
    
    for(j = 0; j<n; j++){
        if(arr[j] == mini)
            break;
    }    
    swap(arr[0], arr[j]);   
    
    RR_SelectionSort(arr+1, n-1);
    
}

//print function
void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){

    int arr[] = {23,580,12,424,3};
    int n = 5;

    RR_SelectionSort(arr, n);
    print(arr, n);

}