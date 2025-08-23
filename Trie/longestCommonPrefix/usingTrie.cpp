#include <bits/stdc++.h>
using namespace std;

// -------------------- Trie Node --------------------
class TrieNode {
public:
    char data;                        // stores single character
    TrieNode* children[26];           // pointers for each letter 'a' to 'z'
    int childCount;                   // how many children this node has
    bool isTerminal;                  // marks end of a word

    // Constructor
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

// -------------------- Trie Class --------------------
class Trie {
    TrieNode* root;

public:
    Trie() {
        // root node created with dummy character '\0'
        root = new TrieNode('\0');
    }

    // Utility function to insert a word into the Trie
    void insertUtil(TrieNode* root, string word) {
        // Base Case: if no characters left
        if (word.length() == 0) {
            root->isTerminal = true;   // mark end of word
            return;
        }

        int idx = word[0] - 'a';       // calculate index of character
        TrieNode* child;

        // If character already present → just move ahead
        if (root->children[idx] != NULL) {
            child = root->children[idx];
        }
        else {
            // If character absent → create new node and link
            child = new TrieNode(word[0]);
            root->children[idx] = child;
            root->childCount++;        // one more child linked to current node
        }

        // Recurse for remaining substring
        insertUtil(child, word.substr(1));
    }

    // Public function to insert word (calls recursive utility)
    void insertWord(string word) {
        insertUtil(root, word);
    }

    // Function to find longest common prefix using Trie
    void lcp(string first, string &ans) {
        TrieNode* temp = root;

        // Traverse character by character of the first word
        for (int i = 0; i < first.length(); i++) {
            char ch = first[i];

            // If node has exactly 1 child → still in common prefix
            if (temp->childCount == 1) {
                ans.push_back(ch);
                int idx = ch - 'a';
                temp = temp->children[idx];
            }
            else {
                break; // multiple branches → LCP ended
            }

            // If we reached a terminal node (end of word), stop
            if (temp->isTerminal) {
                break;
            }
        }
    }
};

// -------------------- Function for LCP --------------------
string longestCommonPrefix(vector<string> &arr, int n) {
    // Step 1: Create Trie
    Trie* t = new Trie();

    // Step 2: Insert all words into Trie
    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    // Step 3: Take the first word and check prefix
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);

    return ans;
}

// -------------------- Main Function --------------------
int main() {
    vector<string> words = {"coding", "code", "coder", "codex"};

    cout << "Words: ";
    for (auto &w : words) cout << w << " ";
    cout << endl;

    string prefix = longestCommonPrefix(words, words.size());
    cout << "Longest Common Prefix: " << prefix << endl;

    return 0;
}
