#include<iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k) {
    //maxHeap
    priority_queue<int> pq;

    //process first k element
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }

    //process remaining element         
    for(int i=k; i < n; i++) {             // <= in maxHeap
        if(arr[i] < pq.top()) {            //<
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {
    
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout << "Kth Smallest Element is : ";
    cout << getKthSmallestElement(arr, n, k) << endl;

    return 0;
}