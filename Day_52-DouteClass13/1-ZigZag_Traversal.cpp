#include<iostream>
#include<vector>
#include<queue>
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

Node* BuildTree(){
    cout <<"Enter a data ";
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode -> left = BuildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode -> right = BuildTree();

    return newNode;
}

vector<int> zigZagTraversal(Node* &root) {

    vector<int> result;
    if(root == NULL)
    	return result;
    	
    queue<Node*> q;
    q.push(root);
    	
    bool leftToRight = true;
    	
    while(!q.empty()) {
    	    
        int size = q.size();
        vector<int> ans(size);
    	    
        //Level Process
        for(int i=0; i<size; i++) {
    	        
            Node* frontNode = q.front();
            q.pop();
    	        
            //normal insert or reverse insert 
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;
    	        
            if(frontNode->left)
                q.push(frontNode -> left);
    	            
            if(frontNode->right)
                q.push(frontNode -> right);
        }
    	    
        //direction change karni h
        leftToRight = !leftToRight;
    	   
        for(auto i: ans) {
    	    result.push_back(i);
    	}  
    }
    return result;
}

int main(){
    Node* root = NULL;
    root = BuildTree();
    
    vector<int> ans;
    ans = zigZagTraversal(root);

    cout << "Zig Zag Traversal of Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;
    return 0;
}