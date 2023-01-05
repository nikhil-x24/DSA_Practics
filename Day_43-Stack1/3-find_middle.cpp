#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>& st, int totalSize) {
    
    //base case
    if( (totalSize/2) + 1 ==  st.size()) {
        cout << "Middle is: " << st.top() << endl;
        return;
    }

    //step1
    int topElement = st.top();
    st.pop();

    //step2-> RR
    printMiddle(st, totalSize);

    //step3 -> wapas push kr do stack me
    st.push(topElement);
}

int main() {

    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    //st.push(12);

    printMiddle(st, st.size());

    return 0;
}