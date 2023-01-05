#include<iostream>
using namespace std;

bool pll(int arr[], int n){
    int i = 0;
    int j = n-1;
 
    while(i<j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int arr[] = {1, 2, 3, 3, 5, 2, 1};
    cout <<"Check Palindrome or not : "<< pll(arr, 7) <<endl;
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
}