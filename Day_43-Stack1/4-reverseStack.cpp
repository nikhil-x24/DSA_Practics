#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int item) {
    //base case
    if(st.empty()) {
        st.push(item);
        return;
    }

    //step1
    int topElement = st.top();
    st.pop();

    //step2: recursive call
    insertAtBottom(st, item);

    //step3:
    st.push(topElement);

}

void reverse(stack<int>& st) {
    //base case
    if(st.empty())
        return;
    
    //step1:
    int topElement = st.top();
    st.pop();

    //step2
    reverse(st);

    //step3:
    insertAtBottom(st, topElement);
}

int main() {

    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    st.push(12);

    //insertAtBottom(st, 15);
    reverse(st);

    //print
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}