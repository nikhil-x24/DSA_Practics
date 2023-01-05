#include<iostream>
using namespace std;

long long merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    long long inv = 0;
    //divide ke bd arr 2 part me hai 
    int leftlength = mid - s+1;
    int rightlength = e - mid;

    //crete dynamic array of left and right part
    int *left = new int[leftlength];
    int *right = new int[rightlength];

    //copy into left part
    int orignalIndex = s;
    for(int i = 0; i < leftlength; i++){
        left[i] = arr[orignalIndex++];
    }

    //copy into right part
    orignalIndex = mid+1;
    for(int i = 0; i < rightlength; i++){
        right[i] = arr[orignalIndex++];
    }

    //Now we have sorted 2 array
    //we have to merge them
    int leftIndex = 0;
    int rightIndex = 0;
    orignalIndex = s;

    //compare element from left and right array and copy into array
    while(leftIndex < leftlength  &&  rightIndex < rightlength){
        if(left[leftIndex] <= right[rightIndex]){
            arr[orignalIndex++] = left[leftIndex++];
        }
        else{
            arr[orignalIndex++] = right[rightIndex++];
            inv += leftlength - leftIndex;
        }
    }

    //check if any more element is present in left array
    //then copy it to orignal array
    while(leftIndex < leftlength){
        arr[orignalIndex++] = left[leftIndex++];
    }

    //check if any more element is present in right array
    //then copy it to orignal array
    while(rightIndex < rightlength){
        arr[orignalIndex++] = right[rightIndex++];
    }
    return inv;
}

long long mergeSort(int *arr, int s, int e){

    long long inv = 0;
    if(s < e){  
        int mid = (s + e) /2;

        //leftPart   -RR
        inv += mergeSort(arr, s, mid);
        //rightpart  -RR
        inv += mergeSort(arr, mid+1, e);
        //merge 2 sorted part
        inv += merge(arr, s, e);
    }
    return inv;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }
    cout << mergeSort(arr, 0, n-1);
    cout <<endl;
    return 0;
}