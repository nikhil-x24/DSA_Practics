#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallar(vector<int> arr){
    stack<int> s;
    s.push(-1);
    
    int n = arr.size();
    vector<int> ans(n);

    for(int i = n-1; i>= 0; i--){
        int item = arr[i];
        while(s.top() >= item){
            s.pop();
        }

        //push in ans
        ans[i] = s.top();
        s.push(item);
    }
    return ans;
}

int main(){

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans = nextSmallar(arr);

    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}