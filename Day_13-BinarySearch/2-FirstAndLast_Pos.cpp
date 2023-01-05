//find first and last position of element in array
#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int k){

    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    int ans = -1;
    while(s <= e){
        if(arr[mid] == k){
            ans = mid;
            e = mid - 1;
        }   
        else if(k < arr[mid]){   //left me jao
            e = mid - 1;
        }
        else if(k > arr[mid]){  //right me jao
            s = mid + 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}


int LastOcc(int arr[], int n, int k){

    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;

    int ans = -1;
    while(s <= e){
        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }   
        else if(k < arr[mid]){   //left me jao
            e = mid - 1;
        }
        else if(k > arr[mid]){  //right me jao
            s = mid + 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}
int main(){
    int arr[] = {1, 3, 3, 3, 5};
    int n = 5;
    int k = 3;
    cout <<"First Occ is : "<< firstOcc(arr, n, k);
    cout <<endl;
    cout <<"Last Occ is : "<< LastOcc(arr, n, k);
}