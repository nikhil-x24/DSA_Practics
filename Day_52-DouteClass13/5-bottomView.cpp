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

vector<int> bottomView(Node *root) {

    vector<int> ans;
    if(root == NULL) {
            return ans;
    }
        
    map<int,int> topNode;
    queue<pair<Node*, int> > q;
        
    q.push(make_pair(root, 0));
        
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
            
        //if one value is present for a HD, then do nothing
        //if(topNode.find(hd) == topNode.end())           -> check mt kro
        topNode[hd] = frontNode -> data;
                
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
        
    for(auto i:topNode) {
            ans.push_back(i.second);
    }
    return ans;
}

int main() {
    Node* root = NULL;
    root = BuildTree();
    
    vector<int> ans;
    ans = bottomView(root);

    cout << "Bottom View in Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;
    return 0;
}