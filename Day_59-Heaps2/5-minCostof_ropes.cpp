#include<iostream>
#include<queue>
using namespace std;

int getMinCostRopes(int arr[], int n) {
    //initialise cost with 0
    int cost = 0;

    //create a min heap
    priority_queue<int, vector<int>, greater<int> > minHeap;

    //insert all array elements into min heap
    for(int i=0; i<n; i++) {
        minHeap.push(arr[i]);
    }

    while(minHeap.size() > 1) {
        //fetch 2 min elements and put their sum in cost 
        //and put element back in minHeap
        int first = minHeap.top();
        minHeap.pop();

        int second = minHeap.top();
        minHeap.pop();

        int sum = first + second;

        cost += sum;
        minHeap.push(sum);

    }
    return cost;
}

int main() {

    int arr[] = {4,3,2,6};
    int n = 4;
    cout << "Cost is " << getMinCostRopes(arr, n) << endl;

    return 0;
}