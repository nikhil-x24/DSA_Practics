#include<iostream>
#include<queue>
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

Node* buildTree() {
    cout << "Enter the value of data " << endl;
    int data;
    cin >> data;

    if(data == -1) 
        return NULL;

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode -> left = buildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode -> right = buildTree();

    return newNode;
}

int height(Node* root ) {
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node* root) {
    if(root == NULL)
        return 0;

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = 1 + height(root->left) + height(root->right);
    int ans =  max(option1, max(option2, option3));
    return ans;
}

int diameterOfBinaryTree(Node* root) {
    if(root == NULL)
        return 0;

    return diameter(root) - 1;
}


/////////////
pair<int, int> diameterFast(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) +1;

    return ans;
}

int dimeter(Node* root){
    if(root == NULL)
        return 0;
        
    return diameterFast(root).first;
}
int main() {

    Node* root = NULL;
    root = buildTree();
    cout << "Diameter of tree is: " << dimeter(root) << endl;

}