#include<iostream>
using namespace std;
int main(){

    //staic
    int i = 5;
    int &j = i;

    cout << i <<endl;
    i++;
    cout << j <<endl;
    j++;
    cout << i <<endl <<endl; 

    //dynamic
    cout <<"DYNAMIC ALLOCATION  " <<endl;
    int n;
    cout << "Enter the size of array ";
    cin >> n;
    int *arr = new int[n];

    //input
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    //print
    for(int i = 0; i<n; i++){
        cout << arr[i]  << " ";
    }
    //deleting of memeory
    delete[] arr;
}