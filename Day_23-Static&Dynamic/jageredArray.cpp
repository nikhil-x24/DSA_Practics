#include<iostream>
using namespace std;
int main(){
    int n, m;
    cout <<"Enter the value of row & col: ";
    cin >> n;
    cin >> m;
    int **arr = new int *[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int [sizeof(i)];
    }
    //input
    for(int i = 0; i<m; i++){
        for(int j = 0; j <n; j++){
            cin >> arr[i][j];
        }
    }
    //print
    cout <<endl <<"Print 2D array ";
    for(int i = 0; i < m; i++){  
        cout <<endl;
        for(int j = 0; j < n; j++){
            cout << arr[i][j] <<" ";
        }
    }
    cout <<endl;
    //delete
    for(int i = 0; i<m; i++){
        delete[] arr[i];
    }
    delete[] arr;
}