#include<iostream>
#include<queue>
using namespace std;

int getKthLargestElement(int arr[], int n, int k) {
    //minHeap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    //process first k element
    for(int i=0; i<k; i++) {
        minHeap.push(arr[i]);
    }

    //process remaining element
    for(int i=k; i<n; i++) {
        if(arr[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}

int main() {
    
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout << "Kth Largest Element is : ";
    cout << getKthLargestElement(arr, n, k) << endl;

    return 0;
}