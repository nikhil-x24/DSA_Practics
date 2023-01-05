#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int median = 0;
    for(int i = 0; i<n; i++){
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int signum(int a, int b){
    if(a == b)
        return 0;
    else if(a > b)
        return 1;
    else
        return -1;
}

void callMedian(int element, priority_queue<int> &maxi, 
                priority_queue<int, vector <int>, greater<int>> & min, int &median){
                    switch(signum(maxi.size(), mini.size() ) ){
                        case 0: if(element > median){
                                    mini.push(element);
                                    median = mini.top();
                                }
                                else{
                                    maxi.push(element);
                                    median = maxi.top();
                                }
                                break;

                        case 1: if(element)
                    }
                }

void printMedian(int A[], int size){
    int m = 0; // effective median
    Heap *left  = new MaxHeap();
    Heap *right = new MinHeap();
 
    for(int i = 0; i < size; i++){
        m = getMedian(A[i], m, *left, *right);
 
        cout << m << endl;
    }
 
    // C++ more flexible, ensure no leaks
    delete left;
    delete right;
}

int main(){
    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = ARRAY_SIZE(A);
 
    printMedian(A, size);
 
    return 0;
}