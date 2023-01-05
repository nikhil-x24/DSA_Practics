 /*

     *
    * *
   *   *
  ******* 

*/

#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int row, col;
    for(int row = 1; row <= n; row++){
        for(int col =row; col <= n; col++)
                cout << " ";
        for(int col =1; col <= 2*row-1; col++){
            if(col == 1 || col == 2*row-1 || row == n)
                cout <<"*";
            else 
                cout << " ";
        }
        if(row == n){
            if(col == row +2)
                cout <<"*";
        }
        cout <<endl;
    }       
        }
    
        
