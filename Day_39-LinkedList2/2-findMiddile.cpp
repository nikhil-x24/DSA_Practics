#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this-> data = d;
        this-> next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail-> next = newNode;
    tail = newNode;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

Node* getMiddle(Node* head) {

    if(head == NULL) {
        cout << "LIST iS empty" << endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        //2 step
        fast = fast -> next ->next;
        //1 step
        slow = slow -> next;
    }
    return slow;
}

int getLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    } return len;
}
int main(){
     //object creation
    Node* b = new Node(3);
    Node* head = b;
    Node* tail = b;

    insertAtTail(tail, 23);
    insertAtTail(tail, 12);
    insertAtTail(tail, 45);
    insertAtTail(tail, 48);
    insertAtTail(tail, 75);
    print(head);

    cout << "legnth: " << getLength(head) << endl;
    
    Node* middle = getMiddle(head);
    cout << "Middle is at " << middle->data << endl;
}