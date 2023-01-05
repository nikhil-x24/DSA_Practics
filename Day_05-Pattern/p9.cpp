/*
Hollow Interted Half Pyramid

*********
*      *
*     *
*    *
*   *
*  *
* *
**
*

        */
#include <iostream>
using namespace std;
// Hollow inverted half pyramid
int main(){
    int n = 9;
    for(int row = 1; row <= n; row++){
        //first and last row 
        if(row == 1 || row == n){
            for(int col = 1; col <= n-row+1; col++){
                cout <<"*";
            }
        }
        else{
            cout <<"*";
            //space
            for(int col = 1; col <= n-row-1;col++){
                cout <<" ";
            }
            cout <<"*";
        }
        cout << endl;
    }
        
}