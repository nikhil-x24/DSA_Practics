//   ( lastIndex - firstIndex ) + 1 
#include<iostream>
using namespace std;

int FirstOcc(int arr[], int n, int k){
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid = s + (e-s) / 2;
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
    int arr[] = {1, 2, 3, 3, 4, 4, 4};  //array must be sorted
    int n = 7;
    int k;
    cout << "Enter th evalue of k : ";
    cin>> k;
    int first = FirstOcc(arr, n, k);
    int second = LastOcc(arr, n, k);
    int ttOcc =( second - first ) + 1;
    cout <<ttOcc << endl;
}
