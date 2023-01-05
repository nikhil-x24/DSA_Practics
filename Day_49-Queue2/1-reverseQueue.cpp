#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {

    queue<int> q;
    
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);

    //step1: queue -> stack
    stack<int> s;

    while(!q.empty()) {
        int element = q.front();
        q.pop();

        //stack me dal do
        s.push(element);
    }

    //step2: stack -> queue
    while(!s.empty()) {
        int element = s.top();
        s.pop();

        q.push(element);
    }

    //printing
    cout << "printing the queue" << endl;
    while(!q.empty()) {
        cout << q.front( ) << " ";
        q.pop();
    }cout << endl;

    return 0;
}