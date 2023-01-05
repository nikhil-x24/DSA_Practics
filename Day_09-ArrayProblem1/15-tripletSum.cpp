#include<iostream>
using namespace std;

/*
Brute Force Approch
*/
int triplet(int arr[], int n, int trg){

    for(int i = 0; i < n; i++){

        for(int j = i+1; j < n; j++){
            
            for(int k = j+1; k < n; k++){

                if(arr[i] + arr[j] + arr[k] == trg){
                    cout << arr[i] <<" " << arr[j] <<" " << arr[k] <<" ";
                }
                i++;
                j++;
                k++;
            }
        }
    }
   return 0;
}

int main(){
    int arr[] ={1, 3, 4, 6, 11, 13};
    cout << triplet(arr, 6, 14);
    // if(triplet(arr, 6, 3)){
    //     cout << "Found ";
    // }
    // else{
    //     cout << "Not Found ";
    // }
}