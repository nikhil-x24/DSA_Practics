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

Node* solve(int in[], int pre[], int& index, 
            int inOrderStart, int inOrderEnd, int n){

        //base case
        if(index > n) 
            return NULL;
        
        if(inOrderStart > inOrderEnd)
            return NULL;

        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);

        //RR
        root-> left = solve(in, pre, index, inOrderStart, position-1, n);
        root-> right = solve(in, pre, index, position+1, inOrderEnd, n);

}

Node* ConstructTree(int in[], int pre[], int n) {

    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
    return ans;
}

void postOrder(Node* root) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    postOrder(root->left);
    //R
    postOrder(root->right);
    //N
    cout << root->data << " ";
}

int main() {

    // int in[] = { 4, 2, 1, 7, 5, 8, 3, 6 };
    // int pre[] = { 1, 2, 4, 3, 5, 7, 8, 6 };

    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};

    int n = 6;
    Node* root = ConstructTree(inorder, preorder, n);
 
    cout << "Printing PostOrder " << endl;
    postOrder(root);
    cout << endl;

    return 0;
} 