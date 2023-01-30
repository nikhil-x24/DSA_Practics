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

int countKFromLast(Node* &head,int k){
    //base case
    if(head == NULL)
        return 0;
    
    int cnt  = countKFromLast(head ->next, k) + 1;
    
    if(cnt == k)
        cout << "Kth Node from end is " << head -> data << endl;
    
    return cnt;

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
    insertAtTail(tail,40);
    insertAtTail(tail,45);

    countKFromLast(head, 2);
}