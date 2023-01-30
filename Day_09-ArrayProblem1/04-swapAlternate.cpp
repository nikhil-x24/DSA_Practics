#include<iostream>
using namespace std;

void swapAlt(int arr[], int n){
    int i = 0;
    while(i < n){
        if(i+1 < n){
            swap(arr[i], arr[i+1]);
        }
        i = i+2;
    }
}

int main(){
    int arr[] = {4, 71, 9, 58, 12, 102};
    swapAlt(arr, 6);
    //print
    for(int i = 0; i < 6 ; i++){
        cout <<arr[i] <<" ";
    }
}