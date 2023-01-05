#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    } 
};

//insert element
void insertAtHead(Node* & head, int d){
    Node* newNode = new Node(d);
    newNode-> next = head;
    head = newNode;
}

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail-> next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head, int position, int d){
    if(position == 1)
        return insertAtHead(head, d);
    
    else{
        Node* newNode = new Node(d);

        Node* prev = head;
        int t = position-2;
        while(t--){
            prev = prev-> next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
    }
}

//print
void traverse(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

//reverse
Node* reverse(Node* &head){
    //edge case
    if(head == NULL){
        cout << "List is Empty" << endl;
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* forward = curr-> next;
        curr-> next = prev;
        //aage badho
        prev = curr;
        curr = forward;
    }
    return prev;
}

//reverse RR
Node* revRR(Node* &curr, Node* prev){
    //base case
    if(curr == NULL){
        return prev;
    }

    //connection change
    Node* forward = curr-> next;
    curr-> next = prev;

    //RR
    return revRR(forward, curr);
}

int main(){
    //object creating
    Node* b = new Node(8);
    Node* head = b;
    Node* tail = b;

    insertAtHead(head, 5);
    insertAtHead(head, 15);
    insertAtHead(head, 35);
    insertAtTail(tail, 12);
    insertAtTail(tail, 21);
    insertAtPosition(head, 4, 124);
    traverse(head);

    cout <<"Reverse :" <<endl;

    head = revRR(head, NULL);
    traverse(head);

}