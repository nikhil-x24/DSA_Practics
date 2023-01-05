#include <iostream>
using namespace std;

void selection(int arr[], int n){
    for(int i = 0; i <n; i++){
        //let's assume 1st element is sort then ->
        int minIndex = i;

        //find Min element i+1 -> se check kro
        for(int j = i+1; j < n; j++){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void print(int *arr, int n){
    for(int i = 0; i <n; i++){
        cout << arr[i] <<" ";
    }
}
int main() {
    int arr[] = {652, 464, 5, 7};
    selection(arr, 4);
    print(arr, 4);
}