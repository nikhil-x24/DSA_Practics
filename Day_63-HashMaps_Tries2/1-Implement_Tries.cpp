// In tries -> insertion, seaching , deletions

#include<iostream>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
            this->data = d;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return ;
            }

            //current character fetch 
            char ch = word[0];

            //mapping character to an index integer
            int index = ch - 'a';

            TrieNode* child;

            //2 cases exists
            //the alphabet is already present
            // alphabet is absent

            if(root->children[index] != NULL) {
                //present case-> child pr pohoch jao
                child = root->children[index];
            }
            else {
                //absent case-> child create and link
                child = new TrieNode(ch);
                root->children[index] = child;
            }

            //Recursion will take care of insertion of remaining string
            insertUtil(child, word.substr(1));
        }

        void insert(string word) {
            insertUtil(root, word);
            cout << word << " -> Insert successful " << endl;
        }

        bool searchUtil(TrieNode* root, string word) {
            //Base case
            if(word.length() == 0) {
                return root->isTerminal;
            }

            //fetch current character
            char ch = word[0];
            //mapping character to an index integer
            int index = ch - 'a';

            TrieNode* child;

            //2 cases exists
            //the alphabet is already present
            // alphabet is absent
            if(root->children[index] != NULL) {
                //present case-> child pr pohoch jao
                child = root->children[index];
            }
            else {
                return false;
            }

            //Recursion
            return searchUtil(child, word.substr(1));

        }

        bool search(string word) {
            return searchUtil(root, word);
        }


        bool deletionUtil(TrieNode* root, string word) {
            //Base case
            if(word.length() == 0) {
                return root->isTerminal;
            }
            if(root->isTerminal == true) {
                return false;
            }

            //fetch current character
            char ch = word[0];
            //mapping character to an index integer
            int index = ch - 'a';

            TrieNode* child;

            //2 cases exists
            //the alphabet is already present
            // alphabet is absent
            if(root->children[index] != NULL) {
                //present case-> child pr pohoch jao
                child = root->children[index];
            }
            else {
                return false;
            }

            //Recursion
            return deletionUtil(child, word.substr(1));

        }

        bool deletion(string word) {
            return deletionUtil(root, word);
        }

};

int main() {

    //trie create

    Trie* trie = new Trie();

    //insert code
    trie->insert("code");
    trie->insert("coding");
    trie->insert("codemonk");
    trie->insert("coder");
    trie->insert("codee");

    cout << trie->search("code") << endl;
    cout << trie->search("coding") << endl;
    cout << trie->search("codemonk") << endl;
    cout << trie->search("coder") << endl;
    cout << trie->search("codee") << endl;
    cout << trie->search("codi") << endl;
    cout << trie->search("cody") << endl;

    cout << endl;
    trie->deletion("code");
    cout << trie->search("code") << endl;

    return 0;
}