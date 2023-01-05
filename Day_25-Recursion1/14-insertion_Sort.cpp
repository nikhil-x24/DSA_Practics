#include<iostream>
#include<vector>
using namespace std;

void RR_InsertionSort(vector<int>& arr, int n){
    //base case
    if(n <= 1)
        return;
  
    // Sort first n-1 elements
    RR_InsertionSort( arr, n-1 );
  
    // Insert last element at its correct position
    int last = arr[n-1];
    int j = n-2;
  
    while (j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;    
}

//print function
    void print(vector<int> &arr, int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }

int main(){
    vector<int> arr;

    //input_Array
    cout <<"Enter the size of arr  " <<endl;
    int size;
    cin >> size;
    for(int i = 0; i <size; i++){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    RR_InsertionSort(arr, size);
    print(arr, size);

}