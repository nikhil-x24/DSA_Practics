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

//insert
void insertTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail-> next = newNode;
    tail = newNode;
}

void insertAtTail(Node* &tail, Node* curr){
    tail-> next = curr;
    tail = curr;
}
//print
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

Node* sortList(Node *head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }

    //1s list -> empty
    else{
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main() {
    //object creation
    Node* b = new Node(0);
    Node* head = b;
    Node* tail = b;

    insertTail(tail, 1);
    insertTail(tail, 2);
    insertTail(tail, 1);
    insertTail(tail, 0);
    insertTail(tail, 2);
    print(head);
    

    Node* Ans = sortList(head);
    print(head);

    return 0;
}