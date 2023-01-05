#include <iostream>
using namespace std;

void insertion(int arr[], int n){
    for(int i = 1; i <n; i++){           
        int temp = arr[i];
        //global var
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j -1;
        }
    arr[j+1] = temp; 
    }
}

//print function
void print(int *arr, int n){
    for(int i = 0; i <n; i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    int arr[] = {6562, 4654, 5, 7};
    insertion(arr, 4);
    print(arr, 4);
}