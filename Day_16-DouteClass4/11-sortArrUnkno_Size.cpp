//code for find element in a sorted array of unknown size
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int s, int e, int target) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target)
            return mid;
        if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
        mid = s + (e-s)/2;    
    }
    return -1;
}

//we dont know the size of array, 
// considering it infinite as per question
//assumption array size if infinite, so no Index Out of Bound Exception
int findPosition(int arr[], int target) {
    int s = 0, e = 1;
    int val = arr[s];

    while(val < target) {
        s = e;
        e = 2*e;
        val = arr[e];
    }

    return binarySearch(arr, s, e, target);
}

int main() {
    //infinite array
    int arr[] = {3, 7, 13, 18, 24, 30, 34, 37, 40};
    int target = 37;

    cout<<"Target index is: " << findPosition(arr, target);
    return 0;
}