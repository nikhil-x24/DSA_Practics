#include<iostream>
using namespace std;
int main(){
    //creating
    int arr1[3][3] = {0};
    int arr2[3][3] = {1};
    int arr3[3][3] = {1,2,3,4,5,6,7,8,9};
    int arr4[4][2] = {{1}, {2,3}, {3,4}, {4,5}};
    //int n = 3;

    for(int i = 0; i <3; i++){
        //entire row
        for(int j = 0; j <3; j++){
            cout <<arr3[i][j] <<" ";
        }
        cout <<endl;
    }
}