#include<iostream>
using namespace std;

//print Function
void print_arr(int arr[], int size){
    for(int  i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr23[5] = {3, 6, 9, 2, 18};
    print_arr(arr23, 5);   //name -> arr23     size -> 5
    return 0;
}