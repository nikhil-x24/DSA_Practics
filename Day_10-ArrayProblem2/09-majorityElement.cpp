#include<iostream>
#include<unordered_map>
using namespace std;

int majority(int arr[], int n){
    //mapping create
    unordered_map<int, int> freq;
    for(int i = 0; i <n; i++){
        freq[arr[i]]++;
    }

    for(int i= 0; i<n; i++){
        int value = freq[arr[i]];
        if(value > n/2)
            return arr[i];
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,3,3};      // n=6 -> n/2 -> 3
    cout << majority(arr, 6) <<endl;
}
