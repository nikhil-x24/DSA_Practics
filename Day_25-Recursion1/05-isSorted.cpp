#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    //base cas
    if(size == 0 || size == 1)   
        return 1;

    if(arr[0] > arr[1])     //sorted nhi hai
        return false;

        //RR
    else{
        bool ans = isSorted(arr + 1, size - 1);
        return ans;
    }
}

int main(){
    int arr[] = {2, 2, 3, 4, 5};
    int size = 5;
    int ans = isSorted(arr, size);
    if(ans)
        cout << "Array is sorted " <<endl;
    else
        cout << "Array is not sorted " <<endl;
}