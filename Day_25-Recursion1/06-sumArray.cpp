/*   //Brute Force Approach

#include<iostream>
using namespace std;
int sum(int arr[], int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s = s + arr[i];
    }
    return s;
}
int main(){
    int arr[] = {2,3,6,7};
    int size = 4;
    cout << sum(arr, size);
}
  */

#include<iostream>
using namespace std;

int findSum(int arr[], int size){

    //base case
    if(size <= 0)
        return 0;
    
    //RR
    int rm = findSum(arr + 1, size - 1);
    int sum = arr[0] + rm;
    return sum;
}

int main(){
    int arr[] = {2,3,6,7};
    int size = 4;
    cout<< findSum(arr, size);   
}