#include<iostream>
using namespace std;

void transpose(int arr[3][3], int row, int col){
    for(int i = 0; i < row; i++){
        
        for(int j = 0; j < i; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void reverse(int arr[3][3], int row, int col){
    for(int i = 0; i < row; i++){

        int s = 0;
        int e = col-1;
        while(s < e){
            swap(arr[i][s++], arr[i][e--]);
        }
    }
}

void printFun(int arr[3][3]){
   //print
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            cout <<arr[i][j] <<" ";
        }
        cout <<endl;
    }
}

int main(){
    int arr[3][3]= {1,2,3,4,5,6,7,8,9};

    cout <<"Given array " << endl;
    printFun (arr);
    cout <<endl;
 
    cout <<"Transpose array " <<endl;
    transpose(arr, 3, 3);
    printFun(arr);
    cout <<endl;
    
    
    cout <<"Roated array " << endl;
    reverse(arr, 3, 3);
    printFun(arr);
    
}