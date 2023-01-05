#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallar(vector<int> arr){
    stack<int> s;
    s.push(-1);
    
    int n = arr.size();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
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
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(2);

    vector<int> ans = prevSmallar(arr);

    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}