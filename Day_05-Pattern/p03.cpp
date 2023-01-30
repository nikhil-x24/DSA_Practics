/*

* * * * * 
* * * * 
* * * 
* * 
* 

*/

#include <iostream>
using namespace std;
int main(){
    /*
    int n = 5;
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n-i+1  ; j++){        // if i = 0 then no need to n-i+1  X   -> n-i
            cout << "* ";
        }
        cout << endl;
    }
    */
   int n = 5, counter = 0;
   for(int row = 1; row <= n; row++){
       for(int col = 1; col <= n-counter; col++){
           cout <<"* ";
       }
       counter++;
       cout <<endl;
   }
}