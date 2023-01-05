#include<iostream>
#include<queue>
#include<vector>
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

void lvlOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    //change no. 1
    q.push(NULL);

    while(!q.empty()) {
        //tu nikal
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            //catch here
            if(!q.empty())//still elements are present
                q.push(NULL);
        }
        else{
            cout << front->data << " ";

            //bache chor jaio
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);
        }
    }
}

int position(vector<int> in, int key, int s, int e) {
    for(int i=s; i<=e; i++) {
        if(in[i] == key)
            return i;
    }
    return -1;
}
Node* buildFromInorderPreorder(vector<int> in, vector<int> preorder, 
                int &preOrderIndex, int inStart, int inEnd) {
    
    //Base case
    if(preOrderIndex == preorder.size() || inStart > inEnd) {
        return NULL;
    }

    int element = preorder[preOrderIndex++];
    Node* root = new Node(element);

    //search element in inorder array
    int pos = position(in, element, inStart, inEnd);
    root -> left = buildFromInorderPreorder(in, preorder, preOrderIndex, inStart, pos-1);
    root -> right = buildFromInorderPreorder(in, preorder, preOrderIndex, pos+1, inEnd);
    return root;
}


Node* buildFromInorderPostorder(vector<int> in, vector<int> postorder, 
                int &postOrderIndex, int inStart, int inEnd) {
    
    //Base case
    if(postOrderIndex < 0 || inStart > inEnd) {
        return NULL;
    }

    int element = postorder[postOrderIndex--];
    Node* root = new Node(element);

    //search element in inorder array
    int pos = position(in, element, inStart, inEnd);
    root -> right = buildFromInorderPostorder(in, postorder, postOrderIndex, 
                                              pos+1, inEnd);
    root -> left = buildFromInorderPostorder(in, postorder, postOrderIndex, 
                                              inStart, pos-1);
    
    return root;
}

int main() {

    vector<int> inorder;
    inorder.push_back(4);
    inorder.push_back(8);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(1);
    inorder.push_back(6);
    inorder.push_back(3);
    inorder.push_back(7);

    vector<int> preorder;
    preorder.push_back(8);
    preorder.push_back(4);
    preorder.push_back(5);
    preorder.push_back(2);
    preorder.push_back(6);
    preorder.push_back(7);
    preorder.push_back(3);
    preorder.push_back(1);

    vector<int> postorder ;
    postorder.push_back(8);
    postorder.push_back(4);
    postorder.push_back(5);
    postorder.push_back(2);
    postorder.push_back(6);
    postorder.push_back(7);
    postorder.push_back(3);
    postorder.push_back(1);
    
    int preindex = 0;
    int postindex = postorder.size() - 1;
    Node* PreRoot = buildFromInorderPreorder(inorder, preorder, preindex, 0, 7);
    Node* PostRoot = buildFromInorderPostorder(inorder, postorder, postindex, 0, 7);
    lvlOrderTraversal(PreRoot);
    cout <<endl;
    lvlOrderTraversal(PostRoot);

    return 0;
}