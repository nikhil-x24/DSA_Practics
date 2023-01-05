#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
   
    Node(int data){
        this->data  = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
        Node* newNode = new Node(d);
        tail->next = newNode;
        tail = newNode;
}

void traverse(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

Node* detectLoop(Node* &head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow ->next;
        fast = fast -> next ->next;

        //isko upr lgne se error aye ga
        if(slow == fast)
            return slow;
    }
    return NULL;
}

bool detectAndDeleteLoop(Node* &head) {

    if(head == NULL)
        return false;

    //Step1: detect if loop is present or not
    Node* fast = detectLoop(head);

    if(fast == NULL){
        cout << "Loop is not there" <<endl;
        return true;
    }
    
    //Step2: detect beginning node
    Node* slow = head;

    while(fast != slow) {
        slow = slow ->next;
        fast = fast ->next;
    }

    Node* beginningNode = slow;
    //step3: remove the loop connection
    Node* temp = beginningNode;

    while(temp ->next != beginningNode) {
        temp = temp->next;
    }
    temp ->next = NULL;
    return true;
}


int main(){
    //object creation

    Node* b = new Node(3);
    Node* head = b;
    Node* tail = b;

    insertAtTail(tail,5);
    insertAtTail(tail,7);
    insertAtTail(tail,9);
    Node* temp = tail;
    insertAtTail(tail,11);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);    //15 point 9
    tail -> next = temp;

    cout << detectAndDeleteLoop(head) << endl;
    traverse(head);
}