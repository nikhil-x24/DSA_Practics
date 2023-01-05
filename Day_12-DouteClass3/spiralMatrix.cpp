//sprial matrix print

#include<iostream>                        ////error hai
using namespace std;

int sprial(int arr[3][6], int r, int c){

    int cnt = 0;
    int total = r * c;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = r - 1;
    int endingCol = c - 1;

    while(total--){
        //print staring row
        for(int i = startingCol; i < endingCol; i++){
            cnt++;
            cout << arr[startingRow][i];
        }
        startingRow++;
        cout <<endl;

        //print ending col
        for(int i = startingRow; i < endingRow; i++){
            cnt++;
            cout << arr[i][endingCol];
        }
        endingCol--;
        cout <<endl;

        //print ending row
        for(int i = endingCol; i < startingCol; i++){
            cnt++;
            cout << arr[endingRow][i];
        }
        endingRow--;
        cout <<endl;

        //print ending row
        for(int i = endingRow; i < startingRow; i++){
            cnt++;
            cout << arr[i][startingCol];
        }
        startingCol++;
        cout <<endl;
    }
    cout <<endl;
    //cout <<total;
}

int main(){
    int matix[3][6] = {{1,2,3,4,5,6},
                        {7,8,9,10,11,12},
                        {13,14,15,16,17,18}};
    sprial(matix, 3, 6);
   
}