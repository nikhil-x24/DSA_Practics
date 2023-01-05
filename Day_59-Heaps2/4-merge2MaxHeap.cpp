#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int N, int M){
    // Copy elements of a[] and b[] one by one,  And merged[]
    for (int i = 0; i < N; i++)
        merged[i] = a[i];
    for (int i = 0; i < M; i++)
        merged[N + i] = b[i];
 
    // build heap for the modified array of
    // size n+m
    buildMaxHeap(merged, N + M);
}
 
int main() {

    int a[] = { 10, 5, 6, 2 };
    int b[] = { 12, 7, 9 };
 
    int N = sizeof(a) / sizeof(a[0]);
    int M = sizeof(b) / sizeof(b[0]);
 
    int merged[N + M];
 
    // Function call
    mergeHeaps(merged, a, b, N, M);
 
    for (int i = 0; i < N + M; i++)
        cout << merged[i] << " ";
 
    return 0;
}