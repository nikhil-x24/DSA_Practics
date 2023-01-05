#include<iostream>
#include<stack>
using namespace std;

class Stack {

    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int d) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = d;
        }
        else{
            cout << "Overflow";
        }
    }

    void push2(int d) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = d;
        }
        else{
            cout << "Overflow";
        }
    }
    
    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main() {

    //creation
    Stack* st = new Stack(5);  //size

    st->push1(1);
    st->push1(2);
    st->push2(3);
    st->push2(4);
    st->push1(5);

    cout << "Popped element from stack1 is "
         << " : " << st->pop1()  << endl;

    cout << "\nPopped element from stack2 is "
         << ": " << st->pop2()  << endl;

}