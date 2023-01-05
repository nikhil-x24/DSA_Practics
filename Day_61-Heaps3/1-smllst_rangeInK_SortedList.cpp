#include <bits/stdc++.h>
using namespace std;

class Info {
    public:
    int data;
    int row;
    int col;
    Info() {

    }

    Info(int d, int r, int c) {
        this->data = d;
        this->row = r;
        this->col = c;
    }
};

class Cmp {
    public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;
    }
};

vector<int> solve(vector<vector<int> > arr, int k, int n ) {
        
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Info*, vector<Info*>, Cmp > minHeap; 
    //processs first k elements

    for(int i=0; i<k; i++) {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Info(element, i, 0));
    }

    //for storing answer range
    int start = mini;
    int end = maxi;

    while(!minHeap.empty()) {

        //extract top element or minimum element and pop from heap
        Info* temp = minHeap.top();
        minHeap.pop();
        //save data in mini
        mini  = temp->data;

        //answer update
        if(end - start > maxi - mini ){
            end = maxi;
            start = mini;
        }

        //push next element, and update max
        if(temp->col + 1 < arr[temp->row].size()) {
            Info* toPush = new Info(arr[temp->row][temp->col + 1], 
                                        temp->row, temp->col+1);
            minHeap.push(toPush);
            maxi = max(maxi, toPush->data);
        }
        else {
            break;
        }
    }
    // cout << "Start : " << start << "End : " << end <<endl;
    // return end - start;
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

vector<int> smallestRange(vector<vector<int>>& nums) {
    return solve(nums, nums.size(), 1);
}

int main(){

    vector<vector<int> > arr(3, vector<int>(4, 0));
    arr[0][0] = 4;
    arr[0][1] = 10;
    arr[0][2] = 15;
    arr[0][3] = 24;

    arr[1][0] = 0;
    arr[1][1] = 9;
    arr[1][2] = 12;
    arr[1][3] = 20;

    arr[2][0] = 5;
    arr[2][1] = 18;
    arr[2][2] = 22;
    arr[2][3] = 30;

    vector<int> ans = smallestRange(arr);
 
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << "  ";
    }   
 
    return 0;
}