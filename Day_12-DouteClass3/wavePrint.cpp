#include<iostream>
using namespace std;

void wavePrint(int arr[4][4], int row, int col){

    for(int j = 0; j < row; j++){

        if(j % 2 == 0){
            for(int i = 0; i < col; i++){
                cout << arr[i][j]<<" ";
            }
            cout <<endl;
        }
        else{
            for(int i = col-1; i >= 0; i--){
                cout << arr[i][j] <<" ";
            }
            cout <<endl;
        }
    }
}

int main(){
    int are[4][4] = {{11, 15 ,18, 17},
                     {12, 41, 42, 32},
                     {49, 22, 11, 91},
                     {17, 31, 58, 87}};
    wavePrint(are, 4, 4 );
}