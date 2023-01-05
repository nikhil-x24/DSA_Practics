#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {

        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if(ch == ')') {
            bool removeInvalidParentheses = true; //flag

            while(st.top() != '(') {
                char top = st.top();

                if(top == '+' || top == '-' || top == '*' || top == '/')
                    removeInvalidParentheses = false;  //flag

                st.pop();  //remove
            }

            //check rundantand
            if(removeInvalidParentheses == true){
                return true;
            }
            st.pop();
        }
    }
    return false;
}

int main(){
    string st = "(a+b)";

    bool ans = checkRedundant(st);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}