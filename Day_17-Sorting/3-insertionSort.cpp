#include <iostream>
using namespace std;
                                              //wrong hai
int in(int arr[], int n){
    for(int i = 1; i <n; i++){ 

        int temp = arr[i];
        int j = i-1;
        for(; j >= 0; j++){    //n-i-1
            if(arr[j] > temp){
                arr[j+1] = temp;
            }
            else{
                break;
            }
        }  
        arr[j+1] = temp;
    }
    return -1;
}

//print function
void print(int *arr, int n){
    for(int i = 0; i <n; i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    int arr[] = {62, 44, 5, 7};
    in(arr, 4);
    print(arr, 4);
}