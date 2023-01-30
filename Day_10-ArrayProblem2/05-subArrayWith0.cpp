//Find subarray with 0 sum in an array
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int arr[] = {4, 2, -3, 1, 6};
    int n = 5;

    //find prefix sum
    vector<int> prefixSum(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        prefixSum[i] = sum;
    }

    unordered_map<int, bool> m;
    for(int i = 0; i <n; i++){
        if (prefixSum[i] == 0){
            cout << "O wala case " <<endl;
            cout << "Zero Sum subarray is present " <<endl;
            break;
        }
        else if(m[prefixSum[i]] == true){
            cout << "same no. wala case " <<endl;
            cout << "Zero sum subarray is present " <<endl;
        }
        else{
            m[prefixSum[i]] = true; 
        }
    }
    for(int i = i; i <n; i++){
        cout  << prefixSum[i] <<" ";
    }
    cout <<endl;

}