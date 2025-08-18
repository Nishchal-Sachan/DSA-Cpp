#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int idx = word[0]-'a';
        TrieNode* child;

        // present
        if(root->children[idx]!=NULL){
            child = root->children[idx];
        }else{
            // absent
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int idx = word[0]-'a';
        TrieNode* child;

        // present
        if(root->children[idx]!=NULL){
            child = root->children[idx];
        }else{
            // absent
            return false;
        }

        //recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal = false;
            return;
        }
        int idx = word[0]-'a';
        TrieNode* child;
        // present
        if(root->children[idx]!=NULL){
            child = root->children[idx];
        }else{
            // absent
            return;
        }

        //recursion
        deleteUtil(child, word.substr(1));
        //deletion
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[idx] = NULL; 
        }
    }
    void deleteWord(string word){
        deleteUtil(root, word);
    }
};

int main(){
    Trie t;
    t.insertWord("abc");
    cout << t.searchWord("abc") << endl;
    return 0;
}