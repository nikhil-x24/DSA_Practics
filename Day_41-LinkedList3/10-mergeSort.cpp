#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};

node* findMid(node* head) {
    node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

node* merge(node* left, node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}

node* mergeSort(node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}

void push(node* &head, int d) {
        //step 1: create new node
        node* newNode = new node(d);
        //step2: set next ptr to head node
        newNode->next = head;
        //step3: head update;
        head = newNode;
}

void traverse(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout << endl;
}

int main(){

    node* res = NULL;
    node* head = NULL;
  
    /* Let us create a unsorted linked lists to test the functions 
       Created lists shall be a: 2->3->20->5->10->15 */
    push(head, 15);
    push(head, 10);
    push(head, 5);
    push(head, 20);
    push(head, 3);
    push(head, 2);
 
    mergeSort(head);
  
    cout << "Sorted Linked List is: " <<endl;
    traverse(head);
  
    return 0;
}