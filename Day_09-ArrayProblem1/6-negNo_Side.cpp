//move all neg. no. to move one side

#include<iostream>
using namespace std;

void move(int arr[], int n){
    int j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[] = {-3, 5, 2, -4, -6, 5};
    move(arr, 6);
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
}