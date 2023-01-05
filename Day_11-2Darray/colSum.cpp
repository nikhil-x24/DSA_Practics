//print column's vai sum & max column sum print

#include<iostream>
using namespace std;

int colSum(int arr[4][3], int row, int col){
    
    int maxi = INT_MIN;
    
    for(int i = 0; i<row; i++){        //row vai sum  ->   i < col 
        int sum = 0;
        
        for(int j = 0; j < col; j++){      //i < row 
            sum = sum + arr[i][j];
            maxi = max(maxi, sum);
        }
        cout << sum <<" ";   
    }
    cout <<endl <<"Maximum Element is : ";
    return maxi;
}

int main(){
    int arr[4][3] = {{3,7,5}, {5,49,0}, {11,8,1}, {2,0,3}};
    cout << colSum(arr, 4, 3);
}