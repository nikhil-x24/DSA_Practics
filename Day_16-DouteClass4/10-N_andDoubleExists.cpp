//code for find N and its Double Problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool binarySearch(vector<int> &arr, int s, int e, int target) {
        //cout << s << " " << e << " " << target << endl;
        int mid = s + (e-s)/2;
        while(s <= e) {
            //cout << "value of mid " << mid << " and target " << target << endl;
            if(target == arr[mid])
                return true;
            
            if(arr[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e-s)/2;
        }
        return false;
    }

bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++) {
            //positive number
            if(arr[i] >= 0 && 
                binarySearch(arr,i+1, arr.size()-1, 2*arr[i]) )
                return true; 
            //negative number
            if( arr[i] < 0 && 
                arr[i]%2 == 0 && 
                binarySearch(arr, i+1, arr.size()-1, arr[i]/2))
                return true;
        }
        return false;
}

int main(){
    vector<int> arr = {10, 3, 5, 2, 7};
    cout <<"No. is present 1 or 0: " <<endl << checkIfExist(arr);
}