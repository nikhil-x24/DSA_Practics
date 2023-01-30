#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int> &q){
    if(q.empty())
        return;
    
    int element = q.front();
    q.pop();

    reverse(q);
    q.push(element);
}

int main() {

    queue<int> q;
    
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);

    //step1: queue -> stack
    stack<int> s;

    reverse(q);

    //printing
    cout << "printing the queue" << endl;
    while(!q.empty()) {
        cout << q.front( ) << " ";
        q.pop();
    }cout << endl;
    
    return 0;
}