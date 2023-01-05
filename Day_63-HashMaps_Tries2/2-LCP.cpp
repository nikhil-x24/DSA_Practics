#include<iostream>
#include<vector>
#include<string>
using namespace std;

class TrieNode {
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char d) {
            this->data = d;

            isTerminal = false;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            } 
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertHelper(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return ;
            }

            //current character fetch = 
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
            insertHelper(child, word.substr(1));
        }

        void insert(string word) {
            
            insertHelper(root, word);
           /// cout << word << " -> Insert successful " << endl;
        }

        //longest Common Prefix 

        int getChildCount(TrieNode* temp)  {
            int count = 0;

            for(int i=0; i<26; i++) {
                if(temp->children[i] != NULL)   
                    count++;
            }
            return count;
        }

        void longestCommonPrefix(string input, string &res) {
            TrieNode* temp = root;

            //traverse over input string
            for(int i=0; i<input.length(); i++) {
                
                //fetch current character
                char ch = input[i];

                if(getChildCount(temp) == 1 && temp->isTerminal == false) {
                    //include character in answer string
                    res.push_back(ch);

                    //root ko aage badhao
                    int index = ch - 'a';
                    temp = temp->children[index];
                }
                else
                    break;

                if(temp->isTerminal) 
                    break;
            }
        }
};

/*
string longestCommonPrefix(vector<string>& strs) {
    Trie* trie = new Trie();

    for(string s: strs) {
        trie->insert(s);
    }

    string res = "";
    trie->longestCommonPrefix(strs[0], res);
    return res;
} */

int main(){
    //cretions
    Trie* trie = new Trie();
    
    //insertion
    trie->insert("code");
    trie->insert("coder");
    trie->insert("codemonk");
    trie->insert("codeing");
    trie->insert("codee");

    string res = "";
    trie->longestCommonPrefix("code", res);
    cout << "Result is : " << res <<endl;

}