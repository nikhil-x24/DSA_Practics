#include<iostream>
#include<vector>
#include<map>
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

vector<int> verticalOrder(Node *root) {

    map<int, map<int,vector<int> > > nodes;
    queue< pair<Node*, pair<int,int> > > q;
    vector<int> ans;
        
    if(root == NULL)
        return ans;
            
    q.push(make_pair(root, make_pair(0,0)));
        
    while(!q.empty()) {
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
            
        nodes[hd][lvl].push_back(frontNode->data);
            
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }
        
    for(auto i: nodes) {
          
        for(auto j:i.second) {
                
            for(auto k:j.second) {
                    ans.push_back(k);
            }
        }
    }
    return ans;
}

int main() {

    Node* root = NULL;
    root = BuildTree();
    
    vector<int> ans;
    ans = verticalOrder(root);

    cout << "Vertical Order Traversal of Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;

	return 0;
}
