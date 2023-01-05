#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int findPosition(int in[], int element, int n){
    for(int i = 0; i< n; i++){
        if(in[i] == element)
            return i;
    }
    return -1;
}

Node* solve(int in[], int post[], int& index, 
            int inOrderStart, int inOrderEnd, int n){

        //base case
        if(index < 0) 
            return NULL;
        
        if(inOrderStart > inOrderEnd)
            return NULL;

        int element = post[index--];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);

        //RR
        root-> right = solve(in, post, index, position+1, inOrderEnd, n);
        root-> left = solve(in, post, index, inOrderStart, position-1, n);
        

}

Node* ConstructTree(int in[], int pre[], int n) {

    int preOrderIndex = n-1;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
    return ans;
}

void preOrder(Node* root) {
    //base case
    if(root == NULL)
        return;

    //N
    cout << root->data << " ";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);
}

int main() {

    int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};

    int n = 8;
    Node* root = ConstructTree(inorder, postorder, n);
 
    cout << "Printing PreOrder " << endl;
    preOrder(root);
    cout << endl;

    return 0;
} 