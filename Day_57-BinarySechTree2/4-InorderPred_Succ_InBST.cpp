#include<iostream>
#include<queue>
#include<limits.h>
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

int predSucc(Node* root, int key){

    //find key
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    //pred
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    //succ
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->right;
    }

    return leftTree && rightTree;
}

int main(){

    Node* root = NULL;
    root = buildTree();

    int k = 2;
    cout << predSucc(root, k);

}