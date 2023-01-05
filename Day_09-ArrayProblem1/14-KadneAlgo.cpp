//atleast 1 +ve no. -> O(n)
//largest sum continuous subarray

#include<iostream>
using namespace std;

int get_kadane(int arr[], int n){
    int ans = INT_MIN;
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum =sum + arr[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }
    return ans;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << endl;
    cout <<"Largest sum of subarray : " << get_kadane(arr, 7) << endl;

    //print array
    for(int i = 0; i < 7; i++){
        cout << arr[i] <<" ";
    }
}