#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//convert a BST into sorted LL
void convertIntoSortedDDL(Node* root, Node* &head) {
    //base case
    if(root == NULL)
        return;
    
    convertIntoSortedDDL(root->right, head);
    //R
    root->right = head;

    if(head != NULL)
        //L
        head->left = root;

    head = root;
    //L
    convertIntoSortedDDL(root->left, head);
}

//merge 2 sorted LL
Node* mergeLinkedList(Node* head1, Node* head2){

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1->data < head2->data ){

            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }//insert at tail
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

//countNode
int countNode(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

//sorted LL -> BST
Node* sortedLLtoBST(Node* & head, int n){
    //base case
    if(n <= 0 || head == NULL)
        return NULL;
    
    //step1->
    Node* left = sortedLLtoBST(head, n/2);

    //step2->
    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLtoBST(head, n-n/2-1);
    return root;
}

Node* mergeBST(Node* root1, Node* root2){

    //step1-> convert BST into sorted DLL
    Node* head1 = NULL;
    convertIntoSortedDDL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDDL(root2, head2);
    head2->left = NULL;

    //step2-> merge Sorted LL
    Node* head = mergeLinkedList(head1, head2);

    //step3-> convert DLL to BST
    return sortedLLtoBST(head, countNode(head));
}

void inorder(Node* root) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    inorder(root->left);
    //N
    cout << root->data << " ";
    //R
    inorder(root->right);
}

int main(){

    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
 
    Node *root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(7);
    root2->right->right->left = new Node(6);

    Node* temp = mergeBST(root1, root2);

    cout << "Inorder Treaversal And Merge 2 BST : " <<endl;
    inorder(temp);
}