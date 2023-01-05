#include<iostream>
#include<unordered_map>
using namespace std;

bool checkSubset(int arr1[], int n, int arr2[], int m){
    //mapping
    unordered_map<int, int> freq;

    for(int i = 0; i <n; i++){
        freq[arr1[i]]++;
    }

    //dec
    for(int i = 0; i <m; i++){
        freq[arr2[i]]--;
        
        //check < 0
        if(freq[arr2[i]] < 0)
            return false;
    }
    return true;
}
int main(){
    int arr1[] = {1,3,5,9,10,12,15};
    int n = 7;
    int arr2[] = {365,565,945,13};
    int m = 4;
    cout << checkSubset(arr1, n, arr2, m) <<endl;
}