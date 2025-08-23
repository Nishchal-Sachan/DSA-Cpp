#include <bits/stdc++.h>
using namespace std;

// ------------------- Trie Node -------------------
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// ------------------- Trie Class -------------------
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // Root is empty node
    }

    // Insert word into Trie
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void insertUtil(TrieNode* curr, string word) {
        if (word.length() == 0) {
            curr->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (curr->children[index] != NULL) {
            child = curr->children[index];
        } else {
            child = new TrieNode(word[0]);
            curr->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // Collect all words from current node with given prefix
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);               // add this char
                printSuggestions(next, temp, prefix); // recurse
                prefix.pop_back();                  // backtrack
            }
        }
    }

    // Get suggestions for each prefix of query string
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.size(); i++) {
            char lastCh = str[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh - 'a'];
            if (curr == NULL) {
                break; // no such prefix exists
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }

        return output;
    }
};

// ------------------- Phone Directory Function -------------------
vector<vector<string>> phoneDirectory(vector<string>& contacts, string queryStr) {
    Trie* t = new Trie();

    // Insert all contacts into Trie
    for (auto& contact : contacts) {
        t->insertWord(contact);
    }

    // Get auto-suggestions for the query string
    return t->getSuggestions(queryStr);
}

// ------------------- Main Function -------------------
int main() {
    vector<string> contacts = {"code", "coder", "coding", "codding", "coly", "cool", "bat", "ball", "batter"};
    string queryStr = "cod";

    vector<vector<string>> result = phoneDirectory(contacts, queryStr);

    cout << "Phone Directory Suggestions for query: " << queryStr << endl;
    string prefix = "";
    for (int i = 0; i < result.size(); i++) {
        prefix.push_back(queryStr[i]);
        cout << "Suggestions for \"" << prefix << "\": ";
        for (auto s : result[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
