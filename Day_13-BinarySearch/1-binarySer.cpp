#include<iostream>
using namespace std;

int binSer(int arr[], int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;        //int range 2^31 - 1
    while(s <= e){
    
        if(arr[mid] == k)
            return mid;
        
        if(arr[mid] > k)
            e = mid - 1;
        
        else if(arr[mid] < k)
            s = mid + 1;
        
        mid = s+(e-s)/2;
    }
    // mid iss liye update kiya gya hai kyu ki
    // jb start AUR end update kiya hai to mid ko update krna hoga na......
    return -1;
}

int main(){
    int arr[] = {23, 45 ,56 ,57 ,59 ,66};   //sorted
    int n = 6;
    int k = 9;
    cout << endl;
    int index = binSer(arr, n, k);
    cout << "Index is: " << index << endl;

}