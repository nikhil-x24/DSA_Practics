#include<iostream>
#include<vector>
using namespace std;

void RR_BubbleSort(vector<int>& arr, int n){
    //base case
    if(n == 0 || n == 1)
        return;
    
    //1 case solve kr diya-> largest element last me ho jye ga
    for(int i = 0; i< n-1; i++){
        if(arr[i] > arr[i+1]){
             swap(arr[i], arr[i+1]);
          }
    }
    //RR
    RR_BubbleSort(arr, n-1);
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

    RR_BubbleSort(arr, size);
    print(arr, size);

}