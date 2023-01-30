#include<iostream>
#include<queue>
using namespace std;

void solve(vector<int> &v, vector<int> &ans, int k){
    //step1 -> create
    queue<int> q;   //deque<int> q;

    //step2 -> first window
    for(int i = 0; i<k; i++){
        if(v[i] < 0)  //neg no. store
            q.push(i);  //q.push_back(i)
    }

    //step3 -> ans save
    if(q.size() > 0) 
        ans.push_back(v[q.front()]);
    else
        ans.push_back(0);  //nhi to 0 push kro

    //step4 -> remaning window
    for(int i = k; i< v.size(); i++){
        if(!q.empty()  && i - q.front() >= k){
            q.pop();   //q.pop_front()
        }
        //push in queue
        if(v[i] < 0){
            q.push(i);   //q.push_back(i)
        }
        //ans store
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(v[q.front()]);
        }
    }
}

int main(){

    vector<int> v;
    v.push_back(-8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-6);
    v.push_back(10);

    int k = 2;
    vector<int> ans;
    solve(v, ans, k);

    cout <<"Printing answer" <<endl;
    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << " ";
    }cout <<endl;
    
}