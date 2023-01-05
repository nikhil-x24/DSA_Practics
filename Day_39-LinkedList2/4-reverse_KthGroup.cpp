#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
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

Node* reverseInKth(Node* &head, int k) {
    //empty list
    if(head == NULL)
        return NULL;

    Node* curr = head;
    Node* next = curr -> next;
    Node* prev = NULL;

    int count = 0;  //track ki kitne node reverse ho gya
    
    //Step 1: reverse first k nodes
    while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next; 
        count++;
    }
    //next pointer will be pointing at the head of the remaining list
    if(next != NULL){
        //step2:recursion will get ans for remaining list
        Node* rem = reverseInKth(curr, k);
        //step3: connection list in step 1 and step 3
        head -> next = rem;
    } 
    //step 4: return head of entire list
    return prev;
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
    cout << endl;

    head = reverseInKth(head, 3);
    traverse(head);

}