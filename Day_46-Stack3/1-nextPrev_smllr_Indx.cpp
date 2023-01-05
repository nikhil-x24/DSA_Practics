#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
    
vector<int> prevSmaller(vector<int> arr, int n) {

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}

int main(){

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    int n = arr.size();
    vector<int> prevAns = prevSmaller(arr, n);
    vector<int> nextAns = nextSmaller(arr, n);

    cout <<"Printing NEXT smallar element " << endl;
    for(int i = 0; i < nextAns.size(); i++){
        cout << nextAns[i] <<" ";
    }
    cout <<endl;

    cout <<"Printing PREV smallar element " << endl;
    for(int i = 0; i < prevAns.size(); i++){
        cout << prevAns[i] <<" ";
    }
    cout <<endl;
}