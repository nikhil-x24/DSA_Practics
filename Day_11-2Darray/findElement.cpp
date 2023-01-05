#include<iostream>
using namespace std;

     //atleast column ki value dena hi hoga
bool search(int arr[][3], int trg, int row, int col){

    for(int i = 0; i <row; i++){
        
        for(int j = 0; j < col; j++){
            if(arr[i][j] == trg){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[3] [3] = {1,2,3,4,5,6,7,8,9};
    int trg = 15;
    cout << search(arr, trg, 3, 3);
}