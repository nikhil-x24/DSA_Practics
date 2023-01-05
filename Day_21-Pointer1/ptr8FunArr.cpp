#include<iostream>
using namespace std;

void dummy(int *arr, int n){
    cout <<sizeof(arr) <<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};   //5 X 4 byte of interger
    dummy(arr,5);
    cout<< sizeof(arr);
}