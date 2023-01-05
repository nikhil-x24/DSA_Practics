//find duplicate in an array of n+1 integer
#include<iostream>
using namespace std;

int duplicate(int arr[], int n){

    //sum of given all number in array
    int sum1 = 0;
    for(int i = 0; i <=n; i++){
        sum1 = sum1 + arr[i];
    }
    cout <<"Value of Sum1: "<< sum1 <<endl;

    //total no. of sum all number
    int sum2 = n * (n+1) / 2;
    cout <<"Value of Sum2: "<< sum2 <<endl;

    //substration   or -> Cross
    int ans = sum1 - sum2;
    cout << "Duplicate Element is : ";
    return ans;
}

int main(){
    int arr[] = { 1, 2, 3, 4, 4, 5, 6};
    cout << duplicate(arr, 6);
}