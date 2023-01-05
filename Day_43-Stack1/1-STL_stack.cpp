#include<iostream>
#include<stack>
using namespace std;
int main(){
    //creation of stack
    stack<int> st;

    //insertion
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(4);

    //size
    cout << st.size() <<endl;

    //check empty or not
    cout << st.empty() <<endl;

    //top element in stack
    cout << st.top() <<endl;

    //remove
    st.pop();
    cout << st.top() <<endl;
}