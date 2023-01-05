//unique NO. of occurenece ------ LEETCODE
// i/p -> {3,2,2,1,3,3}
// 1 ->1
// 2 ->2
// 3 ->3
//this no. is unique occ 1,2,3,..........

#include<iostream>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        int a[1000] = {0};
        for(int i = 0; i < arr.size(); i++){
            int count = 0;
            if(arr[i] == 1001)  
                continue;
            
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = 1001;
                }
            }
            if(a[count])  return false;
            else  a[count] = 1;
        }
        return true;
    }


int main(){
    vector<int> arr = {3,2,2,1,3,3};
    cout << uniqueOccurrences(arr);
}