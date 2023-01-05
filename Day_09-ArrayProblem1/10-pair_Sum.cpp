#include<iostream>
using namespace std;

int pair_sum(int arr[], int n, int trg){
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(arr[i] + arr[j] == trg){
            cout <<"First No. "<< arr[i]  <<endl; 
            cout <<"Second No. " << arr[j];
            break;
        }
        if(arr[i] + arr[j] > trg){
            j--;
        }
        if(arr[i] + arr[j] < trg){
            i++;
        }
    }
    //return 1;
}

int main(){
    // int arr[] = {3, 1, 4, 5, 9, 13, 11};
    int arr[] = {1, 3, 4, 5, 9 ,45, 46};
    int trg = 14;
    int n = 7;
    //sort(arr, arr+n);
    if(pair_sum(arr, n, trg)){
        cout << endl;
        cout << "valid " <<endl;
    }
    else{
        cout << " No valid pair " <<endl;
    }
}