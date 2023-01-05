#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {

    //taking first element as pivot 
    int pivot = arr[s];

    //count smaller elements
    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <= pivot)
            cnt++;
    }

    //find right place for pivot
    int pivotIndex = s + cnt;

    //swap
    swap(arr[pivotIndex], arr[s]);

    //handle left and rtight
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {

        //already smaller element in left side
        while(arr[i] <= pivot) {
            i++;
        }

        //already greater element in right side
        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    //base case
    if(s >= e) 
        return;

    int pIndex = partition(arr, s, e);

    //left
    quickSort(arr, s, pIndex-1);

    //right
    quickSort(arr, pIndex+1, e);

}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 7, 7};
    int size = 8;

    quickSort(arr, 0, size-1);
    cout << "Sorted Element : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    return 0;
}