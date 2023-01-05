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
void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);
    tail-> next = newNode;
    tail = newNode;
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

Node* getMid(Node* head ) {
    Node* slow = head;
    Node* fast = head -> next;
       
    while(fast != NULL && fast-> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reverse(Node* head) {
        
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
        
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//Function to check whether the list is palindrome.
bool isPalindrome(Node *head){

    if(head -> next == NULL) {
        return true;
    }
        
    //step 1 -> find Middle
    Node* middle = getMid(head);
    //cout << "Middle " << middle->data << endl;
      
    //step2 -> reverse List after Middle
    Node* temp = middle -> next;
    middle -> next = reverse(temp);
        
    //step3 - Compare both halves
    Node* head1 = head;
    Node* head2 = middle -> next;
        
    while(head2 != NULL) {
        if(head2->data != head1->data) {
            return 0;
        }
        //aage badho
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    
    //step4 - repeat step 2 jyse LL aai thi wyse hi honi chahiye
    temp = middle -> next;
    middle -> next = reverse(temp);
        
    return true;
}

int main(){
    //object creation
    Node* b = new Node(3);
    Node* head = b;
    Node* tail = b;

    insertAtTail(tail, 23);
    insertAtTail(tail, 12);
    insertAtTail(tail, 12);
    insertAtTail(tail, 23);
    insertAtTail(tail, 3);
    print(head);
    
    cout << "Palindrome or not " << isPalindrome(head) << endl;
}