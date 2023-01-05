#include<iostream>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};

void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

int getLength(node* head) {
    int len = 0;
        
    node* temp = head;
        
    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
} 

node* rotateRight(node* head,int k) {

    int n = getLength(head);  

    if(head == NULL || head -> next == NULL || k == 0 || k % n == 0)
        return head;
        
    //update k
    k = k % n;
       
    node* prev = NULL;
    node* curr = head;
        
    int t = n-k;
        
    while(t--) {
        prev = curr;
        curr = curr->next;
    }    
    //step2
    prev -> next = NULL;               
    //step3: tail -> next = head
    
    node* tail = curr;
    while(tail ->next != NULL) {
        tail = tail -> next;
    }
            
    tail -> next = head;
        
    //step4: return ans
    return curr;

}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 2;
    node* newHead = rotateRight(head,k);
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);
    return 0;

}