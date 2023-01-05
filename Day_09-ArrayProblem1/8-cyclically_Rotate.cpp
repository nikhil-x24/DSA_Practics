#include<iostream>
using namespace std;

void roatate(int *arr, int n){

    //store last element in temp variable
    int temp = arr[n-1];

    for(int i = n-1; i > 0; i--){   
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main(){
    int arr[] = {1, 2 ,3 , 4 ,5};
    int n =  5;
    roatate(arr, n);
    cout << "After Roation : ";
    for(int i = 0; i < n ; i++){
        cout << arr[i] <<" ";
    }
}