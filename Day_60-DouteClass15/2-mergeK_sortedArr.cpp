#include<iostream>
#include<queue>
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

vector<int> mergeKSortedArrays(vector<vector<int> > arr, int k ) {

    int n = arr[0].size();

    priority_queue<Info*, vector<Info*>, Cmp > minheap;
    vector<int> ans;

    //step1: put the first element fo all rows into the heap
    for(int i=0; i<k; i++) {
        int element = arr[i][0];
        Info* temp= new Info(element, i,0);
        minheap.push(temp);
    }

    while(minheap.size() > 0) {
        //fetch top element
        Info* temp = minheap.top();
        minheap.pop();

        //ans push
        ans.push_back(temp->data);

        //check if next element exist , if yes then push in heap
        if(temp->col + 1 < n) {
            Info* toPush= new Info(arr[temp->row][temp->col+1], temp->row, temp->col+1);
            minheap.push(toPush);
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > arr(3, vector<int>(4,0));

    arr[0][0] = 1;
    arr[0][1] = 3;
    arr[0][2] = 5;
    arr[0][3] = 7;

    arr[1][0] = 2;
    arr[1][1] = 4;
    arr[1][2] = 6;
    arr[1][3] = 8;

    arr[2][0] = 0;
    arr[2][1] = 9;
    arr[2][2] = 10;
    arr[2][3] = 11;

    vector<int> ans = mergeKSortedArrays(arr, 3);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
