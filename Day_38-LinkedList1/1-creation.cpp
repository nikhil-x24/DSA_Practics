#include<iostream>
using namespace std;

class Node {

    //Data Member are below:
    public:
    int data;
    Node* next;

    //constructor 
    Node(int data) {
        this->data  = data;
        this->next = NULL;
    }
};

int main() {

    Node staticobj(8);
    cout << staticobj.data <<"   ";
    cout << staticobj.next <<"   " << endl;

    //object creation
    Node* first = new Node(6);
    cout << first -> data <<"   ";
    cout << first -> next << endl;

}