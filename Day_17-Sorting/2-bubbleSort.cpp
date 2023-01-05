#include <iostream>
#include<vector>
using namespace std;

/*  without optimizations

void bubble(vector<int> &arr, int n){

    for(int i = 0; i <n-1; i++){           //n-1
        //for round 1 to n-1
        for(int j = 0; j < n-i-1; j++){    //n-i-1
            swap(arr[j], arr[j+1]);
        }
    }
}
*/
/*
optimize Bubble sort
*/
void bubbleOpt(vector<int> &arr, int n){
    for(int i = 1; i < n; i++){

        //for round 1 to n-1
        bool swapped = false;

        for(int j = 0; j < n-i; j++){
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false){
            //already sorted
            break;
        }
    }
}
//print function
void print(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr;

    //input_inArray
    cout <<"Enter the size of arr  " <<endl;
    int size;
    cin >> size;
    for(int i = 0; i <size; i++){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    bubbleOpt(arr, size);
    print(arr, size);
    cout <<endl;

    //bubble(arr, size);
    //print(arr, size);
    cout <<endl;
 }



