#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this->data  = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d) {
        Node* newNode = new Node(d);
        tail->next = newNode;
        tail = newNode;
}

void traverse(Node* &head) {
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

bool isCircular(Node* &head) {
    Node* temp = head;

    //to traverse the LL, in normal case
    while(temp != NULL) {

        //incase the list is circular
        if(temp->next == head) {
            return true;
        }
        //move one node ahead
        temp = temp ->next;
    }
    //it means we have traversed the entire list, return false
    return false;
}

int main(){
    
    //object creation
    Node* b = new Node(3);
    Node* head = b;
    Node* tail = b;

    insertAtTail(tail,5);
    insertAtTail(tail,7);
    insertAtTail(tail,9);
    insertAtTail(tail,11);
    insertAtTail(tail,13);
    insertAtTail(tail,14);

    traverse(head);

    head -> next  = head; //to make circular

    cout << "Circular or not " << isCircular(head) << endl;

}