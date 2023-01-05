#include<iostream>
#include<stack>
using namespace std;

int main() {

    int n;
    cin >> n;

    stack<int> s;

    while(n-- ) {
        int data;
        cin >> data;
        s.push(data);
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}